
// These are called from node::meta() and node::child() functions to read
// their wrapped types. This way, we can have generic versions for those
// functions - which are member functions, and thus not technically something
// a user can extend - but then still allow users to define input for their
// own user-defined type by making their own custom gnds::read() to override
// the default one below.

// Note that our default gnds::read() just uses stream input. Generally, then,
// a user would just make a run-of-the-mill operator>>, as they'd probably
// wish and expect to. However, we chose not have gnds::read() layered around
// normal stream input, just in case somebody wants to avoid foisting stream
// input capabilities on a type that perhaps shouldn't have it. For example,
// we may not really want stream input to a vector. (And so, below, we instead
// specialize a gnds::read() for vector.)

// -----------------------------------------------------------------------------
// read
// Note that these are in gnds:: because this file is included therein.
// Our calls want the gnds::.
// So, if you customize for your own type, put your own read() in gnds::.
// -----------------------------------------------------------------------------

// default
template<class T>
inline void read(std::istream &is, T &value)
{
   is >> value;
}


// bool
// Sort of goofy, but we'll go with it for now
inline void read(std::istream &is, bool &value)
{
   std::string str;
   is >> str;

   // true
   if (str == "1"    ) value = true;
   if (str == "t"    ) value = true;
   if (str == "true" ) value = true;
   if (str == "T"    ) value = true;
   if (str == "True" ) value = true;
   if (str == "TRUE" ) value = true;

   // false
   if (str == "0"    ) value = false;
   if (str == "f"    ) value = false;
   if (str == "false") value = false;
   if (str == "F"    ) value = false;
   if (str == "False") value = false;
   if (str == "FALSE") value = false;

   // oh well
   // fixme Obviously, do something less stupid eventually...
   assert(false);
   value = false;
}


// vector<T>
template<class T>
inline void read(std::istream &is, std::vector<T> &value)
{
   T val;
   while (is >> val)
      value.push_back(val);
}
