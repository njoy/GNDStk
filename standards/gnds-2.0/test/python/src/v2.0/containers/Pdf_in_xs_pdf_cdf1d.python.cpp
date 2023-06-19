
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/containers/Pdf_in_xs_pdf_cdf1d.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_containers {

// wrapper for containers::Pdf_in_xs_pdf_cdf1d
void wrapPdf_in_xs_pdf_cdf1d(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = containers::Pdf_in_xs_pdf_cdf1d;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Pdf_in_xs_pdf_cdf1d",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const containers::Values &
      >(),
      py::arg("values"),
      cppCLASS::component_t::documentation("constructor").data()
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
