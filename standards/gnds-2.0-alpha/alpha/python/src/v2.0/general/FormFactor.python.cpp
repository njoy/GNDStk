
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/FormFactor.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// FormFactor wrapper
void wrapFormFactor(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::FormFactor;

   // create the component
   python::class_<Component> component(
      module, "FormFactor",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const general::XYs1d &
         >(),
         python::arg("xys1d"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "xys1d",
         [](const Component &self)
         {
            return self.XYs1d();
         },
         Component::documentation("xys1d").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
