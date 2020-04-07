
// -----------------------------------------------------------------------------
// Node::add() metadatum
// -----------------------------------------------------------------------------

// ------------------------
// string, ...
// ------------------------

// (string,string) direct
metaPair &add(const std::string &key, const std::string &value)
{
   /// debug("node add() #1: (string,string)");
   metadata.push_back(metaPair(key,value));
   return metadata.back();
}

// (string,string) pair
metaPair &add(const metaPair &m)
{
   /// debug("node add() #2: pair(string,string)");
   return add(m.first,m.second);
}

// (string,T) direct
template<class T>
metaPair &add(const std::string &key, const T &value)
{
   /// debug("node add() #3: (string,T)");
   std::string str;
   type2string(value,str);
   return add(key,str);
}

// (string,T) pair
template<class T>
metaPair &add(const std::pair<std::string,T> &m)
{
   debug("node add() #4: pair(string,T)");
   return add(m.first,m.second);
}


// ------------------------
// meta_t, ...
// ------------------------

// (meta_t<void>,string) direct
metaPair &add(const meta_t<void> &kwd, const std::string &value = "")
{
   debug("node add() #5: (meta_t<void>,string)");
   return add(kwd.name,value);
}

// (meta_t<void>,string) pair
metaPair &add(const std::pair<meta_t<void>,std::string> &m)
{
   debug("node add() #6: pair(meta_t<void>,string)");
   return add(m.first,m.second);
}

// (meta_t<T>,T) direct
template<class T>
metaPair &add(const meta_t<T> &kwd, const T &value = T{})
{
   debug("node add() #7: (meta_t<T>,T)");
   return add(kwd.name,value);
}

// (meta_t<T>,T) pair
template<class T>
metaPair &add(const std::pair<meta_t<T>,T> &m)
{
   debug("node add() #8: pair(meta_t<T>,T)");
   return add(m.first,m.second);
}



// -----------------------------------------------------------------------------
// Node::add() child
// -----------------------------------------------------------------------------

// ()
// (string)
Node &add(const std::string &name = "")
{
   /// debug("node add() #9: (string)");
   children.push_back(std::make_unique<Node>());
   children.back()->name = name;
   return *children.back();
}
