
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "try/v2.0/tsl/GaussianApproximation.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_tsl {

// GaussianApproximation wrapper
void wrapGaussianApproximation(python::module &module)
{
   using namespace try;
   using namespace try::v2_0;

   // type aliases
   using Component = tsl::GaussianApproximation;

   // create the component
   python::class_<Component> component(
      module,
      "GaussianApproximation",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<tsl::PhononSpectrum> &
         >(),
         python::arg("phonon_spectrum") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "phonon_spectrum",
         [](const Component &self) { return self.phononSpectrum(); },
         Component::documentation("phonon_spectrum").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_tsl
} // namespace python_v2_0