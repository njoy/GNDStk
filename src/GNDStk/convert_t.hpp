
namespace detail {

// -----------------------------------------------------------------------------
// convert_t
// failure_t
// -----------------------------------------------------------------------------

class convert_t {
public:
   template<class FROM, class TO>
   void operator()(const FROM &from, TO &to) const
   {
      convert(from,to);
   }
};

class failure_t {
public:
   template<class FROM, class TO>
   void operator()(const FROM &, TO &) const
   {
      // fixme say something intelligent here;
      // maybe better class name too
      throw std::exception{};
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
   using type = failure_t;
};

} // namespace detail
