
// Like getter.hpp, but to help with *setters* in Component-derived classes.

// push_back a value into the vector.
template<
   class T, class FROM,
   class = std::enable_if_t<
      std::is_constructible_v<T,FROM> || std::is_convertible_v<FROM,T>
   >
>
static void setter(std::vector<T> &vec, const FROM &value)
{
   vec.push_back(value);
}

// Create an empty vector in the optional<vector> if it has no value, then
// push_back a value into the vector.
template<
   class T, class FROM,
   class = std::enable_if_t<
      std::is_constructible_v<T,FROM> || std::is_convertible_v<FROM,T>
   >
>
static void setter(std::optional<std::vector<T>> &opt, const FROM &value)
{
   if (!opt.has_value())
      opt = std::vector<T>{};
   opt->push_back(value);
}
