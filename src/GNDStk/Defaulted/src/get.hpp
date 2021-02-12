
// -----------------------------------------------------------------------------
// Raw data getters
// -----------------------------------------------------------------------------

// get_default()
// Access the default.
// Read-only. Once this object is constructed, its default cannot change.
const T &get_default() const
{
   return def;
}

// get_optional()
// Access the std::optional.
// Read-only. Other functionality, specifically designed for objects of
// this class, should be used for effecting any changes.
const std::optional<T> &get_optional() const
{
   return opt;
}   