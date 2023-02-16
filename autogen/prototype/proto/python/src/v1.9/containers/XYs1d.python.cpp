
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "proto/v1.9/containers/XYs1d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v1_9 {
namespace python_containers {

// wrapper for containers::XYs1d
void wrapXYs1d(py::module &module)
{
   using namespace proto;
   using namespace proto::v1_9;

   // type aliases
   using cppCLASS = containers::XYs1d;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "XYs1d",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<int> &,
         const std::optional<enums::Interpolation> &,
         const std::optional<std::string> &,
         const std::optional<double> &,
         const std::optional<containers::Axes> &,
         const containers::Values &
      >(),
      py::arg("index") = std::nullopt,
      py::arg("interpolation") = std::nullopt,
      py::arg("label") = std::nullopt,
      py::arg("outer_domain_value") = std::nullopt,
      py::arg("axes") = std::nullopt,
      py::arg("values"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set index
   object.def_property(
      "index",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.index();
      },
      [](cppCLASS &self, const std::optional<int> &value)
      {
         self.index() = value;
      },
      cppCLASS::component_t::documentation("index").data()
   );

   // get/set interpolation
   object.def_property(
      "interpolation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.interpolation().value();
      },
      [](cppCLASS &self, const enums::Interpolation &value)
      {
         self.interpolation() = value;
      },
      cppCLASS::component_t::documentation("interpolation").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
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
      [](cppCLASS &self, const std::optional<double> &value)
      {
         self.outerDomainValue() = value;
      },
      cppCLASS::component_t::documentation("outer_domain_value").data()
   );

   // get/set axes
   object.def_property(
      "axes",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.axes();
      },
      [](cppCLASS &self, const std::optional<containers::Axes> &value)
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
} // namespace python_v1_9
