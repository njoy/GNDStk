
// -----------------------------------------------------------------------------
// Tests regarding default-ness
// -----------------------------------------------------------------------------

// ------------------------
// Has a hard value (not
// just the default)?
// ------------------------

// has_value()
//
// Compare/contrast with std::optional's. Here, it means "has something other
// than the default." (That "something" could, coincidentally, be the same
// as the default. It's a matter of whether the internally stored std::optional
// contains a value.)
//
// If you have code that involves has_value(), consider reversing it and using
// is_default(), below, instead. While we've kept has_value() in order to be
// consistent with std::optional, the concept of "has a value?" is arguably less
// cut-and-dry here. Objects of the present class always, in some sense, have a
// value, even if only their default. So, a call to is_default() may be clearer.
bool has_value() const
{
   return opt.has_value();
}


// ------------------------
// Is its default?
// ------------------------

// is_default()
// The opposite of has_value(). True if there's no value in the std::optional;
// else false (so that the object is regarded as having its default).
bool is_default() const
{
   return !has_value();
}
