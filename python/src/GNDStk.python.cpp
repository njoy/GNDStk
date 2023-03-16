
// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"

// namespace aliases
namespace python = pybind11;

// core interface declarations
namespace core {
   void wrapNode( python::module& );

   void wrapContributorType( python::module& );
   void wrapDateType( python::module& );
   void wrapDecayType( python::module& );
   void wrapFrame( python::module& );
   void wrapGridStyle( python::module& );
   void wrapHashAlgorithm( python::module& );
   void wrapInteraction( python::module& );
   void wrapInterpolation( python::module& );
   void wrapInterpolationQualifier( python::module& );
   void wrapParity( python::module& );
   void wrapRelationType( python::module& );
   void wrapBoundaryCondition( python::module& );
}

// v2.0 interface declarations
namespace python_v2_0 {
   void wrapGNDS( python::module& );
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

   // wrap core components (in the core module)
   core::wrapNode( submodule );

   // enumerations (in the GNDStk module)
   core::wrapContributorType( module );
   core::wrapDateType( module );
   core::wrapDecayType( module );
   core::wrapFrame( module );
   core::wrapGridStyle( module );
   core::wrapHashAlgorithm( module );
   core::wrapInteraction( module );
   core::wrapInterpolation( module );
   core::wrapInterpolationQualifier( module );
   core::wrapParity( module );
   core::wrapRelationType( module );
   core::wrapBoundaryCondition( module );

   // v2.0 components (in the v2_0 module, created in this function)
   python_v2_0::wrapGNDS( module );

   // ------------------------
   // general settings
   // ------------------------

   struct settings { };
   python::class_<settings> obj(module,"settings");

   // get/set colors
   obj.def_property_static(
      "colors",
      [](python::object)
      {
         return njoy::GNDStk::colors;
      },
      [](python::object, const bool &value)
      {
         njoy::GNDStk::colors = value;
      }
   );

   // get/set shades
   obj.def_property_static(
      "shades",
      [](python::object)
      {
         return njoy::GNDStk::shades;
      },
      [](python::object, const bool &value)
      {
         njoy::GNDStk::shades = value;
      }
   );

   // zzz Martin: put lots more here, after figuring out what they should be
}
