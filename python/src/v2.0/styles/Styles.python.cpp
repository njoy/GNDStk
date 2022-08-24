
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk/v2.0/styles/Styles.hpp"
#include "definitions.hpp"

// namespace aliases
namespace python = pybind11;

namespace python_v2_0 {
namespace python_styles {

// Styles wrapper
void wrapStyles(python::module &module)
{
   using namespace njoy::GNDStk;
   using namespace njoy::GNDStk::v2_0;

   // type aliases
   using Component = styles::Styles;

   // create the component
   python::class_<Component> component(
      module,
      "Styles",
      Component::documentation().data()
   );

   // wrap the component
   component
      .def(
         python::init<
            const std::optional<std::vector<styles::MonteCarlo_cdf>> &,
            const std::optional<std::vector<styles::SnElasticUpScatter>> &,
            const std::optional<std::vector<styles::URR_probabilityTables>> &,
            const std::optional<std::vector<styles::AngularDistributionReconstructed>> &,
            const std::optional<std::vector<styles::AverageProductData>> &,
            const std::optional<std::vector<styles::CrossSectionReconstructed>> &,
            const std::optional<std::vector<styles::Evaluated>> &,
            const std::optional<std::vector<styles::GriddedCrossSection>> &,
            const std::optional<std::vector<styles::Heated>> &,
            const std::optional<std::vector<styles::HeatedMultiGroup>> &
         >(),
         python::arg("monte_carlo_cdf") = std::nullopt,
         python::arg("sn_elastic_up_scatter") = std::nullopt,
         python::arg("urr_probability_tables") = std::nullopt,
         python::arg("angular_distribution_reconstructed") = std::nullopt,
         python::arg("average_product_data") = std::nullopt,
         python::arg("cross_section_reconstructed") = std::nullopt,
         python::arg("evaluated") = std::nullopt,
         python::arg("gridded_cross_section") = std::nullopt,
         python::arg("heated") = std::nullopt,
         python::arg("heated_multi_group") = std::nullopt,
         Component::documentation("constructor").data()
      )
      .def_property_readonly(
         "monte_carlo_cdf",
         python::overload_cast<>(&Component::MonteCarlo_cdf),
         Component::documentation("monte_carlo_cdf").data()
      )
      .def_property_readonly(
         "sn_elastic_up_scatter",
         python::overload_cast<>(&Component::SnElasticUpScatter),
         Component::documentation("sn_elastic_up_scatter").data()
      )
      .def_property_readonly(
         "urr_probability_tables",
         python::overload_cast<>(&Component::URR_probabilityTables),
         Component::documentation("urr_probability_tables").data()
      )
      .def_property_readonly(
         "angular_distribution_reconstructed",
         python::overload_cast<>(&Component::angularDistributionReconstructed),
         Component::documentation("angular_distribution_reconstructed").data()
      )
      .def_property_readonly(
         "average_product_data",
         python::overload_cast<>(&Component::averageProductData),
         Component::documentation("average_product_data").data()
      )
      .def_property_readonly(
         "cross_section_reconstructed",
         python::overload_cast<>(&Component::crossSectionReconstructed),
         Component::documentation("cross_section_reconstructed").data()
      )
      .def_property_readonly(
         "evaluated",
         python::overload_cast<>(&Component::evaluated),
         Component::documentation("evaluated").data()
      )
      .def_property_readonly(
         "gridded_cross_section",
         python::overload_cast<>(&Component::griddedCrossSection),
         Component::documentation("gridded_cross_section").data()
      )
      .def_property_readonly(
         "heated",
         python::overload_cast<>(&Component::heated),
         Component::documentation("heated").data()
      )
      .def_property_readonly(
         "heated_multi_group",
         python::overload_cast<>(&Component::heatedMultiGroup),
         Component::documentation("heated_multi_group").data()
      )
   ;

   // add standard component definitions
   addStandardComponentDefinitions< Component >( component );
}

} // namespace python_styles
} // namespace python_v2_0