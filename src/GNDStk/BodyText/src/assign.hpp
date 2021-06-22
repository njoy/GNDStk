
// -----------------------------------------------------------------------------
// Assignment from string
// Same effect as the string(new string) setter
// -----------------------------------------------------------------------------

BodyText &operator=(const std::string &str)
{
   return string(str);
}


// -----------------------------------------------------------------------------
// Assignment from vector
// -----------------------------------------------------------------------------

/*
DISCUSSION

Elsewhere, a BodyText object can be made from a GNDS node. From GNDS, we get
a text string (copied to the rawstring field), from which a vector of values
can be created on an as-needed basis. A GNDS node might also give us any of
length, start, and valueType, which, when pulling data from the Node, we'll
use if they're there, or otherwise assume to be our defaults.

Here, we're allowing for an assignment BodyText = vector. For this assignment,
the caller should send the full, complete vector of values that's appropriate
for the GNDS Node whose data this BodyText object is intended to represent.

Specifically: the vector should contain whatever leading and/or trailing 0s
the full data vector is supposed to have. The "length" and "start" values are
completely ignored by this function. They're neither used nor set. Future
vector accesses though our various get() functions simply access the vector
exactly as-is. Length and start won't come into play until - and unless - a
caller either sets remake = true, or uses the string setter (or assignment
to string) and subsequently triggers a remake of the vector. (Which would then
be a newly-created vector, not the one being assigned from here.)

As for valueType, this function attempts to guess it from the vector's type,
and sets it to "", the empty string, if we don't recognize the vector's type.

If a vector that's assigned from, here, is still in play when this BodyText's
data are written to a Node (see the toNode() function), then toNode() will
recompute length and start automatically, based on the vector's beginning and
ending content, if the "trim" flag is set. See toNode() for more information.
*/

template<class T>
typename std::enable_if<
   detail::is_oneof<std::vector<T>,variant_t>::value,
   BodyText &
>::type operator=(const std::vector<T> &vec)
{
   // valueType: best guess
   if (std::is_same<T,Integer32>::value)
      valueType("Integer32");
   else if (std::is_same<T,Float64>::value)
      valueType("Float64");
   else
      valueType("");

   variant = vec;
   active = Active::vector;
   return *this;
}
