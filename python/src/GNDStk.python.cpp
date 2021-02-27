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

/**
 *  @brief GNDStk python bindings
 *
 *  The name given here (GNDStk) must be the same as the name
 *  set on the PROPERTIES OUTPUT_NAME in the CMakeLists.txt file.
 */
PYBIND11_MODULE( GNDStk, module ) {

  // create the core submodule
  python::module submodule = module.def_submodule(

    "core",
    "core - GNDS core interface components"
  );

  // wrap core components
  core::wrapNode( submodule );
}
