
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "code/v2.0/gnds/Authors.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_gnds {

// wrapper for gnds::Authors
void wrapAuthors(py::module &module)
{
   using namespace code;
   using namespace code::v2_0;

   // type aliases
   using cppCLASS = gnds::Authors;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Authors",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<gnds::Author> &
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
      [](cppCLASS &self, const std::vector<gnds::Author> &value)
      {
         self.author() = value;
      },
      cppCLASS::component_t::documentation("author").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_gnds
} // namespace python_v2_0
