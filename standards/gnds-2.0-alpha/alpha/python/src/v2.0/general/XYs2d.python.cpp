
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/XYs2d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::XYs2d
void wrapXYs2d(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::XYs2d;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "XYs2d",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<int> &,
         const std::optional<std::string> &,
         const std::optional<std::string> &,
         const std::optional<double> &,
         const std::optional<general::Axes> &,
         const general::Function1ds &,
         const std::optional<general::Uncertainty> &
      >(),
      py::arg("index") = std::nullopt,
      py::arg("interpolation") = std::nullopt,
      py::arg("interpolation_qualifier") = std::nullopt,
      py::arg("outer_domain_value") = std::nullopt,
      py::arg("axes") = std::nullopt,
      py::arg("function1ds"),
      py::arg("uncertainty") = std::nullopt,
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
         return self.interpolation();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.interpolation() = value;
      },
      cppCLASS::component_t::documentation("interpolation").data()
   );

   // get/set interpolationQualifier
   object.def_property(
      "interpolation_qualifier",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.interpolationQualifier();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.interpolationQualifier() = value;
      },
      cppCLASS::component_t::documentation("interpolation_qualifier").data()
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
      [](cppCLASS &self, const std::optional<general::Axes> &value)
      {
         self.axes() = value;
      },
      cppCLASS::component_t::documentation("axes").data()
   );

   // get/set function1ds
   object.def_property(
      "function1ds",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.function1ds();
      },
      [](cppCLASS &self, const general::Function1ds &value)
      {
         self.function1ds() = value;
      },
      cppCLASS::component_t::documentation("function1ds").data()
   );

   // get/set uncertainty
   object.def_property(
      "uncertainty",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.uncertainty();
      },
      [](cppCLASS &self, const std::optional<general::Uncertainty> &value)
      {
         self.uncertainty() = value;
      },
      cppCLASS::component_t::documentation("uncertainty").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
