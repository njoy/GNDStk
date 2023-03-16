
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/transport/OrphanProducts.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_transport {

// OrphanProducts wrapper
void wrapOrphanProducts(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = transport::OrphanProducts;

   // create the component
   python::class_<Component> component(
      module,
      "OrphanProducts",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::vector<transport::OrphanProduct> &
         >(),
         python::arg("orphan_product"),
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "orphan_product",
         python::overload_cast<>(&Component::orphanProduct),
         Component::documentation("orphan_product").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_transport
} // namespace python_v2_0
