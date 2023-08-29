
// For e.g. uint32_t, which is used in pybind11.h. A recent attempted build
// with g++ reported that std::uint32_t wasn't a known type, which suggests
// that pybind11.h doesn't #include everything it should.
#include <cstdint>

// system includes
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

// local includes
#include "GNDStk.hpp"

// namespace aliases
namespace python = pybind11;


// -----------------------------------------------------------------------------
// macros
// -----------------------------------------------------------------------------

// NJOY_GNDSTK_PROPERTY
#define NJOY_GNDSTK_PROPERTY(class,pyname,cppvar) \
class.def_property_static( \
   #pyname, \
   [](python::object) \
   { \
      return cppvar; \
   }, \
   [](python::object, const std::decay_t<decltype(cppvar)> &value) \
   { \
      cppvar = value; \
   } \
)

// NJOY_GNDSTK_COLOR
#define NJOY_GNDSTK_COLOR(class,pyname,cppvar) \
class.def_property_static( \
   #pyname, \
   [](python::object) \
   { \
      return cppvar; \
   }, \
   [](python::object, const std::array<int,3> &rgb) \
   { \
      cppvar = njoy::GNDStk::color::makeColor(rgb[0],rgb[1],rgb[2]); \
   } \
);


// -----------------------------------------------------------------------------
// core interface declarations
// -----------------------------------------------------------------------------

namespace python_core {
   void wrapNode( python::module& );

   /*
   zzz probably remove
   void wrapBoundaryCondition( python::module& );
   void wrapContributorType( python::module& );
   void wrapDateType( python::module& );
   void wrapDecayType( python::module& );
   void wrapEncoding( python::module& );
   void wrapEnergy( python::module& );
   void wrapFrame( python::module& );
   void wrapGridStyle( python::module& );
   void wrapHashAlgorithm( python::module& );
   void wrapInteraction( python::module& );
   void wrapInterpolation( python::module& );
   void wrapInterpolationQualifier( python::module& );
   void wrapLength( python::module& );
   void wrapParity( python::module& );
   void wrapRelationType( python::module& );
   void wrapStorageOrder( python::module& );
   */
}


// -----------------------------------------------------------------------------
// v2.0 interface declarations
// -----------------------------------------------------------------------------

namespace python_GNDS {
   void wrapV2_0( python::module& );
}


// -----------------------------------------------------------------------------
// Submodule: settings
// -----------------------------------------------------------------------------

void submodule_settings(python::module &gnds)
{
   python::module settings = gnds.def_submodule(
      "settings",
      "Global behavioral settings"
   );

   // ------------------------
   // Module: settings
   // Class:  read
   // ------------------------

   struct Read { };
   python::class_<Read> read(settings,"read");

   NJOY_GNDSTK_PROPERTY(read, threads, njoy::GNDStk::threads);

   // ------------------------
   // Module: settings
   // Class:  write
   // ------------------------

   struct Write { };
   python::class_<Write> write(settings,"write");

   NJOY_GNDSTK_PROPERTY(write, comments, njoy::GNDStk::comments);
   NJOY_GNDSTK_PROPERTY(write, indent,   njoy::GNDStk::indent  );
   NJOY_GNDSTK_PROPERTY(write, align,    njoy::GNDStk::align   );
   NJOY_GNDSTK_PROPERTY(write, columns,  njoy::GNDStk::columns );
   NJOY_GNDSTK_PROPERTY(write, elements, njoy::GNDStk::elements);
   NJOY_GNDSTK_PROPERTY(write, colors,   njoy::GNDStk::colors  );
   NJOY_GNDSTK_PROPERTY(write, shades,   njoy::GNDStk::shades  );

   // ------------------------
   // Module: settings
   // Class:  report
   // ------------------------

   struct Report { };
   python::class_<Report> report(settings,"report");

   NJOY_GNDSTK_PROPERTY(report, notes,    njoy::GNDStk::notes);
   NJOY_GNDSTK_PROPERTY(report, warnings, njoy::GNDStk::warnings);
   NJOY_GNDSTK_PROPERTY(report, context,  njoy::GNDStk::context);
   NJOY_GNDSTK_PROPERTY(report, debug,    njoy::GNDStk::debug);

   // ------------------------
   // Module: settings
   // Class:  sort
   // ------------------------

   struct Sort { };
   python::class_<Sort> sort(settings,"sort");

   NJOY_GNDSTK_PROPERTY(sort, fields, njoy::GNDStk::sort);
}


