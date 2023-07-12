
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/containers/Function2ds.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_containers {

// wrapper for containers::Function2ds
void wrapFunction2ds(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = containers::Function2ds;
   using _t = std::variant<
      containers::XYs2d,
      containers::Gridded2d
   >;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Function2ds",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<_t> &
      >(),
      py::arg("_xys2dgridded2d"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   object.def_property(
      "_xys2dgridded2d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self._XYs2dgridded2d();
      },
      [](cppCLASS &self, const std::vector<_t> &value)
      {
         self._XYs2dgridded2d() = value;
      },
      cppCLASS::component_t::documentation("_xys2dgridded2d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_containers
} // namespace python_v2_0
