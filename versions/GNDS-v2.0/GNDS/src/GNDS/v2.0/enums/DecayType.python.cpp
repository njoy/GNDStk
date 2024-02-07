
// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"
#include "GNDS/v2.0.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_enums {

void wrapDecayType( pybind11::module& module ) {

  // type aliases
  using Component = GNDS::v2_0::enums::DecayType;

  // wrap views created by this component

  // create the component
  pybind11::enum_< Component > component(

    module,
    "DecayType",
    "Enumeration class giving acceptable decay type values",
    pybind11::arithmetic()
  );

  // wrap the component
  component
  .value( "SF", Component::SpontaneousFission )
  .value( "beta-", Component::BetaMinus )
  .value( "beta+", Component::BetaPlus )
  .value( "EC", Component::ElectronCapture )
  .value( "electroMagnetic", Component::ElectroMagnetic )
  .value( "IT", Component::IsomericTransition )
  .value( "n", Component::Neutron )
  .value( "p", Component::Proton )
  .value( "d", Component::Deuteron )
  .value( "t", Component::Triton )
  .value( "alpha", Component::Alpha )
  .value( "atomicRelaxation", Component::AtomicRelaxation );
}

} // namespace python_enums
} // namespace python_v2_0
} // namespace python_GNDS
