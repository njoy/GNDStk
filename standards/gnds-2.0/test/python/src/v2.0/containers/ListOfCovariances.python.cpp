
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/containers/ListOfCovariances.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_containers {

// ListOfCovariances wrapper
void wrapListOfCovariances(python::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using Component = containers::ListOfCovariances;

   // create the component
   python::class_<Component> component(
      module,
      "ListOfCovariances",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<containers::Covariance> &
         >(),
         python::arg("covariance"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "covariance",
         [](const Component &self) { return self.covariance(); },
         Component::documentation("covariance").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_containers
} // namespace python_v2_0