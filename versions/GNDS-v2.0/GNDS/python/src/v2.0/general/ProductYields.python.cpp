
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/ProductYields.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::ProductYields
void wrapProductYields(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::ProductYields;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "ProductYields",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::vector<general::ProductYield> &
      >(),
      pybind11::arg("product_yield"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set productYield
   object.def_property(
      "product_yield",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.productYield();
      },
      [](cppCLASS &self, const std::vector<general::ProductYield> &value)
      {
         self.productYield() = value;
      },
      cppCLASS::component_t::documentation("product_yield").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS