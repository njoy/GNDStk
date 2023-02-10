
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Reaction.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Reaction
void wrapReaction(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Reaction;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Reaction",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const int &,
         const std::optional<std::string> &,
         const general::CrossSection &,
         const general::OutputChannel &,
         const std::optional<general::DoubleDifferentialCrossSection> &
      >(),
      py::arg("label"),
      py::arg("endf_mt"),
      py::arg("fission_genre") = std::nullopt,
      py::arg("cross_section"),
      py::arg("output_channel"),
      py::arg("double_differential_cross_section") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set ENDF_MT
   object.def_property(
      "endf_mt",
      [](const cppCLASS &self)
      {
         return self.ENDF_MT();
      },
      [](cppCLASS &self, const int &value)
      {
         self.ENDF_MT() = value;
      },
      cppCLASS::component_t::documentation("endf_mt").data()
   );

   // get/set fissionGenre
   object.def_property(
      "fission_genre",
      [](const cppCLASS &self)
      {
         return self.fissionGenre();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.fissionGenre() = value;
      },
      cppCLASS::component_t::documentation("fission_genre").data()
   );

   // get/set crossSection
   object.def_property(
      "cross_section",
      [](const cppCLASS &self)
      {
         return self.crossSection();
      },
      [](cppCLASS &self, const general::CrossSection &value)
      {
         self.crossSection() = value;
      },
      cppCLASS::component_t::documentation("cross_section").data()
   );

   // get/set outputChannel
   object.def_property(
      "output_channel",
      [](const cppCLASS &self)
      {
         return self.outputChannel();
      },
      [](cppCLASS &self, const general::OutputChannel &value)
      {
         self.outputChannel() = value;
      },
      cppCLASS::component_t::documentation("output_channel").data()
   );

   // get/set doubleDifferentialCrossSection
   object.def_property(
      "double_differential_cross_section",
      [](const cppCLASS &self)
      {
         return self.doubleDifferentialCrossSection();
      },
      [](cppCLASS &self, const std::optional<general::DoubleDifferentialCrossSection> &value)
      {
         self.doubleDifferentialCrossSection() = value;
      },
      cppCLASS::component_t::documentation("double_differential_cross_section").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
