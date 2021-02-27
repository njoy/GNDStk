// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"

// namespace aliases
namespace python = pybind11;

namespace core {

  void wrapNode( python::module& module ) {

    // type aliases
    using Component = njoy::GNDStk::core::Node;

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

      python::init< const std::string& >(),
      python::arg( "name" ),
      "Initialise the node with its name\n\n"
      "Arguments:\n"
      "    self   the node\n"
      "    name   the name of the node"
    )
    // add the copy constructor to the python class
    .def(

      python::init< const Component& >(),
      python::arg( "name" ),
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
    // add a public member function
    .def(

      "empty",
      &Component::empty,
      "Return whether or not the node is empty"
    );
  }
}
