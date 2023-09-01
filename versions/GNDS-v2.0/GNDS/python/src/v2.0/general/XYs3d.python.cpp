
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/XYs3d.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::XYs3d
void wrapXYs3d(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::XYs3d;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "XYs3d",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::optional<std::string> &,
         const std::optional<general::Axes> &,
         const std::vector<general::Function2ds> &
      >(),
      pybind11::arg("interpolation_qualifier") = std::nullopt,
      pybind11::arg("axes") = std::nullopt,
      pybind11::arg("function2ds"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set interpolationQualifier
   object.def_property(
      "interpolation_qualifier",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.interpolationQualifier();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.interpolationQualifier() = value;
      },
      cppCLASS::component_t::documentation("interpolation_qualifier").data()
   );

   // get/set axes
   object.def_property(
      "axes",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.axes();
      },
      [](cppCLASS &self, const std::optional<general::Axes> &value)
      {
         self.axes() = value;
      },
      cppCLASS::component_t::documentation("axes").data()
   );

   // get/set function2ds
   object.def_property(
      "function2ds",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.function2ds();
      },
      [](cppCLASS &self, const std::vector<general::Function2ds> &value)
      {
         self.function2ds() = value;
      },
      cppCLASS::component_t::documentation("function2ds").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
