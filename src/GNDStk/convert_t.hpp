
namespace detail {

// -----------------------------------------------------------------------------
// convert_t
// Serves as a default "function object" in places where a function object
// can be (optionally) user-provided for converting *from* something, *to*
// something else.
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
// Used for selecting the CONVERTER template argument of the Meta and Child
// classes. Usually gives convert_t, but gives void (which in turn won't, and
// shouldn't, be used) for Meta<void> and Child<void>, for which the concept
// of a converter is not applicable.
// -----------------------------------------------------------------------------

template<class TYPE>
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
