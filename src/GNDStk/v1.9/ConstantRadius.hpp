#ifndef NJOY_GNDSTK_V1_9_CONSTANTRADIUS
#define NJOY_GNDSTK_V1_9_CONSTANTRADIUS

// system includes

// other includes
#include "GNDStk.hpp"
#include "GNDStk/units/Energy.hpp"
#include "GNDStk/units/Length.hpp"
#include "GNDStk/v1.9/Constant1D.hpp"

namespace njoy {
namespace GNDStk {
namespace v1_9 {

  /**
   *  @class
   *  @brief A constant scattering radius or channel radius
   *
   *  See GNDS v1.9 specifications section 19.1.1 and 19.1.2
   */
  class ConstantRadius : protected Constant1D {

    /* auxiliary functions */
    void verify() {

      // verify that the axis(0) is a length
      // verify that the axis(1) is an energy
    }

  public :

    /* constructors */

    /**
     *  @brief Default constructor (required for the core GNDS interface)
     */
    ConstantRadius() : Constant1D() {}

    /**
     *  @brief Constructor using a Constant1D (move semantics)
     *
     *  @param[in] constant    the Constant1D instance
     */
    ConstantRadius( Constant1D&& constant ) :
      Constant1D( std::move( constant ) ) {

      this->verify();
    }

    /**
     *  @brief Constructor
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    ConstantRadius( NodeType& core ) : Constant1D( core ) {

      this->verify();
    }

    /**
     *  @brief Constructor
     *
     *  @param[in] core    the core GNDS node that makes up the component
     */
    ConstantRadius( const NodeType& core ) : Constant1D( core ) {

      this->verify();
    }

    /**
     *  @brief Constructor
     *
     *  @param[in] label               the constant label
     *  @param[in] radius              the constant radius
     *  @param[in] energyMin           the minimum energy domain value
     *  @param[in] energyMax           the maximum energy domain value
     *  @param[in] radiusUnit          the radius unit (e.g. "fm")
     *  @param[in] energyUnit          the energy unit (e.g. "eV")
     */
    ConstantRadius( const std::string& label, double radius,
                    double energyMin, double energyMax,
                    units::Energy energyUnit = units::Energy::eV,
                    units::Length radiusUnit = units::Length::fm ) :
      ConstantRadius(
        Constant1D( label, radius, energyMin, energyMax,
                    "energy_in", "radius",
                    units::toString( energyUnit ),
                    units::toString( radiusUnit ) ) ) {}

    /* methods */

    using Constant1D::label;
    using Constant1D::constant;
    using Constant1D::domainMin;
    using Constant1D::domainMax;
    using Constant1D::axes;
    using Constant1D::node;

    /**
     *  @brief Return the radius value
     *
     *  @return The radius value
     */
    double radius() const { return this->constant(); }

    /**
     *  @brief Return the minimum energy domain value
     *
     *  @return The minimum energy domain value
     */
    double energyMin() const { return this->domainMin(); }

    /**
     *  @brief Return the maximum energy domain value
     *
     *  @return The maximum domain value
     */
    double energyMax() const { return this->domainMax(); }
  };

} // v1_9 namespace

/**
 *  @brief Convert a core GNDS node to a component
 *
 *  @param[in] core         the core GNDS node
 *  @param[in] component    the component
 */
void convert( const node& core, v1_9::ConstantRadius& component ) {

  // create the component
  component = v1_9::ConstantRadius( core );
}

/**
 *  @brief Convert a component to a core GNDS node
 *
 *  @param[in] component    the component
 *  @param[in] core         the core GNDS node
 */
void convert( const v1_9::ConstantRadius& component, node& core ) {

  core = component.node();
};

} // GNDStk namespace
} // njoy namespace

#endif
