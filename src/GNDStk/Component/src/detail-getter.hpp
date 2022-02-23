
// -----------------------------------------------------------------------------
// isSearchKey<T>
// Type T is one of:
//    - convertible to std::size_t, for use as an index
//    - convertible to std::string, for use as a label
//    - of type Lookup<...>
// Used for SFINAE and such.
// -----------------------------------------------------------------------------

// isLookup: helper
template<class T>
class isLookup : std::false_type { };

template<bool HAS, class EXTRACTOR, class TYPE, class CONVERTER>
class isLookup<Lookup<HAS,EXTRACTOR,TYPE,CONVERTER>> : std::true_type { };

// isSearchKey
template<class T>
inline constexpr bool isSearchKey =
   std::is_convertible_v<T,std::size_t> ||
   std::is_convertible_v<T,std::string> ||
   isLookup<T>::value;



// -----------------------------------------------------------------------------
// getter(vector, index, names...)
// Index into vector data member of class.
// -----------------------------------------------------------------------------

template<class T>
const T &getter(
   const std::vector<T> &vec,
   const std::size_t &index,
   // for the Component-derived class: names of namespace, class, relevant field
   const std::string &nname, const std::string &cname, const std::string &fname
) {
   static const std::string context = "getter {}::{}.{}({}) on vector";

   try {

      if constexpr (hasIndex<T>) {
         // hasIndex<T>
         // T (or at least one of its alternatives, if T is a variant) has
         // a metadatum called "index". In this case, this function's index
         // parameter is interpreted to mean: find the object with an "index"
         // metadatum that matches the parameter. Importantly, then, index
         // in this case is ***NOT*** a C++ [index] index!

         // fixme Make this more efficient, e.g. by assuming that the vector's
         // elements are sorted by index, so that the wanted value is probably
         // at [index], even though a vector [index] is not the interpretation.
         const T *object = nullptr;

         for (auto &v : vec) {
            const T *ptr = nullptr;

            if constexpr (isVariant<T>::value) {
               // T == variant
               std::visit(
                  [&v,&index,&ptr](auto &&alternative)
                  {
                     if constexpr (hasIndex<decltype(alternative)>)
                        if (alternative.index() == index)
                           ptr = &v;
                  },
                  v
               );
            } else {
               // T != variant
               if constexpr (hasIndex<T>)
                  if (v.index() == index)
                     ptr = &v;
            }

            if (ptr) {
               if (object) {
                  log::warning(
                    "Element with metadatum \"index\" {} was already found "
                    "in the vector.\n"
                    "Keeping the first element that was found.",
                     index
                  );
                  log::member(context, nname, cname, fname, index);
               } else
                  object = ptr;
            }
         } // for

         if (!object) {
            log::error(
              "Element with metadatum \"index\" {} was not found "
              "in the vector" + std::string(vec.size()
                  ? "."
                  : ";\nin fact the vector is empty."),
               index
            );
            throw std::exception{};
         }
         return *object;

      } else {

         // !hasIndex<T>
         // No "index" is anywhere to be found in T. Here, then, we interpret
         // this function's index parameter to be a regular, C++ [index] index.
         if (!(index < vec.size())) {
            log::error(
              "Index {} is out of range; vector size is {}.",
               vec.size());
            throw std::exception{};
         }
         return vec[index];
      }

   } catch (...) {
      // context
      // Example: prints "getter containers::Axes.axis(100)"
      log::member(context, nname, cname, fname, index);
      throw;
   }
}



// -----------------------------------------------------------------------------
// getter(vector, label, names...)
// Element of the vector that has .label() == label.
// Assumes that the element type has a .label() getter.
// -----------------------------------------------------------------------------

