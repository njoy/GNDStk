#ifndef NJOY_GNDSTK_V1_9_AXIS
#define NJOY_GNDSTK_V1_9_AXIS

// system includes
#include <optional>

// other includes
#include "GNDStk.hpp"
#include "GNDStk/enums/GridStyle.hpp"
#include "GNDStk/enums/Interpolation.hpp"
#include "GNDStk/v1.9/Component.hpp"
#include "GNDStk/v1.9/Values.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

  /**
   *  @class
   *  @brief A GNDS basic component: an grid with an index, label, style, values
   *         and optional unit
   *
   *  This component in used in the axes node, which in turn is used in most
   *  functional containers.
   *
   *  See GNDS v1.9 specifications section 5.1.3
   */
  class Grid : public Component {

    /* query object */
    static inline
    const auto query = unsigned{} / GNDStk::basic::index |
                       GNDStk::basic::label |
                       std::optional< std::string >{} / GNDStk::basic::unit |
                       std::optional< enums::Interpolation >{}
                           / GNDStk::basic::interpolation |
                       std::optional< enums::GridStyle >{}
                           / GNDStk::basic::interpolation |
                       GNDStk::basic::values;

    /* data fields */
    unsigned int index_;
    std::string label_;
    std::optional< std::string > unit_;
    enums::Interpolation interpolation_ = enums::Interpolation::linlin;
    enums::GridStyle style_ = enums::GridStyle::none;
    Values values_;

    /* auxiliary functions */
    void sync() {

      // verify the node name
      if ( this->node().name != "grid" ) {

        log::error( "Expected a \"grid\" node, found \"{}\" instead",
                    this->node().name );
        throw std::exception();
      }

      // extract the data
      bool found = false;
      auto tuple = this->node()( query, found );
      if ( !found ) {

        // the query did not work
        log::error( "Some or all of the required attributes and/or children for "
                    "the \"grid\" node are missing" );
        //!@todo print out the node content?
        throw std::exception();
      }
      else {

        // sync the component
        this->index_ = std::get< 0 >( tuple );
        this->label_ = std::get< 1 >( tuple );
        this->unit_ = std::get< 2 >( tuple );
        if ( std::get< 3 >( tuple ) ) {

          this->interpolation_ = std::get< 3 >( tuple ).value();
        }
        if ( std::get< 4 >( tuple ) ) {

          this->style_ = std::get< 4 >( tuple ).value();
        }
        this->values_ = std::move( Values( std::get< 5 >( tuple ) ) );
      }
    }

  public :

    /* constructors */

    /**
     *  @brief Default constructor (required for the core GNDS interface)
     */
    Grid() : Component() {}

    /**
     *  @brief Constructor
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Grid( NodeType& core ) : Component( core ) {

      this->sync();
    }

    /**
     *  @brief Constructor
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Grid( const NodeType& core ) : Component( core ) {

      this->sync();
    }

    /**
     *  @brief Full constructor with move semantics
     *
     *  @param[in] label    the axis label
     *  @param[in] index    the axis index
     *  @param[in] unit     the optional unit
     */
    Grid( unsigned int index, std::string&& label,
          std::optional< std::string >&& unit ) :
      Component(), index_( index ), label_( std::move( label ) ),
      unit_( std::move( unit ) ) {

      this->node().name = "grid";
      this->node().add( "index", this->index() );
      this->node().add( "interpolation", this->interpolation() );
      this->node().add( "label", this->label() );
      this->node().add( "style", this->style() );
      if ( this->unit() ) {

        this->node().add( "unit", this->unit().value() );
      };
    }

    /**
     *  @brief Convenience constructor
     *
     *  @param[in] label    the axis label
     *  @param[in] index    the axis index
     */
    Grid( unsigned int index, const std::string& label ) :
      Grid( index, std::string( label ), std::nullopt ) {}

    /**
     *  @brief Convenience constructor
     *
     *  @param[in] label    the axis label
     *  @param[in] index    the axis index
     *  @param[in] unit     the axis unit
     */
    Grid( unsigned int index, const std::string& label,
          const std::string& unit ) :
      Grid( index, std::string( label ), std::make_optional( unit ) ) {}

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
void convert( const node& core, v1_9::Grid& component ) {

  component = v1_9::Grid( core );
}

/**
 *  @brief Convert a component to a core GNDS node
 *
 *  @param[in] component    the component
 *  @param[in] core         the core GNDS node
 */
void convert( const v1_9::Grid& component, node& core ) {

  core = component.node();
};

} // GNDStk namespace
} // njoy namespace

#endif
