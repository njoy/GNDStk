// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// other includes

// namespace aliases
namespace python = pybind11;

// core interface declarations
namespace core {

  void wrapNode( python::module& );
}

// v1.9 interface declarations
namespace v1_9 {

  void wrapGeneralPurposeDataContainers( python::module& );
}

/**
 *  @brief GNDStk python bindings
 *
 *  The name given here (GNDStk) must be the same as the name
 *  set on the PROPERTIES OUTPUT_NAME in the CMakeLists.txt file.
 */
PYBIND11_MODULE( GNDStk, module ) {

  // create the core submodule
  python::module coremodule = module.def_submodule(

    "core",
    "core - GNDS core interface components"
  );

  // wrap core components
  core::wrapNode( coremodule );

  // create the core submodule
  python::module v1_9_module = module.def_submodule(

    "v1_9",
    "v1.9 - GNDS v1.9 standard components"
  );

  // wrap GNDS v1.9 standard components
  v1_9::wrapGeneralPurposeDataContainers( v1_9_module );
}
