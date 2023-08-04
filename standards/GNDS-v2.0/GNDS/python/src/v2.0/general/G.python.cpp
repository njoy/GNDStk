
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDS/v2.0/general/G.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_GNDS {
namespace python_v2_0 {
namespace python_general {

// wrapper for general::G
void wrapG(py::module &module)
{
   using namespace GNDS;
   using namespace GNDS::v2_0;

   // type aliases
   using cppCLASS = general::G;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "G",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<general::XYs1d> &
      >(),
      py::arg("xys1d") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set XYs1d
   object.def_property(
      "xys1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.XYs1d();
      },
      [](cppCLASS &self, const std::optional<general::XYs1d> &value)
      {
         self.XYs1d() = value;
      },
      cppCLASS::component_t::documentation("xys1d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_general
} // namespace python_v2_0
} // namespace python_GNDS
