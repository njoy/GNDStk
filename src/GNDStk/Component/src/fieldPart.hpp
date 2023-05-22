
// -----------------------------------------------------------------------------
// FieldPart
// As with class Field, this is intentionally defined within class Component.
// -----------------------------------------------------------------------------

template<class WHOLE, class PART>
class FieldPart<Field<WHOLE>,PART> {
   Field<WHOLE> &whole;

   static_assert(
      detail::isVariant_v<WHOLE> || detail::isVectorOfVariant<WHOLE>::value,
     "FieldPart<Field<WHOLE>,PART>: "
     "WHOLE must be variant or vector<variant>"
   );

public:

   // ------------------------
   // Constructors
   // ------------------------

   // Because [Field<WHOLE> &whole] would be wrong
   FieldPart(const FieldPart &) = delete; // no copy
   FieldPart(FieldPart &&) = delete; // no move

   explicit FieldPart(Field<WHOLE> &whole) :
      whole(whole)
   { }

   // ------------------------
   // Getters:
   // If WHOLE == variant
   // ------------------------

   // ptr()
   // Get as PART *
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   const PART *ptr() const
   {
      return whole.parent.template getter<PART>(whole());
   }

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   PART *ptr()
   {
      return whole.parent.template getter<PART>(whole());
   }

   // ref()
   // Get as PART &
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

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   PART &ref()
   {
      return const_cast<PART &>(std::as_const(*this).template ref());
   }

   // opt()
   // Makes a std::optional. So, we must return by value,
   // and then only the const version is needed.
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   const std::optional<PART> opt() const
   {
      const PART *const p = ptr();
      return p ? std::optional<PART>{*p} : std::optional<PART>{};
   }

   // operator()
   // Get as PART &
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

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   PART &operator()()
   {
      return const_cast<PART &>(std::as_const(*this)());
   }

   // ------------------------
   // Conversions
   // If WHOLE == variant
   // ------------------------

   // To PART *
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator const PART *() const { return ptr(); }

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator PART *() { return ptr(); }

   // To PART &
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator const PART &() const
   {
      try {
         return ref();
      } catch (...) {
         log::member("FieldPart:: conversion to variant alternative");
         throw;
      }
   }

   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator PART &()
   {
      return const_cast<PART &>(std::as_const(*this).operator const PART &());
   }

   // To std::optional<PART>
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   operator std::optional<PART>() const { return opt(); }

   // ------------------------
   // has
   // Similar to Field's
   // ------------------------

   /*
   // todo I'm not sure that this would have a clear meaning for FieldPart.
   // For Field, it means whether or not a value exists - either it's not
   // optional, or is optional but has a value. Here, that meaning could be
   // confused with the concept of whether or not the variant contains the
   // part represented by this FieldPart. Think about this.

   // has()
   bool has() const
   {
      if constexpr (detail::isOptional<WHOLE>)
         return wrappedValue.has_value();
      else
         return true;
   }
   */

   // has(key)
   template<class KEY>
   auto has(const KEY &look) const -> std::enable_if_t<
      std::is_same_v<decltype((*this)[GNDStk::has(look)]),bool>, bool
   > {
      return (*this)[GNDStk::has(look)];
   }

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

   // [Lookup]
   template<
      LookupMode MODE, class EXTRACTOR, class TYPE, class CONVERTER,
      class T = WHOLE, class = detail::isVector_t<T>>
   decltype(auto)
   operator[](const Lookup<MODE,EXTRACTOR,TYPE,CONVERTER> &look) const // const
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

   template<
      LookupMode MODE, class EXTRACTOR, class TYPE, class CONVERTER,
      class T = WHOLE, class = detail::isVector_t<T>>
   decltype(auto)
   operator[](const Lookup<MODE,EXTRACTOR,TYPE,CONVERTER> &look) // non-const
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

   // If T == vector
   // size()
   template<
      class T = WHOLE, class = detail::isVector_t<T>>
   size_t size() const
   {
      return whole.size();
   }

   // ------------------------
   // Setters
   // Using std::optional
   // ------------------------

   // If WHOLE == variant
   // replace(value)
   template<class T = WHOLE, class = detail::isVariant_t<T>>
   DERIVED &replace(const std::optional<PART> &opt)
   {
      if (opt) whole = opt.value();
      return whole.parent;
   }

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

   // operator+=(value)
   template<class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &operator+=(const std::optional<PART> &opt)
   {
      return add(opt);
   }

   // If WHOLE == vector
   // replace(Lookup,element)
   template<
      class KEY, class = detail::isLookupRefReturn_t<KEY>,
      class T = WHOLE, class = detail::isVector_t<T>>
   DERIVED &replace(const KEY &look, const std::optional<PART> &opt)
   {
      if (opt) whole[look] = opt.value();
      return whole.parent;
   }

   // ------------------------
   // Assignment
   // ------------------------

   // Intentional: don't assign [referenced] whole; doing so would be wrong
   FieldPart &operator=(const FieldPart &) { return *this; }
   FieldPart &operator=(FieldPart &&) { return *this; }
}; // class FieldPart
