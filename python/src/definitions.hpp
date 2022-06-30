#ifndef NJOY_GNDSTK_PYTHON_DEFINITIONS
#define NJOY_GNDSTK_PYTHON_DEFINITIONS

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// other includes
#include "GNDStk.hpp"

// namespace aliases
namespace python = pybind11;

/**
 *  @brief Add standard component definitions
 *
 *  This adds the following standard properties/functions:
 *    init (copy), from_string
 *
 *  @param[in] component   the component to which the definitions have to be added
 */
template < typename Component, typename PythonClass >
void addStandardComponentDefinitions( PythonClass& component ) {

  component
  .def(

    python::init< const Component& >(),
    python::arg( "component" ),
    "Initialise the component with another instance\n\n"
    "Arguments:\n"
    "    self    the component\n"
    "    file    the component to be copied"
  )
  .def_static(

    "from_string",
    [] ( const std::string& string ) -> Component {

      using namespace njoy::GNDStk;

      Node node;
      node << string;

      return Component( node );
    },
    python::arg( "string" ),
    "Read the component from an XML or JSON string\n\n"
    "An exception is raised if something goes wrong while reading the\n"
    "component\n\n"
    "Arguments:\n"
    "    string    the string representing the component"
  )
  .def(

    "to_xml_string",
    [] ( const Component& self ) -> std::string {

      using namespace njoy::GNDStk;

      std::ostringstream out;
      XML( Node( self ) ).write( out, false );

      return out.str();
    },
    "Write the component to an XML formatted string\n\n"
    "Arguments:\n"
    "    self    the component"
  )
  .def(

    "to_xml_file",
    [] ( const Component& self, const std::string& fileName ) {

      using namespace njoy::GNDStk;

      XML( Node( self ) ).write( fileName );
    },
    python::arg( "file_name" ),
    "Write the component to an XML file\n\n"
    "Arguments:\n"
    "    self         the component\n"
    "    file_name    the name of the XML file"
  );
}

#endif
