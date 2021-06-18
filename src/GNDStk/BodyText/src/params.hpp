
// -----------------------------------------------------------------------------
// length, start, valueType
// We place these into a struct so that our setters, defined elsewhere,
// can use the above names themselves.
// -----------------------------------------------------------------------------

/*
Quoted from the official JSON specification files for GNDS:

length
   The total number of data values including leading and trailing zero
   values that are not stored. This attribute should only be used when
   the sum of start and the number of listed values do not add to the
   total number of data values. This should only happen when there are
   trailing zeros not listed in the body text.

start
   default: 0
   For start = N, the first N values are zero and are not stored.

valueType
   Specifies the type of data in the body (e.g., Integer32, Float64).
   Only one type of data can be stored in each instance of a values node.
*/

struct {
   // Any of these might or might not have appeared in a particular node
   // that had body text, but we handle them all here, and have defaults
   std::size_t length = 0;
   std::size_t start = 0;
   std::string valueType = "";
} vars;
