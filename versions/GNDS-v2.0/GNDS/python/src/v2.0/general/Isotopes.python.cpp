
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Isotopes.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Isotopes
void wrapIsotopes(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Isotopes;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "Isotopes",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::vector<general::Isotope> &
      >(),
      pybind11::arg("isotope"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set isotope
   object.def_property(
      "isotope",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.isotope();
      },
      [](cppCLASS &self, const std::vector<general::Isotope> &value)
      {
         self.isotope() = value;
      },
      cppCLASS::component_t::documentation("isotope").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
