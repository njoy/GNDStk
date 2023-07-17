
// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

private:

// ------------------------
// Transfer Meta
// ------------------------

template<class DEST, class TYPE, class CONVERTER>
void transferMeta(
   const Node &node, DEST &to,
   const Meta<TYPE,CONVERTER> &key
) {
   node.meta(to, key);
}


// ------------------------
// Transfer Child
// ------------------------

template<class DEST, class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
void transferChild(
   const Node &node, DEST &to,
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &key
) {
   // Absolutely respect any non-default converter in the Child key, by doing
   // a Core Interface child-node query in the usual manner. Note that we can
   // still use the more-efficient "node.child(to,key)" rather than the less-
   // efficient "to = node(key)", because, in the present context, we do have
   // a specific destination for the query result.
   if constexpr (!std::is_same_v<CONVERTER,detail::convert_t>) {
      node.child(to, key);
      return;
   }

   // In the following conditionals, assume that Foo derives from Component,
   // while Bar does not, i.e.:
   //    Foo: Component
   //    Bar
   // Remarks, below, reflect various situations.

   if constexpr (detail::isDerivedFromComponent_v<DEST>) {
      // *** Foo
      // Derives from Component, so we know that it has, via Component,
      // a .read(node) function, which should be most efficient to use
      // for "conversion" of the Node to a Foo.
      node.child(to, key/[](const Node &n, DEST &to) { to.read(n); });

   } else if constexpr (detail::isOptional<DEST>) {
      using OPT = typename DEST::value_type; // type the optional may contain

      if constexpr (detail::isVector_v<OPT>) {
         using ELEM = typename OPT::value_type; // vector element type
         if constexpr (detail::isDerivedFromComponent_v<ELEM>) {
            // *** optional<vector<Foo>>
            if (!to.has_value())
               to = OPT{};
            node.child(to, key/[](const Node &n, ELEM &e) { e.read(n); });
         } else {
            // *** optional<vector<Bar>>
            node.child(to, key);
         }
      } else {
         if constexpr (detail::isDerivedFromComponent_v<OPT>) {
            // *** optional<Foo>
            node.child(to, key/[](const Node &n, OPT &to) { to.read(n); });
         } else {
            // *** optional<Bar>
            node.child(to, key);
         }
      }
   } else if constexpr (detail::isVector_v<DEST>) {
      using ELEM = typename DEST::value_type; // vector element type
      if constexpr (detail::isDerivedFromComponent_v<ELEM>) {
         // *** vector<Foo>
         node.child(to, key/[](const Node &n, ELEM &e) { e.read(n); });
      } else {
         // *** vector<Bar>
         node.child(to, key);
      }
   } else {
      // *** Bar
      node.child(to, key);
   }
}


// ------------------------
// Transfer
// ------------------------

template<class KEY>
void transfer(const size_t n, const Node &node, const KEY &key)
{
   using DEST = typename detail::queryResult<KEY>::type;
   DEST &to = *(DEST *)links[n];

   if constexpr (detail::IsMeta<KEY>::value)
      transferMeta(node, to, key);
   else if constexpr (detail::IsChild<KEY>::value)
      transferChild(node, to, key);
   else {
      // todo Does this situation involve only the pair<Child,something> case?
      // I think that may be true, given the way keys are placed into keytuples;
      // see or.hh. In this case, are there some optimizations we can do here,
      // as we do in transferChild above?
      to = node(key);
   }
}


// -----------------------------------------------------------------------------
// Component::fromNode(Node)
// -----------------------------------------------------------------------------

public:

// Retrieve a Node's data, and, via the links, get it into the fields in the
// derived-class object. We'd have preferred to call this in the constructor,
// so that users wouldn't need to call it directly in the constructors
// of their derived classes that accept Nodes. However, data initialization
// order in derived classes is such that their member data won't have been
// initialized (and thus would contain garbage data) when the Component base
// is constructed. Under such circumstances, the assignment in the below fold
// expression would, in general, break. (Imagine, say, assigning X = Y for
// std::strings X and Y - but when X isn't initialized, so that X contains
// garbage. The assignment would attempt to deallocate a junk pointer in X,
// and funny stuff would happen. Maybe not too funny.) We could use placement
// new(), below, but to no real effect: the result would be replaced, anyway,
// when the derived class' own members are initialized in its constructor.

void fromNode(const Node &node)
{
   try {
      // does the node have the name we expect?
      if (node.name != DERIVED::NODENAME()) {
         log::error(
           "Node name \"{}\" is not the expected name \"{}\"",
            node.name, DERIVED::NODENAME()
         );
         throw std::exception{};
      }

      // consistency check
      assert(std::tuple_size_v<decltype(Keys().tup)> == links.size());

      // apply links:
      // Node ==> derived-class data
      std::apply(
         [this,&node](const auto &... key) {
            size_t n = 0; (this->transfer(n++, node, key), ...);
         },
         Keys().tup
      );

      // block data
      if constexpr (hasBlockData)
         BLOCKDATA::fromNode(node);

      // ------------------------
      // If we're putting certain
      // instrumentation into the
      // Component interface...
      // ------------------------

      #ifdef GNDSTK_INSTRUMENT
      {
         // context
         std::vector<std::string> ancestors;
         for (const Node *n = &node; n; n = &n->parent())
            ancestors.push_back(n->name);

         // metadata
         for (const auto &m : node.metadata)
            if (!beginsin(m.first, "marked-")) {
               std::cout << color::custom::green << "missed: metadatum ";
               for (size_t i = ancestors.size(); i--; )
                  std::cout << ancestors[i] << ".";
               std::cout << m.first << color::reset << std::endl;
            }

         // children
         for (const auto &c : node.children)
            if (!c->marked) {
               std::cout << color::custom::blue << "missed: child node ";
               for (size_t i = ancestors.size(); i--; )
                  std::cout << ancestors[i] << ".";
               std::cout << c->name << color::reset << std::endl;
            }
      }
      #endif

   } catch (...) {
      log::member("Component.fromNode(Node(\"{}\"))", node.name);
      throw;
   }
}
