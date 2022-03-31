
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
   static auto NAMESPACE() { return "precision"; }
   static auto CLASS() { return "Floats"; }
   static auto FIELD() { return "floats"; }

   // Core Interface object to extract metadata and child nodes
   static auto KEYS()
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
   using BlockData::operator=;

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
   } Content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // length
   const std::optional<int> &length() const
    { return Content.length; }
   std::optional<int> &length()
    { return Content.length; }

   // start
   const Defaulted<int> &start() const
    { return Content.start; }
   Defaulted<int> &start()
    { return Content.start; }

   // valueType
   const std::optional<std::string> &valueType() const
    { return Content.valueType; }
   std::optional<std::string> &valueType()
    { return Content.valueType; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // length(value)
   Floats &length(const std::optional<int> &obj)
    { BlockData::length(length() = obj); return *this; }

   // start(value)
   Floats &start(const Defaulted<int> &obj)
    { BlockData::start(start() = obj); return *this; }
   Floats &start(const std::optional<int> &obj)
    { BlockData::start(start() = obj); return *this; }

   // valueType(value)
   Floats &valueType(const std::optional<std::string> &obj)
    { BlockData::valueType(valueType() = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Floats() :
      Component{
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
      }
   {
      Component::finish();
   }

   // copy
   Floats(const Floats &other) :
      Component{
         other,
         this->length(),
         this->start(),
         this->valueType()
      },
      Content{other.Content}
   {
      Component::finish(other);
   }

   // move
   Floats(Floats &&other) :
      Component{
         other,
         this->length(),
         this->start(),
         this->valueType()
      },
      Content{std::move(other.Content)}
   {
      Component::finish(other);
   }

   // from node
   Floats(const Node &node) :
      Component{
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
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
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
      },
      Content{
         length,
         Defaulted<int>(defaults.start,start),
         valueType
      }
   {
      Component::finish();
   }

   // from vector
   template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
   Floats(const std::vector<T> &vector) :
      Component{
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
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
   static auto NAMESPACE() { return "precision"; }
   static auto CLASS() { return "Doubles"; }
   static auto FIELD() { return "doubles"; }

   // Core Interface object to extract metadata and child nodes
   static auto KEYS()
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
   using BlockData::operator=;

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
   } Content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // length
   const std::optional<int> &length() const
    { return Content.length; }
   std::optional<int> &length()
    { return Content.length; }

   // start
   const Defaulted<int> &start() const
    { return Content.start; }
   Defaulted<int> &start()
    { return Content.start; }

   // valueType
   const std::optional<std::string> &valueType() const
    { return Content.valueType; }
   std::optional<std::string> &valueType()
    { return Content.valueType; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // length(value)
   Doubles &length(const std::optional<int> &obj)
    { BlockData::length(length() = obj); return *this; }

   // start(value)
   Doubles &start(const Defaulted<int> &obj)
    { BlockData::start(start() = obj); return *this; }
   Doubles &start(const std::optional<int> &obj)
    { BlockData::start(start() = obj); return *this; }

   // valueType(value)
   Doubles &valueType(const std::optional<std::string> &obj)
    { BlockData::valueType(valueType() = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Doubles() :
      Component{
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
      }
   {
      Component::finish();
   }

   // copy
   Doubles(const Doubles &other) :
      Component{
         other,
         this->length(),
         this->start(),
         this->valueType()
      },
      Content{other.Content}
   {
      Component::finish(other);
   }

   // move
   Doubles(Doubles &&other) :
      Component{
         other,
         this->length(),
         this->start(),
         this->valueType()
      },
      Content{std::move(other.Content)}
   {
      Component::finish(other);
   }

   // from node
   Doubles(const Node &node) :
      Component{
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
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
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
      },
      Content{
         length,
         Defaulted<int>(defaults.start,start),
         valueType
      }
   {
      Component::finish();
   }

   // from vector
   template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
   Doubles(const std::vector<T> &vector) :
      Component{
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
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
   static auto NAMESPACE() { return "precision"; }
   static auto CLASS() { return "Quads"; }
   static auto FIELD() { return "quads"; }

   // Core Interface object to extract metadata and child nodes
   static auto KEYS()
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
   using BlockData::operator=;

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
   } Content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // length
   const std::optional<int> &length() const
    { return Content.length; }
   std::optional<int> &length()
    { return Content.length; }

   // start
   const Defaulted<int> &start() const
    { return Content.start; }
   Defaulted<int> &start()
    { return Content.start; }

   // valueType
   const std::optional<std::string> &valueType() const
    { return Content.valueType; }
   std::optional<std::string> &valueType()
    { return Content.valueType; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // length(value)
   Quads &length(const std::optional<int> &obj)
    { BlockData::length(length() = obj); return *this; }

   // start(value)
   Quads &start(const Defaulted<int> &obj)
    { BlockData::start(start() = obj); return *this; }
   Quads &start(const std::optional<int> &obj)
    { BlockData::start(start() = obj); return *this; }

   // valueType(value)
   Quads &valueType(const std::optional<std::string> &obj)
    { BlockData::valueType(valueType() = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Quads() :
      Component{
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
      }
   {
      Component::finish();
   }

   // copy
   Quads(const Quads &other) :
      Component{
         other,
         this->length(),
         this->start(),
         this->valueType()
      },
      Content{other.Content}
   {
      Component::finish(other);
   }

   // move
   Quads(Quads &&other) :
      Component{
         other,
         this->length(),
         this->start(),
         this->valueType()
      },
      Content{std::move(other.Content)}
   {
      Component::finish(other);
   }

   // from node
   Quads(const Node &node) :
      Component{
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
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
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
      },
      Content{
         length,
         Defaulted<int>(defaults.start,start),
         valueType
      }
   {
      Component::finish();
   }

   // from vector
   template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
   Quads(const std::vector<T> &vector) :
      Component{
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
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
// class Reals
// -----------------------------------------------------------------------------

namespace precision {

class Reals : public Component<Reals,true> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto NAMESPACE() { return "precision"; }
   static auto CLASS() { return "Reals"; }
   static auto FIELD() { return "reals"; }

   // Core Interface object to extract metadata and child nodes
   static auto KEYS()
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
   using BlockData::operator=;

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
   } Content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // length
   const std::optional<int> &length() const
    { return Content.length; }
   std::optional<int> &length()
    { return Content.length; }

   // start
   const Defaulted<int> &start() const
    { return Content.start; }
   Defaulted<int> &start()
    { return Content.start; }

   // valueType
   const std::optional<std::string> &valueType() const
    { return Content.valueType; }
   std::optional<std::string> &valueType()
    { return Content.valueType; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // length(value)
   Reals &length(const std::optional<int> &obj)
    { BlockData::length(length() = obj); return *this; }

   // start(value)
   Reals &start(const Defaulted<int> &obj)
    { BlockData::start(start() = obj); return *this; }
   Reals &start(const std::optional<int> &obj)
    { BlockData::start(start() = obj); return *this; }

   // valueType(value)
   Reals &valueType(const std::optional<std::string> &obj)
    { BlockData::valueType(valueType() = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Reals() :
      Component{
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
      }
   {
      Component::finish();
   }

   // copy
   Reals(const Reals &other) :
      Component{
         other,
         this->length(),
         this->start(),
         this->valueType()
      },
      Content{other.Content}
   {
      Component::finish(other);
   }

   // move
   Reals(Reals &&other) :
      Component{
         other,
         this->length(),
         this->start(),
         this->valueType()
      },
      Content{std::move(other.Content)}
   {
      Component::finish(other);
   }

   // from node
   Reals(const Node &node) :
      Component{
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
      }
   {
      Component::finish(node);
   }

   // from fields
   // std::optional replaces Defaulted; this class knows the default(s)
   explicit Reals(
      const std::optional<int> &length,
      const std::optional<int> &start,
      const std::optional<std::string> &valueType
   ) :
      Component{
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
      },
      Content{
         length,
         Defaulted<int>(defaults.start,start),
         valueType
      }
   {
      Component::finish();
   }

   // from vector
   template<class T, class = std::enable_if_t<BLOCKDATA::template supported<T>>>
   Reals(const std::vector<T> &vector) :
      Component{
         BlockData{},
         this->length(),
         this->start(),
         this->valueType()
      }
   {
      Component::finish(vector);
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Reals &operator=(const Reals &) = default;

   // move
   Reals &operator=(Reals &&) = default;
}; // class Reals

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
   static auto NAMESPACE() { return "precision"; }
   static auto CLASS() { return "Numbers"; }
   static auto FIELD() { return "numbers"; }

   // Core Interface object to extract metadata and child nodes
   static auto KEYS()
   {
      return
         // metadata
         Defaulted<double>
            {1.414213562373095048801688724209698078569671875377}
            / Meta<>("adouble") |
         Defaulted<float>
            {1.732050807568877293527446341505872366942805253810}
            / Meta<>("afloat") |
         Defaulted<long double>
            {2.236067977499789696409173668731276235440618359612}
            / Meta<>("aquad") |
         Defaulted<double>
            {2.449489742783178098197284074705891391965947480657}
            / Meta<>("bdouble") |
         Defaulted<float>
            {2.645751311064590590501615753639260425710259183082}
            / Meta<>("bfloat") |
         Defaulted<long double>
            {2.828427124746190097603377448419396157139343750754}
            / Meta<>("bquad") |
         // children
         std::optional<precision::Doubles>{}
            / --Child<>("doubles") |
         std::optional<precision::Floats>{}
            / --Child<>("floats") |
         std::optional<precision::Quads>{}
            / --Child<>("quads") |
         std::optional<precision::Reals>{}
            / --Child<>("reals")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static inline const struct Defaults {
      static inline const double adouble =
         1.414213562373095048801688724209698078569671875377;
      static inline const float afloat =
         1.732050807568877293527446341505872366942805253810;
      static inline const long double aquad =
         2.236067977499789696409173668731276235440618359612;
      static inline const double bdouble =
         2.449489742783178098197284074705891391965947480657;
      static inline const float bfloat =
         2.645751311064590590501615753639260425710259183082;
      static inline const long double bquad =
         2.828427124746190097603377448419396157139343750754;
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      Defaulted<double> adouble
         { 1.414213562373095048801688724209698078569671875377 };
      Defaulted<float> afloat
         { 1.732050807568877293527446341505872366942805253810 };
      Defaulted<long double> aquad
         { 2.236067977499789696409173668731276235440618359612 };
      Defaulted<double> bdouble
         { 2.449489742783178098197284074705891391965947480657 };
      Defaulted<float> bfloat
         { 2.645751311064590590501615753639260425710259183082 };
      Defaulted<long double> bquad
         { 2.828427124746190097603377448419396157139343750754 };

      // children
      std::optional<precision::Doubles> doubles;
      std::optional<precision::Floats> floats;
      std::optional<precision::Quads> quads;
      std::optional<precision::Reals> reals;
   } Content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // adouble
   const Defaulted<double> &adouble() const
    { return Content.adouble; }
   Defaulted<double> &adouble()
    { return Content.adouble; }

   // afloat
   const Defaulted<float> &afloat() const
    { return Content.afloat; }
   Defaulted<float> &afloat()
    { return Content.afloat; }

   // aquad
   const Defaulted<long double> &aquad() const
    { return Content.aquad; }
   Defaulted<long double> &aquad()
    { return Content.aquad; }

   // bdouble
   const Defaulted<double> &bdouble() const
    { return Content.bdouble; }
   Defaulted<double> &bdouble()
    { return Content.bdouble; }

   // bfloat
   const Defaulted<float> &bfloat() const
    { return Content.bfloat; }
   Defaulted<float> &bfloat()
    { return Content.bfloat; }

   // bquad
   const Defaulted<long double> &bquad() const
    { return Content.bquad; }
   Defaulted<long double> &bquad()
    { return Content.bquad; }

   // doubles
   const std::optional<precision::Doubles> &doubles() const
    { return Content.doubles; }
   std::optional<precision::Doubles> &doubles()
    { return Content.doubles; }

   // floats
   const std::optional<precision::Floats> &floats() const
    { return Content.floats; }
   std::optional<precision::Floats> &floats()
    { return Content.floats; }

   // quads
   const std::optional<precision::Quads> &quads() const
    { return Content.quads; }
   std::optional<precision::Quads> &quads()
    { return Content.quads; }

   // reals
   const std::optional<precision::Reals> &reals() const
    { return Content.reals; }
   std::optional<precision::Reals> &reals()
    { return Content.reals; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // adouble(value)
   Numbers &adouble(const Defaulted<double> &obj)
    { adouble() = obj; return *this; }
   Numbers &adouble(const std::optional<double> &obj)
    { adouble() = obj; return *this; }

   // afloat(value)
   Numbers &afloat(const Defaulted<float> &obj)
    { afloat() = obj; return *this; }
   Numbers &afloat(const std::optional<float> &obj)
    { afloat() = obj; return *this; }

   // aquad(value)
   Numbers &aquad(const Defaulted<long double> &obj)
    { aquad() = obj; return *this; }
   Numbers &aquad(const std::optional<long double> &obj)
    { aquad() = obj; return *this; }

   // bdouble(value)
   Numbers &bdouble(const Defaulted<double> &obj)
    { bdouble() = obj; return *this; }
   Numbers &bdouble(const std::optional<double> &obj)
    { bdouble() = obj; return *this; }

   // bfloat(value)
   Numbers &bfloat(const Defaulted<float> &obj)
    { bfloat() = obj; return *this; }
   Numbers &bfloat(const std::optional<float> &obj)
    { bfloat() = obj; return *this; }

   // bquad(value)
   Numbers &bquad(const Defaulted<long double> &obj)
    { bquad() = obj; return *this; }
   Numbers &bquad(const std::optional<long double> &obj)
    { bquad() = obj; return *this; }

   // doubles(value)
   Numbers &doubles(const std::optional<precision::Doubles> &obj)
    { doubles() = obj; return *this; }

   // floats(value)
   Numbers &floats(const std::optional<precision::Floats> &obj)
    { floats() = obj; return *this; }

   // quads(value)
   Numbers &quads(const std::optional<precision::Quads> &obj)
    { quads() = obj; return *this; }

   // reals(value)
   Numbers &reals(const std::optional<precision::Reals> &obj)
    { reals() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Numbers() :
      Component{
         BlockData{},
         this->adouble(),
         this->afloat(),
         this->aquad(),
         this->bdouble(),
         this->bfloat(),
         this->bquad(),
         this->doubles(),
         this->floats(),
         this->quads(),
         this->reals()
      }
   {
      Component::finish();
   }

   // copy
   Numbers(const Numbers &other) :
      Component{
         other,
         this->adouble(),
         this->afloat(),
         this->aquad(),
         this->bdouble(),
         this->bfloat(),
         this->bquad(),
         this->doubles(),
         this->floats(),
         this->quads(),
         this->reals()
      },
      Content{other.Content}
   {
      Component::finish(other);
   }

   // move
   Numbers(Numbers &&other) :
      Component{
         other,
         this->adouble(),
         this->afloat(),
         this->aquad(),
         this->bdouble(),
         this->bfloat(),
         this->bquad(),
         this->doubles(),
         this->floats(),
         this->quads(),
         this->reals()
      },
      Content{std::move(other.Content)}
   {
      Component::finish(other);
   }

   // from node
   Numbers(const Node &node) :
      Component{
         BlockData{},
         this->adouble(),
         this->afloat(),
         this->aquad(),
         this->bdouble(),
         this->bfloat(),
         this->bquad(),
         this->doubles(),
         this->floats(),
         this->quads(),
         this->reals()
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
      const std::optional<precision::Doubles> &doubles,
      const std::optional<precision::Floats> &floats,
      const std::optional<precision::Quads> &quads,
      const std::optional<precision::Reals> &reals
   ) :
      Component{
         BlockData{},
         this->adouble(),
         this->afloat(),
         this->aquad(),
         this->bdouble(),
         this->bfloat(),
         this->bquad(),
         this->doubles(),
         this->floats(),
         this->quads(),
         this->reals()
      },
      Content{
         Defaulted<double>(defaults.adouble,adouble),
         Defaulted<float>(defaults.afloat,afloat),
         Defaulted<long double>(defaults.aquad,aquad),
         Defaulted<double>(defaults.bdouble,bdouble),
         Defaulted<float>(defaults.bfloat,bfloat),
         Defaulted<long double>(defaults.bquad,bquad),
         doubles,
         floats,
         quads,
         reals
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
   doubles("doubles"),
   floats("floats"),
   numbers("numbers"),
   quads("quads"),
   reals("reals");

} // namespace child
using namespace child;
} // namespace key
} // namespace precision
