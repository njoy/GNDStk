
   // ------------------------
   // assignment to vector
   // ------------------------

   template<class VECTOR>
   typename std::enable_if<
      detail::is_oneof<VECTOR,decltype(variant)>::value &&
     !detail::isVariant<VECTOR>::value,
      BodyText<true> &
   >::type operator=(const VECTOR &vector)
   {
      // Discussion
      //
      // Elsewhere, a BodyText object can be made from a GNDS node. From GNDS
      // we get a text string (copied to the rawstring field in this class),
      // from which a vector of values can be created on an as-needed basis.
      // A GNDS node might also give us any of valueType, start, and length,
      // which we use if they're there, or assign to default values otherwise.
      //
      // Here, we're allowing for a simple assignment BodyText = vector, and
      // no additional information arrives through the right-hand side. We'll
      // try to guess the string valueType based on the vector type. Guessing
      // start and length would be less reliable, so, for simplicity, we'll use
      // their existing values. A caller should set those immediately prior to
      // the assignment if they want other values to be used.
      //
      // This class also has an internal boolean flag, hasZeros, that's set
      // in the get<std::vector<T>> function if somebody wants a vector, with
      // or without zeros, to be built from the existing raw string. Here, we
      // get an existing vector. As with start and length: instead of trying
      // to guess what hasZeros should be, we'll consider its existing value
      // to indicate whether or not the incoming vector has any zero padding
      // or not. (And that's relevant only if start or length is nonzero.)
      //
      // In short: before doing an assignment BodyText = vector, consider
      // setting start, length, and hasZeros.

zzz need to fix/finish this
zzz miscellaneous code in there now...
zzz maybe want a hasZeros setter too
zzz then i think the interpretation is that it reflects the incoming vector

      // vector element type
      using T = typename VECTOR::value_type;

      // valueType - best guess
      if constexpr (std::is_same<T,Integer32>::value) {
         valueType = "Integer32";
         std::cout << "Recognized Integer32 !!" << std::endl;
      } else if constexpr (std::is_same<T,Float64>::value) {
         valueType = "Float64";
         std::cout << "Recognized Float64 !!" << std::endl;
      } else {
         valueType = "";
         std::cout << "Recognized neither Integer32 nor Float64" << std::endl;
      }

      variant = vector;
      std::ostringstream oss;

      /*
      // zzz How should this behave w.r.t....
      std::string  vars.valueType = "";
      std::size_t  vars.start     = 0;
      std::size_t  vars.length    = 0;
      mutable bool vars.hasZeros  = false;
      */

      // For this action (writing to the raw string), we won't bother
      // doing any formatting with regards to columns or newlines.
      std::visit(
         [&oss](auto &&alt)
         {
            std::size_t count = 0;
            for (auto &element : alt) 
               oss << (count++ ? " " : "") << element;
         },
         variant
      );

      rawstring = oss.str();
      return *this;
   }
