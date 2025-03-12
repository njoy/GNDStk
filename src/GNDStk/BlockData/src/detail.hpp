
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

// getBounds
template<class T>
auto getBounds(const std::vector<T> &vec)
{
   T zero;
   if constexpr (std::is_same_v<T,std::string>)
      zero = "";
   else
      zero = T(0);
   std::pair<size_t,size_t> bnd(0,vec.size());
   while (bnd.first < bnd.second && vec[bnd.first   ] == zero) ++bnd.first;
   while (bnd.first < bnd.second && vec[bnd.second-1] == zero) --bnd.second;
   return bnd;
}


// -----------------------------------------------------------------------------
// SFINAE constructs for detecting whether or not a class has certain members.
// Adapted from an answer here: https://stackoverflow.com/questions/1005476
// -----------------------------------------------------------------------------

// ------------------------
// has_index
// ------------------------

template<class T, class = int>
struct has_index {
   static constexpr bool value = false;
};

template<class T>
struct has_index<
   // Just using T{}.index() on the next line can lead to an ambiguity between
   // this specialization and the one for std::variant below, arising from the
   // fact that std::variant has an index function. Hence the conditional_t.
   T, decltype((void)std::conditional_t<isVariant_v<T>,void,T>{}.index(),0)
> {
   static constexpr bool value = true;
};

// for variant: does any alternative have .index()?
template<class... Ts>
struct has_index<std::variant<Ts...>> {
   static constexpr bool value = (has_index<Ts>::value || ...);
};

template<class T>
inline constexpr bool has_index_v = has_index<std::decay_t<T>>::value;

// ------------------------
// has_label
// ------------------------

template<class T, class = int>
struct has_label {
   static constexpr bool value = false;
};

template<class T>
struct has_label<
   // std::variant doesn't have a label function, like it has an index function,
   // but, for the sake of consistency, we'll do here as we did with has_index.
   T, decltype((void)std::conditional_t<isVariant_v<T>,void,T>{}.label(),0)
> {
   static constexpr bool value = true;
};

// for variant: does any alternative have .label()?
template<class... Ts>
struct has_label<std::variant<Ts...>> {
   static constexpr bool value = (has_label<Ts>::value || ...);
};

template<class T>
inline constexpr bool has_label_v = has_label<std::decay_t<T>>::value;


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
// colorize
// colorize_comment
// -----------------------------------------------------------------------------

inline std::string colorize(
   const std::string &text,
   const std::string &color
) {
   return GNDStk::colors && color != ""
      ? color + text + GNDStk::color::reset
      : text;
}

inline std::string colorize_comment(
   const std::string &text,
   const std::string &color = ""
) {
   return colorize((printMode == PrintMode::cpp ? "// " : "# ") + text, color);
}

} // namespace detail
