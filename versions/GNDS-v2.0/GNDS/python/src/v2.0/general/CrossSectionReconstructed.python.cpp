
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/CrossSectionReconstructed.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::CrossSectionReconstructed
void wrapCrossSectionReconstructed(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::CrossSectionReconstructed;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "CrossSectionReconstructed",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::string &,
         const std::string &,
         const std::string &
      >(),
      pybind11::arg("label"),
      pybind11::arg("derived_from"),
      pybind11::arg("date"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set derivedFrom
   object.def_property(
      "derived_from",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.derivedFrom();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.derivedFrom() = value;
      },
      cppCLASS::component_t::documentation("derived_from").data()
   );

   // get/set date
   object.def_property(
      "date",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.date();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.date() = value;
      },
      cppCLASS::component_t::documentation("date").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
