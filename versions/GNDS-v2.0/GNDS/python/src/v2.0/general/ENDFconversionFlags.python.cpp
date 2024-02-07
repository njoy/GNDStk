
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/ENDFconversionFlags.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::ENDFconversionFlags
void wrapENDFconversionFlags(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::ENDFconversionFlags;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "ENDFconversionFlags",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::optional<std::string> &,
         const std::optional<std::string> &,
         const std::vector<general::Conversion> &
      >(),
      pybind11::arg("flags") = std::nullopt,
      pybind11::arg("href") = std::nullopt,
      pybind11::arg("conversion"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set flags
   object.def_property(
      "flags",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.flags();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.flags() = value;
      },
      cppCLASS::component_t::documentation("flags").data()
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

   // get/set conversion
   object.def_property(
      "conversion",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.conversion();
      },
      [](cppCLASS &self, const std::vector<general::Conversion> &value)
      {
         self.conversion() = value;
      },
      cppCLASS::component_t::documentation("conversion").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
