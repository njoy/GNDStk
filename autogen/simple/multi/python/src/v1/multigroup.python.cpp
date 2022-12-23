
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace python = pybind11;

// v1 interface
namespace python_v1 {

// multigroup declarations
namespace python_multigroup {
   void wrapIsotope(python::module &);
   void wrapFoobar(python::module &);
   void wrapElement(python::module &);
   void wrapLibrary(python::module &);
   void wrapMultigroup(python::module &);
} // namespace python_multigroup

// multigroup wrapper
void wrapMultigroup(python::module &module)
{
   // create the multigroup submodule
   python::module submodule = module.def_submodule(
      "multigroup",
      "multi v1 multigroup"
   );

   // wrap multigroup components
   python_multigroup::wrapIsotope(submodule);
   python_multigroup::wrapFoobar(submodule);
   python_multigroup::wrapElement(submodule);
   python_multigroup::wrapLibrary(submodule);
   python_multigroup::wrapMultigroup(submodule);
};

} // namespace python_v1
