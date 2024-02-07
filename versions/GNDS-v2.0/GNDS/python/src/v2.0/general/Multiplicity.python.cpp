
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Multiplicity.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Multiplicity
void wrapMultiplicity(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Multiplicity;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "Multiplicity",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::optional<general::Constant1d> &,
         const std::optional<general::XYs1d> &,
         const std::optional<general::Regions1d> &,
         const std::optional<general::Polynomial1d> &,
         const std::optional<general::Reference> &,
         const std::optional<general::Branching1d> &,
         const std::optional<general::Branching3d> &,
         const std::optional<general::Unspecified> &
      >(),
      pybind11::arg("constant1d") = std::nullopt,
      pybind11::arg("xys1d") = std::nullopt,
      pybind11::arg("regions1d") = std::nullopt,
      pybind11::arg("polynomial1d") = std::nullopt,
      pybind11::arg("reference") = std::nullopt,
      pybind11::arg("branching1d") = std::nullopt,
      pybind11::arg("branching3d") = std::nullopt,
      pybind11::arg("unspecified") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
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

   // get/set XYs1d
   object.def_property(
      "xys1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.XYs1d();
      },
      [](cppCLASS &self, const std::optional<general::XYs1d> &value)
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
      [](cppCLASS &self, const std::optional<general::Regions1d> &value)
      {
         self.regions1d() = value;
      },
      cppCLASS::component_t::documentation("regions1d").data()
   );

   // get/set polynomial1d
   object.def_property(
      "polynomial1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.polynomial1d();
      },
      [](cppCLASS &self, const std::optional<general::Polynomial1d> &value)
      {
         self.polynomial1d() = value;
      },
      cppCLASS::component_t::documentation("polynomial1d").data()
   );

   // get/set reference
   object.def_property(
      "reference",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.reference();
      },
      [](cppCLASS &self, const std::optional<general::Reference> &value)
      {
         self.reference() = value;
      },
      cppCLASS::component_t::documentation("reference").data()
   );

   // get/set branching1d
   object.def_property(
      "branching1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.branching1d();
      },
      [](cppCLASS &self, const std::optional<general::Branching1d> &value)
      {
         self.branching1d() = value;
      },
      cppCLASS::component_t::documentation("branching1d").data()
   );

   // get/set branching3d
   object.def_property(
      "branching3d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.branching3d();
      },
      [](cppCLASS &self, const std::optional<general::Branching3d> &value)
      {
         self.branching3d() = value;
      },
      cppCLASS::component_t::documentation("branching3d").data()
   );

   // get/set unspecified
   object.def_property(
      "unspecified",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.unspecified();
      },
      [](cppCLASS &self, const std::optional<general::Unspecified> &value)
      {
         self.unspecified() = value;
      },
      cppCLASS::component_t::documentation("unspecified").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
