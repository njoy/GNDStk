
// -----------------------------------------------------------------------------
// atom
// -----------------------------------------------------------------------------

#if defined(JSON_RAW)

// ------------------------
// Raw pointer version
// ------------------------

template<class T>
class atom {
   static inline constexpr bool plain = sizeof(T) <= sizeof(std::shared_ptr<T>);
   std::conditional_t<plain, T, T *> val;

public:

   // construction: default
   atom()
   {
      if constexpr ( plain) val = T();
      if constexpr (!plain) val = new T();
   }

   // construction: from T (exactly)
   template<class FROM, class = require<same<FROM,T>>>
   atom(const FROM &from)
   {
      if constexpr ( plain) val = from;
      if constexpr (!plain) val = new T(from);
   }

   // construction: copy
   atom(const atom &other)
   {
      if constexpr ( plain) val = other.val;
      if constexpr (!plain) val = new T(*other.val);
   }

   // construction: move
   atom(atom &&other)
   {
      val = std::move(other.val);
      if constexpr (!plain)
         other.val = nullptr;
   }

   // assignment: copy
   atom &operator=(const atom &other)
   {
      if constexpr ( plain) return  val =  other.val, *this;
      if constexpr (!plain) return *val = *other.val, *this;
   }

   // assignment: move
   atom &operator=(atom &&other)
   {
      val = std::move(other.val);
      if constexpr ( plain) return *this;
      if constexpr (!plain) return other.val = nullptr, *this;
   }

   // assignment: general
   template<class FROM, class = require<assignable<T &, FROM &&>>>
   atom &operator=(FROM &&from)
   {
      if constexpr ( plain) return  val = std::move(from), *this;
      if constexpr (!plain) return *val = std::move(from), *this;
   }

   // conversion: to T
   operator const T &() const
   { if constexpr (plain) return val; else return *val; }
   operator T &()
   { if constexpr (plain) return val; else return *val; }

   // destructor
  ~atom()
   {
      if constexpr (!plain)
         delete val;
   }
};

// ------------------------
// Shared pointer version
// ------------------------

#elif defined(JSON_SHARED)

template<class T>
class atom {
   static inline constexpr bool plain = sizeof(T) <= sizeof(std::shared_ptr<T>);
   std::conditional_t<plain, T, std::shared_ptr<T>> val;

public:

   // construction: default
   atom()
   {
      if constexpr ( plain) val = T();
      if constexpr (!plain) val = std::make_shared<T>();
   }

   // construction: from T (exactly)
   template<class FROM, class = require<same<FROM,T>>>
   atom(const FROM &from)
   {
      if constexpr ( plain) val = from;
      if constexpr (!plain) val = std::make_shared<T>(from);
   }

   // conversion: to T
   operator const T &() const
   { if constexpr (plain) return val; else return *val; }
   operator T &()
   { if constexpr (plain) return val; else return *val; }

   // assignment
   template<class FROM, class = require<assignable<T &, FROM &&>>>
   atom &operator=(FROM &&from)
   {
      if constexpr ( plain) return  val = std::move(from), *this;
      if constexpr (!plain) return *val = std::move(from), *this;
   }
};

// ------------------------
// atom<T> == T
// ------------------------

#else

template<class T>
using atom = T;

#endif
