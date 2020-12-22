#ifndef NJOY_GNDSTK_V1_9_VALUES
#define NJOY_GNDSTK_V1_9_VALUES

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
   *  @brief A GNDS basic component: a list of values
   *
   *  This component is used in the nodes like XYs1D or the grid node.
   *
   *  See GNDS v1.9 specifications section 5.2.1
   */
  template < typename T,
             typename = typename std::enable_if< std::is_arithmetic< T >::value, T >::type >
  class Values : public Component {

    //! @todo all metadata of the values node have to be present, for now

    /* query object */
    static inline
    const auto query = std::optional< std::string >{} / GNDStk::basic::valueType |
                       std::optional< unsigned >{} / GNDStk::basic::start |
                       std::optional< unsigned >{} / GNDStk::basic::length;

    /* data fields */
    std::vector< T > values_;            // required
    std::string value_type_ = "Float64"; // optional, default = Float64
    unsigned int start_ = 0;             // optional, default = 0
    unsigned int length_;                // optional, required if start != 0

    /* auxiliary functions */
    void sync() {

      // verify the node name
      if ( this->node().name != "values" ) {

        log::error( "Expected a \"values\" node, found \"{}\" instead",
                    this->node().name );
        throw std::exception();
      }

      // extract the data
      bool found = false;
      auto tuple = this->node()( query, found );
      if ( !found ) {

        // the query did not work
        log::error( "Some or all of the required attributes and/or children for "
                    "the \"values\" node are missing"  );
        //!@todo print out the node content?
        throw std::exception();
      }
      else {

        // sync the component
        detail::convert_pcdata_text_t{}( this->node(), this->values_ );
        if ( std::get< 0 >( tuple ) ) {

          this->value_type_ = std::get< 0 >( tuple ).value();
        }
        if ( std::get< 1 >( tuple ) ) {

          this->start_ = std::get< 1 >( tuple ).value();
        }
        this->length_ = this->values().size() + this->start();
        if ( std::get< 2 >( tuple ) ) {

          unsigned int length = std::get< 2 >( tuple ).value();
          if ( this->length() != length ) {

            log::error( "Inconsistent size for \"values\" array" );
            log::info( "start: {}", this->start() );
            log::info( "number values: {}", this->values().size() );
            log::info( "derived length: {}", this->length() );
            log::info( "found length: {}", length );
            throw std::exception();
          }
        }
      }
    }

  public :

    /* constructors */

    /**
     *  @brief Default constructor (required for the core GNDS interface)
     */
    Values() : Component() {}

    /**
     *  @brief Constructor
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Values( NodeType& core ) : Component( core ) {

      this->sync();
    }

    /**
     *  @brief Constructor
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Values( const NodeType& core ) : Component( core ) {

      this->sync();
    }

    /**
     *  @brief Full constructor with move semantics
     *
     *  @param[in] values       the values array
     *  @param[in] start        the starting index of the values
     *  @param[in] valueType    the value type of the array
     */
    Values( std::vector< T >&& values,
            unsigned int start = 0 ) :
      values_( std::move( values ) ), start_( start ) {

      this->length_ = this->values().size() + this->start();

      std::ostringstream out;
      for ( unsigned int i = 0; i < this->length() - 1; ++i ) {

        out << this->values()[i] << ' ';
      }
      out << this->values().back();

      this->node().name = "values";
      detail::set_pcdata_text( this->node() ) = out.str();
      this->node().add( "valueType", this->valueType() );
      this->node().add( "start", this->start() );
      this->node().add( "length", this->length() );
    }

    /* methods */

    /**
     *  @brief Retrieve the label of the axis
     *
     *  @return The label of the axis
     */
    const std::string& valueType() const { return this->value_type_; }

    /**
     *  @brief Retrieve the starting index of the values
     *
     *  @return The starting index
     */
    unsigned int start() const { return this->start_; }

    /**
     *  @brief Retrieve the length of the values
     *
     *  @return The length of the values
     */
    unsigned int length() const { return this->length_; }

    /**
     *  @brief Retrieve the length of the values
     *
     *  @return The length of the values
     */
    const std::vector< T >& values() const { return this->values_; }
  };

} // v1_9 namespace

/**
 *  @brief Convert a core GNDS node to a component
 *
 *  @param[in] core         the core GNDS node
 *  @param[in] component    the component
 */
template < typename T,
           typename = typename std::enable_if< std::is_arithmetic< T >::value, T >::type >
void convert( const node& core, v1_9::Values< T >& component ) {

  component = v1_9::Values< T >( core );
}

/**
 *  @brief Convert a component to a core GNDS node
 *
 *  @param[in] component    the component
 *  @param[in] core         the core GNDS node
 */
template < typename T,
           typename = typename std::enable_if< std::is_arithmetic< T >::value, T >::type >
void convert( const v1_9::Values< T >& component, node& core ) {

  core = component.node();
}

} // GNDStk namespace
} // njoy namespace

#endif
