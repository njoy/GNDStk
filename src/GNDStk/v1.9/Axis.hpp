#ifndef NJOY_GNDSTK_V1_9_AXIS
#define NJOY_GNDSTK_V1_9_AXIS

// system includes
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

    /* query object */
    static inline
    const auto query = unsigned{} / GNDStk::basic::index |
                       GNDStk::basic::label |
                       std::optional< std::string >{} / GNDStk::basic::unit;

    /* data fields */
    unsigned int index_;
    std::string label_;
    std::optional< std::string > unit_;

    /* auxiliary functions */
    void sync() {

      // verify the node name
      if ( this->node().name != "axis" ) {

        log::error( "Expected an \"axis\" node, found \"{}\" instead",
                    this->node().name );
        throw std::exception();
      }

      // extract the data
      bool found = false;
      auto tuple = this->node()( query, found );
      if ( !found ) {

        // the query did not work
        log::error( "Some or all of the required attributes and/or children for "
                    "the \"axis\" node are missing" );
        //!@todo print out the node content?
        throw std::exception();
      }
      else {

        // sync the component
        this->index_ = std::get< 0 >( tuple );
        this->label_ = std::get< 1 >( tuple );
        this->unit_ = std::get< 2 >( tuple );
      }
    }

  public :

    /* constructors */

    /**
     *  @brief Default constructor (required for the core GNDS interface)
     */
    Axis() : Component() {}

    /**
     *  @brief Constructor
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Axis( NodeType& core ) : Component( core ) {

      this->sync();
    }

    /**
     *  @brief Constructor
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
