
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/Title.hpp"
#include "definitions.hpp"

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::Title
void wrapTitle(pybind11::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::Title;

   // create the Python object
   pybind11::class_<cppCLASS> object(
      module, "Title",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      pybind11::init<
      >(),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set data string
   object.def_property(
      "string",
      [](const cppCLASS &self) -> const std::string &
      {
         return self;
      },
      [](cppCLASS &self, const std::string &value)
      {
         self = value;
      },
      cppCLASS::component_t::documentation("string").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
