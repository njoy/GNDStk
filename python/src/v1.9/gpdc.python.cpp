// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// other includes

// namespace aliases
namespace python = pybind11;

// v1.9 interface declarations
namespace v1_9 {

// gpdc declarations
namespace gpdc {

  void wrapAxis( python::module& );
}

void wrapGeneralPurposeDataContainers( python::module& module ) {

  // create the gpdc submodule
  python::module submodule = module.def_submodule(

    "gpdc",
    "v1.9 gpdc - GNDS general purpose data containers"
  );

  // wrap core components
  gpdc::wrapAxis( submodule );
}

} // v1_9 namespace
