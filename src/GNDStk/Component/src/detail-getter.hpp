
namespace detail {

// Contents:
//    1. bool           compGetter   (vector<T>, Lookup exists)
//    2. auto           compGetter   (vector<T>, Lookup get/unvalued)
//    3. const T       &compGetter   (vector<T>, Lookup get/valued)
//    4. const T       *compGetter<T>(vector<variant>, Lookup)
//    5. decltype(auto) compGetter   (optional<vector<T>>, Lookup)

// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

// ------------------------
// quote
// ------------------------

// general
template<class T>
std::string quote(const T &value)
{
   std::ostringstream oss;
   oss << value;
   return oss.str();
}

// for string
inline std::string quote(const std::string &value)
{
   return '"' + value + '"';
}

// for char *
// Else the general T case, not the string case, would be called
inline std::string quote(const char *const value)
{
   return quote(std::string(value));
}

// ------------------------
// firstOrOnly
// ------------------------

// general
// the type
template<class T>
struct firstOrOnly {
   using type = T;
};

// for variant
// the variant's first type
template<class T, class... Ts>
struct firstOrOnly<std::variant<T,Ts...>> {
   using type = T;
};

// ------------------------
// has_field
// ------------------------

template<class T, class EXTRACTOR, class = int>
struct has_field {
   static constexpr bool value = false;
};

template<class T, class EXTRACTOR>
struct has_field<
   T,
   EXTRACTOR,
   decltype(
      (void)std::declval<EXTRACTOR>()(
         std::conditional_t<isVariant_v<T>,void,T>{}
      ),
      0
   )
> {
   static constexpr bool value = true;
};

// for variant: does any alternative have the field?
template<class... Ts, class EXTRACTOR>
struct has_field<std::variant<Ts...>,EXTRACTOR>
{
   static constexpr bool value = (has_field<Ts,EXTRACTOR>::value || ...);
};


// -----------------------------------------------------------------------------
// 1.
// compGetter(vector<T>, Lookup exists/valued or unvalued, names)
// Returns: bool
// -----------------------------------------------------------------------------

template<class T, class EXTRACTOR, class TYPE, class CONVERTER>
bool compGetter(
   const std::vector<T> &vec,
   const Lookup<LookupMode::exists,EXTRACTOR,TYPE,CONVERTER> &look,
   const std::string &nname, const std::string &cname, const std::string &fn
) {
   if constexpr (!has_field<T,EXTRACTOR>::value)
      return false;
   else if constexpr (std::is_same_v<TYPE,void>)
      return true;
   else {
      const std::string fname = fn != "" ? fn : "<unknown name>";

      try {
         for (const auto &elem : vec) {
            if constexpr (isVariant_v<T>) {
               // T == variant
               if (std::visit(
                  [&look](auto &&alternative)
                  {
                     return look.extractor(alternative) == look.value;
                  },
                  elem
               ))
                  return true;
            } else {
               // T != variant
               if (look.extractor(elem) == look.value)
                  return true;
            }
         }
      } catch (...) {
         // context
         log::member(
           "compGetter {}::{}.{}(has({}({}))) on vector",
            nname, cname, fname, look.name, quote(look.value));
         throw;
      }

      return false;
   }
}


// -----------------------------------------------------------------------------
// 2.
// compGetter(vector<T>, Lookup get/unvalued, names)
// Returns: vector
// Meaning: create and return a vector with the extracted fields. Analogy: given
// a vector<complex>, return a vector<double> with just, say, the .real parts.
// -----------------------------------------------------------------------------

template<
   class T, class EXTRACTOR,
   class = std::enable_if_t<has_field<T,EXTRACTOR>::value>
>
auto compGetter(
   const std::vector<T> &vec,
   const Lookup<LookupMode::get,EXTRACTOR> &look,
   const std::string &nname, const std::string &cname, const std::string &fn
) {
   const std::string fname = fn != "" ? fn : "<unknown name>";

   std::vector<std::decay_t<
      decltype(look.extractor(typename firstOrOnly<T>::type{}))
   >> ret;

   try {
      for (const auto &elem : vec) {
         if constexpr (isVariant_v<T>) {
            // T == variant
            std::visit(
               [&look,&ret](auto &&alternative)
               {
                  ret.push_back(look.extractor(alternative));
               },
               elem
            );
         } else {
            // T != variant
            ret.push_back(look.extractor(elem));
         }
      } // for
   } catch (...) {
      // context
      log::member(
        "compGetter {}::{}.{}({}) on vector",
         nname, cname, fname, look.name);
      throw;
   }

   return ret;
}


// -----------------------------------------------------------------------------
// 3.
// compGetter(vector<T>, Lookup get/valued, names)
// Returns: const T &
// Get-mode Lookup, with a value. Meaning: return the element, of the vector,
// where extractor(element) == look.value. (Analogy: taking a vector<complex>,
// and returning the (first) element that has .real() == some given value.)
// -----------------------------------------------------------------------------

template<
   class T, class EXTRACTOR, class TYPE, class CONVERTER,
   class = std::enable_if_t<has_field<T,EXTRACTOR>::value>
>
const T &compGetter(
   const std::vector<T> &vec,
   const Lookup<LookupMode::get,EXTRACTOR,TYPE,CONVERTER> &look,
   const std::string &nname, const std::string &cname, const std::string &fn
) {
   static const std::string context = "compGetter {}::{}.{}({}({})) on vector";
   const std::string fname = fn != "" ? fn : "<unknown name>";

   try {
      const T *object = nullptr;

      for (const auto &elem : vec) {
         const T *ptr = nullptr;

         if constexpr (isVariant_v<T>) {
            // T == variant
            std::visit(
               [&elem,&look,&ptr](auto &&alternative)
               {
                  using Class = std::decay_t<decltype(alternative)>;
                  if constexpr (has_field<Class,EXTRACTOR>::value)
                     if (look.extractor(alternative) == look.value)
                        ptr = &elem;
               },
               elem
            );
         } else {
            // T != variant
            if (look.extractor(elem) == look.value)
               ptr = &elem;
         }

         if (ptr) {
            if (object) {
               const std::string valuestr = quote(look.value);
               log::warning(
                 "Element with {}({}) was already found in the vector.\n"
                 "Keeping the first element that was found.",
                  look.name, valuestr
               );
               log::member(context, nname, cname, fname, look.name, valuestr);
            } else
               object = ptr;
         }
      } // for

      if (object)
         return *object;

      log::error(
        "Element with metadatum {} == {} was not found in the vector" +
         std::string(vec.size() ? "." : ";\nin fact, the vector is empty."),
         look.name, quote(look.value)
      );
      throw std::exception{};

   } catch (...) {
      // context
      log::member(context, nname, cname, fname, look.name, quote(look.value));
      throw;
   }
}


// -----------------------------------------------------------------------------
// 4.
// compGetter<T>(vector<variant>, Lookup, names)
// Returns: const T *
// -----------------------------------------------------------------------------

template<
   class T, class... Ts,
   LookupMode MODE, class EXTRACTOR, class TYPE, class CONVERTER,
   class = std::enable_if_t<is_in_v<T,Ts...>>
>
const T *compGetter(
   const std::vector<std::variant<Ts...>> &vecvar,
   const Lookup<MODE,EXTRACTOR,TYPE,CONVERTER> &look,
   const std::string &nname, const std::string &cname, const std::string &fn
) {
   const std::string fname = fn != "" ? fn : "<unknown name>";

   try {
      return std::get_if<T>(&compGetter(vecvar, look, nname, cname, fname));
   } catch (...) {
      // context
      log::member(
        "compGetter {}::{}.{}({}) on vector<variant>",
         nname, cname, fname, quote(look.value));
      throw;
   }
}


// -----------------------------------------------------------------------------
// 5.
// compGetter(optional<vector<T>>, Lookup, names)
// -----------------------------------------------------------------------------

template<class T, LookupMode MODE, class EXTRACTOR, class TYPE, class CONVERTER>
decltype(auto) compGetter(
   const std::optional<std::vector<T>> &optvec,
   const Lookup<MODE,EXTRACTOR,TYPE,CONVERTER> &look,
   const std::string &nname, const std::string &cname, const std::string &fn
) {
   const std::string fname = fn != "" ? fn : "<unknown name>";

   try {
      // optional must have value
      if (!optvec.has_value()) {
         log::error("optional vector {} does not have a value", fname);
         throw std::exception{};
      }
      return compGetter(*optvec, look, nname, cname, fname);
   } catch (...) {
      // context...
      // ...nname::cname.fname(field(value))
      if constexpr (MODE == LookupMode::get    && !detail::is_void_v<TYPE>)
         log::member("compGetter {}::{}.{}({}({})) on optional<vector>",
                     nname, cname, fname, look.name, quote(look.value));
      // ...nname::cname.fname(has(field(value)))
      if constexpr (MODE == LookupMode::exists && !detail::is_void_v<TYPE>)
         log::member("compGetter {}::{}.{}(has({}({}))) on optional<vector>",
                     nname, cname, fname, look.name, quote(look.value));
      // ...nname::cname.fname(field)
      if constexpr (MODE == LookupMode::get    &&  detail::is_void_v<TYPE>)
         log::member("compGetter {}::{}.{}({}) on optional<vector>",
                     nname, cname, fname, look.name);
      // ...nname::cname.fname(has(field))
      if constexpr (MODE == LookupMode::exists &&  detail::is_void_v<TYPE>)
         log::member("compGetter {}::{}.{}(has({})) on optional<vector>",
                     nname, cname, fname, look.name);
      throw;
   }
}

} // namespace detail
