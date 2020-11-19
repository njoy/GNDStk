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

/* forward declaration of the component and convert functions */
namespace v1_9 { class Constant1D; }
void convert( const node&, v1_9::Constant1D& );
void convert( const v1_9::Constant1D&, node& );

namespace v1_9 {

  /**
   *  @class
   *  @brief A GNDS functional container: a constant value
   *
   *  See GNDS v1.9 specifications section 6.2.3
   */
  class Constant1D : public Component< Constant1D > {

    /* type aliases */
    using NodeType = GNDStk::node;

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

  public :

    /* constructors */

    /**
     *  @brief Default constructor (required for the core GNDS interface)
     */
    Constant1D() = default;

    /**
     *  @brief Constructor to initialise the component using a core GNDS node
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    Constant1D( const NodeType& core ) :
      Constant1D( Component::fromNode( core ) ) {

      this->verify();
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
                const std::string& constantLabel, const std::string& domainLabel,
                const std::string& constantUnit, const std::string& domainUnit ) :
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

  using namespace GNDStk::basic;

  // verify the node name
  if ( core.name != "constant1d" ) {

    log::error( "Expected a \"constant1d\" node, found \"{}\" instead", core.name );
    throw std::exception();
  }

  // verify required attributes and children
  if ( !core.has( label ) || !core.has( constant ) ||
       !core.has( domainMin ) || !core.has( domainMax ) ||
       !core.has( axes ) ) {

    log::error( "Some or all of the required attributes and/or children for "
                "the \"constant1d\" node are missing"  );
    throw std::exception();
  }

  // create the component
  component = v1_9::Constant1D(
                  core( std::string{} / label ),
                  core( double{} / constant ),
                  core( double{} / domainMin ),
                  core( double{} / domainMax ),
                  core.has( outerDomainValue )
                    ? std::make_optional( core( double{} / outerDomainValue ) )
                    : std::nullopt,
                  core( v1_9::Axes{} / axes ) );
}
/**
 *  @brief Convert a component to a core GNDS node
 *
 *  @param[in] component    the component
 *  @param[in] core         the core GNDS node
 */
void convert( const v1_9::Constant1D& component, node& core ) {

  core.name = "constant1d";
  core.add( "label", component.label() );
  core.add( "constant", component.constant() );
  core.add( "domainMin", component.domainMin() );
  core.add( "domainMax", component.domainMax() );
  if ( component.outerDomainValue() ) {

    core.add( "outerDomainValue", component.outerDomainValue().value() );
  }
  core.add( "axes" ) = component.axes().node();
};

} // GNDStk namespace
} // njoy namespace

#endif
