
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
      "Read the object from an XML, JSON, or HDF5 (binary) string.\n"
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
      [](const cppCLASS &self)
      {
         using namespace njoy::GNDStk;
         std::ostringstream oss;
         XML(Node(self)).write(oss,false);
         return oss.str();
      },
      "Write the object to an XML formatted string.\n\n"
      "Arguments:\n"
      "    self    The object."
   );

   // to_xml_file
   object.def(
      "to_xml_file",
      [](const cppCLASS &self, const std::string &file)
      {
         using namespace njoy::GNDStk;
         XML(Node(self)).write(file);
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
      [](const cppCLASS &self)
      {
         using namespace njoy::GNDStk;
         std::ostringstream oss;
         JSON(Node(self)).write(oss,false);
         return oss.str();
      },
      "Write the object to an JSON formatted string.\n\n"
      "Arguments:\n"
      "    self    The object."
   );

   // to_json_file
   object.def(
      "to_json_file",
      [](const cppCLASS &self, const std::string &file)
      {
         using namespace njoy::GNDStk;
         JSON(Node(self)).write(file);
      },
      py::arg("file"),
      "Write the object to an JSON file.\n\n"
      "Arguments:\n"
      "    self    The object.\n"
      "    file    The name of the JSON file."
   );

   // ------------------------
   // re: HDF5
   // ------------------------

   // to_hdf5_string
   object.def(
      "to_hdf5_string",
      [](const cppCLASS &self)
      {
         using namespace njoy::GNDStk;
         std::ostringstream oss;
         HDF5(Node(self)).write(oss,false);
         return oss.str();
      },
      "Write the object to an HDF5 formatted string.\n\n"
      "Arguments:\n"
      "    self    The object."
   );

   // to_hdf5_file
   object.def(
      "to_hdf5_file",
      [](const cppCLASS &self, const std::string &file)
      {
         using namespace njoy::GNDStk;
         HDF5(Node(self)).write(file);
      },
      py::arg("file"),
      "Write the object to an HDF5 file.\n\n"
      "Arguments:\n"
      "    self    The object.\n"
      "    file    The name of the HDF5 file."
   );

   // ------------------------
   // for printing
   // ------------------------

   // These use GNDStk::Component's prettyprinter

   // Python's __repr__
   object.def(
      "__repr__",
      [](const cppCLASS &self)
      {
         std::ostringstream oss;
         return self.print(oss,0), oss.str();
      }
   );

   // print
   object.def(
      "print",
      [](const cppCLASS &self)
      {
         std::ostringstream oss;
         return self.print(oss,0), oss.str();
      }
   );

   // print as XML
   object.def(
      "xml",
      [](const cppCLASS &self)
      {
         std::ostringstream oss;
         return self.write(oss,"xml"), oss.str();
      }
   );

   // print as JSON
   object.def(
      "json",
      [](const cppCLASS &self)
      {
         std::ostringstream oss;
         return self.write(oss,"json"), oss.str();
      }
   );

   // ------------------------
   // read from file or string
   // ------------------------

   object.def(
      "read",
      [](cppCLASS &self, const std::string &string)
      {
         std::ifstream ifs(string);
         if (ifs)
            self.read(ifs);
         else
            self << string;
      },
      py::arg("string"),
      "If string can be opened as a file, read the object from the file.\n"
      "Else, assume string contains literal XML, JSON, or HDF5 content.\n\n"
      "Arguments:\n"
      "    self    The object.\n"
      "    file    The name of the HDF5 file."
   );
}

#endif
