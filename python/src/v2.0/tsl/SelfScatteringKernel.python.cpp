
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/tsl/SelfScatteringKernel.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_tsl {

// SelfScatteringKernel wrapper
void wrapSelfScatteringKernel(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = tsl::SelfScatteringKernel;
   using _t = std::variant<
      containers::Gridded3d,
      tsl::SelfScatteringKernelGaussianApproximation
   >;

   // create the component
   python::class_<Component> component(
      module,
      "SelfScatteringKernel",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<bool> &,
            const std::optional<tsl::SelfScatteringKernelSCTApproximation> &,
            const _t &
         >(),
         python::arg("symmetric") = std::nullopt,
         python::arg("self_scattering_kernel_sctapproximation") = std::nullopt,
         python::arg("_gridded3dself_scattering_kernel_gaussian_approximation"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "symmetric",
         &Component::symmetric,
         Component::documentation("symmetric").data()
      )
      .def_property_readonly(
         "self_scattering_kernel_sctapproximation",
         python::overload_cast<>(&Component::selfScatteringKernelSCTApproximation),
         Component::documentation("self_scattering_kernel_sctapproximation").data()
      )
      .def_property_readonly(
         "gridded3d",
         python::overload_cast<>(&Component::gridded3d),
         Component::documentation("gridded3d").data()
      )
      .def_property_readonly(
         "self_scattering_kernel_gaussian_approximation",
         python::overload_cast<>(&Component::selfScatteringKernelGaussianApproximation),
         Component::documentation("self_scattering_kernel_gaussian_approximation").data()
      )
      .def_property_readonly(
         "_gridded3dself_scattering_kernel_gaussian_approximation",
         python::overload_cast<>(&Component::_gridded3dselfScatteringKernelGaussianApproximation),
         Component::documentation("_gridded3dself_scattering_kernel_gaussian_approximation").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_tsl
} // namespace python_v2_0
