
namespace detail {

// -----------------------------------------------------------------------------
// Miscellaneous
// -----------------------------------------------------------------------------

// scalarize
template<class... Ts>
auto scalarize(const std::variant<Ts...>)
{
   return std::variant<typename Ts::value_type ...>{};
}

// decays, decays_t
// Like std::decay and std::decay_t, but for tuple
template<class T>
struct decays { };
template<class... Ts>
struct decays<std::tuple<Ts...>> {
   using type = std::tuple<std::decay_t<Ts> ...>;
};

template<class T>
using decays_t = typename decays<T>::type;



// -----------------------------------------------------------------------------
// SFINAE constructs for detecting whether or not a class has certain members.
// Adapted from an answer here: https://stackoverflow.com/questions/1005476
// -----------------------------------------------------------------------------

// ------------------------
// has_index
// ------------------------

template<class T, class = int>
struct has_index
   : std::false_type { };

template<class T>
struct has_index<
   T,
   decltype(
      (void)
      // Just using T{}.index() on the next line, like we do with other has_*
      // classes above, can lead to an ambiguity between this specialization
      // and the std::variant specialization below, arising from the fact that
      // std::variant has an index() function. Hence the std::conditional_t.
      std::conditional_t<isVariant<T>::value,void,T>{}.index(),
      0
   )
>
   : std::true_type { };

// for variant
template<class... Ts>
struct has_index<std::variant<Ts...>> {
   // does any alternative have index?
   static constexpr bool value = (has_index<Ts>::value || ...);
};

// ------------------------
// has_label
// ------------------------

template<class T, class = int>
struct has_label
   : std::false_type { };

template<class T>
struct has_label<
   T,
   // std::variant doesn't have a label(), like it has an index(), but we'll
   // do the same thing here, for has_label, as we do above for has_index.
   // It's harmless, and if std::variant is ever given a label() function...
   decltype((void)std::conditional_t<isVariant<T>::value,void,T>{}.label(),0)
>
   : std::true_type { };

// for variant
template<class... Ts>
struct has_label<std::variant<Ts...>> {
   // for variant: does any alternative have label?
   static constexpr bool value = (has_label<Ts>::value || ...);
};

// ------------------------
// Prefer these.
// They apply std::decay,
// and don't need ::value
// ------------------------

template<class T>
inline constexpr bool hasIndex = has_index<std::decay_t<T>>::value;
template<class T>
inline constexpr bool hasLabel = has_label<std::decay_t<T>>::value;



// -----------------------------------------------------------------------------
// element2element
// -----------------------------------------------------------------------------

// Remark: PrecisionContext::data, not PrecisionContext::metadata, is the right
// precision context (in terms of our functionality for handling floating-point
// precision) in the code for which element2element() is called. We could bypass
// element2element() entirely, using convert_t{}(...) instead, except that then
// PrecisionContext::metadata would ultimately get used for floating-point T.
// So, below, we recognize floating-point T directly, and handle it correctly.

// string ==> arithmetic
template<class T, class = std::enable_if_t<!std::is_same_v<T,std::string>>>
void element2element(const std::string &str, T &value)
{
   if constexpr (std::is_floating_point_v<T>)
      value = Precision<PrecisionContext::data,T>{}.read(str);
   else
      convert_t{}(str,value);
}

// arithmetic ==> arithmetic
template<class FROM, class TO>
void element2element(const FROM &from, TO &to)
{
   convert_t{}(from,to);
}

// arithmetic ==> string
template<class T, class = std::enable_if_t<!std::is_same_v<T,std::string>>>
void element2element(const T &value, std::string &str)
{
   if constexpr (std::is_floating_point_v<T>)
      str = Precision<PrecisionContext::data,T>{}.write(value);
   else
      convert_t{}(value,str);
}



// -----------------------------------------------------------------------------
// getBounds
// -----------------------------------------------------------------------------

template<class T>
auto getBounds(const std::vector<T> &vec)
{
   T zero;
   if constexpr (std::is_same_v<T,std::string>) zero = ""; else zero = T(0);
   std::pair<std::size_t,std::size_t> bnd(0,vec.size());
   while (bnd.first < bnd.second && vec[bnd.first   ] == zero) ++bnd.first;
   while (bnd.first < bnd.second && vec[bnd.second-1] == zero) --bnd.second;
   return bnd;
}



// -----------------------------------------------------------------------------
// colorize_*(text)
// -----------------------------------------------------------------------------

#define gndstkPaste(one,two) one ## two
#define gndstkColorFun(part) \
   inline std::string gndstkPaste(colorize_,part)(const std::string &text) \
   { \
      return GNDStk::color && colors::part != "" \
         ? colors::part + text + colors::reset \
         : text; \
   }

   // colorize_label() etc.
   gndstkColorFun(label)
   gndstkColorFun(colon)
   gndstkColorFun(component)
   gndstkColorFun(brace)
   gndstkColorFun(bracket)
   gndstkColorFun(comment)

#undef gndstkColorFun
#undef gndstkPaste

} // namespace detail
