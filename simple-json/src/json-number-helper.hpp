
// types
template<class T, class U>
struct types {
   // T/U integral/floating
   static constexpr bool
      tintegral = json::integral<T>, tfloating = json::floating<T>,
      uintegral = json::integral<U>, ufloating = json::floating<U>;

   // types: integral, floating
   using integral = std::conditional_t<
      tintegral, T, std::conditional_t<uintegral, U, void>>;
   using floating = std::conditional_t<
      tfloating, T, std::conditional_t<ufloating, U, void>>;

   // compatible: are T and U compatible, for our purposes?
   // True iff T and U aren't both integral and aren't both floating point,
   // and are both either void, or in number's variant.
   static constexpr bool compatible =
     !(tintegral && uintegral) && (allowed<T,variant> || same<T,void>) &&
     !(tfloating && ufloating) && (allowed<U,variant> || same<U,void>);
};
