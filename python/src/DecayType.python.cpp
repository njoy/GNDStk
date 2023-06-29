// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_core {

void wrapDecayType( python::module& module ) {

  // type aliases
  using Component = njoy::GNDStk::enums::DecayType;

  // wrap views created by this component

  // create the component
  python::enum_< Component > component(

    module,
    "DecayType",
    "Enumeration class giving acceptable decay type values",
    python::arithmetic()
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

} // namespace python_core
