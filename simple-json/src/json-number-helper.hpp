
// types
template<class T, class U>
struct types {
   // T/U integral/floating
   static constexpr bool
      tintegral = detail::isintegral<T>, tfloating = detail::isfloating<T>,
      uintegral = detail::isintegral<U>, ufloating = detail::isfloating<U>;

   // types: integral, floating
   using integral = std::conditional_t<
      tintegral, T, std::conditional_t<uintegral, U, void>>;
   using floating = std::conditional_t<
      tfloating, T, std::conditional_t<ufloating, U, void>>;

   // compatible: are T and U compatible, for our purposes?
   // True iff T and U aren't both integral and aren't both floating-point,
   // and are both either void, or in number's variant.
   static constexpr bool compatible =
     !(tintegral && uintegral) &&
     !(tfloating && ufloating) &&
      (detail::invar<T,variant> || std::is_same_v<T,void>) &&
      (detail::invar<U,variant> || std::is_same_v<U,void>);
};
