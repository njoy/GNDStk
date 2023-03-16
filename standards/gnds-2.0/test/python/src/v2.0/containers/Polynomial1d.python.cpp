
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/containers/Polynomial1d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_containers {

// wrapper for containers::Polynomial1d
void wrapPolynomial1d(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = containers::Polynomial1d;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Polynomial1d",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<XMLName> &,
         const std::optional<Float64> &,
         const std::optional<Integer32> &,
         const Float64 &,
         const Float64 &,
         const containers::Axes &,
         const std::optional<extra::Uncertainty> &,
         const containers::Values &
      >(),
      py::arg("label") = std::nullopt,
      py::arg("outer_domain_value") = std::nullopt,
      py::arg("lower_index") = std::nullopt,
      py::arg("domain_min"),
      py::arg("domain_max"),
      py::arg("axes"),
      py::arg("uncertainty") = std::nullopt,
      py::arg("values"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::optional<XMLName> &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set outerDomainValue
   object.def_property(
      "outer_domain_value",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.outerDomainValue();
      },
      [](cppCLASS &self, const std::optional<Float64> &value)
      {
         self.outerDomainValue() = value;
      },
      cppCLASS::component_t::documentation("outer_domain_value").data()
   );

   // get/set lowerIndex
   object.def_property(
      "lower_index",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.lowerIndex().value();
      },
      [](cppCLASS &self, const Integer32 &value)
      {
         self.lowerIndex() = value;
      },
      cppCLASS::component_t::documentation("lower_index").data()
   );

   // get/set domainMin
   object.def_property(
      "domain_min",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.domainMin();
      },
      [](cppCLASS &self, const Float64 &value)
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
      [](cppCLASS &self, const Float64 &value)
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
      [](cppCLASS &self, const containers::Axes &value)
      {
         self.axes() = value;
      },
      cppCLASS::component_t::documentation("axes").data()
   );

   // get/set uncertainty
   object.def_property(
      "uncertainty",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.uncertainty();
      },
      [](cppCLASS &self, const std::optional<extra::Uncertainty> &value)
      {
         self.uncertainty() = value;
      },
      cppCLASS::component_t::documentation("uncertainty").data()
   );

   // get/set values
   object.def_property(
      "values",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.values();
      },
      [](cppCLASS &self, const containers::Values &value)
      {
         self.values() = value;
      },
      cppCLASS::component_t::documentation("values").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_containers
} // namespace python_v2_0
