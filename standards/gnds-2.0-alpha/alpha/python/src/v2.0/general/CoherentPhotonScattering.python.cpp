
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/CoherentPhotonScattering.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::CoherentPhotonScattering
void wrapCoherentPhotonScattering(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::CoherentPhotonScattering;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "CoherentPhotonScattering",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::optional<std::string> &,
         const std::optional<std::string> &,
         const std::optional<std::string> &,
         const std::optional<general::FormFactor> &,
         const std::optional<general::RealAnomalousFactor> &,
         const std::optional<general::ImaginaryAnomalousFactor> &
      >(),
      py::arg("label"),
      py::arg("href") = std::nullopt,
      py::arg("pid") = std::nullopt,
      py::arg("product_frame") = std::nullopt,
      py::arg("form_factor") = std::nullopt,
      py::arg("real_anomalous_factor") = std::nullopt,
      py::arg("imaginary_anomalous_factor") = std::nullopt,
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

   // get/set href
   object.def_property(
      "href",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.href();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.href() = value;
      },
      cppCLASS::component_t::documentation("href").data()
   );

   // get/set pid
   object.def_property(
      "pid",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.pid();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.pid() = value;
      },
      cppCLASS::component_t::documentation("pid").data()
   );

   // get/set productFrame
   object.def_property(
      "product_frame",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.productFrame();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.productFrame() = value;
      },
      cppCLASS::component_t::documentation("product_frame").data()
   );

   // get/set formFactor
   object.def_property(
      "form_factor",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.formFactor();
      },
      [](cppCLASS &self, const std::optional<general::FormFactor> &value)
      {
         self.formFactor() = value;
      },
      cppCLASS::component_t::documentation("form_factor").data()
   );

   // get/set realAnomalousFactor
   object.def_property(
      "real_anomalous_factor",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.realAnomalousFactor();
      },
      [](cppCLASS &self, const std::optional<general::RealAnomalousFactor> &value)
      {
         self.realAnomalousFactor() = value;
      },
      cppCLASS::component_t::documentation("real_anomalous_factor").data()
   );

   // get/set imaginaryAnomalousFactor
   object.def_property(
      "imaginary_anomalous_factor",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.imaginaryAnomalousFactor();
      },
      [](cppCLASS &self, const std::optional<general::ImaginaryAnomalousFactor> &value)
      {
         self.imaginaryAnomalousFactor() = value;
      },
      cppCLASS::component_t::documentation("imaginary_anomalous_factor").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
