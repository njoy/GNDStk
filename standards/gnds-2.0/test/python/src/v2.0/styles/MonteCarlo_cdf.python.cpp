
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/styles/MonteCarlo_cdf.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_styles {

// wrapper for styles::MonteCarlo_cdf
void wrapMonteCarlo_cdf(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = styles::MonteCarlo_cdf;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "MonteCarlo_cdf",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const XMLName &,
         const XMLName &,
         const std::optional<documentation::Documentation> &
      >(),
      py::arg("date"),
      py::arg("derived_from"),
      py::arg("label"),
      py::arg("documentation") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
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

   // get/set derivedFrom
   object.def_property(
      "derived_from",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.derivedFrom();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.derivedFrom() = value;
      },
      cppCLASS::component_t::documentation("derived_from").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set documentation
   object.def_property(
      "documentation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.documentation();
      },
      [](cppCLASS &self, const std::optional<documentation::Documentation> &value)
      {
         self.documentation() = value;
      },
      cppCLASS::component_t::documentation("documentation").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_styles
} // namespace python_v2_0
