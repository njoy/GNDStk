
// fixme This comment needs some modification...

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
// read(istream,T)
// default: use operator>>
// -----------------------------------------------------------------------------

// default
template<class T>
inline void read(std::istream &is, T &value)
{
   is >> value;
}


// vector<T>
template<class T>
inline void read(std::istream &is, std::vector<T> &value)
{
   T val;
   while (is >> val)
      value.push_back(val);
}



// -----------------------------------------------------------------------------
// read(string,T)
// default: convert string to istringstream, use read(istream,T) above
// -----------------------------------------------------------------------------

// default
template<class T>
inline void read(const std::string &str, T &value)
{
   std::istringstream iss(str);
   read(iss,value);
}


// bool
inline void read(const std::string &str, bool &value)
{
   if (
      str == "1" || str == "t"     || str == "true"  ||
      str == "T" || str == "True"  || str == "TRUE"  )
      value = true;
   else if (
      str == "0" || str == "f"     || str == "false" ||
      str == "F" || str == "False" || str == "FALSE" )
      value = false;
   else {
      // fixme do something better than this
      assert(false);
      value = false;
   }
}


// miscellaneous
// string-to-T specializations that may be faster than our default
#define gnds_read(fun,T) \
   inline void read(const std::string &str, T &value) \
   { \
      value = std::fun(str); \
   }

gnds_read(stod, double)
gnds_read(stof, float)
gnds_read(stoi, int)
gnds_read(stol, long)
gnds_read(stold, long double)
gnds_read(stoll, long long)
gnds_read(stoul, unsigned long)
gnds_read(stoull, unsigned long long)

#undef gnds_read



// -----------------------------------------------------------------------------
// read(node,T)
// default: error
// -----------------------------------------------------------------------------

// default
// Doesn't know what to do; should be overridden
// fixme Consider having *no* default for read(node,...)
template<class T>
inline void read(const gnds::node &node, T &value)
{
   (void)node;
   assert(false);
   value = T{};
}
