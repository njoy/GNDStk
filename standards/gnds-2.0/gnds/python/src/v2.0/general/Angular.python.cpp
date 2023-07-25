
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "gnds/v2.0/general/Angular.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Angular
void wrapAngular(py::module &module)
{
   using namespace gnds;
   using namespace gnds::v2_0;

   // type aliases
   using cppCLASS = general::Angular;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Angular",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<general::Isotropic2d> &,
         const std::optional<general::XYs2d> &
      >(),
      py::arg("isotropic2d") = std::nullopt,
      py::arg("xys2d") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set isotropic2d
   object.def_property(
      "isotropic2d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.isotropic2d();
      },
      [](cppCLASS &self, const std::optional<general::Isotropic2d> &value)
      {
         self.isotropic2d() = value;
      },
      cppCLASS::component_t::documentation("isotropic2d").data()
   );

   // get/set XYs2d
   object.def_property(
      "xys2d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.XYs2d();
      },
      [](cppCLASS &self, const std::optional<general::XYs2d> &value)
      {
         self.XYs2d() = value;
      },
      cppCLASS::component_t::documentation("xys2d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
