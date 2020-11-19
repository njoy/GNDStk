#ifndef NJOY_GNDSTK_V1_9
#define NJOY_GNDSTK_V1_9

// GNDStk provides a number of convenience types and classes corresponding to
// the GNDS 1.9 standard. These can be used together with the core interface
// to quickly extract data from an existing GNDS 1.9 file or even build
// entire GNDS 1.9 hierarchies from scratch.
//
// Example 1: extracting a constant scattering radius value, corresponding to
//            the evaluated style using the generic Constant1D container
//
// using GNDStk::basic;
// using GNDStk::v1_9;
//
// auto filter = [] ( const auto& node ) { return node( label ) == "eval"; };
//
// Tree<> tree( "n-094_Pu_239.xml" );
// auto top = tree.top();
// auto radius = top( Constant1D{}
//                    / reactionSuite, resonances, scatteringRadius, constant1d,
//                    filter );
//
// Example 2: creating a constant scattering radius value, corresponding to
//            the evaluated style
//
// using GNDStk::v1_9;
//
// auto radius = Constant1D( "eval", 9.41, 1e-5, 30000.,
//                           "fm", "eV", "radius", "energy_in" );
// auto node = radius.node();
//
// When written in XML, this node would result in the following GNDS XML:
//   <constant1d label="eval" constant="9.41" domainMin="1e-5" domainMax="3e4">
//     <axes>
//       <axis index="1" label="energy_in" unit="eV"/>
//       <axis index="0" label="radius" unit="fm"/></axes></constant1d>

// Array-like container nodes - GNDS 1.9 specifications chapter 5
#include "GNDStk/v1.9/Axis.hpp"
#include "GNDStk/v1.9/Axes.hpp"

// Functional container nodes - GNDS 1.9 specifications chapter 6
#include "GNDStk/v1.9/Constant1D.hpp"

// Resonance nodes - GNDS 1.9 specifications chapter 19
#include "GNDStk/v1.9/ConstantRadius.hpp"

#endif
