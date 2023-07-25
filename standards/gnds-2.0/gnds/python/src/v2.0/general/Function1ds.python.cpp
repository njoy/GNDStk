
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "gnds/v2.0/general/Function1ds.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Function1ds
void wrapFunction1ds(py::module &module)
{
   using namespace gnds;
   using namespace gnds::v2_0;

   // type aliases
   using cppCLASS = general::Function1ds;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Function1ds",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::Legendre> &,
         const std::optional<std::vector<general::XYs1d>> &,
         const std::optional<std::vector<general::Regions1d>> &
      >(),
      py::arg("legendre"),
      py::arg("xys1d") = std::nullopt,
      py::arg("regions1d") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set Legendre
   object.def_property(
      "legendre",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.Legendre();
      },
      [](cppCLASS &self, const std::vector<general::Legendre> &value)
      {
         self.Legendre() = value;
      },
      cppCLASS::component_t::documentation("legendre").data()
   );

   // get/set XYs1d
   object.def_property(
      "xys1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.XYs1d();
      },
      [](cppCLASS &self, const std::optional<std::vector<general::XYs1d>> &value)
      {
         self.XYs1d() = value;
      },
      cppCLASS::component_t::documentation("xys1d").data()
   );

   // get/set regions1d
   object.def_property(
      "regions1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.regions1d();
      },
      [](cppCLASS &self, const std::optional<std::vector<general::Regions1d>> &value)
      {
         self.regions1d() = value;
      },
      cppCLASS::component_t::documentation("regions1d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
