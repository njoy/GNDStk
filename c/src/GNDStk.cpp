
// -----------------------------------------------------------------------------
// Interface for C
// Definitions
// -----------------------------------------------------------------------------

#include "GNDStk.h"


// -----------------------------------------------------------------------------
// Some basic flags
// In C++, these are available via inline variables.
// For C, we make them functions.
// -----------------------------------------------------------------------------

// ------------------------
// General
// ------------------------

void indent(const int value)
{
   njoy::GNDStk::indent = value;
}

void align(const int value)
{
   njoy::GNDStk::align = bool(value);
}

void colors(const int value)
{
   njoy::GNDStk::colors = bool(value);
}

// ------------------------
// Re: Component printing
// ------------------------

void comments(const int value)
{
   njoy::GNDStk::comments = bool(value);
}

void columns(const long value)
{
   njoy::GNDStk::columns = value;
}

void elements(const long value)
{
   njoy::GNDStk::elements = value;
}

// ------------------------
// Re: GNDStk diagnostics
// ------------------------

void notes(const int value)
{
   njoy::GNDStk::notes = bool(value);
}

void warnings(const int value)
{
   njoy::GNDStk::warnings = bool(value);
}

void debug(const int value)
{
   njoy::GNDStk::debug = bool(value);
}

void context(const int value)
{
   njoy::GNDStk::context = bool(value);
}

// ------------------------
// Re: OpenMP
// ------------------------

void threads(const int value)
{
   njoy::GNDStk::threads = value;
}
