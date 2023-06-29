
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/IncompleteReactions.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_transport {

// wrapper for transport::IncompleteReactions
void wrapIncompleteReactions(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = transport::IncompleteReactions;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "IncompleteReactions",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<transport::Reaction> &
      >(),
      py::arg("reaction") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set reaction
   object.def_property(
      "reaction",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.reaction();
      },
      [](cppCLASS &self, const std::optional<transport::Reaction> &value)
      {
         self.reaction() = value;
      },
      cppCLASS::component_t::documentation("reaction").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_transport
} // namespace python_v2_0
