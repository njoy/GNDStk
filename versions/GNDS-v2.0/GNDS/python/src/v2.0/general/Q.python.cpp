
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Q.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Q
void wrapQ(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Q;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "Q",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::optional<general::Double> &,
         const std::optional<general::Constant1d> &
      >(),
      pybind11::arg("double") = std::nullopt,
      pybind11::arg("constant1d") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set Double
   object.def_property(
      "double",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.Double();
      },
      [](cppCLASS &self, const std::optional<general::Double> &value)
      {
         self.Double() = value;
      },
      cppCLASS::component_t::documentation("double").data()
   );

   // get/set constant1d
   object.def_property(
      "constant1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.constant1d();
      },
      [](cppCLASS &self, const std::optional<general::Constant1d> &value)
      {
         self.constant1d() = value;
      },
      cppCLASS::component_t::documentation("constant1d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
