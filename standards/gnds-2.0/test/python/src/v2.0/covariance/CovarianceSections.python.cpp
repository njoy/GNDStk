
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/covariance/CovarianceSections.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_covariance {

// CovarianceSections wrapper
void wrapCovarianceSections(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = covariance::CovarianceSections;

   // create the component
   python::class_<Component> component(
      module,
      "CovarianceSections",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::vector<covariance::CovarianceSection>> &
         >(),
         python::arg("covariance_section") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "covariance_section",
         [](const Component &self) { return self.covarianceSection(); },
         Component::documentation("covariance_section").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_covariance
} // namespace python_v2_0