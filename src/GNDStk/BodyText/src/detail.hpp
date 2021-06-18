
namespace detail {

// -----------------------------------------------------------------------------
// remove_cvref
// remove_cvrefs
// -----------------------------------------------------------------------------

// C++20 will have this
template<class T>
class remove_cvref {
public:
   using type = std::remove_cv_t<std::remove_reference_t<T>>;
};

// With -s, for tuple
template<class T>
class remove_cvrefs {
};

template<class... Ts>
class remove_cvrefs<std::tuple<Ts...>> {
public:
   using type = std::tuple<typename remove_cvref<Ts>::type ...>;
};


// -----------------------------------------------------------------------------
// has_*
// SFINAE constructs for detecting whether or not a class has certain members.
// Adapted from an answer here: https://stackoverflow.com/questions/1005476
// -----------------------------------------------------------------------------

// has_length
template<class T, class = int>
struct has_length : std::false_type { };
template<class T>
struct has_length<T,decltype((void)T::length,0)> : std::true_type { };

// has_start
template<class T, class = int>
struct has_start : std::false_type { };
template<class T>
struct has_start<T,decltype((void)T::start,0)> : std::true_type { };

// has_valueType
template<class T, class = int>
struct has_valueType : std::false_type { };
template<class T>
struct has_valueType<T,decltype((void)T::valueType,0)> : std::true_type { };

} // namespace detail
