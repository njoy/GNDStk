
// -----------------------------------------------------------------------------
// Node::add() metadatum
// -----------------------------------------------------------------------------

// ------------------------
// string, ...
// ------------------------

// (string,string) direct
metaPair &add(const std::string &key, const std::string &value /*= ""*/ )
{
   metadata.push_back(metaPair(key,value));
   return metadata.back();
}

// (string,string) pair
metaPair &add(const metaPair &m)
{
   return add(m.first,m.second);
}

// (string,T) direct
template<class T>
metaPair &add(const std::string &key, const T &value)
{
   std::string str;
   type2string(value,str);
   return add(key,str);
}

// (string,T) pair
template<class T>
metaPair &add(const std::pair<std::string,T> &m)
{
   return add(m.first,m.second);
}


// ------------------------
// meta_t, ...
// ------------------------

// (meta_t<void>,string) direct
metaPair &add(const meta_t<void> &kwd, const std::string &value = "")
{
   return add(kwd.name,value);
}

// (meta_t<void>,string) pair
metaPair &add(const std::pair<meta_t<void>,std::string> &m)
{
   return add(m.first,m.second);
}

// (meta_t<T>,T) direct
template<class T>
metaPair &add(const meta_t<T> &kwd, const T &value = T{})
{
   return add(kwd.name,value);
}

// (meta_t<T>,T) pair
template<class T>
metaPair &add(const std::pair<meta_t<T>,T> &m)
{
   return add(m.first,m.second);
}



// -----------------------------------------------------------------------------
// Node::add() child
// -----------------------------------------------------------------------------

// ()
// (string)
Node &add(const std::string &name = "")
{
   children.push_back(std::make_unique<Node>());
   children.back()->name = name;
   return *children.back();
}
