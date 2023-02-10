
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Reactions.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Reactions
void wrapReactions(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Reactions;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Reactions",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::Reaction> &
      >(),
      py::arg("reaction"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set reaction
   object.def_property(
      "reaction",
      [](const cppCLASS &self)
      {
         return self.reaction();
      },
      [](cppCLASS &self, const std::vector<general::Reaction> &value)
      {
         self.reaction() = value;
      },
      cppCLASS::component_t::documentation("reaction").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
