
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "gnds/v2.0/general/Summand.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Summand
void wrapSummand(py::module &module)
{
   using namespace gnds;
   using namespace gnds::v2_0;

   // type aliases
   using cppCLASS = general::Summand;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Summand",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<std::string> &,
         const std::optional<std::string> &,
         const std::optional<std::string> &
      >(),
      py::arg("endf_mfmt") = std::nullopt,
      py::arg("coefficient") = std::nullopt,
      py::arg("href") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set ENDF_MFMT
   object.def_property(
      "endf_mfmt",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.ENDF_MFMT();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.ENDF_MFMT() = value;
      },
      cppCLASS::component_t::documentation("endf_mfmt").data()
   );

   // get/set coefficient
   object.def_property(
      "coefficient",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.coefficient();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.coefficient() = value;
      },
      cppCLASS::component_t::documentation("coefficient").data()
   );

   // get/set href
   object.def_property(
      "href",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.href();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.href() = value;
      },
      cppCLASS::component_t::documentation("href").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
