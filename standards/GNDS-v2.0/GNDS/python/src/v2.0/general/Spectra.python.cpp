
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Spectra.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Spectra
void wrapSpectra(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Spectra;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Spectra",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::Spectrum> &
      >(),
      py::arg("spectrum"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set spectrum
   object.def_property(
      "spectrum",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.spectrum();
      },
      [](cppCLASS &self, const std::vector<general::Spectrum> &value)
      {
         self.spectrum() = value;
      },
      cppCLASS::component_t::documentation("spectrum").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0