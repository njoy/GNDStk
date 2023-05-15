
namespace detail {

// -----------------------------------------------------------------------------
// Re: [optional] vector [of variant]
// -----------------------------------------------------------------------------

// ------------------------
// isVector
// ------------------------

// general
template<class T>
struct isVector
   : public std::false_type
{ };

// for std::vector
template<class T, class Alloc>
struct isVector<std::vector<T,Alloc>>
   : public std::true_type
{ };

// isVector_v
template<class T>
inline constexpr bool isVector_v = isVector<T>::value;

// isVector_t
template<class T>
using isVector_t = std::enable_if_t<isVector_v<T>>;

// ------------------------
// isOptionalVector
// ------------------------

// general
template<class T>
struct isOptionalVector
   : public std::false_type
{ };

// for std::optional<std::vector>
template<class T, class Alloc>
struct isOptionalVector<std::optional<std::vector<T,Alloc>>>
   : public std::true_type
{ };

// isOptionalVector_v
template<class T>
inline constexpr bool isOptionalVector_v = isOptionalVector<T>::value;

// isOptionalVector_t
template<class T>
using isOptionalVector_t = std::enable_if_t<isOptionalVector_v<T>>;

// ------------------------
// isVectorOrOptionalVector
// ------------------------

// general
template<class T>
struct isVectorOrOptionalVector
   : public std::false_type
{ };

// for std::vector
template<class T, class Alloc>
struct isVectorOrOptionalVector<std::vector<T,Alloc>>
   : public std::true_type
{
   using value_type = T;
};

// for std::optional<std::vector>
template<class T, class Alloc>
struct isVectorOrOptionalVector<std::optional<std::vector<T,Alloc>>>
   : public std::true_type
{
   using value_type = T;
};

// isVectorOrOptionalVector_v
template<class T>
inline constexpr bool isVectorOrOptionalVector_v =
   isVectorOrOptionalVector<T>::value;

// isVectorOrOptionalVector_t
template<class T>
using isVectorOrOptionalVector_t =
   std::enable_if_t<isVectorOrOptionalVector_v<T>>;

// ------------------------
// isVectorOfVariant
// ------------------------

// general
template<class T>
struct isVectorOfVariant
   : public std::false_type
{ };

// for std::vector<std::variant<...>>
template<class... Ts, class Alloc>
struct isVectorOfVariant<std::vector<std::variant<Ts...>,Alloc>>
   : public std::true_type
{ };

// isVectorOfVariant_t
template<class T>
using isVectorOfVariant_t = std::enable_if_t<isVectorOfVariant<T>::value>;


// -----------------------------------------------------------------------------
// isDefaulted
// -----------------------------------------------------------------------------

// general
template<class T>
struct isDefaulted
   : public std::false_type
{ };

// for Defaulted
template<class T>
struct isDefaulted<Defaulted<T>>
   : public std::true_type
{ };

// isDefaulted_t
template<class T>
using isDefaulted_t = std::enable_if_t<isDefaulted<T>::value>;


// -----------------------------------------------------------------------------
// isDataNode
// -----------------------------------------------------------------------------

// general
template<class T>
struct isDataNode {
   static constexpr bool value = false;
};

// for DataNode
template<class T, bool preferCDATA>
struct isDataNode<DataNode<T,preferCDATA>> {
   static constexpr bool value = true;
};


// -----------------------------------------------------------------------------
// isLookupRefReturn
// -----------------------------------------------------------------------------

// general
template<class T>
struct isLookupRefReturn
   : public std::false_type
{ };

// for Lookup<get,EXTRACTOR,TYPE,CONVERTER>
template<class EXTRACTOR, class TYPE, class CONVERTER>
struct isLookupRefReturn<Lookup<LookupMode::get,EXTRACTOR,TYPE,CONVERTER>>
{
   static inline constexpr bool value = !is_void_v<TYPE>; // == "TYPE != void"
};

// isLookupRefReturn_v
template<class T>
inline constexpr bool isLookupRefReturn_v = isLookupRefReturn<T>::value;

// isLookupRefReturn_t
template<class T>
using isLookupRefReturn_t = std::enable_if_t<isLookupRefReturn<T>::value>;


// -----------------------------------------------------------------------------
// Re: Component's "forwards"
// -----------------------------------------------------------------------------

// ------------------------
// isMatchExact
// ------------------------

// general
template<class, class>
struct isMatchExact {
   static constexpr int count = 0;
};

// FROM, vector<FROM>
template<class FROM, class Alloc>
struct isMatchExact<FROM,std::vector<FROM,Alloc>> {
   static constexpr int count = 1;
};

// FROM, std::optional<vector<FROM>>
template<class FROM, class Alloc>
struct isMatchExact<FROM,std::optional<std::vector<FROM,Alloc>>> {
   static constexpr int count = 1;
};

// ------------------------
// MatchesExact
// ------------------------

// general
template<class, class>
struct MatchesExact {
   static constexpr size_t count = 0;
};

// FROM, tuple<...>
template<class FROM, class... TOs>
struct MatchesExact<FROM,std::tuple<TOs...>> {
   static constexpr size_t count = (
      isMatchExact<
         FROM,
         std::decay_t<decltype(Node{}(std::declval<TOs>()))>
      >::count +
      ...
   );
};

// ------------------------
// isMatchViable
// ------------------------

// general
template<class, class>
struct isMatchViable {
   static constexpr int count = 0;
};

// FROM, vector<TO>
template<class FROM, class TO, class Alloc>
struct isMatchViable<FROM,std::vector<TO,Alloc>> {
   static constexpr int count = std::is_convertible_v<FROM,TO>;
};

// FROM, std::optional<vector<TO>>
template<class FROM, class TO, class Alloc>
struct isMatchViable<FROM,std::optional<std::vector<TO,Alloc>>> {
   static constexpr int count = std::is_convertible_v<FROM,TO>;
};

// ------------------------
// MatchesViable
// ------------------------

// general
template<class, class>
struct MatchesViable {
   static constexpr size_t count = 0;
};

// FROM, tuple<...>
template<class FROM, class... TOs>
struct MatchesViable<FROM,std::tuple<TOs...>> {
   static constexpr size_t count = (
      isMatchViable<
         FROM,
         std::decay_t<decltype(Node{}(std::declval<TOs>()))>
      >::count +
      ...
   );
};

// ------------------------
// added
// ------------------------

// MC = Meta or Child
template<class COMPONENT, class FROM, class MC>
bool added(
   const COMPONENT &comp,
   const FROM &elem, const MC &mc,
   const bool exact, const size_t n
) {
   // Silences unused-parameter warnings if neither "if constexpr" passes
   (void)n;

   // Remark. The below conditional code (involving both runtime and constexpr
   // ifs) doesn't simplify in what may seem like obvious ways. Note that bool
   // exact is runtime, and came from looking over all types in the caller's
   // fold expression. For a given type from the fold expression, either or both
   // of the following constexpr ifs may fail, and their bodies not make sense
   // or not be something we'd necessarily want to call. (Specifically, if exact
   // and viable matches both == 1, and the viable match is found before the
   // exact one, we want to skip the [return setter] and wait for the exact.)
   using T = std::decay_t<decltype(Node{}(mc))>;
   if ( exact) if constexpr (detail::isMatchExact <FROM,T>::count)
      return comp.setter(*(T *)comp.links[n],elem), true;
   if (!exact) if constexpr (detail::isMatchViable<FROM,T>::count)
      return comp.setter(*(T *)comp.links[n],elem), true;
   return false;
}

// ------------------------
// bracket
// ------------------------

// default
template<class, class, class>
class bracket {
};

// tuple<...>
template<class COMPONENT, class... Ts, class LOOK>
class bracket<COMPONENT,std::tuple<Ts...>,LOOK>
{
   // Field
   template<class T>
   using Field = typename COMPONENT::template Field<T>;

