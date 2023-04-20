
// -----------------------------------------------------------------------------
// length, start, valueType
// We place these into a struct so our setters can have the names themselves.
// -----------------------------------------------------------------------------

/*
Quoted [slightly edited] from the official JSON specification files for GNDS:

   length
      The total number of data values including leading and trailing zero
      values that are not stored. This attribute should only be used when
      the sum of start and the number of listed values do not add to the
      total number of data values. This should only happen when there are
      trailing zeros not listed in the block data.

   start
      Default: 0
      For start = N, the first N values are zero and are not stored.

   valueType
      Specifies the type of data in the body (e.g., "Integer32", "Float64").
      Only one type of data can be stored in each instance of a values node.

In some places, e.g. the JSON-format GNDS spec files, these are listed in
a different order: valueType, start, length. Ordering doesn't really matter.
We just chose to use alphabetical) ordering here.
*/

private:

// toNode() works with a conceptually const object, but may update these to be
// consistent with vector data; so, mutable.
struct {
   // Any of these might or might not have appeared in a particular node that
   // had block data. For uniformity, we have them all here, and with defaults.
   mutable size_t length = 0;
   mutable size_t start = 0;
   mutable std::string valueType = "";
} vars;


// -----------------------------------------------------------------------------
// Getters
// Note: we intentionally return by (non-const!) reference, because the values
// in question are mutable.
// -----------------------------------------------------------------------------

public:

// length
size_t &length() const
{
   return vars.length;
}

// start
size_t &start() const
{
   return vars.start;
}

// valueType
std::string &valueType() const
{
   return vars.valueType;
}


// -----------------------------------------------------------------------------
// Setters
// Builder pattern for all: return *this.
// Arguments of optional type allow for more flexibility in derived classes.
// -----------------------------------------------------------------------------

// todo Consider using a macro to shorten the similar code below.

// ------------------------
// For std::optional
// ------------------------

BlockData &length(const std::optional<size_t> &opt)
{
   if (opt.has_value())
      vars.length = opt.value();
   return *this;
}

BlockData &start(const std::optional<size_t> &opt)
{
   if (opt.has_value())
      vars.start = opt.value();
   return *this;
}

BlockData &valueType(const std::optional<std::string> &opt)
{
   if (opt.has_value())
      vars.valueType = opt.value();
   return *this;
}

// ------------------------
// For GNDStk::Optional
// ------------------------

BlockData &length(const GNDStk::Optional<size_t> &opt)
{
   if (opt.has_value())
      vars.length = opt.value();
   return *this;
}

BlockData &start(const GNDStk::Optional<size_t> &opt)
{
   if (opt.has_value())
      vars.start = opt.value();
   return *this;
}

BlockData &valueType(const GNDStk::Optional<std::string> &opt)
{
   if (opt.has_value())
      vars.valueType = opt.value();
   return *this;
}
