
namespace detail {

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
