
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Institution.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Institution
void wrapInstitution(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Institution;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Institution",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<std::string> &,
         const general::ENDFconversionFlags &
      >(),
      py::arg("label") = std::nullopt,
      py::arg("endfconversion_flags"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set ENDFconversionFlags
   object.def_property(
      "endfconversion_flags",
      [](const cppCLASS &self)
      {
         return self.ENDFconversionFlags();
      },
      [](cppCLASS &self, const general::ENDFconversionFlags &value)
      {
         self.ENDFconversionFlags() = value;
      },
      cppCLASS::component_t::documentation("endfconversion_flags").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
