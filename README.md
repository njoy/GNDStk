# GNDStk
Generalized Nuclear Database Structure toolkit

## LICENSE
This software is copyrighted by Los Alamos National Laboratory and distributed according to the conditions in the accompanying [LICENSE](LICENSE) file.

## Usage

```cpp
#include "GNDStk.hpp"
// Everything is in njoy::GNDStk namespace
```

### Infrastructure Classes
#### Metadata
This class holds the metadata. It's simply a `std::map` under the hood.  The `AllowedKeys` template parameter is a compile-time constant `std::vector` That specifies which keys are allowed. If some other key is given, an exception is thrown.
```cpp
// exception is thrown.
template< const std::vector< std::string >& AllowedKeys, 
          typename ValueType=std::string >
class Metadata{...};
```
There are two pre-defined vectors of `AllowedKeys` that can help
```cpp
inline const std::vector< std::string > allKeysValid;
inline const std::vector< std::string > noValidKeys{ "241993800" };
```
If `AllowedKeys` is empty, then any metadata key is valid. 

#### SterileNode
A node that does not have children. It contains a `Metadata` instance
```cpp
template< const std::vector< std::string >& AllowedKeys >
class SterileNode {...};
```

#### Generic Node
```cpp
// Generic Node class. The Ls... template parameters indicate which types are 
// allowed as children. As with the SterileNode, it also has a Metadata instance
template< const std::vector< std::string >& AllowedKeys, typename... Ls >
class Node : protected SterileNode< AllowedKeys > {...};
```
There is a `children()` method to get the children that are contained.
```cpp
auto children() const{...}
auto children( int index ) const{...}
template< typename T > auto children() const{...}
```
The `index` argument and the `T` parameter are used to specify which type of the children you want to retrieve. This isn't working quite as well as I would like. See Issues below.

### Basic GNDS Nodes
The above nodes are not intended to be used, but to be derived from. (Perhaps there is something we can do to ensure this.) All of the nodes that we want to use for GNDStk lie in the `GNDStk::nodes` namespace.

### `Axis` Node
It doesn't get any simpler than this.
```
inline const std::vector< std::string > axisKeys{ "label", "unit" };
struct Axis : public SterileNode< axisKeys >{ };
```

### `Axes` Node
This one is also fairly simple.
```cpp
class Axes : public Node< noValidKeys, Axis, Grid >  {
public:
  using Node_t = Node< noValidKeys, Axis >;
  auto axis() const { return this->children< Axis >(); }
  auto grid() const { return this->children< Grid >(); }
};
```
Note that I've added a few specific methods to facilitate getting the children that I want.

### `Values` Node
This is a "leaf node" in that it doesn't have any children; thus it inherits from `SterileNode`. With the above classes defined, it is really easy to define the `Values` Node.
```cpp
inline const
std::vector< std::string > valuesKeys{ "start", "length" };

template< typename ValueType = double >
struct Values : public SterileNode< valuesKeys >{
public:
  using Node_t = SterileNode< valuesKeys >;
private:
  std::vector< ValueType > values_;
public:

#include "GNDStk/nodes/Values/src/ctor.hpp"

  const auto& values() const{ return values_; }
};
```
I can instantiate the `Values` Node like this:
```cpp
// Create a Node that has two values
GNDStk::nodes::Values< double > iILValues{ { 13.0, 14.0 } };
// I can also specify start and length parameters during consruction
GNDStk::nodes::Values< double > dSparse{ { 13.0, 14.0 }, 3, 7 };
```
See [GNDStk/nodes/Values/test/Values.test.cpp](src/GNDStk/nodes/Values/test/Values.test.cpp) for full usage

### `XYs1d` Node
This one I haven't created yet, but I'm hoping it's as easy as:
```cpp
inline const
std::vector< std::string > valuesKeys{ "interpolation", "label" };
class XYs1d : public Node< valuesKeys, Axes, Uncertainties, Uncertainty, Values >{
public:
  double value;
};
```
Please note that `value` is officially an "attribute" (i.e., metadata) according to GNDS. However, it isn't really metadata, so we shouldn't treat it as such. There are many such instances throughout GNDS.

### Issues
1. The `children()` method (all versions) returns a "range" which I can iterate over, but I can't index; i.e., I can't call `operator[]` on it. Could use some help figuring this out. 
2. I have not implemented the builder pattern. 
   1. We could build this on top of what I have, but then we can create Nodes in multiple ways
   2. We could scrap the constructors that I have and make the builder the only way to construct these Nodes.
