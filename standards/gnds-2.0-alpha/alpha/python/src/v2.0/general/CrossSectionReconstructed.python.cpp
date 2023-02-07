
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/CrossSectionReconstructed.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// CrossSectionReconstructed wrapper
void wrapCrossSectionReconstructed(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::CrossSectionReconstructed;

   // create the component
   python::class_<Component> component(
      module, "CrossSectionReconstructed",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::string &,
            const std::string &,
            const std::string &
         >(),
         python::arg("label"),
         python::arg("derived_from"),
         python::arg("date"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "label",
         [](const Component &self)
         {
            return self.label();
         },
         Component::documentation("label").data()
      )
      .def_property_readonly(
         "derived_from",
         [](const Component &self)
         {
            return self.derivedFrom();
         },
         Component::documentation("derived_from").data()
      )
      .def_property_readonly(
         "date",
         [](const Component &self)
         {
            return self.date();
         },
         Component::documentation("date").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
