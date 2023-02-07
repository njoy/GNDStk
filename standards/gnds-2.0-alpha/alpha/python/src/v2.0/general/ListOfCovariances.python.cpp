
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/ListOfCovariances.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// ListOfCovariances wrapper
void wrapListOfCovariances(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::ListOfCovariances;

   // create the component
   python::class_<Component> component(
      module, "ListOfCovariances",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<general::Covariance> &
         >(),
         python::arg("covariance"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "covariance",
         [](const Component &self)
         {
            return self.covariance();
         },
         Component::documentation("covariance").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
