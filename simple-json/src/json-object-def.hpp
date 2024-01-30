
// operator[]: non-const
// Feature, not defect: referring to an element creates it, if it isn't already
// there. Use operator[] const, defined below, if you don't want this behavior.
inline value &object::operator[](const string &key)
{
   for (pair &elem : *this)
      if (elem.first == key)
         return elem.second;
   return push_back(pair(key,value())), back().second;
}

// operator[]: const
inline const value &object::operator[](const string &key) const
{
   for (const pair &elem : *this)
      if (elem.first == key)
         return elem.second;
   error("const json::object[key=\"" + key + "\"]: key not found.");

   // error() throws, so the following just suppresses compilation errors.
   static const value ret;
   return ret;
}

// has key
inline bool object::has(const string &key) const
{
   for (const pair &elem : *this)
      if (elem.first == key)
         return true;
   return false;
}
