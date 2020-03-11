
// -----------------------------------------------------------------------------
// Node::add()
// -----------------------------------------------------------------------------

// ------------------------
// add metadatum
// ------------------------

// (string,string) direct
metaPair &add(const std::string &key, const std::string &value)
{
   metadata.push_back(metaPair(key,value));
   return metadata.back();
}

// (string,string) pair
metaPair &add(const metaPair &m)
{
   metadata.push_back(m);
   return metadata.back();
}

// (string,T) direct
template<class T>
metaPair &add(const std::string &key, const T &value)
{
   std::ostringstream oss;
   oss << value;
   return add(key,oss.str());
}

// (string,T) pair
template<class T>
metaPair &add(const std::pair<std::string,T> &m)
{
   std::ostringstream oss;
   oss << m.second;
   return add(m.first,oss.str());
}


// ------------------------
// add child
// ------------------------

// ()
// (string)
Node &add(const std::string &name = "")
{
   children.push_back(std::make_shared<Node>());
   children.back()->name = name;
   return *children.back();
}
