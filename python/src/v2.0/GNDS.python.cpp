// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// other includes

// namespace aliases
namespace python = pybind11;

// v2.0 interface declarations
namespace python_v2_0 {

  void wrapContainers( python::module& );
  void wrapFpy( python::module& );
  void wrapFissionFragmentData( python::module& );
  void wrapPops( python::module& );
  void wrapResonances( python::module& );
}

namespace python_v2_0 {

  void wrapGNDS( python::module& module ) {

    // create the core submodule
    python::module submodule = module.def_submodule(

      "v2_0",
      "GNDS 2.0 standard components"
    );

    python_v2_0::wrapContainers( submodule );
    python_v2_0::wrapFpy( submodule );
    python_v2_0::wrapFissionFragmentData( submodule );
    python_v2_0::wrapPops( submodule );
    python_v2_0::wrapResonances( submodule );
  }
} // v2_0 namespace
