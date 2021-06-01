
namespace detail {

// -----------------------------------------------------------------------------
// check_index
// -----------------------------------------------------------------------------

template<class T>
void check_index(const std::vector<T> &vec, const std::size_t n)
{
   const std::size_t size = vec.size();
   if (!(n < size)) {
      if (size > 0)
         log::error(
           "Index {} is out of range [0..{}] (the vector size is {})",
            n, size-1, size
         );
      else
         log::error(
           "Index {} is out of range; in fact the vector is empty",
            n
         );
      throw std::exception{};
   }
}


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
