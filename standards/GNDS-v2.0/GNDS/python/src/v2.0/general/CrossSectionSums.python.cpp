
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/CrossSectionSums.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::CrossSectionSums
void wrapCrossSectionSums(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::CrossSectionSums;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "CrossSectionSums",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::CrossSectionSum> &
      >(),
      py::arg("cross_section_sum"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set crossSectionSum
   object.def_property(
      "cross_section_sum",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.crossSectionSum();
      },
      [](cppCLASS &self, const std::vector<general::CrossSectionSum> &value)
      {
         self.crossSectionSum() = value;
      },
      cppCLASS::component_t::documentation("cross_section_sum").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