// -----------------------------------------------------------------------------
// Submodule: colors
// -----------------------------------------------------------------------------

void submodule_colors(python::module &gnds)
{
   python::module colors = gnds.def_submodule(
      "colors",
      "Colors for diagnostics and printing"
   );

   // ------------------------
   // Module: colors
   // Class:  required
   // ------------------------

   struct Required { };
   python::class_<Required> required(colors,"required");

   NJOY_GNDSTK_COLOR(required, field,   njoy::GNDStk::color::field);
   NJOY_GNDSTK_COLOR(required, vector,  njoy::GNDStk::color::vector);
   NJOY_GNDSTK_COLOR(required, label,   njoy::GNDStk::color::label);
   NJOY_GNDSTK_COLOR(required, value,   njoy::GNDStk::color::value);
   NJOY_GNDSTK_COLOR(required, comment, njoy::GNDStk::color::comment);

   // ------------------------
   // Module: colors
   // Class:  optional
   // ------------------------

   struct Optional { };
   python::class_<Optional> optional(colors,"optional");

   NJOY_GNDSTK_COLOR(optional, field,  njoy::GNDStk::color::optional::field);
   NJOY_GNDSTK_COLOR(optional, vector, njoy::GNDStk::color::optional::vector);
   NJOY_GNDSTK_COLOR(optional, label,  njoy::GNDStk::color::optional::label);
   NJOY_GNDSTK_COLOR(optional, value,  njoy::GNDStk::color::optional::value);

   // ------------------------
   // Module: colors
   // Class:  data
   // ------------------------

   struct Data { };
   python::class_<Data> data(colors,"data");

   NJOY_GNDSTK_COLOR(data, string, njoy::GNDStk::color::data::string);
   NJOY_GNDSTK_COLOR(data, vector, njoy::GNDStk::color::data::vector);
}


// -----------------------------------------------------------------------------
// Submodule: format
// -----------------------------------------------------------------------------

void submodule_format(python::module &gnds)
{
   // todo
   /*
   python::module format = gnds.def_submodule(
      "format",
      "Properties related to input/output (mostly output) formatting,\n"
      "in particular (but not exclusively) for floating-point numbers"
   );

   // ------------------------
   // Module: format
   // Class:  todo
   // ------------------------

   struct Todo { };
   python::class_<Todo> todo(format,"todo");

   NJOY_GNDSTK_COLOR(todo, field,   njoy::GNDStk::color::field);
   NJOY_GNDSTK_COLOR(todo, vector,  njoy::GNDStk::color::vector);
   NJOY_GNDSTK_COLOR(todo, label,   njoy::GNDStk::color::label);
   NJOY_GNDSTK_COLOR(todo, value,   njoy::GNDStk::color::value);
   NJOY_GNDSTK_COLOR(todo, comment, njoy::GNDStk::color::comment);
   */
}


// -----------------------------------------------------------------------------
// GNDStk python bindings
// -----------------------------------------------------------------------------

/**
 *  @brief GNDStk python bindings
 *
 *  The name given here (GNDStk) must be the same as the name
 *  set on the PROPERTIES OUTPUT_NAME in the CMakeLists.txt file.
 */

PYBIND11_MODULE(GNDStk,module)
{
   // ------------------------
   // Submodule: core
   // ------------------------

   python::module core = module.def_submodule(
      "core",
      "core - GNDStk core interface components"
   );

   // wrap core components (in the core module)
   python_core::wrapNode(core);

   /*
   zzz probably remove
   // enumerations (in the GNDStk module)
   python_core::wrapBoundaryCondition(module);
   python_core::wrapContributorType(module);
   python_core::wrapDateType(module);
   python_core::wrapDecayType(module);
   python_core::wrapEncoding(module);
   python_core::wrapEnergy(module);
   python_core::wrapFrame(module);
   python_core::wrapGridStyle(module);
   python_core::wrapHashAlgorithm(module);
   python_core::wrapInteraction(module);
   python_core::wrapInterpolation(module);
   python_core::wrapInterpolationQualifier(module);
   python_core::wrapLength(module);
   python_core::wrapParity(module);
   python_core::wrapRelationType(module);
   python_core::wrapStorageOrder(module);
   */

   // v2.0 components (in the v2_0 module, created in this function)
   python_GNDS::wrapV2_0(module);

   // Submodules
   submodule_settings(module);
   submodule_colors(module);
   submodule_format(module);
}

#undef NJOY_GNDSTK_PROPERTY
#undef NJOY_GNDSTK_COLOR
