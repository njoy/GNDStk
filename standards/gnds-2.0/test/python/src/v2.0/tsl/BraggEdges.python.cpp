
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/tsl/BraggEdges.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_tsl {

// wrapper for tsl::BraggEdges
void wrapBraggEdges(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = tsl::BraggEdges;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "BraggEdges",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<tsl::BraggEdge> &
      >(),
      py::arg("bragg_edge"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set BraggEdge
   object.def_property(
      "bragg_edge",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.BraggEdge();
      },
      [](cppCLASS &self, const std::vector<tsl::BraggEdge> &value)
      {
         self.BraggEdge() = value;
      },
      cppCLASS::component_t::documentation("bragg_edge").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_tsl
} // namespace python_v2_0
