
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/RealInterferenceTerm.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::RealInterferenceTerm
void wrapRealInterferenceTerm(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::RealInterferenceTerm;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "RealInterferenceTerm",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<general::Regions2d> &,
         const std::optional<general::XYs2d> &
      >(),
      py::arg("regions2d") = std::nullopt,
      py::arg("xys2d") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set regions2d
   object.def_property(
      "regions2d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.regions2d();
      },
      [](cppCLASS &self, const std::optional<general::Regions2d> &value)
      {
         self.regions2d() = value;
      },
      cppCLASS::component_t::documentation("regions2d").data()
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
