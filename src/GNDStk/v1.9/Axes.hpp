#ifndef NJOY_GNDSTK_V1_9_AXES
#define NJOY_GNDSTK_V1_9_AXES

// system includes

// other includes
#include "GNDStk.hpp"
#include "GNDStk/v1.9/Component.hpp"
#include "GNDStk/v1.9/Axis.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

  /**
   *  @class
   *  @brief A GNDS basic component: an axes element with multiple axis
   *
   *  This component in used in most functional containers (e.g. Constant1D or
   *  XYs1D).
   *
   *  @todo not implemented: grid child instead of axis child (exception raised)
   *
   *  See GNDS v1.9 specifications section 5.1.1
   */
  class Axes : public Component {

    /* keys */
    struct keys {

      static inline const auto axis = GNDStk::basic::axis;
    };

    /* fields */
    std::vector< Axis > axis_;

    /* auxiliary functions */
    void sort() {

      std::sort( this->axis_.begin(), this->axis_.end(),
                 [] ( const auto& left, const auto& right )
                    { return left.index() < right.index(); } );
    }

    void sync() {

      // verify the node name
      if ( this->node().name != "axes" ) {

        log::error( "Expected an \"axes\" node, found \"{}\" instead",
                    this->node().name );
        throw std::exception();
      }

      // verify required attributes and children
      if ( !this->node().has( keys::axis ) ) {

        log::error( "Some or all of the required attributes and/or children for "
                    "the \"axes\" node are missing" );
        throw std::exception();
      }

      for ( auto& child : this->node().children ) {

        if ( child->name == "axis" ) {

          this->axis_.emplace_back( *child );
        }
        else if ( child->name == "axis" ) {

          log::error( "An \"axes\" node uses a \"grid\" node, this is "
                      "currently unsupported" );
          throw std::exception();
        }
      }
      this->sort();
    }

  public :

    /* constructors */

    /**
     *  @brief Default constructor (required for the core GNDS interface)
     */
    Axes() : Component() {}

    /**
     *  @brief Constructor
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Axes( NodeType& core ) : Component( core ) {

      this->sync();
    }

    /**
     *  @brief Constructor
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Axes( const NodeType& core ) : Component( core ) {

      this->sync();
    }

    /**
     *  @brief Full constructor with move semantics
     *
     *  The axis in the vector need not be given in order, they will be sorted
     *  by index as required.
     *
     *  @param[in] axis    the axis
     */
    Axes( std::vector< Axis >&& axis ) : axis_( std::move( axis ) ) {

      this->sort();

      // axis need to be printed in reverse index order
      auto begin = this->axis_.rbegin();
      auto end = this->axis_.rend();

      this->node().name = "axes";
      for ( auto iter = begin; iter != end; ++iter ) {

        this->node().add( "axis" ) = iter->node();
      }
    }

    /**
     *  @brief Full constructor with copy semantics
     *
     *  The axis in the vector need not be given in order, they will be sorted
     *  by index as required.
     *
     *  @param[in] axis    the axis
     */
    Axes( const std::vector< Axis >& axis ) :
      Axes( std::vector< Axis >( axis ) ) {}

    /* methods */

    /**
     *  @brief Retrieve the axes
     *
     *  The order of the axis in the vector will correspond to the order of the
     *  index attribute on the Axis instances.
     *
     *  @return The axis in the component
     */
    const std::vector< Axis >& axis() const { return this->axis_; }

    /**
     *  @brief Return the number of axis defined in the axes component
     *
     *  @return The number of axis
     */
    std::size_t size() const { return this->axis().size(); }

    /**
     *  @brief Return the axis with the given index
     *
     *  @param[in] index    the index of the axis to be retrieved
     *
     *  The order of the Axis in the Axes component corresponds to the order
     *  of the index attribute on the Axis instances.
     *
     *  An std::out_of_range exception will be thrown when the index is out of
     *  range.
     *
     *  @return The axis with the given index
     */
    const Axis& axis( unsigned int index ) const {

      return this->axis().at( index );
    }
  };

} // v1_9 namespace

/**
 *  @brief Convert a core GNDS node to a component
 *
 *  @param[in] core         the core GNDS node
 *  @param[in] component    the component
 */
void convert( const node& core, v1_9::Axes& component ) {

  component = v1_9::Axes( core );
}

/**
 *  @brief Convert a component to a core GNDS node
 *
 *  @param[in] component    the component
 *  @param[in] core         the core GNDS node
 */
void convert( const v1_9::Axes& component, node& core ) {

  core = component.node();
};

} // GNDStk namespace
} // njoy namespace

#endif
