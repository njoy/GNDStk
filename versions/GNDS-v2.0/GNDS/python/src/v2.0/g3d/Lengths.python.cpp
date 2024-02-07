
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/g3d/Lengths.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_g3d {

// wrapper for g3d::Lengths
void wrapLengths(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = g3d::Lengths;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "Lengths",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::string &,
         const std::string &
      >(),
      pybind11::arg("value_type"),
      pybind11::arg("label"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // constructor: from vector
   object.def(
      pybind11::init<
         const std::vector<int> &
      >(),
      pybind11::arg("ints"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set valueType
   object.def_property(
      "value_type",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.valueType();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.valueType() = value;
      },
      cppCLASS::component_t::documentation("value_type").data()
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

   // get/set vector<int>
   object.def_property(
      "ints",
      [](const cppCLASS &self) -> const std::vector<int> &
      {
         return self;
      },
      [](cppCLASS &self, const std::vector<int> &value)
      {
         self = value;
      },
      cppCLASS::component_t::documentation("ints").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_g3d
} // namespace python_v2_0
} // namespace python_GNDS