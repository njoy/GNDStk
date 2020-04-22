
// -----------------------------------------------------------------------------
// convert(*,Tree)
// That is, convert to Tree objects
// -----------------------------------------------------------------------------

// ------------------------
// Tree ==> Tree
// ------------------------

template<
   template<class...> class METADATA_CONTAINER_FROM,
   template<class...> class CHILDREN_CONTAINER_FROM,
   template<class...> class METADATA_CONTAINER_TO,
   template<class...> class CHILDREN_CONTAINER_TO
>
bool convert(
   const GNDStk::Tree<METADATA_CONTAINER_FROM,CHILDREN_CONTAINER_FROM> &from,
   GNDStk::Tree<METADATA_CONTAINER_TO,CHILDREN_CONTAINER_TO> &to
) {
   // casts are used here because the template arguments may be different
   if ((void*)&to == (void*)&from)
      return true;

   // clear
   to.clear();

   // convert
   if (not from.empty()) {
      to.root =
         std::make_unique<Node<METADATA_CONTAINER_TO,CHILDREN_CONTAINER_TO>>();
      try {
         detail::node2Node(*from.root, *to.root);
      } catch (const std::exception &) {
         detail::context("convert(Tree,Tree)");
         throw;
      }
   }

   // done
   return true;
}



// ------------------------
// XML ==> Tree
// ------------------------

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::XML &x,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree
) {
   // clear
   tree.clear();

   // visit the XML's nodes
   int count = 0;
   for (const pugi::xml_node &xnode : x.doc.children()) {
      if (count == 0) {
         // expect the following, given that we called load_file()
         // with pugi::parse_declaration |d in its second argument
         if (xnode.name() != std::string("xml")) {
            njoy::Log::error(
               "Internal error in convert(XML,Tree):\n"
               "Expected the initial (declaration) node "
               "to have the name \"xml\";\n"
               "its name is instead \"{}\"",
               xnode.name()
            );
            throw std::exception{};
            return false;
         }

         tree.root =
            std::make_unique<Node<METADATA_CONTAINER,CHILDREN_CONTAINER>>();
         tree.root->name = "xml"; // indicates that we came from an XML

         // base XML "attributes", e.g. version and encoding
         for (const pugi::xml_attribute &xattr : xnode.attributes())
            tree.root->add(xattr.name(), xattr.value());
      }

      if (count == 1) {
         // visit the XML's outer node, and its descendants
         try {
            if (not detail::xml_node2Node(xnode,tree.root->add()))
               return false;
         } catch (const std::exception &) {
            detail::context("convert(XML,Tree)");
            throw;
         }
      }

      count++;
   }

   // a proper XML document should contain just one outer node; we expect
   // two (but no more) only because we loaded the file with a flag that
   // said to include the declaration node <?xml ... ?> as part of the deal
   if (count != 2) {
      njoy::Log::error(
         "Internal error in convert(XML,Tree):\n"
         "Found more than just a declaration node and one top-level node "
         "in the XML"
      );
      throw std::exception{};
      return false;
   }

   // done
   return true;
}



// ------------------------
// JSON ==> Tree
// ------------------------

template<
   template<class...> class METADATA_CONTAINER,
   template<class...> class CHILDREN_CONTAINER
>
bool convert(
   const GNDStk::JSON &j,
   GNDStk::Tree<METADATA_CONTAINER,CHILDREN_CONTAINER> &tree
) {
   using node_t = Node<METADATA_CONTAINER,CHILDREN_CONTAINER>;

   // clear
   tree.clear();

   // I suppose this could happen
   if (j.doc.size() == 0)
      return true;

   // otherwise, I think there should always be one
   if (j.doc.size() != 1) {
      njoy::Log::error(
         "Internal error in convert(JSON,Tree):\n"
         "Found more than just one top-level node in the JSON"
      );
      throw std::exception{};
      return false;
   }

   // make a boilerplate declaration node
   tree.root = std::make_unique<node_t>();
   tree.decl().name = "json"; // indicates that we came from a JSON

   // make a top-level GNDS node, name to-be-determined
   node_t &top = tree.decl().add();

   // visit the JSON's outer node, and its descendants
   try {
      if (not detail::json2node(j.doc.begin(),top))
         return false;
      } catch (const std::exception &) {
         detail::context("convert(JSON,Tree)");
         throw;
      }

   // done
   return true;
}
