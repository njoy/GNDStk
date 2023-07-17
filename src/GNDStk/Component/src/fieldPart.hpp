
// -----------------------------------------------------------------------------
// FieldPart
// As with class Field, this is intentionally defined within class Component.
// -----------------------------------------------------------------------------

// FieldPart is designed to be used in tandem with either of these:
//    Field<variant<...>>
//    Field<vector<variant<...>>>
// with one FieldPart object for each alternative in the variant.
template<class WHOLE, class PART>
class FieldPart<Field<WHOLE>,PART> {
   Field<WHOLE> &whole;

   static_assert(
      detail::isVariant_v<WHOLE> || detail::isVectorOfVariant<WHOLE>::value,
     "FieldPart<Field<WHOLE>,PART>: WHOLE must be variant or vector<variant>"
   );

public:

   // ------------------------
   // Constructors
   // ------------------------

   // Because Field<WHOLE> &whole would be wrong
   FieldPart(const FieldPart &) = delete; // no copy
   FieldPart(FieldPart &&) = delete; // no move

   explicit FieldPart(Field<WHOLE> &whole) :
      whole(whole)
   { }

   // ------------------------
   // ptr()
   // Get as PART *
   // For Field<variant<...>>
   // ------------------------

   // const
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   const PART *ptr() const
   {
      return std::get_if<PART>(&whole());
   }

   // non-const
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   PART *ptr()
   {
      return std::get_if<PART>(&whole());
   }

   // ------------------------
   // ref()
   // Get as PART &
   // For Field<variant<...>>
   // ------------------------

   // const
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   const PART &ref() const
   {
      const PART *const p = ptr();
      if (p) return *p;
      log::error(
        "Cannot get reference; variant contains a different alternative");
      log::member("FieldPart::ref()");
      throw std::exception{};
   }

   // non-const
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   PART &ref()
   {
      return const_cast<PART &>(std::as_const(*this).template ref());
   }

   // ------------------------
   // opt()
   // Get as optional<PART>
   // For Field<variant<...>>
   // ------------------------

   // Makes a std::optional. So, we must return by value,
   // and then only the const version is needed.
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   std::optional<PART> opt() const
   {
      const PART *const p = ptr();
      return p ? std::optional<PART>{*p} : std::optional<PART>{};
   }

   // ------------------------
   // operator()
   // Get as PART &
   // For Field<variant<...>>
   // Same as ref()
   // ------------------------

   // const
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   const PART &operator()() const
   {
      try {
         return ref();
      } catch (...) {
         log::member("FieldPart::operator()");
         throw;
      }
   }

   // non-const
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   PART &operator()()
   {
      return const_cast<PART &>(std::as_const(*this)());
   }

   // ------------------------
   // Conversions
   // For Field<variant<...>>
   // ------------------------

   // To PART *
   // Like ptr()
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator const PART *() const { return ptr(); } // const

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator PART *() { return ptr(); } // non-const

   // To PART &
   // Like ref()
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator const PART &() const // const
   {
      try {
         return ref();
      } catch (...) {
         log::member("FieldPart:: conversion to variant alternative");
         throw;
      }
   }

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator PART &() // non-const
   {
      return const_cast<PART &>(std::as_const(*this).operator const PART &());
   }

   // To std::optional<PART>
   // Like opt(), and need const case only
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator std::optional<PART>() const { return opt(); }

   // ------------------------
   // operator()(has(...))
   // has
   // ------------------------

   template<class LOOK>
   auto operator()(const LOOK &look) const ->
      std::enable_if_t<std::is_same_v<decltype(whole(look)),bool>,bool>
   {
      return whole(look);
   }

   template<class LOOK>
   auto has(const LOOK &look) const ->
      std::enable_if_t<std::is_same_v<decltype(whole.has(look)),bool>,bool>
   {
      return whole.has(look);
   }

   // ------------------------
   // size()
   // ------------------------

   // Works where Field<T>.size() works
   template<class T = WHOLE>
   auto size() const -> decltype(std::declval<Field<T>>().size())
   {
      return whole.size();
   }

   // zzz working here

   // ------------------------
   // Getters:
   // If WHOLE == vector
   // ------------------------

   // ptr(Lookup)
   // Get as PART *
   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   const PART *ptr(const KEY &look) const
   {
      return whole.parent.template getter<PART>(whole(),look);
   }

   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   PART *ptr(const KEY &look)
   {
      return whole.parent.template getter<PART>(whole(),look);
   }

   // ref(Lookup)
   // Get as PART &
   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   const PART &ref(const KEY &look) const
   {
      const PART *const p = ptr(look);
      if (p) return *p;
      log::error(
        "Cannot get reference; variant contains a different alternative");
      log::member("FieldPart::ref(Lookup)");
      throw std::exception{};
   }

   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   PART &ref(const KEY &look)
   {
      return const_cast<PART &>(std::as_const(*this).template ref(look));
   }

   // opt(Lookup)
   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   const std::optional<PART> opt(const KEY &look) const
   {
      const PART *const p = ptr(look);
      return p ? std::optional<PART>{*p} : std::optional<PART>{};
   }

   // ------------------------
   // operator[](Lookup)
   // ------------------------

   // qqq This would apply to:
   // qqq Field< T = vector<variant<...,PART,...>> >

   // const
   template<
      LookupMode MODE, class EXTRACTOR, class TYPE, class CONVERTER,
      class T = WHOLE, class = detail::isVector_t<T>>
   decltype(auto)
   operator[](const Lookup<MODE,EXTRACTOR,TYPE,CONVERTER> &look) const
   {
      if constexpr (
         detail::isLookupRefReturn_v<Lookup<MODE,EXTRACTOR,TYPE,CONVERTER>>
      ) {
         // a reference
         try {
            return ref(look);
         } catch (...) {
            log::member("FieldPart::operator[](Lookup)");
            throw;
         }
      } else {
         // bool, or by-value vector
         return whole[look];
      }
   }

   // non-const
   template<
      LookupMode MODE, class EXTRACTOR, class TYPE, class CONVERTER,
      class T = WHOLE, class = detail::isVector_t<T>>
   decltype(auto)
   operator[](const Lookup<MODE,EXTRACTOR,TYPE,CONVERTER> &look)
   {
      if constexpr (
         detail::isLookupRefReturn_v<Lookup<MODE,EXTRACTOR,TYPE,CONVERTER>>
      ) {
         // a reference
         return const_cast<PART &>(std::as_const(*this)(look));
      } else {
         // bool, or by-value vector
         return whole[look];
      }
   }

   // ------------------------
   // Setters
   // Using std::optional
   // ------------------------

   // If WHOLE == variant
   // operator=(value)
   template<class T = WHOLE, std::enable_if_t<detail::isVariant_v<T>, int> = 0>
   FieldPart &operator=(const std::optional<PART> &opt)
   {
      if (opt) whole = opt.value();
      return *this;
   }

   // If WHOLE == vector
   // add(value)
   template<class T = WHOLE, class = detail::isVector_t<T>>
   FieldPart &add(const std::optional<PART> &opt)
   {
      if (opt) whole.add(opt.value());
      return *this;
   }

   // If WHOLE == vector
   // operator+=(value)
   template<class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &operator+=(const std::optional<PART> &opt)
   {
      return add(opt);
   }

   // ------------------------
   // Assignment
   // ------------------------

   // Intentional: don't assign [referenced] whole; doing so would be wrong
   FieldPart &operator=(const FieldPart &) { return *this; }
   FieldPart &operator=(FieldPart &&) { return *this; }
}; // class FieldPart
