#ifndef NJOY_GNDSTK_V1_9_COMPONENT
#define NJOY_GNDSTK_V1_9_COMPONENT

// system includes
#include <memory>

// other includes
#include "GNDStk.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

  /**
   *  @class
   *  @brief GNDS component base class
   */
  class Component {

  protected:

    /* type aliases */
    using NodeType = GNDStk::node;

  private:

    /* node fields */
    std::unique_ptr< NodeType > pointer_ = std::make_unique< NodeType >( "unassigned" );
    NodeType& node_ = *( this->pointer_ );

  protected :

    /* constructors */

    /**
     *  @brief Default constructor (required for the core GNDS interface)
     */
    Component() = default;

    /**
     *  @brief Copy constructor
     *
     *  The internal node is copied, and the link to any outside node is
     *  therefore severed. The derived component's data then has to be synced to
     *  the copied internal node.
     *
     *  @param[in] component    the component to be copied
     */
    Component( const Component& component ) :
      node_( *( pointer_ = std::make_unique< NodeType >( component.node() ) ) ) {}

    /**
     *  @brief Copy assignment
     *
     *  The internal node is copied, and a link to any outside node is
     *  therefore severed. The derived component's data then has to be synced to
     *  the copied internal node.
     *
     *  @param[in] component    the component to be copied
     */
    Component& operator=( const Component& component ) {

      this->pointer_ = std::make_unique< NodeType >( component.node() );
      this->node_ = *( this->pointer_ );
      return *this;
    }

    /**
     *  @brief Move constructor
     *
     *  @param[in] component    the component to be moved
     */
    Component( Component&& component ) :
      pointer_( std::move( component.pointer_ ) ), node_( component.node_ ) {}

    /**
     *  @brief Constructor
     *
     *  The internal node reference is initialised to the given node reference,
     *  which means that the tree where the node came from will remain in sync
     *  with this component. A derived component's data should then be synced to
     *  the referenced internal node.
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Component( NodeType& core ) : node_( core ) {}

    /**
     *  @brief Constructor
     *
     *  The internal node reference is initialised with a copy of the given
     *  node, and a link to any outside node is therefore severed. A derived
     *  component's data should then be synced to the copied internal node.
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Component( const NodeType& core ) :
      node_( *( pointer_ = std::make_unique< NodeType >( core ) ) ) {}

  public :

    /**
     *  @brief Retrieve the core GNDS node for this component
     *
     *  @return The internal core GNDS node
     */
    NodeType& node() {

      return this->node_;
    }

    /**
     *  @brief Retrieve the core GNDS node for this component
     *
     *  @return The internal core GNDS node
     */
    const NodeType& node() const {

      return this->node_;
    }
  };

} // v1_9 namespace
} // GNDStk namespace
} // njoy namespace

#endif
