
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace python = pybind11;

// v2.0 interface
namespace python_v2_0 {

// processed declarations
namespace python_processed {
   void wrapAngularEnergyMC(python::module &);
   void wrapEnergyAngularMC(python::module &);
   void wrapMultiGroup3d(python::module &);
   void wrapAverageProductEnergy(python::module &);
   void wrapAverageProductMomentum(python::module &);
   void wrapAvailableMomentum(python::module &);
   void wrapAvailableEnergy(python::module &);
} // namespace python_processed

// processed wrapper
void wrapProcessed(python::module &module)
{
   // create the processed submodule
   python::module submodule = module.def_submodule(
      "processed",
      "test v2.0 processed"
   );

   // wrap processed components
   python_processed::wrapAngularEnergyMC(submodule);
   python_processed::wrapEnergyAngularMC(submodule);
   python_processed::wrapMultiGroup3d(submodule);
   python_processed::wrapAverageProductEnergy(submodule);
   python_processed::wrapAverageProductMomentum(submodule);
   python_processed::wrapAvailableMomentum(submodule);
   python_processed::wrapAvailableEnergy(submodule);
};

} // namespace python_v2_0
