
// -----------------------------------------------------------------------------
// Raw data getters
// -----------------------------------------------------------------------------

// get_default()
// Access the default.
// Read-only; once this object is constructed, its default cannot change.
const T &get_default() const
{
   return def;
}

// get_optional()
// Access the std::optional.
// Read-only; other functionality that we specifically designed for these
// objects should be used for effecting any changes.
const std::optional<T> &get_optional() const
{
   return opt;
}   
