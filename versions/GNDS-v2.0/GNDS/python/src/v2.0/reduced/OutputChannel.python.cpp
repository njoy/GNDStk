
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/reduced/OutputChannel.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_reduced {

// wrapper for reduced::OutputChannel
void wrapOutputChannel(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = reduced::OutputChannel;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "OutputChannel",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::string &,
         const std::optional<std::string> &,
         const general::Q &,
         const std::optional<reduced::Products> &
      >(),
      pybind11::arg("genre"),
      pybind11::arg("process") = std::nullopt,
      pybind11::arg("q"),
      pybind11::arg("products") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set genre
   object.def_property(
      "genre",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.genre();
      },
      [](cppCLASS &self, const std::string &value)
      {
         self.genre() = value;
      },
      cppCLASS::component_t::documentation("genre").data()
   );

   // get/set process
   object.def_property(
      "process",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.process();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.process() = value;
      },
      cppCLASS::component_t::documentation("process").data()
   );

   // get/set Q
   object.def_property(
      "q",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.Q();
      },
      [](cppCLASS &self, const general::Q &value)
      {
         self.Q() = value;
      },
      cppCLASS::component_t::documentation("q").data()
   );

   // get/set products
   object.def_property(
      "products",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.products();
      },
      [](cppCLASS &self, const std::optional<reduced::Products> &value)
      {
         self.products() = value;
      },
      cppCLASS::component_t::documentation("products").data()
   );

   // shortcut: get/set Double
   object.def_property(
      "double",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.Double();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.Double())> &value)
      {
         self.Double() = value;
      },
      cppCLASS::component_t::documentation("double").data()
   );

   // shortcut: get/set constant1d
   object.def_property(
      "constant1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.constant1d();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.constant1d())> &value)
      {
         self.constant1d() = value;
      },
      cppCLASS::component_t::documentation("constant1d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_reduced
} // namespace python_v2_0
} // namespace python_GNDS
