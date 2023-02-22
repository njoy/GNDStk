
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/MadlandNix.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_general {

// wrapper for general::MadlandNix
void wrapMadlandNix(py::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using cppCLASS = general::MadlandNix;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "MadlandNix",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const general::EFL &,
         const general::EFH &,
         const general::T_M &
      >(),
      py::arg("efl"),
      py::arg("efh"),
      py::arg("t_m"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set EFL
   object.def_property(
      "efl",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.EFL();
      },
      [](cppCLASS &self, const general::EFL &value)
      {
         self.EFL() = value;
      },
      cppCLASS::component_t::documentation("efl").data()
   );

   // get/set EFH
   object.def_property(
      "efh",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.EFH();
      },
      [](cppCLASS &self, const general::EFH &value)
      {
         self.EFH() = value;
      },
      cppCLASS::component_t::documentation("efh").data()
   );

   // get/set T_M
   object.def_property(
      "t_m",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.T_M();
      },
      [](cppCLASS &self, const general::T_M &value)
      {
         self.T_M() = value;
      },
      cppCLASS::component_t::documentation("t_m").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0