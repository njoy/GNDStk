
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/DiscreteGamma.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// DiscreteGamma wrapper
void wrapDiscreteGamma(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::DiscreteGamma;

   // create the component
   python::class_<Component> component(
      module, "DiscreteGamma",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const double &,
            const double &,
            const double &,
            const general::Axes &
         >(),
         python::arg("value"),
         python::arg("domain_min"),
         python::arg("domain_max"),
         python::arg("axes"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "value",
         [](const Component &self)
         {
            return self.value();
         },
         Component::documentation("value").data()
      )
      .def_property_readonly(
         "domain_min",
         [](const Component &self)
         {
            return self.domainMin();
         },
         Component::documentation("domain_min").data()
      )
      .def_property_readonly(
         "domain_max",
         [](const Component &self)
         {
            return self.domainMax();
         },
         Component::documentation("domain_max").data()
      )
      .def_property_readonly(
         "axes",
         [](const Component &self)
         {
            return self.axes();
         },
         Component::documentation("axes").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
