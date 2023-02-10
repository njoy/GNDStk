
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/PromptProductKE.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::PromptProductKE
void wrapPromptProductKE(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::PromptProductKE;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "PromptProductKE",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<general::Polynomial1d> &,
         const std::optional<general::XYs1d> &
      >(),
      py::arg("polynomial1d") = std::nullopt,
      py::arg("xys1d") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set polynomial1d
   object.def_property(
      "polynomial1d",
      [](const cppCLASS &self)
      {
         return self.polynomial1d();
      },
      [](cppCLASS &self, const std::optional<general::Polynomial1d> &value)
      {
         self.polynomial1d() = value;
      },
      cppCLASS::component_t::documentation("polynomial1d").data()
   );

   // get/set XYs1d
   object.def_property(
      "xys1d",
      [](const cppCLASS &self)
      {
         return self.XYs1d();
      },
      [](cppCLASS &self, const std::optional<general::XYs1d> &value)
      {
         self.XYs1d() = value;
      },
      cppCLASS::component_t::documentation("xys1d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
