
// -----------------------------------------------------------------------------
// Get the value; various forms
// -----------------------------------------------------------------------------

// ------------------------
// Channeling std::optional
// ------------------------

// These are here largely so this class is more consistent with std::optional,
// which many users may be familiar with. Note that value() and operator* are
// like conversion to T, except that they return const T &, not T.

// value(), const
// We don't have a non-const version of this, because def (the default value)
// is always const, and *might* be returned (and by reference) here. So, this
// function's non-const analog would still have to return const T &, and thus
// just isn't needed. (As ever, non-const objects can still go to places that
// use const &; it's the reverse that's of course disallowed.)
const T &value() const
{
   return opt ? opt.value() : def;
}

// *, const
// Motivated by std::optional's *, but not quite the same. std::optional's has
// undefined behavior if the std::optional has no value, and in that respect
// is different from std::optional's value(), which throws an exception if
// there's no value. An object of the present class *always* has a value, even
// if only the stipulated default. So, here, * is equivalent to value().
const T &operator*() const
{
   return value();
}

// ->
// Helpful mainly if T is a nontrivial type. With a defaulted<std::vector>
// object, for example, you could write object->size().
const T *operator->() const
{
   return &value();
}


// ------------------------
// Convert to T
// Probably the workhorse
// ------------------------

// Discussion.
//
// Consider std::optional<T>. It has conversion to bool, which checks whether
// the std::optional<T> has a value; and also has a function has_value() that
// means the same thing. std::optional<T> does *not* have a conversion to T,
// which would need to fail somehow if the std::optional didn't have a value,
// and additionally would be ambiguous with conversion to bool when T == bool.
//
// Our current "optional, with default" class contrasts with std::optional<T>
// in the following manner. We dispense with std::optional<T>'s conversion to
// bool,and instead have a conversion to T that's always both unambiguous and
// meaningful (a defaulted<T> always has a value in some sense - its default,
// if nothing else). (As we'll see elsewhere, we'll also keep has_value() in
// this class, with the meaning: "do we have a value other than the default?")

// to T
operator T() const
{
   return value();
}
