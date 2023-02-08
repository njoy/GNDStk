
// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// namespace aliases
namespace python = pybind11;

// v2.0 interface declarations
namespace python_v2_0 {
   void wrapG2d( python::module& );
   void wrapG3d( python::module& );
   void wrapGeneral( python::module& );
   void wrapReduced( python::module& );
   void wrapTop( python::module& );

   void wrapGNDS( python::module& module ) {
      // create the core submodule
      python::module submodule = module.def_submodule(
         "v2_0",
         "GNDS 2.0 standard components"
      );
      python_v2_0::wrapG2d( submodule );
      python_v2_0::wrapG3d( submodule );
      python_v2_0::wrapGeneral( submodule );
      python_v2_0::wrapReduced( submodule );
      python_v2_0::wrapTop( submodule );
   }
} // v2_0 namespace
