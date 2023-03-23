
// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_core {

void wrapNode(python::module &module)
{
   // type aliases
   using Component = njoy::GNDStk::Node;
   using RefConstComponent = std::reference_wrapper< const Component >;

   // create the core component
   python::class_< Component > component(
      module,
      "Node",
      "GNDS core node"
   );

   // wrap the core component
   component
      // add the default Node constructor to the python class
      .def(
         python::init<>(),
         "Initialise an empty node\n\n"
         "Arguments:\n"
         "    self   the node"
      )

      // add the Node constructor using a string argument to the python class
      .def(
         python::init<const std::string &>(),
         python::arg("name"),
         "Initialise the node with its name\n\n"
         "Arguments:\n"
         "    self   the node\n"
         "    name   the name of the node"
      )

      // add the copy constructor to the python class
      .def(
         python::init<const Component &>(),
         python::arg("name"),
         "Initialise the node with a copy of a node\n\n"
         "Arguments:\n"
         "    self   the node\n"
         "    copy   the node to be copied"
      )

      // add a public member/field with read only access
      // you can use def_readwrite to make it read/write
      .def_readonly(
         "name",
         &Component::name,
         "The name of the node"
      )

      .def_readonly(
         "metadata",
         &Component::metadata,
         "The metadata of the node"
      )

      .def_property_readonly(
         "children",
         // we cannot expose a vector of unique pointers, so we need
         // to transform them into a vector of references first (since
         // this is readonly, we use const references)
         [] (const Component &self) -> std::vector<RefConstComponent>
         {
            std::vector<RefConstComponent> children;
            for (auto &pointer : self.children)
               children.push_back(std::cref(*pointer));
            return children;
         },
         "The children of the node"
      )

      .def(
         "add",
         // we need to define one of these for every type we want to use since
         // python does not have a concept of templates
         [] (Component &self, const std::string &name, const std::string &value)
         {
            return self.add(name,value);
         },
         python::arg("name"), python::arg("value"),
         "Add the name,value pair as metadata to the node.\n\n"
         "Arguments:\n"
         "    name    the name of the metadata\n"
         "    value   the value of the metadata\n"
      )

      // add a public member function
      .def(
         "add",
         // we need to define one of these for every type we want to use since
         // python does not have a concept of templates
         [] (Component &self, const std::string &name, int value)
         {
            return self.add(name,value);
         },
         python::arg("name"), python::arg("value"),
         "Add the name,value pair as metadata to the node.\n\n"
         "Arguments:\n"
         "    name    the name of the metadata\n"
         "    value   the value of the metadata\n"
      )

      // add a public member function
      .def(
         "add",
         // we need to define one of these for every type we want to use since
         // python does not have a concept of templates
         [] (Component &self, const std::string &name, double value)
         {
            return self.add(name,value);
         },
         python::arg("name"), python::arg("value"),
         "Add the name,value pair as metadata to the node.\n\n"
         "Arguments:\n"
         "    name    the name of the metadata\n"
         "    value   the value of the metadata\n"
      )    // add a public member function

      .def(
         "empty",
         &Component::empty,
         "Return whether or not the node is empty"
      )

      // add a public member function
      .def(
         "clear",
         &Component::clear,
         "Clear the content of the node and return the resulting empty node"
      )

      // add a new custom function
      .def(
         "to_string",
         [] (const Component &self) -> std::string
         {
            if (self.empty())
               return "";
            std::ostringstream oss;
            self.write(oss);
            return oss.str();
         },
         "Return a string representation of the node"
      );
} // void wrapNode

} // namespace python_core
