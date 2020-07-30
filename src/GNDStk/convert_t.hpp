
namespace detail {

// -----------------------------------------------------------------------------
// convert_t
// -----------------------------------------------------------------------------

class convert_t {
public:
   template<class FROM, class TO>
   void operator()(const FROM &from, TO &to) const
   {
      convert(from,to);
   }
};



// -----------------------------------------------------------------------------
// default_converter
// -----------------------------------------------------------------------------

template<class RESULT>
class default_converter {
public:
   using type = convert_t;
};

template<>
class default_converter<void> {
public:
   using type = void;
};

} // namespace detail
