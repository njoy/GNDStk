
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "test/v2.0/documentation/InputDecks.hpp"
#include "definitions.hpp"

// namespace aliases
namespace py = pybind11;

namespace python_v2_0 {
namespace python_documentation {

// wrapper for documentation::InputDecks
void wrapInputDecks(py::module &module)
{
   using namespace test;
   using namespace test::v2_0;

   // type aliases
   using cppCLASS = documentation::InputDecks;

   // create the Python object
   py::class_<cppCLASS> object(
      module, "InputDecks",
      cppCLASS::component_t::documentation().data()
   );

   // constructor: from fields
   object.def(
      py::init<
         const std::vector<documentation::InputDeck> &
      >(),
      py::arg("input_deck"),
      cppCLASS::component_t::documentation("constructor").data()
   );

   // get/set inputDeck
   object.def_property(
      "input_deck",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.inputDeck();
      },
      [](cppCLASS &self, const std::vector<documentation::InputDeck> &value)
      {
         self.inputDeck() = value;
      },
      cppCLASS::component_t::documentation("input_deck").data()
   );

   // add standard definitions
   addStandardComponentDefinitions<cppCLASS>(object);
}

} // namespace python_documentation
} // namespace python_v2_0
