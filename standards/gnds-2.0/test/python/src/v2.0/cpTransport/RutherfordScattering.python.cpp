
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/cpTransport/RutherfordScattering.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_cpTransport {

// wrapper for cpTransport::RutherfordScattering
void wrapRutherfordScattering(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = cpTransport::RutherfordScattering;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "RutherfordScattering",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
      >(),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_cpTransport
} // namespace python_v2_0
