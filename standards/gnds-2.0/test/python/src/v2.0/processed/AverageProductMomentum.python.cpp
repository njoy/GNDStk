
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/processed/AverageProductMomentum.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_processed {

// wrapper for processed::AverageProductMomentum
void wrapAverageProductMomentum(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = processed::AverageProductMomentum;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "AverageProductMomentum",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<containers::XYs1d> &,
         const std::optional<containers::Gridded1d> &,
         const std::optional<containers::Regions1d> &
      >(),
      py::arg("xys1d") = std::nullopt,
      py::arg("gridded1d") = std::nullopt,
      py::arg("regions1d") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set XYs1d
   object.def_property(
      "xys1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.XYs1d();
      },
      [](cppCLASS &self, const std::optional<containers::XYs1d> &value)
      {
         self.XYs1d() = value;
      },
      cppCLASS::component_t::documentation("xys1d").data()
   );

   // get/set gridded1d
   object.def_property(
      "gridded1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.gridded1d();
      },
      [](cppCLASS &self, const std::optional<containers::Gridded1d> &value)
      {
         self.gridded1d() = value;
      },
      cppCLASS::component_t::documentation("gridded1d").data()
   );

   // get/set regions1d
   object.def_property(
      "regions1d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.regions1d();
      },
      [](cppCLASS &self, const std::optional<containers::Regions1d> &value)
      {
         self.regions1d() = value;
      },
      cppCLASS::component_t::documentation("regions1d").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_processed
} // namespace python_v2_0
