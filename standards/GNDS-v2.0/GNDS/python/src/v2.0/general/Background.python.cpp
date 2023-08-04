
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Background.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Background
void wrapBackground(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Background;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Background",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<general::ResolvedRegion> &,
         const general::FastRegion &,
         const std::optional<general::UnresolvedRegion> &
      >(),
      py::arg("resolved_region") = std::nullopt,
      py::arg("fast_region"),
      py::arg("unresolved_region") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set resolvedRegion
   object.def_property(
      "resolved_region",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.resolvedRegion();
      },
      [](cppCLASS &self, const std::optional<general::ResolvedRegion> &value)
      {
         self.resolvedRegion() = value;
      },
      cppCLASS::component_t::documentation("resolved_region").data()
   );

   // get/set fastRegion
   object.def_property(
      "fast_region",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.fastRegion();
      },
      [](cppCLASS &self, const general::FastRegion &value)
      {
         self.fastRegion() = value;
      },
      cppCLASS::component_t::documentation("fast_region").data()
   );

   // get/set unresolvedRegion
   object.def_property(
      "unresolved_region",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.unresolvedRegion();
      },
      [](cppCLASS &self, const std::optional<general::UnresolvedRegion> &value)
      {
         self.unresolvedRegion() = value;
      },
      cppCLASS::component_t::documentation("unresolved_region").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0