
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/PrimaryGamma.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::PrimaryGamma
void wrapPrimaryGamma(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::PrimaryGamma;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "PrimaryGamma",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const double &,
         const double &,
         const double &,
         const general::Axes &
      >(),
      py::arg("value"),
      py::arg("domain_min"),
      py::arg("domain_max"),
      py::arg("axes"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set value
   object.def_property(
      "value",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.value();
      },
      [](cppCLASS &self, const double &value)
      {
         self.value() = value;
      },
      cppCLASS::component_t::documentation("value").data()
   );

   // get/set domainMin
   object.def_property(
      "domain_min",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.domainMin();
      },
      [](cppCLASS &self, const double &value)
      {
         self.domainMin() = value;
      },
      cppCLASS::component_t::documentation("domain_min").data()
   );

   // get/set domainMax
   object.def_property(
      "domain_max",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.domainMax();
      },
      [](cppCLASS &self, const double &value)
      {
         self.domainMax() = value;
      },
      cppCLASS::component_t::documentation("domain_max").data()
   );

   // get/set axes
   object.def_property(
      "axes",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.axes();
      },
      [](cppCLASS &self, const general::Axes &value)
      {
         self.axes() = value;
      },
      cppCLASS::component_t::documentation("axes").data()
   );

   // shortcut: get/set axis
   object.def_property(
      "axis",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.axis();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.axis())> &value)
      {
         self.axis() = value;
      },
      cppCLASS::component_t::documentation("axis").data()
   );

   // shortcut: get/set grid
   object.def_property(
      "grid",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.grid();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.grid())> &value)
      {
         self.grid() = value;
      },
      cppCLASS::component_t::documentation("grid").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0