
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/reduced/Products.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_reduced {

// wrapper for reduced::Products
void wrapProducts(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = reduced::Products;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Products",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<reduced::Product> &
      >(),
      py::arg("product"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set product
   object.def_property(
      "product",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.product();
      },
      [](cppCLASS &self, const std::vector<reduced::Product> &value)
      {
         self.product() = value;
      },
      cppCLASS::component_t::documentation("product").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_reduced
} // namespace python_v2_0
