
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Slice.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Slice
void wrapSlice(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Slice;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "Slice",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const int &,
         const std::optional<int> &,
         const std::optional<double> &,
         const std::optional<double> &,
         const std::optional<std::string> &
      >(),
      pybind11::arg("dimension"),
      pybind11::arg("domain_value") = std::nullopt,
      pybind11::arg("domain_min") = std::nullopt,
      pybind11::arg("domain_max") = std::nullopt,
      pybind11::arg("domain_unit") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set dimension
   object.def_property(
      "dimension",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.dimension();
      },
      [](cppCLASS &self, const int &value)
      {
         self.dimension() = value;
      },
      cppCLASS::component_t::documentation("dimension").data()
   );

   // get/set domainValue
   object.def_property(
      "domain_value",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.domainValue();
      },
      [](cppCLASS &self, const std::optional<int> &value)
      {
         self.domainValue() = value;
      },
      cppCLASS::component_t::documentation("domain_value").data()
   );

   // get/set domainMin
   object.def_property(
      "domain_min",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.domainMin();
      },
      [](cppCLASS &self, const std::optional<double> &value)
      {
         self.domainMin() = value;
      },
      cppCLASS::component_t::documentation("domain_min").data()
   );

   // get/set domainMax
   object.def_property(
      "domain_max",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.domainMax();
      },
      [](cppCLASS &self, const std::optional<double> &value)
      {
         self.domainMax() = value;
      },
      cppCLASS::component_t::documentation("domain_max").data()
   );

   // get/set domainUnit
   object.def_property(
      "domain_unit",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.domainUnit();
      },
      [](cppCLASS &self, const std::optional<std::string> &value)
      {
         self.domainUnit() = value;
      },
      cppCLASS::component_t::documentation("domain_unit").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
