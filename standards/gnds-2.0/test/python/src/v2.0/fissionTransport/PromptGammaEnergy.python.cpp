
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/fissionTransport/PromptGammaEnergy.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_fissionTransport {

// wrapper for fissionTransport::PromptGammaEnergy
void wrapPromptGammaEnergy(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = fissionTransport::PromptGammaEnergy;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "PromptGammaEnergy",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<containers::XYs1d> &,
         const std::optional<containers::Polynomial1d> &
      >(),
      py::arg("xys1d") = std::nullopt,
      py::arg("polynomial1d") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set XYs1d
   object.def_property(
      "xys1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.XYs1d();
      },
      [](cppCLASS &self, const std::optional<containers::XYs1d> &value)
      {
         self.XYs1d() = value;
      },
      cppCLASS::component_t::documentation("xys1d").data()
   );

   // get/set polynomial1d
   object.def_property(
      "polynomial1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.polynomial1d();
      },
      [](cppCLASS &self, const std::optional<containers::Polynomial1d> &value)
      {
         self.polynomial1d() = value;
      },
      cppCLASS::component_t::documentation("polynomial1d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_fissionTransport
} // namespace python_v2_0
