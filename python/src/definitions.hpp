
#ifndef NJOY_GNDSTK_PYTHON_DEFINITIONS
#define NJOY_GNDSTK_PYTHON_DEFINITIONS

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// other includes
#include "GNDStk.hpp"

// namespace aliases
namespace py = pybind11;

/**
 *  @brief Add standard definitions for classes derived from GNDStk::Component.
 *
 *  This adds standard properties and functions for generated classes.
 *
 *  @param[in] object   The Python object to which definitions should be added.
 */
template<class cppCLASS, class pyCLASS>
void addStandardComponentDefinitions(pyCLASS &object)
{
   // ------------------------
   // Constructors
   // ------------------------

   // constructor: default
   object.def(
      py::init<>(),
      "Initialise the object with its default contents.\n\n"
      "Arguments:\n"
      "    self    The object."
   );

   // constructor: copy
   object.def(
      py::init<const cppCLASS &>(),
      py::arg("from"),
      "Initialise the object with another instance.\n\n"
      "Arguments:\n"
      "    self    The object.\n"
      "    from    The object to be copied from."
   );

   // ------------------------
   // Get/set comment
   // ------------------------

   // get/set comment
   object.def_property(
      "comment",
      [](const cppCLASS &self) -> decltype(auto)
      {
         return self.comment();
      },
      [](cppCLASS &self, const std::vector<std::string> &value)
      {
         self.comment() = value;
      },
      "Array of comments to appear at the beginning of the node."
   );

   // ------------------------
   // Re: input from string;
   // the type (XML, JSON, or
   // HDF5) is auto-determined
   // ------------------------

   // from_string
   object.def(
      "from_string",
      [](cppCLASS &self, const std::string &string)
      {
         self << string;
      },
      py::arg("string"),
      "Read the object from an XML, JSON, or HDF5 string.\n"
      "An exception is raised if something fails during the read.\n\n"
      "Arguments:\n"
      "    string    The string representing the object."
   );

   // ------------------------
   // re: XML
   // ------------------------

   // to_xml_string
   object.def(
      "to_xml_string",
      [](const cppCLASS &self) -> decltype(auto)
      {
         std::ostringstream oss;
         self.write(oss,"xml");
         return oss.str();
      },
      "Write the object to an XML formatted string.\n\n"
      "Arguments:\n"
      "    self    The object."
   );

   // to_xml_file
   object.def(
      "to_xml_file",
      [](const cppCLASS &self, const std::string &filename)
      {
         self.write(filename,"xml");
      },
      py::arg("file"),
      "Write the object to an XML file.\n\n"
      "Arguments:\n"
      "    self    The object.\n"
      "    file    The name of the XML file."
   );

   // ------------------------
   // re: JSON
   // ------------------------

   // to_json_string
   object.def(
      "to_json_string",
      [](const cppCLASS &self) -> decltype(auto)
      {
         std::ostringstream oss;
         self.write(oss,"json");
         return oss.str();
      },
      "Write the object to a JSON formatted string.\n\n"
      "Arguments:\n"
      "    self    The object."
   );

   // to_json_file
   object.def(
      "to_json_file",
      [](const cppCLASS &self, const std::string &filename)
      {
         self.write(filename,"json");
      },
      py::arg("file"),
      "Write the object to a JSON file.\n\n"
      "Arguments:\n"
      "    self    The object.\n"
      "    file    The name of the JSON file."
   );

   // ------------------------
   // re: HDF5
   // ------------------------

#ifndef GNDSTK_DISABLE_HDF5
   // to_hdf5_string
   object.def(
      "to_hdf5_string",
      [](const cppCLASS &self) -> decltype(auto)
      {
         std::ostringstream oss;
         self.write(oss,"hdf5");
         return oss.str();
      },
      "Write the object to an HDF5 formatted string.\n\n"
      "Arguments:\n"
      "    self    The object."
   );

   // to_hdf5_file
   object.def(
      "to_hdf5_file",
      [](const cppCLASS &self, const std::string &filename)
      {
         self.write(filename,"hdf5");
      },
      py::arg("file"),
      "Write the object to an HDF5 file.\n\n"
      "Arguments:\n"
      "    self    The object.\n"
      "    file    The name of the HDF5 file."
   );
#endif

   // ------------------------
   // for printing
   // ------------------------

   // These use GNDStk::Component's prettyprinter

   // prettyprint: for Python's __repr__
   object.def(
      "__repr__",
      [](const cppCLASS &self) -> decltype(auto)
      {
         njoy::GNDStk::printMode = njoy::GNDStk::PrintMode::python;
         std::ostringstream oss;
         self.print(oss,0);
         return oss.str();
      }
   );

   // prettyprint: into string
   object.def(
      "print",
      [](const cppCLASS &self) -> decltype(auto)
      {
         njoy::GNDStk::printMode = njoy::GNDStk::PrintMode::python;
         std::ostringstream oss;
         self.print(oss,0);
         return oss.str();
      }
   );

   // ------------------------
   // write into string, as
   // XML, JSON, HDF5, or our
   // internal debug format
   // ------------------------

   // write into string, as XML
   object.def(
      "xml",
      [](const cppCLASS &self) -> decltype(auto)
      {
         std::ostringstream oss;
         self.write(oss,"xml");
         return oss.str();
      }
   );

   // write into string, as JSON
   object.def(
      "json",
      [](const cppCLASS &self) -> decltype(auto)
      {
         std::ostringstream oss;
         self.write(oss,"json");
         return oss.str();
      }
   );

#ifndef GNDSTK_DISABLE_HDF5
   // write into string, as HDF5
   object.def(
      "hdf5",
      [](const cppCLASS &self) -> decltype(auto)
      {
         std::ostringstream oss;
         self.write(oss,"hdf5");
         return oss.str();
      }
   );
#endif

   // write into string, in our internal debug format
   object.def(
      "debug",
      [](const cppCLASS &self) -> decltype(auto)
      {
         std::ostringstream oss;
         self.write(oss,"debug");
         return oss.str();
      }
   );

   // ------------------------
   // read/write from/to file
   // ------------------------

   // read
   object.def(
      "read",
      [](cppCLASS &self, const std::string &filename)
      {
         self.read(filename);
      },
      py::arg("file"),
      "Read the object from a file. "
      "The file's type will be determined from its contents.\n\n"
      "Arguments:\n"
      "    self    The object.\n"
      "    file    The name of the file."
   );

   // write
   object.def(
      "write",
      [](const cppCLASS &self, const std::string &filename)
      {
         self.write(filename);
      },
      py::arg("file"),
      "Write the object to a file. "
      "The file's type will be determined from its extension.\n\n"
      "Arguments:\n"
      "    self    The object.\n"
      "    file    The name of the file."
   );
} // addStandardComponentDefinitions

#endif
