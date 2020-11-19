#ifndef NJOY_GNDSTK_V1_9_AXIS
#define NJOY_GNDSTK_V1_9_AXIS

// system includes
#include <optional>

// other includes
#include "GNDStk.hpp"
#include "GNDStk/v1.9/Component.hpp"

namespace njoy {
namespace GNDStk {

/* forward declaration of the component and convert functions */
namespace v1_9 { class Axis; }
void convert( const node&, v1_9::Axis& );
void convert( const v1_9::Axis&, node& );

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
  class Axis : public Component< Axis > {

    /* type aliases */
    using NodeType = GNDStk::node;

    /* fields */
    unsigned int index_;                                // required
    std::string label_;                                 // required
    std::optional< std::string > unit_ = std::nullopt;  // optional, no default

    /* auxiliary functions */

  public :

    /* constructors */

    /**
     *  @brief Default constructor (required for the core GNDS interface)
     */
    Axis() = default;

    /**
     *  @brief Constructor to initialise the component using a core GNDS node
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Axis( const NodeType& core ) : Axis( Component::fromNode( core ) ) {}

    /**
     *  @brief Full constructor with move semantics
     *
     *  @param[in] label    the axis label
     *  @param[in] index    the axis index
     *  @param[in] unit     the optional unit
     */
    Axis( unsigned int index, std::string&& label,
          std::optional< std::string >&& unit ) :
      index_( index ), label_( std::move( label ) ),
      unit_( std::move( unit ) ) {}

    /**
     *  @brief Full constructor with copy semantics
     *
     *  @param[in] label    the axis label
     *  @param[in] index    the axis index
     *  @param[in] unit     the optional unit
     */
    Axis( unsigned int index, const std::string& label,
          const std::optional< std::string >& unit ) :
      Axis( index, std::string( label ),
            std::optional< std::string >( unit ) ) {}

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

  using namespace GNDStk::basic;

  // verify the node name
  if ( core.name != "axis" ) {

    log::error( "Expected an \"axis\" node, found \"{}\" instead", core.name );
    throw std::exception();
  }

  // verify required attributes and children
  if ( !core.has( index ) || !core.has( label ) ) {

    log::error( "Some or all of the required attributes and/or children for "
                "the \"axis\" node are missing"  );
    throw std::exception();
  }

  // create the component
  component = v1_9::Axis( core( unsigned{} / index ),
                          core( std::string{} / label ),
                          core.has( unit )
                            ? std::make_optional( core( unit ) )
                            : std::nullopt );
}

/**
 *  @brief Convert a component to a core GNDS node
 *
 *  @param[in] component    the component
 *  @param[in] core         the core GNDS node
 */
void convert( const v1_9::Axis& component, node& core ) {

  core.name = "axis";
  core.add( "index", component.index() );
  core.add( "label", component.label() );
  if ( component.unit() ) {

    core.add( "unit", component.unit().value() );
  }
};

} // GNDStk namespace
} // njoy namespace

#endif
