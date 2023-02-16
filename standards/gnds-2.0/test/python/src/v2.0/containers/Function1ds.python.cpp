
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/containers/Function1ds.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_containers {

// wrapper for containers::Function1ds
void wrapFunction1ds(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = containers::Function1ds;
   using _t = std::variant<
      containers::XYs1d,
      containers::Constant1d,
      containers::Polynomial1d,
      containers::Legendre,
      containers::Gridded1d
   >;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "Function1ds",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<_t> &
      >(),
      py::arg("_xys1dconstant1dpolynomial1d_legendregridded1d"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   object.def_property(
      "_xys1dconstant1dpolynomial1d_legendregridded1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self._XYs1dconstant1dpolynomial1dLegendregridded1d();
      },
      [](cppCLASS &self, const std::vector<_t> &value)
      {
         self._XYs1dconstant1dpolynomial1dLegendregridded1d() = value;
      },
      cppCLASS::component_t::documentation("_xys1dconstant1dpolynomial1d_legendregridded1d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_containers
} // namespace python_v2_0
