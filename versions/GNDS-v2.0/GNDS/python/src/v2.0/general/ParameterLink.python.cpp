
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/ParameterLink.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::ParameterLink
void wrapParameterLink(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::ParameterLink;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "ParameterLink",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::string &,
         const std::string &,
         const std::optional<int> &,
         const std::optional<int> &
      >(),
      pybind11::arg("label"),
      pybind11::arg("href"),
      pybind11::arg("n_parameters") = std::nullopt,
      pybind11::arg("matrix_start_index") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
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

   // get/set href
   object.def_property(
      "href",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.href();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.href() = value;
      },
      cppCLASS::component_t::documentation("href").data()
   );

   // get/set nParameters
   object.def_property(
      "n_parameters",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.nParameters();
      },
      [](cppCLASS &self, const std::optional<int> &value)
      {
         self.nParameters() = value;
      },
      cppCLASS::component_t::documentation("n_parameters").data()
   );

   // get/set matrixStartIndex
   object.def_property(
      "matrix_start_index",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.matrixStartIndex();
      },
      [](cppCLASS &self, const std::optional<int> &value)
      {
         self.matrixStartIndex() = value;
      },
      cppCLASS::component_t::documentation("matrix_start_index").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
