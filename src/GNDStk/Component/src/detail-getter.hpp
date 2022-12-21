
// -----------------------------------------------------------------------------
// getter(vector, index, names...)
// Element of the vector that has .index() == index.
// Or, use C++ [index] if the element type doesn't have an .index() getter.
// -----------------------------------------------------------------------------

template<class T>
const T &getter(
   const std::vector<T> &vec,
   const std::size_t &index,
   // for the Component-derived class: names of namespace, class, relevant field
   const std::string &nname, const std::string &cname, const std::string &fn
) {
   static const std::string context = "getter {}::{}.{}({}) on vector";
   const std::string fname = fn != "" ? fn : "<unknown name>";

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

         for (auto &elem : vec) {
            const T *ptr = nullptr;

            if constexpr (isVariant<T>::value) {
               // T == variant
               std::visit(
                  [&elem,&index,&ptr](auto &&alternative)
                  {
                     if constexpr (hasIndex<decltype(alternative)>)
                        if (alternative.index() == index)
                           ptr = &elem;
                  },
                  elem
               );
            } else {
               // T != variant
               if constexpr (hasIndex<T>)
                  if (elem.index() == index)
                     ptr = &elem;
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

         if (object)
            return *object;

         log::error(
           "Element with metadatum index == {} was not found in the vector" +
            std::string(vec.size() ? "." : ";\nin fact the vector is empty."),
            index
         );
         throw std::exception{};

      } else {
         // !hasIndex<T>
         // No "index" is anywhere to be found in T. Here, then, we interpret
         // this function's index parameter to be a C++ vector [index].
         // zzz Really need to rethink "index" and "label" interpretations.
         if (index < vec.size())
            return vec[index];

         if (vec.size() == 0)
            log::error(
              "Index {} is out of range; vector is empty.",
               index);
         else
            log::error(
              "Index {} is out of range; vector has [0..{}].",
               index, vec.size()-1);

         throw std::exception{};
      }

   } catch (...) {
      // context
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
   const std::string &nname, const std::string &cname, const std::string &fn
) {
   static const std::string context = "getter {}::{}.{}(\"{}\") on vector";
   const std::string fname = fn != "" ? fn : "<unknown name>";

   try {
      const T *object = nullptr;

      for (auto &elem : vec) {
         const T *ptr = nullptr;

         if constexpr (isVariant<T>::value) {
            // T == variant
            std::visit(
               [&elem,&label,&ptr](auto &&alternative)
               {
                  if constexpr (hasLabel<decltype(alternative)>)
                     if (alternative.label() == label)
                        ptr = &elem;
               },
               elem
            );
         } else {
            // T != variant
            if constexpr (hasLabel<T>)
               if (elem.label() == label)
                  ptr = &elem;
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

      if (object)
         return *object;

      log::error(
        "Element with metadatum label == \"{}\" was not found in the vector" +
         std::string(vec.size() ? "." : ";\nin fact the vector is empty."),
         label
      );
      throw std::exception{};

   } catch (...) {
      // context
      log::member(context, nname, cname, fname, label);
      throw;
   }
}


// -----------------------------------------------------------------------------
// getter(vector, Lookup<HAS==true,EXTRACTOR,TYPE,CONVERTER>, names...)
// -----------------------------------------------------------------------------

template<class T, class EXTRACTOR, class TYPE, class CONVERTER>
bool getter(
   const std::vector<T> &vec,
   const Lookup<true,EXTRACTOR,TYPE,CONVERTER> &look,
   const std::string &nname, const std::string &cname, const std::string &fn
) {
   const std::string fname = fn != "" ? fn : "<unknown name>";

   try {
      for (auto &elem : vec)
         if constexpr (isVariant<T>::value) {
            // T == variant
            if (std::visit(
               [&look](auto &&alternative)
               {
                  return look.extractor(alternative) == look.placeholder;
               },
               elem
            ))
               return true;
         } else
            // T != variant
            if (look.extractor(elem) == look.placeholder)
               return true;
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}(has({}({}))) on vector",
         nname, cname, fname, look.name, look.placeholder);
      throw;
   }

   return false;
}


// -----------------------------------------------------------------------------
// getter(vector, Lookup<HAS==false,EXTRACTOR,TYPE,CONVERTER>, names...)
// -----------------------------------------------------------------------------

template<class T, class EXTRACTOR, class TYPE, class CONVERTER>
const T &getter(
   const std::vector<T> &vec,
   const Lookup<false,EXTRACTOR,TYPE,CONVERTER> &look,
   const std::string &nname, const std::string &cname, const std::string &fn
) {
   static const std::string context = "getter {}::{}.{}({}({})) on vector";
   const std::string fname = fn != "" ? fn : "<unknown name>";

   try {
      const T *object = nullptr;

      for (auto &elem : vec) {
         const T *ptr = nullptr;

         if constexpr (isVariant<T>::value) {
            // T == variant
            std::visit(
               [&elem,&look,&ptr](auto &&alternative)
               {
                  if (look.extractor(alternative) == look.placeholder)
                     ptr = &elem;
               },
               elem
            );
         } else {
            // T != variant
            if (look.extractor(elem) == look.placeholder)
               ptr = &elem;
         }

         if (ptr) {
            if (object) {
               log::warning(
                 "Element with {}({}) was already found in the vector.\n"
                 "Keeping the first element that was found.",
                  look.name, look.placeholder
               );
               log::member(context, nname, cname, fname, look.name,
                           look.placeholder);
            } else
               object = ptr;
         }
      } // for

      if (object)
         return *object;

      log::error(
        "Element with metadatum {} == {} was not found in the vector" +
         std::string(vec.size() ? "." : ";\nin fact the vector is empty."),
         look.name, look.placeholder
      );
      throw std::exception{};

   } catch (...) {
      // context
      log::member(context, nname, cname, fname, look.name, look.placeholder);
      throw;
   }
}


// -----------------------------------------------------------------------------
// getter(vector, Lookup<HAS==true,EXTRACTOR,void,void>, names...)
// -----------------------------------------------------------------------------

template<class T, class EXTRACTOR>
bool getter(
   const std::vector<T> &,
   const Lookup<true,EXTRACTOR,void,void> &,
   const std::string &, const std::string &, const std::string &
) {
   return has_field<EXTRACTOR,T>::value;
}


// -----------------------------------------------------------------------------
// getter(vector, Lookup<HAS==false,EXTRACTOR,void,void>, names...)
// -----------------------------------------------------------------------------

template<class T, class EXTRACTOR>
auto getter(
   const std::vector<T> &vec,
   const Lookup<false,EXTRACTOR,void,void> &look,
   const std::string &nname, const std::string &cname, const std::string &fn
) {
   const std::string fname = fn != "" ? fn : "<unknown name>";

   std::vector<std::decay_t<
      decltype(look.extractor(typename firstOrOnly<T>::type{}))
   >> ret;

   try {
      for (auto &elem : vec) {
         if constexpr (isVariant<T>::value) {
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
        "getter {}::{}.{}({}) on vector",
         nname, cname, fname, look.name);
      throw;
   }

   return ret;
}


// -----------------------------------------------------------------------------
// getter(optional<vector>, index/label/Lookup, names...)
// As earlier, but for optional<vector> data member.
// -----------------------------------------------------------------------------

template<
   class T, class KEY,
   class = isSearchKey<KEY>
>
decltype(auto) getter(
   const std::optional<std::vector<T>> &optvec,
   const KEY &key,
   const std::string &nname, const std::string &cname, const std::string &fn
) {
   const std::string fname = fn != "" ? fn : "<unknown name>";

   try {
      // optional must have value
      if (!optvec.has_value()) {
         log::error("optional vector {} does not have a value", fname);
         throw std::exception{};
      }
      return getter(*optvec, key, nname, cname, fname);
   } catch (...) {
      // context
      if constexpr (isLookup<KEY>::value) {
         // nname::cname.fname(field(value))
         if constexpr (!KEY::Has && !KEY::Void)
            log::member("getter {}::{}.{}({}({})) on optional<vector>",
                        nname, cname, fname, key.name, key.placeholder);
         // nname::cname.fname(has(field(value)))
         if constexpr ( KEY::Has && !KEY::Void)
            log::member("getter {}::{}.{}(has({}({}))) on optional<vector>",
                        nname, cname, fname, key.name, key.placeholder);
         // nname::cname.fname(field)
         if constexpr (!KEY::Has &&  KEY::Void)
            log::member("getter {}::{}.{}({}) on optional<vector>",
                        nname, cname, fname, key.name);
         // nname::cname.fname(has(field))
         if constexpr ( KEY::Has &&  KEY::Void)
            log::member("getter {}::{}.{}(has({})) on optional<vector>",
                        nname, cname, fname, key.name);
      } else {
         log::member(
            std::is_convertible_v<KEY,std::size_t>
               ? "getter {}::{}.{}({}) on optional<vector>"
               : "getter {}::{}.{}(\"{}\") on optional<vector>",
            nname, cname, fname, key);
      }
      throw;
   }
}


// -----------------------------------------------------------------------------
// getter<T>(variant, names...)
// -----------------------------------------------------------------------------

template<
   class T, class... Ts,
   class = std::enable_if_t<isAlternative<T,std::variant<Ts...>>>
>
const T *getter(
   const std::variant<Ts...> &var,
   const std::string &nname, const std::string &cname, const std::string &fn
) {
   const std::string fname = fn != "" ? fn : "<unknown name>";

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
// getter<T>(vector<variant>, index/label/Lookup, names...)
// -----------------------------------------------------------------------------

template<
   class T, class KEY, class... Ts,
   class = isSearchKey<KEY>,
   class = std::enable_if_t<isAlternative<T,std::variant<Ts...>>>
>
const T *getter(
   const std::vector<std::variant<Ts...>> &vecvar,
   const KEY &key,
   const std::string &nname, const std::string &cname, const std::string &fn
) {
   const std::string fname = fn != "" ? fn : "<unknown name>";

   try {
      return getter<T>(
         // no <T>, so it calls getter(generic vector); it isn't recursive
         getter(vecvar, key, nname, cname, fname), // scalar variant
         nname, cname, fname
      );
   } catch (...) {
      // context
      log::member(
         std::is_convertible_v<KEY,std::size_t>
            ? "getter {}::{}.{}({}) on vector<variant>"
            : "getter {}::{}.{}(\"{}\") on vector<variant>",
         nname, cname, fname, key);
      throw;
   }
}
