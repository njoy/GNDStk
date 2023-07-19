
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/CrossSectionSum.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_transport {

// wrapper for transport::CrossSectionSum
void wrapCrossSectionSum(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = transport::CrossSectionSum;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "CrossSectionSum",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<Integer32> &,
         const XMLName &,
         const common::Q &,
         const transport::CrossSection &,
         const transport::Summands &
      >(),
      py::arg("endf_mt") = std::nullopt,
      py::arg("label"),
      py::arg("q"),
      py::arg("cross_section"),
      py::arg("summands"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set ENDF_MT
   object.def_property(
      "endf_mt",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.ENDF_MT();
      },
      [](cppCLASS &self, const std::optional<Integer32> &value)
      {
         self.ENDF_MT() = value;
      },
      cppCLASS::component_t::documentation("endf_mt").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set Q
   object.def_property(
      "q",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.Q();
      },
      [](cppCLASS &self, const common::Q &value)
      {
         self.Q() = value;
      },
      cppCLASS::component_t::documentation("q").data()
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

   // get/set summands
   object.def_property(
      "summands",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.summands();
      },
      [](cppCLASS &self, const transport::Summands &value)
      {
         self.summands() = value;
      },
      cppCLASS::component_t::documentation("summands").data()
   );

   // shortcut: get/set add
   object.def_property(
      "add",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.add();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.add())> &value)
      {
         self.add() = value;
      },
      cppCLASS::component_t::documentation("add").data()
   );

   // shortcut: get/set documentation
   object.def_property(
      "documentation",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.documentation();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.documentation())> &value)
      {
         self.documentation() = value;
      },
      cppCLASS::component_t::documentation("documentation").data()
   );

   // shortcut: get/set uncertainty
   object.def_property(
      "uncertainty",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.uncertainty();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.uncertainty())> &value)
      {
         self.uncertainty() = value;
      },
      cppCLASS::component_t::documentation("uncertainty").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_transport
} // namespace python_v2_0
