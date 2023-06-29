
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/documentation/Contributors.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// wrapper for documentation::Contributors
void wrapContributors(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = documentation::Contributors;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Contributors",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<documentation::Author> &
      >(),
      py::arg("author"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set author
   object.def_property(
      "author",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.author();
      },
      [](cppCLASS &self, const std::vector<documentation::Author> &value)
      {
         self.author() = value;
      },
      cppCLASS::component_t::documentation("author").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_documentation
} // namespace python_v2_0
