
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/containers/Xs_pdf_cdf1d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_containers {

// wrapper for containers::Xs_pdf_cdf1d
void wrapXs_pdf_cdf1d(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = containers::Xs_pdf_cdf1d;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Xs_pdf_cdf1d",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<Float64> &,
         const containers::Xs_in_xs_pdf_cdf1d &,
         const containers::Pdf &,
         const containers::Cdf_in_xs_pdf_cdf1d &
      >(),
      py::arg("outer_domain_value") = std::nullopt,
      py::arg("xs_in_xs_pdf_cdf1d"),
      py::arg("pdf"),
      py::arg("cdf_in_xs_pdf_cdf1d"),
      cppCLASS::component_t::documentation("constructor").data()
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

   // get/set xs_in_xs_pdf_cdf1d
   object.def_property(
      "xs_in_xs_pdf_cdf1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.xs_in_xs_pdf_cdf1d();
      },
      [](cppCLASS &self, const containers::Xs_in_xs_pdf_cdf1d &value)
      {
         self.xs_in_xs_pdf_cdf1d() = value;
      },
      cppCLASS::component_t::documentation("xs_in_xs_pdf_cdf1d").data()
   );

   // get/set pdf
   object.def_property(
      "pdf",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.pdf();
      },
      [](cppCLASS &self, const containers::Pdf &value)
      {
         self.pdf() = value;
      },
      cppCLASS::component_t::documentation("pdf").data()
   );

   // get/set cdf_in_xs_pdf_cdf1d
   object.def_property(
      "cdf_in_xs_pdf_cdf1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.cdf_in_xs_pdf_cdf1d();
      },
      [](cppCLASS &self, const containers::Cdf_in_xs_pdf_cdf1d &value)
      {
         self.cdf_in_xs_pdf_cdf1d() = value;
      },
      cppCLASS::component_t::documentation("cdf_in_xs_pdf_cdf1d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_containers
} // namespace python_v2_0