template<class T>
const T &getter(
   const std::vector<T> &vec,
   const std::string &label,
   const std::string &nname, const std::string &cname, const std::string &fname
) {
   static const std::string context = "getter {}::{}.{}(\"{}\") on vector";

   try {
      const T *object = nullptr;

      for (auto &v : vec) {
         const T *ptr = nullptr;

         if constexpr (isVariant<T>::value) {
            // T == variant
            std::visit(
               [&v,&label,&ptr](auto &&alternative)
               {
                  if constexpr (hasLabel<decltype(alternative)>)
                     if (alternative.label() == label)
                        ptr = &v;
               },
               v
            );
         } else {
            // T != variant
            if constexpr (hasLabel<T>)
               if (v.label() == label)
                  ptr = &v;
         }

         if (ptr) {
            if (object) {
               log::warning(
                 "Element with label \"{}\" was already found in the vector.\n"
                 "Keeping the first element that was found.",
                  label
               );
               log::member(context, nname, cname, fname, label);
            } else
               object = ptr;
         }
      } // for

      if (!object) {
         log::error(
           "Element with label \"{}\" was not found in the vector" +
            std::string(vec.size() ? "." : ";\nin fact the vector is empty."),
            label
         );
         throw std::exception{};
      }
      return *object;

   } catch (...) {
      // context
      log::member(context, nname, cname, fname, label);
      throw;
   }
}



// -----------------------------------------------------------------------------
// getter(optional<vector>, index or label, names...)
// As earlier, but for optional<vector> data member.
// -----------------------------------------------------------------------------

template<
   class T, class INDEX_OR_LABEL,
   class = std::enable_if_t<
      std::is_convertible_v<INDEX_OR_LABEL,std::size_t> ||
      std::is_convertible_v<INDEX_OR_LABEL,std::string>
   >
>
const T &getter(
   const std::optional<std::vector<T>> &optvec,
   const INDEX_OR_LABEL &key,
   const std::string &nname, const std::string &cname, const std::string &fname
) {
   try {
      // optional must have value
      if (!optvec.has_value()) {
         log::error("optional vector {} does not have a value", fname);
         throw std::exception{};
      }
      return getter(*optvec, key, nname, cname, fname);
   } catch (...) {
      // context
      log::member(
         std::is_convertible_v<INDEX_OR_LABEL,std::size_t>
            ? "getter {}::{}.{}({}) on optional<vector>"
            : "getter {}::{}.{}(\"{}\") on optional<vector>",
         nname, cname, fname, key);
      throw;
   }
}



// -----------------------------------------------------------------------------
// getter<T>(variant, names...)
// -----------------------------------------------------------------------------

template<
   class T,
   class... Ts,
   class = std::enable_if_t<detail::isAlternative<T,std::variant<Ts...>>>
>
const T *getter(
   const std::variant<Ts...> &var,
   const std::string &nname, const std::string &cname, const std::string &fname
) {
   try {
      return std::holds_alternative<T>(var)
         ? &std::get<T>(var)
         : nullptr;
   } catch (...) {
      // context
      log::member("getter {}::{}.{}() on variant", nname, cname, fname);
      throw;
   }
}



// -----------------------------------------------------------------------------
// getter<T>(vector<variant>, index or label, names...)
// -----------------------------------------------------------------------------

template<
   class T, class INDEX_OR_LABEL,
   class = std::enable_if_t<
      std::is_convertible_v<INDEX_OR_LABEL,std::size_t> ||
      std::is_convertible_v<INDEX_OR_LABEL,std::string>
   >,
   class... Ts
>
const T *getter(
   const std::vector<std::variant<Ts...>> &vecvar,
   const INDEX_OR_LABEL &key,
   const std::string &nname, const std::string &cname, const std::string &fname
) {
   try {
      return getter<T>(
         // no <T>, so it calls getter(generic vector); it isn't recursive
         getter(vecvar, key, nname, cname, fname), // scalar variant
         nname, cname, fname
      );
   } catch (...) {
      // context
      log::member(
         std::is_convertible_v<INDEX_OR_LABEL,std::size_t>
            ? "getter {}::{}.{}({}) on vector<variant>"
            : "getter {}::{}.{}(\"{}\") on vector<variant>",
         nname, cname, fname, key);
      throw;
   }
}
