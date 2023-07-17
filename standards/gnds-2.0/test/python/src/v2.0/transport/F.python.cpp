
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/F.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_transport {

// wrapper for transport::F
void wrapF(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = transport::F;
   using _t = std::variant<
      containers::XYs2d,
      containers::Regions2d
   >;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "F",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const _t &
      >(),
      py::arg("_xys2dregions2d"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   object.def_property(
      "xys2d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.XYs2d();
      },
      [](cppCLASS &self, const containers::XYs2d &value)
      {
         self.XYs2d() = value;
      },
      cppCLASS::component_t::documentation("xys2d").data()
   );

   object.def_property(
      "regions2d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.regions2d();
      },
      [](cppCLASS &self, const containers::Regions2d &value)
      {
         self.regions2d() = value;
      },
      cppCLASS::component_t::documentation("regions2d").data()
   );

   object.def_property(
      "_xys2dregions2d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self._XYs2dregions2d();
      },
      [](cppCLASS &self, const _t &value)
      {
         self._XYs2dregions2d() = value;
      },
      cppCLASS::component_t::documentation("_xys2dregions2d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_transport
} // namespace python_v2_0
