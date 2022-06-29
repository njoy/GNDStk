
// -----------------------------------------------------------------------------
// Assignment from string
// Same effect as the string(new string) setter
// -----------------------------------------------------------------------------

BlockData &operator=(const std::string &str)
{
   return string(str);
}


// -----------------------------------------------------------------------------
// Assignment from vector
// -----------------------------------------------------------------------------

/*
DISCUSSION

Elsewhere, a BlockData object can be made from a GNDS node. From GNDS, we get
a text string (copied to the rawstring field), from which a vector of values
can be created on an as-needed basis. A GNDS node might also give us any of
length, start, and valueType, which, when pulling data from the Node, we'll
use if they're there, or otherwise assume to be our defaults.

Here, we're allowing for an assignment BlockData = vector. For this assignment,
the caller should send the full, complete vector of values that's appropriate
for the GNDS Node whose data this BlockData object is intended to represent.

Specifically: the vector should contain whatever leading and/or trailing 0s
the full data vector is supposed to have. The length and start values are
completely ignored by this function; they're neither used nor set. Future
vector accesses though our various get() functions simply access the vector
exactly as-is. Length and start won't come into play until - and unless - a
caller uses the string setter (or assignment to string) and subsequently
triggers a remake of the vector. (Which would then be a newly-created vector,
based on the value of the raw string - not the vector from which we're
assigning here.)

As for valueType, this function attempts to guess it from the vector's element
type, and sets it to "", the empty string, if we don't recognize that type.

If a vector that's assigned from, here, is still in play when this BlockData's
data are written to a Node (see the toNode() function), then toNode() will
recompute length and start automatically, based on the vector's beginning and
ending content, if the "trim" flag is set. See toNode() for more information.
*/

template<class T>
std::enable_if_t<supported<T>, BlockData &>
operator=(const std::vector<T> &vec)
{
   // set the raw string to "", because it's no longer considered meaningful
   rawstring = "";

   // length, start, valueType
   length(vec.size());
   start(0);
   valueType(detail::MapTypeString<T>::value[0]);

   // assign vector
   if constexpr (runtime)
      variant = vec;
   else if constexpr (std::is_same_v<T,DATA>)
      vector = vec;
   else {
      vector.clear();
      vector.reserve(vec.size());
      for (const T &element : vec)
         vector.push_back(DATA(element));
   }

   act = Active::vector;
   return *this;
}
