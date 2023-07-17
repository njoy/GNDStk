
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/OrphanProducts.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::OrphanProducts
void wrapOrphanProducts(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::OrphanProducts;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "OrphanProducts",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::OrphanProduct> &
      >(),
      py::arg("orphan_product"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set orphanProduct
   object.def_property(
      "orphan_product",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.orphanProduct();
      },
      [](cppCLASS &self, const std::vector<general::OrphanProduct> &value)
      {
         self.orphanProduct() = value;
      },
      cppCLASS::component_t::documentation("orphan_product").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
