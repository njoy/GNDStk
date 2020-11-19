#ifndef NJOY_GNDSTK_V1_9_COMPONENT
#define NJOY_GNDSTK_V1_9_COMPONENT

// system includes

// other includes
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {

namespace v1_9 {

  /**
   *  @class
   *  @brief Base component class implemented as CRTP
   *
   *  This base class adds common interface functions for GNDS components.
   */
  template < typename Derived >
  class Component {

    /* type aliases */
    using NodeType = GNDStk::node;

  protected:

    /* auxiliary functions */
    static NodeType makeNode( const Derived& component ) {

      NodeType core;
      convert( component, core );
      return core;
    }

    static Derived fromNode( const NodeType& core ) {

      Derived component;
      convert( core, component );
      return component;
    }

    /* constructors */

    /**
     *  @brief Default constructor (required for the core GNDS interface)
     */
    Component() = default;

  public:

    /**
     *  @brief Retrieve a core GNDS node for this component
     *
     *  @return The core GNDS node constructed from the component
     */
    NodeType node() const {

      return makeNode( *( static_cast< const Derived* >( this ) ) );
    }
  };

} // v1_9 namespace
} // GNDStk namespace
} // njoy namespace

#endif
