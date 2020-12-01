#ifndef NJOY_GNDSTK_V1_9_AXIS
#define NJOY_GNDSTK_V1_9_AXIS

// system includes
#include <memory>
#include <optional>

// other includes
#include "GNDStk.hpp"
#include "GNDStk/v1.9/Component.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

  /**
   *  @class
   *  @brief A GNDS basic component: an axis with an index, label and optional
   *         unit
   *
   *  This component in used in the axes node, which in turn is used in most
   *  functional containers.
   *
   *  See GNDS v1.9 specifications section 5.1.2
   */
  class Axis : public Component {

    /* keys */
    struct keys {

      static inline const auto index = GNDStk::basic::index;
      static inline const auto label = GNDStk::basic::label;
      static inline const auto unit = GNDStk::basic::unit;
    };

    /* data fields */
    unsigned int index_;                                // required
    std::string label_;                                 // required
    std::optional< std::string > unit_ = std::nullopt;  // optional, no default

    /* auxiliary functions */
    void sync() {

      // verify the node name
      if ( this->node().name != "axis" ) {

        log::error( "Expected an \"axis\" node, found \"{}\" instead",
                    this->node().name );
        throw std::exception();
      }

      // verify required attributes and children
      if ( !this->node().has( keys::index ) ||
           !this->node().has( keys::label ) ) {

        log::error( "Some or all of the required attributes and/or children for "
                    "the \"axis\" node are missing"  );
        //!@todo print out the node content?
        throw std::exception();
      }

      // sync the component
      this->index_ = this->node()( unsigned{} / keys::index );
      this->label_ = this->node()( keys::label );
      this->unit_ = this->node().has( keys::unit )
                      ? std::make_optional( this->node()( keys::unit ) )
                      : std::nullopt;
    }

  public :

    /* constructors */

    /**
     *  @brief Default constructor (required for the core GNDS interface)
     */
    Axis() : Component() {}

    /**
     *  @brief Copy constructor
     *
     *  Since this component has children nodes, we cannot rely on the Component
     *  copy constructor.
     *
     *  @param[in] component    the component to be copied
     */
    Axis( const Axis& component ) : Component( component.node() ) {

      this->sync();
    }

    /**
     *  @brief Copy assignment
     *
     *  Since this component has children nodes, we cannot rely on the Component
     *  copy assignment.
     *
     *  @param[in] component    the component to be copied
     */
    Axis& operator=( const Axis& component ) {

      Component::operator=( component );
      this->sync();
      return *this;
    }

    /**
     *  @brief Move constructor
     *
     *  Since this component has children nodes, we cannot rely on the Component
     *  move constructor. We need to sync the object with the internal node.
     *
     *  @param[in] component    the component to be copied
     */
    Axis( Axis&& component ) : unit_(), Component( std::move( component ) ) {

      this->sync();
    }

    /**
     *  @brief Constructor
     *
     *  The internal node reference is initialised to the given node reference,
     *  which means that the tree where the node came from will remain in sync
     *  with this component. The derived component's data is then synced to the
     *  references internal node.
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Axis( NodeType& core ) : Component( core ) {

      this->sync();
    }

    /**
     *  @brief Constructor
     *
     *  The internal node reference is initialised with a copy of the given
     *  node, and a link to any outside node is therefore severed. The derived
     *  component's data is then synced to the copied internal node.
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Axis( const NodeType& core ) : Component( core ) {

      this->sync();
    }

    /**
     *  @brief Full constructor with move semantics
     *
     *  @param[in] label    the axis label
     *  @param[in] index    the axis index
     *  @param[in] unit     the optional unit
     */
    Axis( unsigned int index, std::string&& label,
          std::optional< std::string >&& unit ) :
      Component(), index_( index ), label_( std::move( label ) ),
      unit_( std::move( unit ) ) {

      this->node().name = "axis";
      this->node().add( "index", this->index_ );
      this->node().add( "label", this->label_ );
      if ( this->unit() ) {

        this->node().add( "unit", this->unit_.value() );
      };
    }

    /**
     *  @brief Convenience constructor
     *
     *  @param[in] label    the axis label
     *  @param[in] index    the axis index
     */
    Axis( unsigned int index, const std::string& label ) :
      Axis( index, std::string( label ), std::nullopt ) {}

    /**
     *  @brief Convenience constructor
     *
     *  @param[in] label    the axis label
     *  @param[in] index    the axis index
     *  @param[in] unit     the axis unit
     */
    Axis( unsigned int index, const std::string& label,
          const std::string& unit ) :
      Axis( index, std::string( label ), std::make_optional( unit ) ) {}

    /* methods */

    /**
     *  @brief Retrieve the index of the axis
     *
     *  @return The index of the axis
     */
    unsigned int index() const { return this->index_; }

    /**
     *  @brief Retrieve the label of the axis
     *
     *  @return The label of the axis
     */
    const std::string& label() const { return this->label_; }

    /**
     *  @brief Retrieve the unit of the axis
     *
     *  @return The unit of the axis
     */
    const std::optional< std::string >& unit() const { return this->unit_; }
  };

} // v1_9 namespace

/**
 *  @brief Convert a core GNDS node to a component
 *
 *  @param[in] core         the core GNDS node
 *  @param[in] component    the component
 */
void convert( const node& core, v1_9::Axis& component ) {

  component = v1_9::Axis( core );
}

/**
 *  @brief Convert a component to a core GNDS node
 *
 *  @param[in] component    the component
 *  @param[in] core         the core GNDS node
 */
void convert( const v1_9::Axis& component, node& core ) {

  core = component.node();
};

} // GNDStk namespace
} // njoy namespace

#endif
