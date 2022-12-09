
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/pops/MetaStable.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_pops {

// MetaStable wrapper
void wrapMetaStable(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = pops::MetaStable;

   // create the component
   python::class_<Component> component(
      module,
      "MetaStable",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const XMLName &,
            const Integer32 &,
            const XMLName &
         >(),
         python::arg("id"),
         python::arg("meta_stable_index"),
         python::arg("pid"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "id",
         [](const Component &self) { return self.id(); },
         Component::documentation("id").data()
      )
      .def_property_readonly(
         "meta_stable_index",
         [](const Component &self) { return self.metaStableIndex(); },
         Component::documentation("meta_stable_index").data()
      )
      .def_property_readonly(
         "pid",
         [](const Component &self) { return self.pid(); },
         Component::documentation("pid").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_pops
} // namespace python_v2_0
