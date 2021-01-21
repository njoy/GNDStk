
// -----------------------------------------------------------------------------
// Reset to default
// -----------------------------------------------------------------------------

// reset()
// Compare/contrast with std::optional's. Here, it means "reset to default."
// We prefer the name clear(), but include this in order to make defaulted
// be more consistent with std::optional.
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
