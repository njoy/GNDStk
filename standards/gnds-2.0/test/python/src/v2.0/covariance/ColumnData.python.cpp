
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/covariance/ColumnData.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_covariance {

// wrapper for covariance::ColumnData
void wrapColumnData(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = covariance::ColumnData;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "ColumnData",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::optional<XMLName> &,
         const std::optional<XMLName> &,
         const std::optional<Integer32> &,
         const std::optional<covariance::Slices> &
      >(),
      py::arg("endf_mfmt") = std::nullopt,
      py::arg("href") = std::nullopt,
      py::arg("dimension") = std::nullopt,
      py::arg("slices") = std::nullopt,
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set ENDF_MFMT
   object.def_property(
      "endf_mfmt",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.ENDF_MFMT();
      },
      [](cppCLASS &self, const std::optional<XMLName> &value)
      {
         self.ENDF_MFMT() = value;
      },
      cppCLASS::component_t::documentation("endf_mfmt").data()
   );

   // get/set href
   object.def_property(
      "href",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.href();
      },
      [](cppCLASS &self, const std::optional<XMLName> &value)
      {
         self.href() = value;
      },
      cppCLASS::component_t::documentation("href").data()
   );

   // get/set dimension
   object.def_property(
      "dimension",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.dimension();
      },
      [](cppCLASS &self, const std::optional<Integer32> &value)
      {
         self.dimension() = value;
      },
      cppCLASS::component_t::documentation("dimension").data()
   );

   // get/set slices
   object.def_property(
      "slices",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.slices();
      },
      [](cppCLASS &self, const std::optional<covariance::Slices> &value)
      {
         self.slices() = value;
      },
      cppCLASS::component_t::documentation("slices").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_covariance
} // namespace python_v2_0
