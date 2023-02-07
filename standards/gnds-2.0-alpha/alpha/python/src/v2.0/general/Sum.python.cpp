
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "alpha/v2.0/general/Sum.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_general {

// Sum wrapper
void wrapSum(python::module &module)
{
   using namespace alpha;
   using namespace alpha::v2_0;

   // type aliases
   using Component = general::Sum;

   // create the component
   python::class_<Component> component(
      module, "Sum",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::string> &,
            const std::optional<double> &,
            const std::optional<double> &,
            const std::optional<std::string> &,
            const std::vector<general::Summand> &
         >(),
         python::arg("label") = std::nullopt,
         python::arg("domain_min") = std::nullopt,
         python::arg("domain_max") = std::nullopt,
         python::arg("domain_unit") = std::nullopt,
         python::arg("summand"),
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
         "domain_unit",
         [](const Component &self)
         {
            return self.domainUnit();
         },
         Component::documentation("domain_unit").data()
      )
      .def_property_readonly(
         "summand",
         [](const Component &self)
         {
            return self.summand();
         },
         Component::documentation("summand").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions<Component>(component);
}

} // namespace python_general
} // namespace python_v2_0
