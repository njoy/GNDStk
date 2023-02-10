
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/ExternalFile.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::ExternalFile
void wrapExternalFile(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::ExternalFile;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "ExternalFile",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::string &,
         const std::optional<std::string> &,
         const std::optional<std::string> &
      >(),
      py::arg("label"),
      py::arg("path"),
      py::arg("checksum") = std::nullopt,
      py::arg("algorithm") = std::nullopt,
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

   // get/set path
   object.def_property(
      "path",
      [](const cppCLASS &self)
      {
         return self.path();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.path() = value;
      },
      cppCLASS::component_t::documentation("path").data()
   );

   // get/set checksum
   object.def_property(
      "checksum",
      [](const cppCLASS &self)
      {
         return self.checksum();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.checksum() = value;
      },
      cppCLASS::component_t::documentation("checksum").data()
   );

   // get/set algorithm
   object.def_property(
      "algorithm",
      [](const cppCLASS &self)
      {
         return self.algorithm();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.algorithm() = value;
      },
      cppCLASS::component_t::documentation("algorithm").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
