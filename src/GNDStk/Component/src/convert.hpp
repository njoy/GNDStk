
// -----------------------------------------------------------------------------
// commentConverter
// Converter to support comments.
// Works with the Core Interface.
// -----------------------------------------------------------------------------

struct commentConverter {
   void operator()(const Node &node, std::string &string) const
   {
      assert(node.name == special::comment);
      string = node.meta(special::text);
   }

   void operator()(const std::string &string, Node &node) const
   {
      assert(node.name == special::comment);
      node.add(special::text,string);
   }
};


// -----------------------------------------------------------------------------
// dataConverter
// Converter to support "cdata" (as in XML) and plain data.
// Works with the Core Interface.
// -----------------------------------------------------------------------------

class dataConverter {

   static std::string &context()
   {
      static std::string str =
        "Component data converter for " +
         detail::fullName(Namespace(), Class());
      return str;
   }

public:

   // ------------------------
   // Node
   // ==> dataNode<vector<T>>
   // ------------------------

   template<class T>
   void operator()(const Node &node, dataNode<std::vector<T>> &vec) const
   {
      assert(node.name == special::cdata || node.name == special::data);

      vec.clear();
      vec.cdata = node.name == special::cdata; // Did the Node arrive as cdata?

      bool found = false;
      const std::string &str = node.meta(special::text,found);
      assert(found);

      if constexpr (std::is_floating_point_v<T>)
         detail::Precision<detail::PrecisionContext::data,T>{}.read(str,vec);
      else {
         // The above read would ultimately do the following for non-floating-
         // point T, but only after extra logic that we might as well avoid.
         std::istringstream iss(str);
         T element;
         while (iss >> element)
            vec.push_back(element);
      }
   }

   // ------------------------
   // dataNode<vector<T>>
   // ==> Node
   // ------------------------

   template<class T>
   void operator()(const dataNode<std::vector<T>> &vec, Node &node) const
   {
      /*
      zzz
      std::cout << "vector ==> Node" << std::endl;
      std::cout << "   Node name: " << node.name << std::endl;
      std::cout << "   Use cdata: " << vec.cdata << std::endl;
      */

      node.name = vec.cdata ? special::cdata : special::data;

      std::ostringstream oss;
      std::size_t count = 0;

      using namespace detail;
      for (const T &element : vec) {
         oss << (count++ ? " " : "");
         if constexpr (std::is_floating_point_v<T>)
            oss << Precision<PrecisionContext::data,T>{}.write(element);
         else
            oss << element;
      }

      node.add(special::text, oss.str());
   }
};
