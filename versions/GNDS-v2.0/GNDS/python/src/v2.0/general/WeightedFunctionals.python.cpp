
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/WeightedFunctionals.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::WeightedFunctionals
void wrapWeightedFunctionals(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::WeightedFunctionals;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "WeightedFunctionals",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::vector<general::Weighted> &
      >(),
      pybind11::arg("weighted"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set weighted
   object.def_property(
      "weighted",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.weighted();
      },
      [](cppCLASS &self, const std::vector<general::Weighted> &value)
      {
         self.weighted() = value;
      },
      cppCLASS::component_t::documentation("weighted").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS