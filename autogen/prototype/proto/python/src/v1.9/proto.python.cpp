// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// other includes

// namespace aliases
namespace python = pybind11;

// v1.9 interface declarations
namespace python_v1_9 {

  void wrapContainers( python::module& );
  void wrapTransport( python::module& );
}

namespace python_v1_9 {

  void wrapGNDS( python::module& module ) {

    // create the core submodule
    python::module submodule = module.def_submodule(

      "v1_9",
      "GNDS 1.9 standard components"
    );

    python_v1_9::wrapContainers( submodule );
    python_v1_9::wrapTransport( submodule );
  }
} // v1_9 namespace
