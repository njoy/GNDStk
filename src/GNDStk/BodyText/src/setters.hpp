
// todo Should rename or split this file; has both *getters* and setters.


// -----------------------------------------------------------------------------
// Get length, start, or valueType
// -----------------------------------------------------------------------------

// length
std::size_t length() const
{
   return vars.length;
}

// start
std::size_t start() const
{
   return vars.start;
}

// valueType
const std::string &valueType() const
{
   return vars.valueType;
}


// -----------------------------------------------------------------------------
// Set length, start, or valueType
// -----------------------------------------------------------------------------

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