   // has: default
   template<class T, class = int>
   struct has {
      static constexpr bool works = false;
      using type = void;
   };

   // has: if [LOOK{}] works
   template<class T>
   struct has<
      T, decltype((void)std::declval<Field<T>>()[std::declval<LOOK>()],0)
   > {
      static constexpr bool works = true;
      using type = decltype(std::declval<Field<T>>()[std::declval<LOOK>()]);
   };

   // getType: default
   template<class X>
   struct getType {
   };

   // getType: for tuple<>
   template<>
   struct getType<std::tuple<>> {
      using type = void;
   };

   // getType: for tuple<something>
   template<class X, class... Xs>
   struct getType<std::tuple<X,Xs...>> {
      using FIELD = std::decay_t<decltype(Node{}(std::declval<X>()))>;
      using type = std::conditional_t<
         has<FIELD>::works,
         typename has<FIELD>::type,
         typename getType<std::tuple<Xs...>>::type
      >;
   };

   // value, returning pointer
   template<class MC>
   static const void *value(
      const COMPONENT &comp, const LOOK &look, const MC &mc, const size_t n
   ) {
      using FIELD = std::decay_t<decltype(Node{}(mc))>;
      if constexpr (has<FIELD>::works)
         return &comp.getter(*(FIELD *)comp.links[n],look);
      return nullptr;
   }

public:

