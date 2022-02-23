
// -----------------------------------------------------------------------------
// getter(vector, index, ...)
// Index into vector data member of class.
// -----------------------------------------------------------------------------

// const
template<class T>
const T &getter(
   const std::vector<T> &vec,
   const std::size_t index,
   const std::string &nsname, // enclosing class' namespace
   const std::string &clname, // enclosing class
   const std::string &field   // enclosing class' field we're accessing
) {
   static const std::string context = "getter {}::{}.{}({}) on vector";

   try {

      if constexpr (hasIndex<T>) {
         // hasIndex<T>
         // T (or at least one alternative in T, if T is a variant) has a
         // metadatum called "index". In this case, this function's size_t
         // index parameter is interpreted to mean: find the object with
         // an "index" metadatum that matches the parameter. Importantly,
         // then, index in this case is ***NOT*** a C++ [index] index!

         // fixme Make the following more efficient, e.g. by assuming that the
         // vector's elements are sorted by index, so that the wanted value is
         // likely to be found at [index], even though (as stated above) [index]
         // is not the interpretation here...
         const T *selected = nullptr;

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

            if (!ptr)
               continue;

            if (selected) {
               log::warning(
                 "Element with metadatum \"index\" {} was already found "
                 "in the vector.\n"
                 "Keeping the first element that was found.",
                  index
               );
               log::member(context, nsname, clname, field, index);
            } else
               selected = ptr;
         } // for

         if (!selected) {
            log::error(
              "Element with metadatum \"index\" {} was not found "
              "in the vector" + std::string(vec.size()
                  ? "."
                  : ";\nin fact the vector is empty."),
               index
            );
            throw std::exception{};
         }
         return *selected;

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
      log::member(context, nsname, clname, field, index);
      throw;
   }
}



// -----------------------------------------------------------------------------
// getter(vector, label, ...)
// Element of the vector that has .label() == label.
// Assumes that the element type has a .label() getter.
// -----------------------------------------------------------------------------

// const
template<class T>
const T &getter(
   const std::vector<T> &vec,
   const std::string &label,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   static const std::string context = "getter {}::{}.{}(\"{}\") on vector";

   try {
      const T *selected = nullptr;

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

         if (!ptr)
            continue;

         if (selected) {
            log::warning(
              "Element with label \"{}\" was already found in the vector.\n"
              "Keeping the first element that was found.",
               label
            );
            log::member(context, nsname, clname, field, label);
         } else
            selected = ptr;
      } // for

      if (!selected) {
         log::error(
           "Element with label \"{}\" was not found in the vector" +
            std::string(vec.size() ? "." : ";\nin fact the vector is empty."),
            label
         );
         throw std::exception{};
      }

      return *selected;

   } catch (...) {
      // context
      log::member(context, nsname, clname, field, label);
      throw;
   }
}



// -----------------------------------------------------------------------------
// getter(optional<vector>, index or label, ...)
// As earlier, but for optional<vector> data member.
// -----------------------------------------------------------------------------

// const
template<
   class T, class INDEX_OR_LABEL,
   class = std::enable_if_t<
      std::is_convertible_v<INDEX_OR_LABEL,std::size_t> ||
      std::is_convertible_v<INDEX_OR_LABEL,std::string>
   >
>
const T &getter(
   const std::optional<std::vector<T>> &opt,
   const INDEX_OR_LABEL &index_or_label,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      // optional must have value
      if (!opt.has_value()) {
         log::error("optional vector {} does not have a value", field);
         throw std::exception{};
      }
      return getter((*opt), index_or_label, nsname, clname, field);
   } catch (...) {
      // context
      log::member(
         std::is_convertible_v<INDEX_OR_LABEL,std::size_t>
            ? "getter {}::{}.{}({}) on optional<vector>"
            : "getter {}::{}.{}(\"{}\") on optional<vector>",
         nsname, clname, field, index_or_label);
      throw;
   }
}



// -----------------------------------------------------------------------------
// getter<T>(...)
// With caller-specified type, when variant is involved
// -----------------------------------------------------------------------------

// ------------------------
// variant,...
// ------------------------

template<
   class T,
   class... Ts,
   class = std::enable_if_t<detail::isAlternative<T,std::variant<Ts...>>>
>
const T *getter(
   const std::variant<Ts...> &var,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      return std::holds_alternative<T>(var)
         ? &std::get<T>(var)
         : nullptr;
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}() on variant",
         nsname, clname, field);
      throw;
   }
}


// ------------------------
// vector<variant>,
// index or label,
// ...
// ------------------------

// The (size_t index) and (string label) cases were similar enough that
// we were able to combine them into one function.

template<
   class T, class INDEX_OR_LABEL,
   class = std::enable_if_t<
      std::is_convertible_v<INDEX_OR_LABEL,std::size_t> ||
      std::is_convertible_v<INDEX_OR_LABEL,std::string>
   >,
   class... Ts
>
const T *getter(
   const std::vector<std::variant<Ts...>> &vec,
   const INDEX_OR_LABEL &index_or_label,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      return getter<T>(
         // no <T>, so it calls getter(generic vector); it isn't recursive
         getter(vec, index_or_label, nsname, clname, field), // scalar variant
         nsname, clname, field
      );
   } catch (...) {
      // context
      log::member(
         std::is_convertible_v<INDEX_OR_LABEL,std::size_t>
            ? "getter {}::{}.{}({}) on vector<variant>"
            : "getter {}::{}.{}(\"{}\") on vector<variant>",
         nsname, clname, field, index_or_label);
      throw;
   }
}
