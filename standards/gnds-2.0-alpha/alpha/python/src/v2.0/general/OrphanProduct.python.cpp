
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/OrphanProduct.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::OrphanProduct
void wrapOrphanProduct(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::OrphanProduct;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "OrphanProduct",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::string &,
         const int &,
         const general::CrossSection &,
         const general::OutputChannel &
      >(),
      py::arg("label"),
      py::arg("endf_mt"),
      py::arg("cross_section"),
      py::arg("output_channel"),
      cppCLASS::component_t::documentation("constructor").data()
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

   // get/set ENDF_MT
   object.def_property(
      "endf_mt",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.ENDF_MT();
      },
      [](cppCLASS &self, const int &value)
      {
         self.ENDF_MT() = value;
      },
      cppCLASS::component_t::documentation("endf_mt").data()
   );

   // get/set crossSection
   object.def_property(
      "cross_section",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.crossSection();
      },
      [](cppCLASS &self, const general::CrossSection &value)
      {
         self.crossSection() = value;
      },
      cppCLASS::component_t::documentation("cross_section").data()
   );

   // get/set outputChannel
   object.def_property(
      "output_channel",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.outputChannel();
      },
      [](cppCLASS &self, const general::OutputChannel &value)
      {
         self.outputChannel() = value;
      },
      cppCLASS::component_t::documentation("output_channel").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0