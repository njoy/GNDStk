
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Weighted.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Weighted
void wrapWeighted(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Weighted;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "Weighted",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const general::XYs1d &,
         const general::Evaporation &
      >(),
      pybind11::arg("xys1d"),
      pybind11::arg("evaporation"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set XYs1d
   object.def_property(
      "xys1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.XYs1d();
      },
      [](cppCLASS &self, const general::XYs1d &value)
      {
         self.XYs1d() = value;
      },
      cppCLASS::component_t::documentation("xys1d").data()
   );

   // get/set evaporation
   object.def_property(
      "evaporation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.evaporation();
      },
      [](cppCLASS &self, const general::Evaporation &value)
      {
         self.evaporation() = value;
      },
      cppCLASS::component_t::documentation("evaporation").data()
   );

   // shortcut: get/set U
   object.def_property(
      "u",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.U();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.U())> &value)
      {
         self.U() = value;
      },
      cppCLASS::component_t::documentation("u").data()
   );

   // shortcut: get/set axes
   object.def_property(
      "axes",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.axes();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.axes())> &value)
      {
         self.axes() = value;
      },
      cppCLASS::component_t::documentation("axes").data()
   );

   // shortcut: get/set regions1d
   object.def_property(
      "regions1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.regions1d();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.regions1d())> &value)
      {
         self.regions1d() = value;
      },
      cppCLASS::component_t::documentation("regions1d").data()
   );

   // shortcut: get/set theta
   object.def_property(
      "theta",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.theta();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.theta())> &value)
      {
         self.theta() = value;
      },
      cppCLASS::component_t::documentation("theta").data()
   );

   // shortcut: get/set uncertainty
   object.def_property(
      "uncertainty",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.uncertainty();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.uncertainty())> &value)
      {
         self.uncertainty() = value;
      },
      cppCLASS::component_t::documentation("uncertainty").data()
   );

   // shortcut: get/set values
   object.def_property(
      "values",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.values();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.values())> &value)
      {
         self.values() = value;
      },
      cppCLASS::component_t::documentation("values").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
