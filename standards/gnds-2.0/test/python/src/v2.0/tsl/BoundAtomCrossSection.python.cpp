
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/tsl/BoundAtomCrossSection.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_tsl {

// wrapper for tsl::BoundAtomCrossSection
void wrapBoundAtomCrossSection(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = tsl::BoundAtomCrossSection;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "BoundAtomCrossSection",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const XMLName &,
         const Float64 &
      >(),
      py::arg("unit"),
      py::arg("value"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set unit
   object.def_property(
      "unit",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.unit();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.unit() = value;
      },
      cppCLASS::component_t::documentation("unit").data()
   );

   // get/set value
   object.def_property(
      "value",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.value();
      },
      [](cppCLASS &self, const Float64 &value)
      {
         self.value() = value;
      },
      cppCLASS::component_t::documentation("value").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_tsl
} // namespace python_v2_0
