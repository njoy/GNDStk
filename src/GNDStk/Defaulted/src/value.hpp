
// -----------------------------------------------------------------------------
// Get the value; various forms
// -----------------------------------------------------------------------------

// ------------------------
// Channeling std::optional
// ------------------------

// These are here largely so this class is more consistent with std::optional,
// which many users may be familiar with. Note that our value() and operator*
// are like our conversion to T, except that they return const T &, not T.

// value(), const
// We don't have a non-const version of this function, because def (the default
// value) might be returned (and by reference) here. We don't want someone to
// inadvertently change the default value through this function; that should be
// done, if it needs to be, by other means.
const T &value() const
{
   return opt.has_value() ? opt.value() : def;
}

// *, const
// Motivated by std::optional's *, but not quite the same. std::optional's has
// undefined behavior if the std::optional has no value, and in that respect
// is different from std::optional's value(), which throws an exception if
// there's no value. An object of the present class *always* has a value, even
// if only its stipulated default. So, here, * is equivalent to value().
const T &operator*() const
{
   return value();
}

// ->, const
// Helpful mainly if T is a nontrivial type. With a Defaulted<std::vector>
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
// does the same thing. std::optional<T> does *not* have a conversion to T,
// which would need to fail somehow if the std::optional didn't have a value,
// and additionally would be ambiguous with conversion to bool when T == bool.
//
// Our current "optional, with default" class contrasts with std::optional<T>
// in the following manner. We dispense with std::optional<T>'s conversion to
// bool, and instead have a conversion to T that's always both unambiguous and
// meaningful. Remember that a Defaulted<T> object always has a value - its
// default, if nothing else.

// to T
operator T() const
{
   return value();
}
