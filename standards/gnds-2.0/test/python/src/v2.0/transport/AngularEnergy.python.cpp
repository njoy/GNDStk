
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/transport/AngularEnergy.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_transport {

// wrapper for transport::AngularEnergy
void wrapAngularEnergy(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = transport::AngularEnergy;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "AngularEnergy",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const XMLName &,
         const XMLName &,
         const containers::XYs3d &
      >(),
      py::arg("label"),
      py::arg("product_frame"),
      py::arg("xys3d"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set label
   object.def_property(
      "label",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.label();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.label() = value;
      },
      cppCLASS::component_t::documentation("label").data()
   );

   // get/set productFrame
   object.def_property(
      "product_frame",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.productFrame();
      },
      [](cppCLASS &self, const XMLName &value)
      {
         self.productFrame() = value;
      },
      cppCLASS::component_t::documentation("product_frame").data()
   );

   // get/set XYs3d
   object.def_property(
      "xys3d",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.XYs3d();
      },
      [](cppCLASS &self, const containers::XYs3d &value)
      {
         self.XYs3d() = value;
      },
      cppCLASS::component_t::documentation("xys3d").data()
   );

   // shortcut: get/set axes
   object.def_property(
      "axes",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.axes();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.axes())> &value)
      {
         self.axes() = value;
      },
      cppCLASS::component_t::documentation("axes").data()
   );

   // shortcut: get/set function2ds
   object.def_property(
      "function2ds",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.function2ds();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.function2ds())> &value)
      {
         self.function2ds() = value;
      },
      cppCLASS::component_t::documentation("function2ds").data()
   );

   // shortcut: get/set uncertainty
   object.def_property(
      "uncertainty",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.uncertainty();
      },
      [](cppCLASS &self, const std::decay_t<decltype(self.uncertainty())> &value)
      {
         self.uncertainty() = value;
      },
      cppCLASS::component_t::documentation("uncertainty").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_transport
} // namespace python_v2_0
