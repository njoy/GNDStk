
// fixme This comment needs some modification...

// These are called from node::meta() and node::child() functions to read
// their wrapped types. This way, we can have generic versions for those
// functions - which are member functions, and thus not technically something
// a user can extend - but then still allow users to define input for their
// own user-defined type by making their own custom GNDStk::read() to override
// the default one below.

// Note that our default GNDStk::read() just uses stream input. Generally,
// then, a user would just make a run-of-the-mill operator>>, as they'd probably
// wish and expect to. However, we chose not have GNDStk::read() layered around
// normal stream input, just in case somebody wants to avoid foisting stream
// input capabilities on a type that perhaps shouldn't have it. For example,
// we may not really want stream input for C++ containers.



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


// ------------------------
// sequence containers,
// except array and
// forward_list
// ------------------------

#define GNDSTK_READ(container) \
   template<class T, class Alloc> \
   inline void read(std::istream &is, std::container<T,Alloc> &value) \
   { \
      value.clear(); \
      T v; \
      while (is >> v) \
         value.push_back(v); \
   }

GNDSTK_READ(deque)
GNDSTK_READ(list)
GNDSTK_READ(vector)

#undef GNDSTK_READ



// -----------------------------------------------------------------------------
// read(string,T)
// default: make istringstream from string, then use read(istream,T) above
// -----------------------------------------------------------------------------

// default
template<class T>
inline void read(const std::string &str, T &value)
{
   std::istringstream iss(str);
   read(iss,value);
}

// string
inline void read(const std::string &str, std::string &value)
{
   value = str;
}

// bool
inline void read(const std::string &str, bool &value)
{
   if (
      str == "1" or str == "t"     or str == "true"  or
      str == "T" or str == "True"  or str == "TRUE"  )
      value = true;
   else if (
      str == "0" or str == "f"     or str == "false" or
      str == "F" or str == "False" or str == "FALSE" )
      value = false;
   else {
      // fixme do something better than this
      assert(false);
      value = false;
   }
}

// miscellaneous
// string-to-T specializations that may be faster than our default
#define GNDSTK_READ(fun,T) \
   inline void read(const std::string &str, T &value) \
   { \
      value = std::fun(str); \
   }

GNDSTK_READ(stod, double)
GNDSTK_READ(stof, float)
GNDSTK_READ(stoi, int)
GNDSTK_READ(stol, long)
GNDSTK_READ(stold, long double)
GNDSTK_READ(stoll, long long)
GNDSTK_READ(stoul, unsigned long)
GNDSTK_READ(stoull, unsigned long long)

#undef GNDSTK_READ



// -----------------------------------------------------------------------------
// read(node,T)
// default: error
// -----------------------------------------------------------------------------

// default
// Doesn't know what to do; should be overridden
// fixme Consider having *no* default for read(node,...)
template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER,
   class T
>
inline void read(
   const GNDStk::Node<METADATA_CONTAINER,CHILDREN_CONTAINER> &,
   T &value
) {
   assert(false);
   value = T{};
}
