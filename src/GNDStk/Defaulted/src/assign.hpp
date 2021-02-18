
// -----------------------------------------------------------------------------
// Assignment operators
// -----------------------------------------------------------------------------

// ------------------------
// Assignment:
// general
// ------------------------

// = T
Defaulted &operator=(const T &val)
{
   this->opt = val;
   return *this;
}

// = optional<T>
Defaulted &operator=(const std::optional<T> &opt)
{
   this->opt = opt;
   return *this;
}

// = nullopt
Defaulted &operator=(const std::nullopt_t nullopt)
{
   this->opt = nullopt;
   return *this;
}


// ------------------------
// Assignment:
// the usual suspects
// ------------------------

// Discussion.
//
// All of the following result in the left-hand-side having a hard value, with
// any existing one disappearing into the ether (which of course is completely
// normal for the left-hand-side of an assignmment). This effect - ending up
// with a hard value in each case - is easy to remember, and seems reasonable,
// given that we're assigning from something that, as a "Defaulted" object,
// can be considered to always have a value. (Its default, if nothing else.)
//
// A case could perhaps be made that if the RIGHT-hand-side doesn't have a hard
// value, but instead only has its default, then the left-hand-side should be
// made to reflect the "doesn't have a hard value" state of affairs. That would
// mean that the left-hand-side's "value", going forward, would be its default,
// which of course would in general be different from the right-hand-side's
// default. (Such an assignment's effect would be equivalent to that of calling
// the left-hand-side's reset().) Possibly, a case could even be made that
// LHS = RHS, where RHS has no hard value, should be a no-op, with LHS retaining
// any hard value it might already have. We considered both of these behaviors,
// but, informally speaking, neither "felt right" in our examples and tests. So,
// instead, we have the assignment semantics we do: copy, template "copy", and
// move all result in the right-hand-side's value, hard or default, being placed
// into *this as a hard value.

// copy
Defaulted &operator=(const Defaulted &other)
{
   opt = T(other);
   return *this;
}

// template "copy"
template<
   class U = T,
   class = typename std::enable_if<
      std::is_constructible<T,U>::value
   >::type
>
Defaulted &operator=(const Defaulted<U> &other)
{
   opt = T(U(other));
   return *this;
}

// move
Defaulted &operator=(Defaulted &&other)
{
   opt = std::move(other.opt.has_value() ? other.opt.value() : other.def);
   return *this;
}
