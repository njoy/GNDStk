
// -----------------------------------------------------------------------------
// length, start, valueType
// We place these into a struct so our setters can use the names themselves.
// -----------------------------------------------------------------------------

/*
Quoted [slightly edited] from the official JSON specification files for GNDS:

   length
      The total number of data values including leading and trailing zero
      values that are not stored. This attribute should only be used when
      the sum of start and the number of listed values do not add to the
      total number of data values. This should only happen when there are
      trailing zeros not listed in the body text.

   start
      Default: 0
      For start = N, the first N values are zero and are not stored.

   valueType
      Specifies the type of data in the body (e.g., "Integer32", "Float64").
      Only one type of data can be stored in each instance of a values node.

In some places, e.g. the JSON-format GNDS spec files, these are listed in
a different order: valueType, start, length. Ordering doesn't really matter.
We'll just note, here, that throughout our code, we'll use the length, start,
valueType ordering, to be consistent with the (alphabetical) ordering that
our GNDS Standard Interface code autogeneration tool produces.
*/

private:

// toNode() works with a conceptually const object but may update these to be
// consistent with vector data; so, mutable.
mutable struct {
   // Any of these might or might not have appeared in a particular node that
   // had body text. For uniformity, we have them all here, and with defaults.
   std::size_t length = 0;
   std::size_t start = 0;
   std::string valueType = "";
} vars;


// -----------------------------------------------------------------------------
// Getters
// -----------------------------------------------------------------------------

public:

// length
std::size_t length() const
{
   return vars.length;
}

// start
std::size_t start() const
{
   return vars.start;
}

// valueType
const std::string &valueType() const
{
   return vars.valueType;
}


// -----------------------------------------------------------------------------
// Setters
// Builder pattern for all: return *this.
// Arguments of std::optional allow for more flexibility in derived classes.
// -----------------------------------------------------------------------------

// length
BlockData &length(const std::optional<std::size_t> &opt)
{
   if (opt.has_value())
      vars.length = opt.value();
   return *this;
}

// start
BlockData &start(const std::optional<std::size_t> &opt)
{
   if (opt.has_value())
      vars.start = opt.value();
   return *this;
}

// valueType
BlockData &valueType(const std::optional<std::string> &opt)
{
   if (opt.has_value())
      vars.valueType = opt.value();
   return *this;
}
