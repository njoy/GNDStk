
// -----------------------------------------------------------------------------
// precision::
// class Floats
// -----------------------------------------------------------------------------

namespace precision {

class Floats : public Component<Floats,true,float> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "precision"; }
   static auto className() { return "Floats"; }
   static auto GNDSName() { return "floats"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<int>{}
            / Meta<>("length") |
         Defaulted<int>{0}
            / Meta<>("start") |
         std::optional<std::string>{}
            / Meta<>("valueType")
      ;
   }

public:

   using Component::construct;
   using BodyText::operator=;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
      static inline const int start = 0;
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      mutable std::optional<int> length;
      mutable Defaulted<int> start{0};
      mutable std::optional<std::string> valueType;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // length
   const std::optional<int> &length() const
    { return content.length; }
   std::optional<int> &length()
    { return content.length; }

   // start
   const Defaulted<int> &start() const
    { return content.start; }
   Defaulted<int> &start()
    { return content.start; }

   // valueType
   const std::optional<std::string> &valueType() const
    { return content.valueType; }
   std::optional<std::string> &valueType()
    { return content.valueType; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // length(value)
   Floats &length(const std::optional<int> &obj)
    { BodyText::length(length() = obj); return *this; }

   // start(value)
   Floats &start(const Defaulted<int> &obj)
    { BodyText::start(content.start = obj); return *this; }
   Floats &start(const std::optional<int> &obj)
    { BodyText::start(content.start = obj); return *this; }

   // valueType(value)
   Floats &valueType(const std::optional<std::string> &obj)
    { BodyText::valueType(valueType() = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Floats() :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish();
   }

   // copy
   Floats(const Floats &other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Floats(Floats &&other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Floats(const Node &node) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish(node);
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Floats(
      const std::optional<int> &length,
      const std::optional<int> &start,
      const std::optional<std::string> &valueType
   ) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      },
      content{
         length,
         Defaulted<int>(defaults.start,start),
         valueType
      }
   {
      Component::finish();
   }

   // from vector
   template<class T, class = std::enable_if_t<body::template supported<T>>>
   Floats(const std::vector<T> &vector) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish(vector);
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Floats &operator=(const Floats &) = default;

   // move
   Floats &operator=(Floats &&) = default;
}; // class Floats

} // namespace precision



// -----------------------------------------------------------------------------
// precision::
// class Doubles
// -----------------------------------------------------------------------------

namespace precision {

class Doubles : public Component<Doubles,true,double> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "precision"; }
   static auto className() { return "Doubles"; }
   static auto GNDSName() { return "doubles"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<int>{}
            / Meta<>("length") |
         Defaulted<int>{0}
            / Meta<>("start") |
         std::optional<std::string>{}
            / Meta<>("valueType")
      ;
   }

public:

   using Component::construct;
   using BodyText::operator=;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
      static inline const int start = 0;
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      mutable std::optional<int> length;
      mutable Defaulted<int> start{0};
      mutable std::optional<std::string> valueType;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // length
   const std::optional<int> &length() const
    { return content.length; }
   std::optional<int> &length()
    { return content.length; }

   // start
   const Defaulted<int> &start() const
    { return content.start; }
   Defaulted<int> &start()
    { return content.start; }

   // valueType
   const std::optional<std::string> &valueType() const
    { return content.valueType; }
   std::optional<std::string> &valueType()
    { return content.valueType; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // length(value)
   Doubles &length(const std::optional<int> &obj)
    { BodyText::length(length() = obj); return *this; }

   // start(value)
   Doubles &start(const Defaulted<int> &obj)
    { BodyText::start(content.start = obj); return *this; }
   Doubles &start(const std::optional<int> &obj)
    { BodyText::start(content.start = obj); return *this; }

   // valueType(value)
   Doubles &valueType(const std::optional<std::string> &obj)
    { BodyText::valueType(valueType() = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Doubles() :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish();
   }

   // copy
   Doubles(const Doubles &other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Doubles(Doubles &&other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Doubles(const Node &node) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish(node);
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Doubles(
      const std::optional<int> &length,
      const std::optional<int> &start,
      const std::optional<std::string> &valueType
   ) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      },
      content{
         length,
         Defaulted<int>(defaults.start,start),
         valueType
      }
   {
      Component::finish();
   }

   // from vector
   template<class T, class = std::enable_if_t<body::template supported<T>>>
   Doubles(const std::vector<T> &vector) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish(vector);
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Doubles &operator=(const Doubles &) = default;

   // move
   Doubles &operator=(Doubles &&) = default;
}; // class Doubles

} // namespace precision



// -----------------------------------------------------------------------------
// precision::
// class Quads
// -----------------------------------------------------------------------------

namespace precision {

class Quads : public Component<Quads,true,long double> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "precision"; }
   static auto className() { return "Quads"; }
   static auto GNDSName() { return "quads"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<int>{}
            / Meta<>("length") |
         Defaulted<int>{0}
            / Meta<>("start") |
         std::optional<std::string>{}
            / Meta<>("valueType")
      ;
   }

public:

   using Component::construct;
   using BodyText::operator=;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
      static inline const int start = 0;
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      mutable std::optional<int> length;
      mutable Defaulted<int> start{0};
      mutable std::optional<std::string> valueType;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // length
   const std::optional<int> &length() const
    { return content.length; }
   std::optional<int> &length()
    { return content.length; }

   // start
   const Defaulted<int> &start() const
    { return content.start; }
   Defaulted<int> &start()
    { return content.start; }

   // valueType
   const std::optional<std::string> &valueType() const
    { return content.valueType; }
   std::optional<std::string> &valueType()
    { return content.valueType; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // length(value)
   Quads &length(const std::optional<int> &obj)
    { BodyText::length(length() = obj); return *this; }

   // start(value)
   Quads &start(const Defaulted<int> &obj)
    { BodyText::start(content.start = obj); return *this; }
   Quads &start(const std::optional<int> &obj)
    { BodyText::start(content.start = obj); return *this; }

   // valueType(value)
   Quads &valueType(const std::optional<std::string> &obj)
    { BodyText::valueType(valueType() = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Quads() :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish();
   }

   // copy
   Quads(const Quads &other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Quads(Quads &&other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Quads(const Node &node) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish(node);
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Quads(
      const std::optional<int> &length,
      const std::optional<int> &start,
      const std::optional<std::string> &valueType
   ) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      },
      content{
         length,
         Defaulted<int>(defaults.start,start),
         valueType
      }
   {
      Component::finish();
   }

   // from vector
   template<class T, class = std::enable_if_t<body::template supported<T>>>
   Quads(const std::vector<T> &vector) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish(vector);
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Quads &operator=(const Quads &) = default;

   // move
   Quads &operator=(Quads &&) = default;
}; // class Quads

} // namespace precision



// -----------------------------------------------------------------------------
// precision::
// class Varfloats
// -----------------------------------------------------------------------------

namespace precision {

class Varfloats : public Component<Varfloats,true> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "precision"; }
   static auto className() { return "Varfloats"; }
   static auto GNDSName() { return "varfloats"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<int>{}
            / Meta<>("length") |
         Defaulted<int>{0}
            / Meta<>("start") |
         std::optional<std::string>{}
            / Meta<>("valueType")
      ;
   }

public:

   using Component::construct;
   using BodyText::operator=;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
      static inline const int start = 0;
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      mutable std::optional<int> length;
      mutable Defaulted<int> start{0};
      mutable std::optional<std::string> valueType;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // length
   const std::optional<int> &length() const
    { return content.length; }
   std::optional<int> &length()
    { return content.length; }

   // start
   const Defaulted<int> &start() const
    { return content.start; }
   Defaulted<int> &start()
    { return content.start; }

   // valueType
   const std::optional<std::string> &valueType() const
    { return content.valueType; }
   std::optional<std::string> &valueType()
    { return content.valueType; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // length(value)
   Varfloats &length(const std::optional<int> &obj)
    { BodyText::length(length() = obj); return *this; }

   // start(value)
   Varfloats &start(const Defaulted<int> &obj)
    { BodyText::start(content.start = obj); return *this; }
   Varfloats &start(const std::optional<int> &obj)
    { BodyText::start(content.start = obj); return *this; }

   // valueType(value)
   Varfloats &valueType(const std::optional<std::string> &obj)
    { BodyText::valueType(valueType() = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Varfloats() :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish();
   }

   // copy
   Varfloats(const Varfloats &other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Varfloats(Varfloats &&other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Varfloats(const Node &node) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish(node);
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Varfloats(
      const std::optional<int> &length,
      const std::optional<int> &start,
      const std::optional<std::string> &valueType
   ) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      },
      content{
         length,
         Defaulted<int>(defaults.start,start),
         valueType
      }
   {
      Component::finish();
   }

   // from vector
   template<class T, class = std::enable_if_t<body::template supported<T>>>
   Varfloats(const std::vector<T> &vector) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish(vector);
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Varfloats &operator=(const Varfloats &) = default;

   // move
   Varfloats &operator=(Varfloats &&) = default;
}; // class Varfloats

} // namespace precision



// -----------------------------------------------------------------------------
// precision::
// class Vardoubles
// -----------------------------------------------------------------------------

namespace precision {

class Vardoubles : public Component<Vardoubles,true> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "precision"; }
   static auto className() { return "Vardoubles"; }
   static auto GNDSName() { return "vardoubles"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<int>{}
            / Meta<>("length") |
         Defaulted<int>{0}
            / Meta<>("start") |
         std::optional<std::string>{}
            / Meta<>("valueType")
      ;
   }

public:

   using Component::construct;
   using BodyText::operator=;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
      static inline const int start = 0;
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      mutable std::optional<int> length;
      mutable Defaulted<int> start{0};
      mutable std::optional<std::string> valueType;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // length
   const std::optional<int> &length() const
    { return content.length; }
   std::optional<int> &length()
    { return content.length; }

   // start
   const Defaulted<int> &start() const
    { return content.start; }
   Defaulted<int> &start()
    { return content.start; }

   // valueType
   const std::optional<std::string> &valueType() const
    { return content.valueType; }
   std::optional<std::string> &valueType()
    { return content.valueType; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // length(value)
   Vardoubles &length(const std::optional<int> &obj)
    { BodyText::length(length() = obj); return *this; }

   // start(value)
   Vardoubles &start(const Defaulted<int> &obj)
    { BodyText::start(content.start = obj); return *this; }
   Vardoubles &start(const std::optional<int> &obj)
    { BodyText::start(content.start = obj); return *this; }

   // valueType(value)
   Vardoubles &valueType(const std::optional<std::string> &obj)
    { BodyText::valueType(valueType() = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Vardoubles() :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish();
   }

   // copy
   Vardoubles(const Vardoubles &other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Vardoubles(Vardoubles &&other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Vardoubles(const Node &node) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish(node);
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Vardoubles(
      const std::optional<int> &length,
      const std::optional<int> &start,
      const std::optional<std::string> &valueType
   ) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      },
      content{
         length,
         Defaulted<int>(defaults.start,start),
         valueType
      }
   {
      Component::finish();
   }

   // from vector
   template<class T, class = std::enable_if_t<body::template supported<T>>>
   Vardoubles(const std::vector<T> &vector) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish(vector);
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Vardoubles &operator=(const Vardoubles &) = default;

   // move
   Vardoubles &operator=(Vardoubles &&) = default;
}; // class Vardoubles

} // namespace precision



// -----------------------------------------------------------------------------
// precision::
// class Varquads
// -----------------------------------------------------------------------------

namespace precision {

class Varquads : public Component<Varquads,true> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "precision"; }
   static auto className() { return "Varquads"; }
   static auto GNDSName() { return "varquads"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<int>{}
            / Meta<>("length") |
         Defaulted<int>{0}
            / Meta<>("start") |
         std::optional<std::string>{}
            / Meta<>("valueType")
      ;
   }

public:

   using Component::construct;
   using BodyText::operator=;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
      static inline const int start = 0;
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      mutable std::optional<int> length;
      mutable Defaulted<int> start{0};
      mutable std::optional<std::string> valueType;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // length
   const std::optional<int> &length() const
    { return content.length; }
   std::optional<int> &length()
    { return content.length; }

   // start
   const Defaulted<int> &start() const
    { return content.start; }
   Defaulted<int> &start()
    { return content.start; }

   // valueType
   const std::optional<std::string> &valueType() const
    { return content.valueType; }
   std::optional<std::string> &valueType()
    { return content.valueType; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // length(value)
   Varquads &length(const std::optional<int> &obj)
    { BodyText::length(length() = obj); return *this; }

   // start(value)
   Varquads &start(const Defaulted<int> &obj)
    { BodyText::start(content.start = obj); return *this; }
   Varquads &start(const std::optional<int> &obj)
    { BodyText::start(content.start = obj); return *this; }

   // valueType(value)
   Varquads &valueType(const std::optional<std::string> &obj)
    { BodyText::valueType(valueType() = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Varquads() :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish();
   }

   // copy
   Varquads(const Varquads &other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Varquads(Varquads &&other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Varquads(const Node &node) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish(node);
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Varquads(
      const std::optional<int> &length,
      const std::optional<int> &start,
      const std::optional<std::string> &valueType
   ) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      },
      content{
         length,
         Defaulted<int>(defaults.start,start),
         valueType
      }
   {
      Component::finish();
   }

   // from vector
   template<class T, class = std::enable_if_t<body::template supported<T>>>
   Varquads(const std::vector<T> &vector) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish(vector);
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Varquads &operator=(const Varquads &) = default;

   // move
   Varquads &operator=(Varquads &&) = default;
}; // class Varquads

} // namespace precision



// -----------------------------------------------------------------------------
// precision::
// class Numbers
// -----------------------------------------------------------------------------

namespace precision {

class Numbers : public Component<Numbers> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "precision"; }
   static auto className() { return "Numbers"; }
   static auto GNDSName() { return "numbers"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         Defaulted<double>{2.718281828459045235360287471352662497757247093700}
            / Meta<>("adouble") |
         Defaulted<float>{3.141592653589793238462643383279502884197169399375}
            / Meta<>("afloat") |
         Defaulted<long double>{1.414213562373095048801688724209698078569671875377}
            / Meta<>("aquad") |
         // children
         std::optional<precision::Doubles>{}
            / --Child<>("doubles") |
         std::optional<precision::Floats>{}
            / --Child<>("floats") |
         std::optional<precision::Quads>{}
            / --Child<>("quads") |
         std::optional<precision::Vardoubles>{}
            / --Child<>("vardoubles") |
         std::optional<precision::Varfloats>{}
            / --Child<>("varfloats") |
         std::optional<precision::Varquads>{}
            / --Child<>("varquads")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
      static inline const double adouble = 2.718281828459045235360287471352662497757247093700;
      static inline const float afloat = 3.141592653589793238462643383279502884197169399375;
      static inline const long double aquad = 1.414213562373095048801688724209698078569671875377;
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      Defaulted<double> adouble{2.718281828459045235360287471352662497757247093700};
      Defaulted<float> afloat{3.141592653589793238462643383279502884197169399375};
      Defaulted<long double> aquad{1.414213562373095048801688724209698078569671875377};

      // children
      std::optional<precision::Doubles> doubles;
      std::optional<precision::Floats> floats;
      std::optional<precision::Quads> quads;
      std::optional<precision::Vardoubles> vardoubles;
      std::optional<precision::Varfloats> varfloats;
      std::optional<precision::Varquads> varquads;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // adouble
   const Defaulted<double> &adouble() const
    { return content.adouble; }
   Defaulted<double> &adouble()
    { return content.adouble; }

   // afloat
   const Defaulted<float> &afloat() const
    { return content.afloat; }
   Defaulted<float> &afloat()
    { return content.afloat; }

   // aquad
   const Defaulted<long double> &aquad() const
    { return content.aquad; }
   Defaulted<long double> &aquad()
    { return content.aquad; }

   // doubles
   const std::optional<precision::Doubles> &doubles() const
    { return content.doubles; }
   std::optional<precision::Doubles> &doubles()
    { return content.doubles; }

   // floats
   const std::optional<precision::Floats> &floats() const
    { return content.floats; }
   std::optional<precision::Floats> &floats()
    { return content.floats; }

   // quads
   const std::optional<precision::Quads> &quads() const
    { return content.quads; }
   std::optional<precision::Quads> &quads()
    { return content.quads; }

   // vardoubles
   const std::optional<precision::Vardoubles> &vardoubles() const
    { return content.vardoubles; }
   std::optional<precision::Vardoubles> &vardoubles()
    { return content.vardoubles; }

   // varfloats
   const std::optional<precision::Varfloats> &varfloats() const
    { return content.varfloats; }
   std::optional<precision::Varfloats> &varfloats()
    { return content.varfloats; }

   // varquads
   const std::optional<precision::Varquads> &varquads() const
    { return content.varquads; }
   std::optional<precision::Varquads> &varquads()
    { return content.varquads; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // adouble(value)
   Numbers &adouble(const Defaulted<double> &obj)
    { content.adouble = obj; return *this; }
   Numbers &adouble(const std::optional<double> &obj)
    { content.adouble = obj; return *this; }

   // afloat(value)
   Numbers &afloat(const Defaulted<float> &obj)
    { content.afloat = obj; return *this; }
   Numbers &afloat(const std::optional<float> &obj)
    { content.afloat = obj; return *this; }

   // aquad(value)
   Numbers &aquad(const Defaulted<long double> &obj)
    { content.aquad = obj; return *this; }
   Numbers &aquad(const std::optional<long double> &obj)
    { content.aquad = obj; return *this; }

   // doubles(value)
   Numbers &doubles(const std::optional<precision::Doubles> &obj)
    { doubles() = obj; return *this; }

   // floats(value)
   Numbers &floats(const std::optional<precision::Floats> &obj)
    { floats() = obj; return *this; }

   // quads(value)
   Numbers &quads(const std::optional<precision::Quads> &obj)
    { quads() = obj; return *this; }

   // vardoubles(value)
   Numbers &vardoubles(const std::optional<precision::Vardoubles> &obj)
    { vardoubles() = obj; return *this; }

   // varfloats(value)
   Numbers &varfloats(const std::optional<precision::Varfloats> &obj)
    { varfloats() = obj; return *this; }

   // varquads(value)
   Numbers &varquads(const std::optional<precision::Varquads> &obj)
    { varquads() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Numbers() :
      Component{
         BodyText{},
         content.adouble,
         content.afloat,
         content.aquad,
         content.doubles,
         content.floats,
         content.quads,
         content.vardoubles,
         content.varfloats,
         content.varquads
      }
   {
      Component::finish();
   }

   // copy
   Numbers(const Numbers &other) :
      Component{
         other,
         content.adouble,
         content.afloat,
         content.aquad,
         content.doubles,
         content.floats,
         content.quads,
         content.vardoubles,
         content.varfloats,
         content.varquads
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Numbers(Numbers &&other) :
      Component{
         other,
         content.adouble,
         content.afloat,
         content.aquad,
         content.doubles,
         content.floats,
         content.quads,
         content.vardoubles,
         content.varfloats,
         content.varquads
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Numbers(const Node &node) :
      Component{
         BodyText{},
         content.adouble,
         content.afloat,
         content.aquad,
         content.doubles,
         content.floats,
         content.quads,
         content.vardoubles,
         content.varfloats,
         content.varquads
      }
   {
      Component::finish(node);
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Numbers(
      const std::optional<double> &adouble,
      const std::optional<float> &afloat,
      const std::optional<long double> &aquad,
      const std::optional<precision::Doubles> &doubles,
      const std::optional<precision::Floats> &floats,
      const std::optional<precision::Quads> &quads,
      const std::optional<precision::Vardoubles> &vardoubles,
      const std::optional<precision::Varfloats> &varfloats,
      const std::optional<precision::Varquads> &varquads
   ) :
      Component{
         BodyText{},
         content.adouble,
         content.afloat,
         content.aquad,
         content.doubles,
         content.floats,
         content.quads,
         content.vardoubles,
         content.varfloats,
         content.varquads
      },
      content{
         Defaulted<double>(defaults.adouble,adouble),
         Defaulted<float>(defaults.afloat,afloat),
         Defaulted<long double>(defaults.aquad,aquad),
         doubles,
         floats,
         quads,
         vardoubles,
         varfloats,
         varquads
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Numbers &operator=(const Numbers &) = default;

   // move
   Numbers &operator=(Numbers &&) = default;
}; // class Numbers

} // namespace precision



// -----------------------------------------------------------------------------
// key::meta::
// -----------------------------------------------------------------------------

namespace key {
namespace meta {

inline const Meta<>
   adouble("adouble"),
   afloat("afloat"),
   aquad("aquad"),
   length("length"),
   start("start"),
   valueType("valueType");

} // namespace meta
using namespace meta;
} // namespace key


// -----------------------------------------------------------------------------
// precision::key::child::
// -----------------------------------------------------------------------------

namespace precision {
namespace key {
namespace child {

inline const Child<>
   doubles("doubles"),
   floats("floats"),
   numbers("numbers"),
   quads("quads"),
   vardoubles("vardoubles"),
   varfloats("varfloats"),
   varquads("varquads");

} // namespace child
using namespace child;
} // namespace key
} // namespace precision
