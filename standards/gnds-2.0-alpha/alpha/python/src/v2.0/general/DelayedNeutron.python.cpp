
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/DelayedNeutron.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::DelayedNeutron
void wrapDelayedNeutron(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::DelayedNeutron;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "DelayedNeutron",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const general::Rate &,
         const reduced::Product &
      >(),
      py::arg("label"),
      py::arg("rate"),
      py::arg("product"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self)
      {
         return self.label();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set rate
   object.def_property(
      "rate",
      [](const cppCLASS &self)
      {
         return self.rate();
      },
      [](cppCLASS &self, const general::Rate &value)
      {
         self.rate() = value;
      },
      cppCLASS::component_t::documentation("rate").data()
   );

   // get/set product
   object.def_property(
      "product",
      [](const cppCLASS &self)
      {
         return self.product();
      },
      [](cppCLASS &self, const reduced::Product &value)
      {
         self.product() = value;
      },
      cppCLASS::component_t::documentation("product").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
