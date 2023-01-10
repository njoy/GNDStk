
// -----------------------------------------------------------------------------
// CommentConverter
// Core Interface "converter" to support comments.
// -----------------------------------------------------------------------------

struct CommentConverter {
   // query: Node ==> string
   void operator()(const Node &node, std::string &str) const
   {
      bool found = false;
      str = node.meta(special::text,found);

      if (!found) {
         log::warning(
           "Cannot find a \"{}\" metadatum in Node \"{}\".\n"
           "The Node appears to be ill-formed.\n"
           "Returning an empty string, \"\", for the comment.",
            special::text, node.name);
         log::context(
           "Node-to-string conversion for comments in class {}." +
            detail::fullName(Namespace(), Class()));
         str = "";
      }
   }

   // write: string ==> Node
   void operator()(const std::string &str, Node &node) const
   {
      node.add(special::text, str);
   }
};


// -----------------------------------------------------------------------------
// DataConverter
// Core Interface "converter" to support "cdata" (as in XML) and plain data.
// -----------------------------------------------------------------------------

struct DataConverter {

   // ------------------------
   // query vector
   // ------------------------

   // Node ==> DataNode<vector<T>>
   template<class T, bool preferCDATA>
   void operator()(
      const Node &self,
      DataNode<std::vector<T>, preferCDATA> &vec
   ) const {
      vec.clear();

      // We'll consider it to be fine, in this context, if a "cdata"
      // or "pcdata" node isn't actually in the present node. This would
      // be the case if, for example, we encountered something like this:
      //    <parent></parent>
      // where we might expect something like one of these:
      //    <parent>1.23 4.56 7.89</parent>
      //    <parent><![CDATA[1.23 4.56 7.89]]></parent>
      // So, we accept the case where the outer node doesn't explicitly
      // have the expected vector-like inner node, and simply produce an
      // empty vector in this situation.
      bool found = false;
      const Node &data = self.one(special::anydata,found);
      if (!found)
         return; // fine; the vector - clear()'d above - is appropriate

      // Remember whether the vector is arriving here in cdata or plain data.
      vec.cdata = data.name == special::cdata;

      // We did find a data node (as opposed to encountering the situation
      // described earlier), and the Core Interface should always have put
      // a text metadatum into it, to store the data node's contents.
      found = false;
      const std::string &str = data.meta(special::text,found);

      if (found) {
         if constexpr (std::is_floating_point_v<T>)
            detail::Precision<detail::PrecisionContext::data,T>{}.read(str,vec);
         else {
            // The above read ultimately does the following for non-floating-
            // point T, but only after extra logic that we might as well avoid.
            std::istringstream iss(str);
            T element;
            while (iss >> element)
               vec.push_back(element);
         }
      } else {
         log::warning(
           "Cannot find a \"{}\" metadatum in Node \"{}\".\n"
           "The Node appears to be ill-formed.\n"
           "Returning an empty vector.",
            special::text, data.name);
         log::context(
           "Node-to-vector conversion for data in class {}." +
            detail::fullName(Namespace(), Class()));
      }

      #ifdef GNDSTK_HACK
      const_cast<Node &>(data).name = "marked-" + data.name;
      #endif
   }

   // ------------------------
   // write vector
   // ------------------------

   // DataNode<vector<T>> ==> Node
   template<class T, bool preferCDATA>
   void operator()(
      const DataNode<std::vector<T>, preferCDATA> &vec,
      Node &self
   ) const {
      // If the data vector is empty, we won't create a data node inside of the
      // current node at all. This is essentially the reverse of the "no data
      // node" situation described in a comment in the other operator() above.
      if (vec.size() == 0)
         return;

      // Depending on the status of our cdata flag, give the Node that's being
      // created the correct name.
      Node &data = self.add(vec.cdata ? special::cdata : special::data);

      std::ostringstream oss;
      {
         std::size_t count = 0;
         using namespace detail;
         for (const T &element : vec) {
            oss << (count++ ? " " : "");
            if constexpr (std::is_floating_point_v<T>)
               oss << Precision<PrecisionContext::data,T>{}.write(element);
            else
               oss << element;
         }
      }
      data.add(special::text, oss.str());
   }

   // ------------------------
   // query string
   // ------------------------

   // Node ==> DataNode<string>
   template<bool preferCDATA>
   void operator()(
      const Node &self,
      DataNode<std::string, preferCDATA> &str
   ) const {
      str = "";

      // Remark as with the Node ==> DataNode<vector<T>> case earlier.
      bool found = false;
      const Node &data = self.one(special::anydata,found);
      if (!found)
         return; // fine; the string - set to "" above - is appropriate

      // Remember whether the string is arriving here in cdata or plain data.
      str.cdata = data.name == special::cdata;

      found = false;
      str = data.meta(special::text,found);

      if (!found) {
         log::warning(
           "Cannot find a \"{}\" metadatum in Node \"{}\".\n"
           "The Node appears to be ill-formed.\n"
           "Returning an empty string, \"\", for the value.",
            special::text, data.name);
         log::context(
           "Node-to-string conversion for data in class {}." +
            detail::fullName(Namespace(), Class()));
         str = ""; // ensure "" after node.meta() call above
      }

      #ifdef GNDSTK_HACK
      const_cast<Node &>(data).name = "marked-" + data.name;
      #endif
   }

   // ------------------------
   // write string
   // ------------------------

   // DataNode<string> ==> Node
   template<bool preferCDATA>
   void operator()(
      const DataNode<std::string, preferCDATA> &str,
      Node &self
   ) const {
      if (str == "")
         return;

      // Remark as in the DataNode<vector> case above.
      Node &data = self.add(str.cdata ? special::cdata : special::data);
      data.add(special::text, str);
   }
};
