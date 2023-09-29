
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "proto/v1.9/transport/Reaction.hpp"
#include "definitions.hpp"

namespace python_v1_9 {
namespace python_transport {

// wrapper for transport::Reaction
void wrapReaction(pybind11::module &module)
{
   using namespace proto;
   using namespace proto::v1_9;

   // type aliases
   using cppCLASS = transport::Reaction;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "Reaction",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const int &,
         const std::optional<std::string> &,
         const std::string &,
         const transport::CrossSection &
      >(),
      pybind11::arg("endf_mt"),
      pybind11::arg("fission_genre") = std::nullopt,
      pybind11::arg("label"),
      pybind11::arg("cross_section"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set ENDF_MT
   object.def_property(
      "endf_mt",
      [](const cppCLASS &self) -> decltype(auto)
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
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.fissionGenre();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.fissionGenre() = value;
      },
      cppCLASS::component_t::documentation("fission_genre").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set crossSection
   object.def_property(
      "cross_section",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.crossSection();
      },
      [](cppCLASS &self, const transport::CrossSection &value)
      {
         self.crossSection() = value;
      },
      cppCLASS::component_t::documentation("cross_section").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_transport
} // namespace python_v1_9
