#ifndef NJOY_GNDSTK_V1_9_AXES
#define NJOY_GNDSTK_V1_9_AXES

// system includes
#include <memory>

// other includes
#include "GNDStk.hpp"
#include "GNDStk/v1.9/Axis.hpp"

namespace njoy {
namespace GNDStk {

/* forward declaration of the component and convert functions */
namespace v1_9 { class Axes; }
void convert( const node&, v1_9::Axes& );
void convert( const v1_9::Axes&, node& );

namespace v1_9 {

  /**
   *  @class
   *  @brief A GNDS basic component: an axes element with multiple axis
   *
   *  This component in used in most functional containers (e.g. Constant1D or
   *  XYs1D).
   *
   *  See GNDS v1.9 specifications section 5.1.1
   */
  class Axes {

    /* type aliases */
    using NodeType = GNDStk::node;

    /* fields */
    std::vector< Axis > axes_;

    /* auxiliary functions */
    static NodeType makeNode( const Axes& component ) {

      NodeType core;
      convert( component, core );
      return core;
    }

    static Axes fromNode( const NodeType& core ) {

      Axes component;
      convert( core, component );
      return component;
    }

    void sort() {

      std::sort( this->axes_.begin(), this->axes_.end(),
                 [] ( const auto& left, const auto& right )
                    { return left.index() < right.index(); } );
    }

  public :

    /* constructors */

    /**
     *  @brief Default constructor (required for the core GNDS interface)
     */
    Axes() = default;

    /**
     *  @brief Constructor to initialise the component using a core GNDS node
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Axes( NodeType core ) : Axes( fromNode( core ) ) {}

    /**
     *  @brief Constructor to initialise the component using its data (copy
     *         semantics)
     *
     *  The axis in the vector need not be given in order, they will be sorted
     *  by index as required.
     *
     *  @param[in] axes    the axes
     */
    Axes( const std::vector< Axis >& axes ) : axes_( axes ) {

      this->sort();
    }

    /**
     *  @brief Constructor to initialise the component using its data (move
     *         semantics)
     *
     *  The axis in the vector need not be given in order, they will be sorted
     *  by index as required.
     *
     *  @param[in] axes    the axes
     */
    Axes( std::vector< Axis >&& axes ) : axes_( std::move( axes ) ) {

      this->sort();
    }

    /* methods */

    /**
     *  @brief Retrieve the axes
     *
     *  The order of the axis in the vector will correspond to the order of the
     *  index attribute on the Axis instances.
     *
     *  @return The axis in the component
     */
    const std::vector< Axis >& axes() const { return this->axes_; }

    /**
     *  @brief Return the number of axis defined in the axes component
     *
     *  @return The number of axis
     */
    auto size() const { return this->axes().size(); }

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

      return this->axes().at( index );
    }

    /**
     *  @brief Retrieve a core GNDS node for this component
     *
     *  @return The core GNDS node constructed from the component
     */
    NodeType node() const { return makeNode( *this ); }
  };

} // v1_9 namespace

/**
 *  @brief Convert a core GNDS node to a component
 *
 *  @param[in] core         the core GNDS node
 *  @param[in] component    the component
 */
void convert( const node& core, v1_9::Axes& component ) {

  // verify the node name
  if ( core.name != "axes" ) {
    log::error( "Expected an \"axes\" node, found \"{}\" instead", core.name );
    throw std::exception();
  }

  // verify required attributes and children
  if ( !core.has( GNDStk::basic::axis ) ) {

    log::error( "Some or all of the required attributes and/or children for "
                "the \"axes\" node are missing"  );
    throw std::exception();
  }

  // create the component
  component = v1_9::Axes( core( v1_9::Axis{} / GNDStk::basic::axis ) );
}
/**
 *  @brief Convert a component to a core GNDS node
 *
 *  @param[in] component    the component
 *  @param[in] core         the core GNDS node
 */
void convert( const v1_9::Axes& component, node& core ) {

  // axis need to be printed in reverse index order

  auto begin = component.axes().rbegin();
  auto end = component.axes().rend();

  core.name = "axes";
  for ( auto iter = begin; iter != end; ++iter ) {

    core.add( "axis" ) = iter->node();
  }
};

} // GNDStk namespace
} // njoy namespace

#endif
