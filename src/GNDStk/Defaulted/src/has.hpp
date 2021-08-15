
// -----------------------------------------------------------------------------
// Tests regarding default-ness
// -----------------------------------------------------------------------------

// ------------------------
// Has a hard value (not
// just its default)?
// ------------------------

// has_value()
//
// Compare/contrast this member function with std::optional's member function
// of the same name. Here, has_value() means "has something other than its
// default." That "something" could, coincidentally, be a value that happens
// to equal the default. The issue is whether or not the internally stored
// std::optional contains a value.
//
// If you have code that involves has_value(), consider reversing it and using
// is_default(), below, instead. While we've kept has_value() in order to be
// consistent with std::optional, the concept of "has a value?" is arguably less
// cut-and-dry here. Objects of the present class always, in some sense, have a
// value, even if only their default. So, a call to is_default() may be clearer.
bool has_value() const
{
   // has *non-default* value
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
