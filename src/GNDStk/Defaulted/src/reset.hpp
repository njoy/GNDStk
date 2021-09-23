
// -----------------------------------------------------------------------------
// Reset to default
// -----------------------------------------------------------------------------

// reset()
// Compare/contrast with std::optional's reset(). Here, reset() means "reset
// to default." We prefer the name clear(), but provide this name in order to
// make the Defaulted class be more consistent with std::optional.
void reset()
{
   opt.reset();
}

// clear()
// Same as reset(). We just prefer this name.
void clear()
{
   reset();
}
