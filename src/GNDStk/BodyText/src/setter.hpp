
// -----------------------------------------------------------------------------
// Change length, start, or valueType
// -----------------------------------------------------------------------------

/*
DISCUSSION

Remember, the present context is that some class derives from Component, which
further derives from BodyText<true> (this class). We're here if the derived
class has "body text". Such a derived class might, or might not, have length,
start, or valueType (possibly as std::optional or GNDStk::Defaulted), but we
don't *require* that it have any of those. For whichever ones the derived class
does have, we suggest that it also have setters that call these too. That way,
we can handle them correctly here, and everthing is kept consistent,

It turns out that we won't use length, start, or valueType in the functions in
this class, except when we're (re)making a vector from a string, or writing to
a Node. Note that calling these, below, does not, in itself, set "remake".

todo: Make sure the above statements are accurate.
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
