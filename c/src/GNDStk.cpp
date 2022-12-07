
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

void color(const int value)
{
   njoy::GNDStk::color = bool(value);
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

// A function name of truncate (for access to our C++ [inline long truncate]
// variable) appears to conflict, here in our C language interface functions,
// with a truncate function in unistd.h. So, we'll give it a different name.
void truncation(const long value)
{
   njoy::GNDStk::truncate = value;
}

// ------------------------
// Re: GNDStk diagnostics
// ------------------------

void note(const int value)
{
   njoy::GNDStk::info = bool(value);
}

void warning(const int value)
{
   njoy::GNDStk::warning = bool(value);
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
