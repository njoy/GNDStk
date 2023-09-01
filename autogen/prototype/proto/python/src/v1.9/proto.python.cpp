
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// v1.9 interface declarations
namespace python_v1_9 {
   void wrapContainers(pybind11::module &);
   void wrapTransport(pybind11::module &);
}

namespace python_v1_9 {

void wrapGNDS(pybind11::module &module)
{
   // create the core submodule
   pybind11::module submodule = module.def_submodule(
      "v1_9",
      "GNDS 1.9 standard components"
   );

   python_v1_9::wrapContainers(submodule);
   python_v1_9::wrapTransport(submodule);
}

} // namespace python_v1_9
