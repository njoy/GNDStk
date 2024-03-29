class Node
{
   using metaPair = std::pair<std::string,std::string>;
   using childPtr = std::unique_ptr<Node>;
public:
   std::string name;
   std::vector<metaPair> metadata;
   std::vector<childPtr> children;
   // constructors, member functions, ...
};

class Tree : public Node
{
   // a few additional and/or different member functions
};
