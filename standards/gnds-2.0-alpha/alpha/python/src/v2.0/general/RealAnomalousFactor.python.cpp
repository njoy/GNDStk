
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/RealAnomalousFactor.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// RealAnomalousFactor wrapper
void wrapRealAnomalousFactor(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::RealAnomalousFactor;

   // create the component
   python::class_<Component> component(
      module, "RealAnomalousFactor",
      Component::component_t::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const general::XYs1d &
         >(),
         python::arg("xys1d"),
         Component::component_t::documentation("constructor").data()
      )
      .def_property_readonly(
         "xys1d",
         [](const Component &self)
         {
            return self.XYs1d();
         },
         Component::component_t::documentation("xys1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
