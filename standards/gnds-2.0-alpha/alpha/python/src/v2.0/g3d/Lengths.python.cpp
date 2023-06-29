
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/g3d/Lengths.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_g3d {

// wrapper for g3d::Lengths
void wrapLengths(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = g3d::Lengths;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Lengths",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const std::string &
      >(),
      py::arg("value_type"),
      py::arg("label"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // constructor: from vector
   object.def(
      py::init<
         const std::vector<int> &
      >(),
      py::arg("ints"),
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
