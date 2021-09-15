
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
// class Areals
// -----------------------------------------------------------------------------

namespace precision {

class Areals : public Component<Areals,true> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "precision"; }
   static auto className() { return "Areals"; }
   static auto GNDSName() { return "areals"; }

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
   Areals &length(const std::optional<int> &obj)
    { BodyText::length(length() = obj); return *this; }

   // start(value)
   Areals &start(const Defaulted<int> &obj)
    { BodyText::start(content.start = obj); return *this; }
   Areals &start(const std::optional<int> &obj)
    { BodyText::start(content.start = obj); return *this; }

   // valueType(value)
   Areals &valueType(const std::optional<std::string> &obj)
    { BodyText::valueType(valueType() = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Areals() :
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
   Areals(const Areals &other) :
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
   Areals(Areals &&other) :
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
   Areals(const Node &node) :
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
   explicit Areals(
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
   Areals(const std::vector<T> &vector) :
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
   Areals &operator=(const Areals &) = default;

   // move
   Areals &operator=(Areals &&) = default;
}; // class Areals

} // namespace precision



// -----------------------------------------------------------------------------
// precision::
// class Breals
// -----------------------------------------------------------------------------

namespace precision {

class Breals : public Component<Breals,true> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "precision"; }
   static auto className() { return "Breals"; }
   static auto GNDSName() { return "breals"; }

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
   Breals &length(const std::optional<int> &obj)
    { BodyText::length(length() = obj); return *this; }

   // start(value)
   Breals &start(const Defaulted<int> &obj)
    { BodyText::start(content.start = obj); return *this; }
   Breals &start(const std::optional<int> &obj)
    { BodyText::start(content.start = obj); return *this; }

   // valueType(value)
   Breals &valueType(const std::optional<std::string> &obj)
    { BodyText::valueType(valueType() = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Breals() :
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
   Breals(const Breals &other) :
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
   Breals(Breals &&other) :
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
   Breals(const Node &node) :
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
   explicit Breals(
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
   Breals(const std::vector<T> &vector) :
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
   Breals &operator=(const Breals &) = default;

   // move
   Breals &operator=(Breals &&) = default;
}; // class Breals

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
         Defaulted<double>{1.414213562373095048801688724209698078569671875377}
            / Meta<>("adouble") |
         Defaulted<float>{1.732050807568877293527446341505872366942805253810}
            / Meta<>("afloat") |
         Defaulted<long double>{2.236067977499789696409173668731276235440618359612}
            / Meta<>("aquad") |
         Defaulted<double>{2.449489742783178098197284074705891391965947480657}
            / Meta<>("bdouble") |
         Defaulted<float>{2.645751311064590590501615753639260425710259183082}
            / Meta<>("bfloat") |
         Defaulted<long double>{2.828427124746190097603377448419396157139343750754}
            / Meta<>("bquad") |
         // children
         std::optional<precision::Areals>{}
            / --Child<>("areals") |
         std::optional<precision::Breals>{}
            / --Child<>("breals") |
         std::optional<precision::Doubles>{}
            / --Child<>("doubles") |
         std::optional<precision::Floats>{}
            / --Child<>("floats") |
         std::optional<precision::Quads>{}
            / --Child<>("quads")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
      static inline const double adouble = 1.414213562373095048801688724209698078569671875377;
      static inline const float afloat = 1.732050807568877293527446341505872366942805253810;
      static inline const long double aquad = 2.236067977499789696409173668731276235440618359612;
      static inline const double bdouble = 2.449489742783178098197284074705891391965947480657;
      static inline const float bfloat = 2.645751311064590590501615753639260425710259183082;
      static inline const long double bquad = 2.828427124746190097603377448419396157139343750754;
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      Defaulted<double> adouble{1.414213562373095048801688724209698078569671875377};
      Defaulted<float> afloat{1.732050807568877293527446341505872366942805253810};
      Defaulted<long double> aquad{2.236067977499789696409173668731276235440618359612};
      Defaulted<double> bdouble{2.449489742783178098197284074705891391965947480657};
      Defaulted<float> bfloat{2.645751311064590590501615753639260425710259183082};
      Defaulted<long double> bquad{2.828427124746190097603377448419396157139343750754};

      // children
      std::optional<precision::Areals> areals;
      std::optional<precision::Breals> breals;
      std::optional<precision::Doubles> doubles;
      std::optional<precision::Floats> floats;
      std::optional<precision::Quads> quads;
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

   // bdouble
   const Defaulted<double> &bdouble() const
    { return content.bdouble; }
   Defaulted<double> &bdouble()
    { return content.bdouble; }

   // bfloat
   const Defaulted<float> &bfloat() const
    { return content.bfloat; }
   Defaulted<float> &bfloat()
    { return content.bfloat; }

   // bquad
   const Defaulted<long double> &bquad() const
    { return content.bquad; }
   Defaulted<long double> &bquad()
    { return content.bquad; }

   // areals
   const std::optional<precision::Areals> &areals() const
    { return content.areals; }
   std::optional<precision::Areals> &areals()
    { return content.areals; }

   // breals
   const std::optional<precision::Breals> &breals() const
    { return content.breals; }
   std::optional<precision::Breals> &breals()
    { return content.breals; }

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

   // bdouble(value)
   Numbers &bdouble(const Defaulted<double> &obj)
    { content.bdouble = obj; return *this; }
   Numbers &bdouble(const std::optional<double> &obj)
    { content.bdouble = obj; return *this; }

   // bfloat(value)
   Numbers &bfloat(const Defaulted<float> &obj)
    { content.bfloat = obj; return *this; }
   Numbers &bfloat(const std::optional<float> &obj)
    { content.bfloat = obj; return *this; }

   // bquad(value)
   Numbers &bquad(const Defaulted<long double> &obj)
    { content.bquad = obj; return *this; }
   Numbers &bquad(const std::optional<long double> &obj)
    { content.bquad = obj; return *this; }

   // areals(value)
   Numbers &areals(const std::optional<precision::Areals> &obj)
    { areals() = obj; return *this; }

   // breals(value)
   Numbers &breals(const std::optional<precision::Breals> &obj)
    { breals() = obj; return *this; }

   // doubles(value)
   Numbers &doubles(const std::optional<precision::Doubles> &obj)
    { doubles() = obj; return *this; }

   // floats(value)
   Numbers &floats(const std::optional<precision::Floats> &obj)
    { floats() = obj; return *this; }

   // quads(value)
   Numbers &quads(const std::optional<precision::Quads> &obj)
    { quads() = obj; return *this; }

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
         content.bdouble,
         content.bfloat,
         content.bquad,
         content.areals,
         content.breals,
         content.doubles,
         content.floats,
         content.quads
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
         content.bdouble,
         content.bfloat,
         content.bquad,
         content.areals,
         content.breals,
         content.doubles,
         content.floats,
         content.quads
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
         content.bdouble,
         content.bfloat,
         content.bquad,
         content.areals,
         content.breals,
         content.doubles,
         content.floats,
         content.quads
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
         content.bdouble,
         content.bfloat,
         content.bquad,
         content.areals,
         content.breals,
         content.doubles,
         content.floats,
         content.quads
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
      const std::optional<double> &bdouble,
      const std::optional<float> &bfloat,
      const std::optional<long double> &bquad,
      const std::optional<precision::Areals> &areals,
      const std::optional<precision::Breals> &breals,
      const std::optional<precision::Doubles> &doubles,
      const std::optional<precision::Floats> &floats,
      const std::optional<precision::Quads> &quads
   ) :
      Component{
         BodyText{},
         content.adouble,
         content.afloat,
         content.aquad,
         content.bdouble,
         content.bfloat,
         content.bquad,
         content.areals,
         content.breals,
         content.doubles,
         content.floats,
         content.quads
      },
      content{
         Defaulted<double>(defaults.adouble,adouble),
         Defaulted<float>(defaults.afloat,afloat),
         Defaulted<long double>(defaults.aquad,aquad),
         Defaulted<double>(defaults.bdouble,bdouble),
         Defaulted<float>(defaults.bfloat,bfloat),
         Defaulted<long double>(defaults.bquad,bquad),
         areals,
         breals,
         doubles,
         floats,
         quads
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
   bdouble("bdouble"),
   bfloat("bfloat"),
   bquad("bquad"),
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
   areals("areals"),
   breals("breals"),
   doubles("doubles"),
   floats("floats"),
   numbers("numbers"),
   quads("quads");

} // namespace child
using namespace child;
} // namespace key
} // namespace precision
