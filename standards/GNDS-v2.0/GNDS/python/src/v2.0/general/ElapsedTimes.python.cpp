
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/ElapsedTimes.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::ElapsedTimes
void wrapElapsedTimes(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::ElapsedTimes;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "ElapsedTimes",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<general::ElapsedTime> &
      >(),
      py::arg("elapsed_time"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set elapsedTime
   object.def_property(
      "elapsed_time",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.elapsedTime();
      },
      [](cppCLASS &self, const std::vector<general::ElapsedTime> &value)
      {
         self.elapsedTime() = value;
      },
      cppCLASS::component_t::documentation("elapsed_time").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
