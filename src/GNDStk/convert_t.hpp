
// -----------------------------------------------------------------------------
// convert_t
// -----------------------------------------------------------------------------

namespace detail {

class convert_t {
public:
   template<class FROM, class TO>
   void operator()(const FROM &from, TO &to) const
   {
      convert(from,to);
   }
};

} // namespace detail