   // type
   using type = typename getType<std::tuple<Ts...>>::type;

   // count
   static constexpr size_t count = (
      has<std::decay_t<decltype(Node{}(std::declval<Ts>()))>>::works + ...
   );

   // value
   static type value(const COMPONENT &comp, const LOOK &look)
   {
      const void *ptr = nullptr;
      std::apply(
         [&comp,&look,&ptr](const auto &... mc)
         {
            size_t n = 0;
            ((ptr || (ptr = value(comp,look,mc,n++))), ...);
         },
         comp.Keys().tup
      );
      return *(std::remove_reference_t<type> *)ptr;
   }
};


// -----------------------------------------------------------------------------
// isDerivedFrom*
// -----------------------------------------------------------------------------

// isDerivedFromComponent
// Adapted from an answer here:
//    https://stackoverflow.com/questions/34672441
// The issue is that Component is a class *template*.
template<class T>
struct isDerivedFromComponent {
private:
   template<class A, bool B, class C>
   static constexpr std::true_type test(Component<A,B,C> *);
   static constexpr std::false_type test(...);
   using type = decltype(test(std::declval<T *>()));
public:
   static constexpr bool value = type::value;
};

template<class T>
inline constexpr bool isDerivedFromComponent_v =
   isDerivedFromComponent<T>::value;

// isDerivedFromVector
template<class T>
struct isDerivedFromVector {
private:
   template<class X, class Allocator>
   static constexpr std::pair<std::vector<X,Allocator>,std::true_type>
      test(std::vector<X,Allocator> *);
   static constexpr std::pair<int,std::false_type>
      test(...);
   using ret = decltype(test(std::declval<T *>()));
public:
   static constexpr bool value = ret::second_type::value;
   using type = std::conditional_t<value, typename ret::first_type,void>;
};

template<class T>
inline constexpr bool isDerivedFromVector_v =
   isDerivedFromVector<T>::value;

template<class T>
using isDerivedFromVector_t = typename isDerivedFromVector<T>::type;


// -----------------------------------------------------------------------------
// HasPrint*
// -----------------------------------------------------------------------------

// These are adapted from an answer here:
// https://stackoverflow.com/questions/87372

// HasPrintOneArg
template<class DERIVED>
class HasPrintOneArg
{
   template<
      class U,
      std::ostream &(U::*)(std::ostream &) const
   > struct SFINAE {};

   template<class U> static char test(SFINAE<U, &U::print> *);
   template<class U> static long test(...);

public:
   static constexpr bool has = sizeof(test<DERIVED>(0)) == sizeof(char);
};

// HasPrintTwoArg
template<class DERIVED>
class HasPrintTwoArg
{
   template<
      class U,
      std::ostream &(U::*)(std::ostream &, const int) const
   > struct SFINAE {};

   template<class U> static char test(SFINAE<U, &U::print> *);
   template<class U> static long test(...);

public:
   static constexpr bool has = sizeof(test<DERIVED>(0)) == sizeof(char);
};

// Variable templates for the above; prefer these
template<class DERIVED>
inline constexpr bool hasPrintOneArg = HasPrintOneArg<DERIVED>::has;

template<class DERIVED>
inline constexpr bool hasPrintTwoArg = HasPrintTwoArg<DERIVED>::has;

} // namespace detail
