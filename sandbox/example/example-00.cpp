
#include "gnds.hpp"

// We'll just include the main gnds header file here, and then compile this
// source file as part of all the others. This is a way to ensure that our
// supposedly header-only library works correctly as header-only, insofar as
// it doesn't have any constructs that cause multiply-defined symbol errors.
