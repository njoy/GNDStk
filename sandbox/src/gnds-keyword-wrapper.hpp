
// -----------------------------------------------------------------------------
// typed
// -----------------------------------------------------------------------------

// default
template<class result, class wraps>
class typed {
};



// ------------------------
// for child_t
// ------------------------

template<class T>
class typed<T,child_t<T>> : public node {
public:

   // data
   const child_t<T> &obj;
   const std::string &key;
   const node &value;

   // ctor
   explicit typed(const child_t<T> &c, const node &n) :
      node(n), obj(c), key(obj.name), value(n)
   { }

   // operator(): evaluate to T
   T operator()() const
   {
      T ret;
      read(value,ret); // fixme should allow for node-to-node automatically
      return ret;
   }

   using node::meta;
   using node::child;
   using node::operator();
   using node::leaf;
};



// -----------------------------------------------------------------------------
// read
// Can be customized for special types.
// -----------------------------------------------------------------------------

// ------------------------
// string,T
// ------------------------

// Default
// Makes an istringstream from the string, and read()s with that
template<class T>
inline void read(const std::string &str, T &ret)
{
   std::istringstream iss(str);
   read(iss,ret);
}


// fixme May want to reformulate read(istream,bool), located elsewhere
// right now, to a read(string,bool) here.


// string-to-T specializations that may be faster than the above default
#define gnds_read(fun,type) \
   inline void read(const std::string &str, type &ret) \
   { \
      ret = std::fun(str); \
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



// ------------------------
// node,T
// ------------------------

// default
// fixme We arguably want *no* default for this
template<class T>
inline void read(const gnds::node &node, T &ret)
{
   (void)node;
   (void)ret;
   ret = T{};
   assert(false);
}
