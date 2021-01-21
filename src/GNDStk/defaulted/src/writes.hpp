
// -----------------------------------------------------------------------------
// Create new object with the WRITES property enabled/disabled.
// I'm open to better names for these, or another way of doing this action.
// -----------------------------------------------------------------------------

// These are similar, conceptually, to the prefix ++ and -- of GNDStk's child_t
// class. Those operators create a "strengthened" child_t with allow::many, or
// a "weakened" child_t with allow::one. The below functions similarly create
// a "strengthened" defaulted<T> object that writes its value (even when its
// value is the default) in certain GNDStk output capabilities; or a "weakened"
// defaulted<T> that doesn't so write. As with the child_t analogs, these create
// brand-new objects - they must, because the change is to a template parameter,
// not to member data. Here, however, we chose not to use ++ and --. Given that
// a defaulted<T> essentially wraps a T, users could too easily make the mistake
// of thinking that ++/-- increment/decrement the value.

// writes
auto writes() const
{
   return defaulted<T,true>(def,opt);
}

// quiet
auto quiet() const
{
   return defaulted<T,false>(def,opt);
}
