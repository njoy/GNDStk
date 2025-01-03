
// -----------------------------------------------------------------------------
// number
// In JSON: integral or floating point number.
// -----------------------------------------------------------------------------

class number : public std::variant<
   // unsigned integers
   atom<unsigned char>,
   atom<unsigned short>,
   atom<unsigned int>,
   atom<unsigned long>,
   atom<unsigned long long>,
   // signed integers
   atom<signed char>,
   atom<short>,
   atom<int>,
   atom<long>,
   atom<long long>,
   // floating points
   atom<double>,
   atom<long double>,
   atom<float>
> {
   // ------------------------
   // Helper: readableAs
   // ------------------------

   // Are the std::string's contents *completely* readable as a T? For example,
   // "123" is completely readable as an int, but "123foo" is not. Neither is,
   // say, "3.1415927", which in other interpretations might qualify as int 3.
   // If yes, place the so-read value into the out parameter. Remark: The out
   // parameter need not be of type T. In some calls it is, but in others, OUT
   // is (derived from) a std::variant that has T as an alternative.
   template<class T, class OUT, class = require<invar<T,variant>>>
   static bool readableAs(const std::string &str, OUT &out) noexcept
   {
      #ifndef JSON_CHARS
         if constexpr (integral<T>)
      #endif
         {
            // Readable?
            T ret;
            const char *c = &str[0], *const end = c + str.size();
            while (isspace(*c)) ++c;
            auto [ptr,err] = std::from_chars(*c == '+' ? ++c : c, end, ret);
            if (err != std::errc()) return false;
            // Completely?
            while (isspace(*ptr)) ++ptr;
            return ptr == end ? out = ret, true : false;
         }
      #ifndef JSON_CHARS
         else {
            try {
               // Readable?
               size_t idx;
               if constexpr (same<T,double     >) out = std::stod (str,&idx);
               if constexpr (same<T,long double>) out = std::stold(str,&idx);
               if constexpr (same<T,float      >) out = std::stof (str,&idx);
               // Completely?
               while (isspace(str[idx])) ++idx;
               return idx == str.size();
            } catch (...) {
            }
            return false;
         }
      #endif
   }

public:

   // ------------------------
   // types
   // ------------------------

   template<class T, class U>
   class types {
      // Are T/U integral/floating?
      static constexpr bool
         tintegral = json::integral<T>, tfloating = json::floating<T>,
         uintegral = json::integral<U>, ufloating = json::floating<U>;

   public:

      // types: integral, floating
      using integral = std::conditional_t<
         tintegral, T, std::conditional_t<uintegral, U, void>>;
      using floating = std::conditional_t<
         tfloating, T, std::conditional_t<ufloating, U, void>>;

      // Are T and U compatible, for our purposes?
      // True iff T and U aren't both integral and aren't both floating point,
      // and are both either void, or in number's variant.
      static constexpr bool compatible =
         !(tintegral && uintegral) && (invar<T,variant> || same<T,void>) &&
         !(tfloating && ufloating) && (invar<U,variant> || same<U,void>);
   };

   JSON_IO(number);

   // ------------------------
   // Construction
   // ------------------------

   // inherited
   using variant::variant;

   // default (override inherited, because we want to select int)
   number() : variant(0) { }

   // from std::variant<...> (instance of base class)
   number(const variant &base) : variant(base) { }
   number(variant &&base) : variant(std::move(base)) { }

   // ------------------------
   // Assignment
   // ------------------------

   template<class FROM, class = require<assignable<variant, FROM &&>>>
   number &operator=(FROM &&from)
   {
      return variant::operator=(std::forward<FROM>(from)), *this;
   }

   // ------------------------
   // Conversion
   // ------------------------

   // to types T in number's variant; also allow T == bool
   // Returns by value, so that we don't need to assume that the underlying
   // variant holds exactly a T. Also, then, we need only a const version.
   template<class T, class = require<invar<T,variant> || same<T,bool>>>
   operator T() const
   {
      return std::visit(
         [](const auto &alt) { return T(alt); },
         static_cast<const variant &>(*this)
      );
   }

   // ------------------------
   // Other
   // ------------------------

   // holds<T>
   template<class T, class = require<invar<T,variant>>>
   bool holds() const { return std::holds_alternative<atom<T>>(*this); }

   // get<T>
   template<class T, class = require<invar<T,variant>>>
   const T &get() const { return std::get<atom<T>>(*this); }
   template<class T, class = require<invar<T,variant>>>
   T &get() { return std::get<atom<T>>(*this); }

   // make
   template<class T, class = require<invar<T,variant> || same<T,bool>>>
   bool make(T &to) const
   {
      return std::visit(
         [&to](const auto &alt)
         {
            return detail::base<std::decay_t<decltype(alt)>>(to=T(alt)) == alt;
         },
         static_cast<const variant &>(*this)
      );
   }
};
