
namespace detail {

// check_index
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

} // namespace detail
