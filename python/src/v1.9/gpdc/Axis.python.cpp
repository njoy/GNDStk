// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v1.9/gpdc/Axis.hpp"

// namespace aliases
namespace python = pybind11;

namespace v1_9 {
namespace gpdc {

void wrapAxis( python::module& module ) {

  // type aliases
  using Component = njoy::GNDStk::v1_9::gpdc::Axis;

  // create the component
  python::class_< Component > component(

    module,
    "Axis",
    "Container component - an axis with index, label and unit"
  );

  // wrap the component
  component
  .def(

    python::init< const std::optional<njoy::GNDStk::Integer32>&,
                  const std::optional<njoy::GNDStk::XMLName>&,
                  const std::optional<njoy::GNDStk::XMLName>& >(),
    python::arg( "index" ), python::arg( "label" ), python::arg( "unit" ),
    "Initialise the component\n\n"
    "Arguments:\n"
    "    self     the component\n"
    "    index    the axis index\n"
    "    label    the axis label\n"
    "    unit     the axis unit"
  )
  .def_property_readonly(

    "index",
    &Component::index,
    "The axis index"
  )
  .def_property_readonly(

    "label",
    &Component::label,
    "The axis label"
  )
  .def_property_readonly(

    "unit",
    &Component::unit,
    "The unit index"
  );
}

} // namespace gpdc
} // namespace v1_9
