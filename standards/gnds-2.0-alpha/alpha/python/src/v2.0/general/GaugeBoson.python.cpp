
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/GaugeBoson.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::GaugeBoson
void wrapGaugeBoson(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::GaugeBoson;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "GaugeBoson",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const general::Mass &,
         const general::Spin &,
         const general::Parity &,
         const general::Charge &,
         const general::Halflife &
      >(),
      py::arg("id"),
      py::arg("mass"),
      py::arg("spin"),
      py::arg("parity"),
      py::arg("charge"),
      py::arg("halflife"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set id
   object.def_property(
      "id",
      [](const cppCLASS &self)
      {
         return self.id();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.id() = value;
      },
      cppCLASS::component_t::documentation("id").data()
   );

   // get/set mass
   object.def_property(
      "mass",
      [](const cppCLASS &self)
      {
         return self.mass();
      },
      [](cppCLASS &self, const general::Mass &value)
      {
         self.mass() = value;
      },
      cppCLASS::component_t::documentation("mass").data()
   );

   // get/set spin
   object.def_property(
      "spin",
      [](const cppCLASS &self)
      {
         return self.spin();
      },
      [](cppCLASS &self, const general::Spin &value)
      {
         self.spin() = value;
      },
      cppCLASS::component_t::documentation("spin").data()
   );

   // get/set parity
   object.def_property(
      "parity",
      [](const cppCLASS &self)
      {
         return self.parity();
      },
      [](cppCLASS &self, const general::Parity &value)
      {
         self.parity() = value;
      },
      cppCLASS::component_t::documentation("parity").data()
   );

   // get/set charge
   object.def_property(
      "charge",
      [](const cppCLASS &self)
      {
         return self.charge();
      },
      [](cppCLASS &self, const general::Charge &value)
      {
         self.charge() = value;
      },
      cppCLASS::component_t::documentation("charge").data()
   );

   // get/set halflife
   object.def_property(
      "halflife",
      [](const cppCLASS &self)
      {
         return self.halflife();
      },
      [](cppCLASS &self, const general::Halflife &value)
      {
         self.halflife() = value;
      },
      cppCLASS::component_t::documentation("halflife").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
