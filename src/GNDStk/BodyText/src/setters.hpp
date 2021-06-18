
// -----------------------------------------------------------------------------
// Change length, start, or valueType
// -----------------------------------------------------------------------------

/*
DISCUSSION

Remember, the present context is that a class derives from Component, which
further derives from BodyText<true> (this class). We're here if the derived
class has "body text". Such a derived class might, or might not, have length,
start, or valueType (possibly as std::optional or GNDStk::Defaulted), but we
don't *require* it to have any of those. For whichever ones it does have, we
suggest that it also provide setters that call these as well. That way we can
use the values correctly here, if they need using, and all is kept consistent.

It turns out that we won't use length, start, or valueType in the functions
in this class, except when we're remaking a vector from a string, or possibly
when we're writing to a Node. Importantly, note that none of these functions
sets the "remake" flag. That flag is initialized to true upon construction,
and set to true if the raw string is changed via its setter. Also, it can be
set directly by anyone, to explicitly trigger a remake of the vector from the
raw string if and when the vector is next accessed with a get() call. Thus,
merely setting one of these *won't* trigger a vector remake.

Each of these accepts an optional<>, for maximum usability from the derived
class, which might have a hard value, a std::optional, or a GNDStk::Defaulted.

Each of these returns *this - a "builder" pattern - which callers might find
to be convenient.
*/

// length
BodyText &length(const std::optional<std::size_t> &opt)
{
   if (opt.has_value())
      vars.length = opt.value();
   return *this;
}

// start
BodyText &start(const std::optional<std::size_t> &opt)
{
   if (opt.has_value())
      vars.start = opt.value();
   return *this;
}

// valueType
BodyText &valueType(const std::optional<std::string> &opt)
{
   if (opt.has_value())
      vars.valueType = opt.value();
   return *this;
}
