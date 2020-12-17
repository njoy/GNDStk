#ifndef NJOY_GNDSTK_V1_9_CONSTANT1D
#define NJOY_GNDSTK_V1_9_CONSTANT1D

// system includes
#include <optional>

// other includes
#include "GNDStk.hpp"
#include "GNDStk/v1.9/Component.hpp"
#include "GNDStk/v1.9/Axes.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

  /**
   *  @class
   *  @brief A GNDS functional container: a constant value
   *
   *  See GNDS v1.9 specifications section 6.2.3
   */
  class Constant1D : public Component {

    /* query object */
    static inline const auto query = (

      GNDStk::basic::label |
      double{} / GNDStk::basic::constant |
      double{} / GNDStk::basic::domainMin |
      double{} / GNDStk::basic::domainMax |
      // placeholder till std::optional is available
      // std::optional< double >{} / GNDStk::basic::outerDomainValue |
      double{} / GNDStk::basic::domainMax |
      GNDStk::basic::axes
    );

    /* fields */
    std::string label_;
    double constant_;
    double min_;
    double max_;
    std::optional< double > outer_ = std::nullopt;  // optional, no default
    Axes axes_;

    /* auxiliary functions */
    void verify() {

      if ( this->axes().size() != 2 ) {

        log::error( "Expected 2 \"axis\" nodes for a \"constant1d\" node" );
        log::info( "Found: {}", this->axes().size() );
        throw std::exception();
      }
    }

    void sync() {

      // verify the node name
      if ( this->node().name != "constant1d" ) {

        log::error( "Expected a \"constant1d\" node, found \"{}\" instead",
                    this->node().name );
        throw std::exception();
      }

      // extract the data
      bool found = false;
      auto tuple = this->node()( query, found );
      if ( !found ) {

        // the query did not work
        log::error( "Some or all of the required attributes and/or children for "
                    "the \"constant1d\" node are missing"  );
        //!@todo print out the node content?
        throw std::exception();
      }
      else {

        // sync the component
        this->label_ = std::get< 0 >( tuple );
        this->constant_ = std::get< 1 >( tuple );
        this->min_ = std::get< 2 >( tuple );
        this->max_ = std::get< 3 >( tuple );
        // placeholder till std::optional is available
        // this->outer_ = std::get< 4 >( tuple );
        this->outer_ = this->node().has( GNDStk::basic::outerDomainValue )
                           ? std::make_optional( this->node()( double{} / GNDStk::basic::outerDomainValue ) )
                           : std::nullopt;
        this->axes_ = std::move( Axes( std::get< 5 >( tuple ) ) );
      }

      // perform verification
      this->verify();
    }

  public :

    /* constructors */

    /**
     *  @brief Default constructor (required for the core GNDS interface)
     */
    Constant1D() : Component() {}

    /**
     *  @brief Constructor
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Constant1D( NodeType& core ) : Component( core ) {

      this->sync();
    }

    /**
     *  @brief Constructor
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Constant1D( const NodeType& core ) : Component( core ) {

      this->sync();
    }

    /**
     *  @brief Full constructor with move semantics
     *
     *  @param[in] label               the constant label
     *  @param[in] constant            the constant value
     *  @param[in] domainMin           the minimum domain value
     *  @param[in] domainMax           the maximum domain value
     *  @param[in] outerDomainValue    the optional outer domain value
     *  @param[in] axes                the axes of the constant
     */
    Constant1D( std::string&& label, double constant, double domainMin,
                double domainMax, std::optional< double >&& outerDomainValue,
                Axes&& axes ) :
      label_( std::move( label ) ), constant_( constant ), min_( domainMin ),
      max_( domainMax ), outer_( std::move( outerDomainValue ) ),
      axes_( std::move( axes ) ) {

      this->verify();

      this->node().name = "constant1d";
      this->node().add( "label", this->label_ );
      this->node().add( "constant", this->constant_ );
      this->node().add( "domainMin", this->min_ );
      this->node().add( "domainMax", this->max_ );
      if ( this->outerDomainValue() ) {

        this->node().add( "outerDomainValue", this->outer_.value() );
      };
      this->node().add( "axes" ) = this->axes_.node();
    }

    /**
     *  @brief Full constructor with copy semantics
     *
     *  @param[in] label               the constant label
     *  @param[in] constant            the constant value
     *  @param[in] domainMin           the minimum domain value
     *  @param[in] domainMax           the maximum domain value
     *  @param[in] outerDomainValue    the optional outer domain value
     *  @param[in] axes                the axes of the constant
     */
    Constant1D( const std::string& label, double constant, double domainMin,
                double domainMax, const std::optional< double >& outerDomainValue,
                const Axes& axes ) :
      Constant1D( std::string( label ), constant, domainMin, domainMax,
                  std::optional< double >( outerDomainValue ), Axes( axes ) ) {}

    /**
     *  @brief Convenience constructor
     *
     *  @param[in] label               the constant label
     *  @param[in] constant            the constant value
     *  @param[in] domainMin           the minimum domain value
     *  @param[in] domainMax           the maximum domain value
     *  @param[in] constantLabel       the constant axis label
     *  @param[in] domainlabel         the domain axis label
     *  @param[in] constantUnit        the constant axis unit
     *  @param[in] domainUnit          the domain axis unit
     */
    Constant1D( const std::string& label, double constant,
                double domainMin, double domainMax,
                const std::string& domainLabel, const std::string& constantLabel,
                const std::string& domainUnit, const std::string& constantUnit ) :
      Constant1D( std::string( label ), constant, domainMin, domainMax, std::nullopt,
                  Axes( { Axis( 0, constantLabel, constantUnit ),
                          Axis( 1, domainLabel, domainUnit ) } ) ) {}

    /* methods */

    /**
     *  @brief Retrieve the label
     *
     *  @return The label of the constant
     */
    const std::string& label() const { return this->label_; }

    /**
     *  @brief Return the constant value
     *
     *  @return The constant value
     */
    double constant() const { return this->constant_; }

    /**
     *  @brief Return the minimum domain value
     *
     *  @return The minimum domain value
     */
    double domainMin() const { return this->min_; }

    /**
     *  @brief Return the maximum domain value
     *
     *  @return The maximum domain value
     */
    double domainMax() const { return this->max_; }

    /**
     *  @brief Return the optional outer domain value
     *
     *  @return The optional outer domain value
     */
    const std::optional< double >& outerDomainValue() const {

      return this->outer_;
    }

    /**
     *  @brief Return the axes
     *
     *  @return The axes of the constant
     */
    const Axes& axes() const { return this->axes_; }
  };

} // v1_9 namespace

/**
 *  @brief Convert a core GNDS node to a component
 *
 *  @param[in] core         the core GNDS node
 *  @param[in] component    the component
 */
void convert( const node& core, v1_9::Constant1D& component ) {

  component = v1_9::Constant1D( core );
}

/**
 *  @brief Convert a component to a core GNDS node
 *
 *  @param[in] component    the component
 *  @param[in] core         the core GNDS node
 */
void convert( const v1_9::Constant1D& component, node& core ) {

  core = component.node();
};

} // GNDStk namespace
} // njoy namespace

#endif
