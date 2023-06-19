
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/NBodyPhaseSpace.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_transport {

// wrapper for transport::NBodyPhaseSpace
void wrapNBodyPhaseSpace(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = transport::NBodyPhaseSpace;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "NBodyPhaseSpace",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<Integer32> &,
         const std::optional<tsl::Mass> &
      >(),
      py::arg("number_of_products") = std::nullopt,
      py::arg("mass") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set numberOfProducts
   object.def_property(
      "number_of_products",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.numberOfProducts();
      },
      [](cppCLASS &self, const std::optional<Integer32> &value)
      {
         self.numberOfProducts() = value;
      },
      cppCLASS::component_t::documentation("number_of_products").data()
   );

   // get/set mass
   object.def_property(
      "mass",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.mass();
      },
      [](cppCLASS &self, const std::optional<tsl::Mass> &value)
      {
         self.mass() = value;
      },
      cppCLASS::component_t::documentation("mass").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_transport
} // namespace python_v2_0
