
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/documentation/Collaborations.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// wrapper for documentation::Collaborations
void wrapCollaborations(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = documentation::Collaborations;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Collaborations",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<documentation::Collaboration> &
      >(),
      py::arg("collaboration"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set collaboration
   object.def_property(
      "collaboration",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.collaboration();
      },
      [](cppCLASS &self, const std::vector<documentation::Collaboration> &value)
      {
         self.collaboration() = value;
      },
      cppCLASS::component_t::documentation("collaboration").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_documentation
} // namespace python_v2_0
