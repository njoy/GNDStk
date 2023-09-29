
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/CovarianceSections.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::CovarianceSections
void wrapCovarianceSections(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::CovarianceSections;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "CovarianceSections",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
         const std::vector<general::CovarianceSection> &
      >(),
      pybind11::arg("covariance_section"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set covarianceSection
   object.def_property(
      "covariance_section",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.covarianceSection();
      },
      [](cppCLASS &self, const std::vector<general::CovarianceSection> &value)
      {
         self.covarianceSection() = value;
      },
      cppCLASS::component_t::documentation("covariance_section").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
