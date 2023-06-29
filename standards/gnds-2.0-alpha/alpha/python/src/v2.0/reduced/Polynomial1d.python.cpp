
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/reduced/Polynomial1d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_reduced {

// wrapper for reduced::Polynomial1d
void wrapPolynomial1d(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = reduced::Polynomial1d;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Polynomial1d",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const double &,
         const double &,
         const general::Axes &,
         const general::Values &
      >(),
      py::arg("domain_min"),
      py::arg("domain_max"),
      py::arg("axes"),
      py::arg("values"),
      cppCLASS::component_t::documentation("constructor").data()
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

   // get/set values
   object.def_property(
      "values",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.values();
      },
      [](cppCLASS &self, const general::Values &value)
      {
         self.values() = value;
      },
      cppCLASS::component_t::documentation("values").data()
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

} // namespace python_reduced
} // namespace python_v2_0
