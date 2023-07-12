
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Decay.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::Decay
void wrapDecay(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::Decay;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Decay",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const int &,
         const std::optional<std::string> &,
         const std::optional<bool> &,
         const std::optional<general::Products> &
      >(),
      py::arg("index"),
      py::arg("mode") = std::nullopt,
      py::arg("complete") = std::nullopt,
      py::arg("products") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set index
   object.def_property(
      "index",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.index();
      },
      [](cppCLASS &self, const int &value)
      {
         self.index() = value;
      },
      cppCLASS::component_t::documentation("index").data()
   );

   // get/set mode
   object.def_property(
      "mode",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.mode();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.mode() = value;
      },
      cppCLASS::component_t::documentation("mode").data()
   );

   // get/set complete
   object.def_property(
      "complete",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.complete();
      },
      [](cppCLASS &self, const std::optional<bool> &value)
      {
         self.complete() = value;
      },
      cppCLASS::component_t::documentation("complete").data()
   );

   // get/set products
   object.def_property(
      "products",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.products();
      },
      [](cppCLASS &self, const std::optional<general::Products> &value)
      {
         self.products() = value;
      },
      cppCLASS::component_t::documentation("products").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
