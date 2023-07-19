
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/pops/Atomic.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_pops {

// wrapper for pops::Atomic
void wrapAtomic(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = pops::Atomic;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Atomic",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<pops::Configurations> &
      >(),
      py::arg("configurations") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set configurations
   object.def_property(
      "configurations",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.configurations();
      },
      [](cppCLASS &self, const std::optional<pops::Configurations> &value)
      {
         self.configurations() = value;
      },
      cppCLASS::component_t::documentation("configurations").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_pops
} // namespace python_v2_0
