
// -----------------------------------------------------------------------------
// Node.meta(string)
// Searches the node's metadata for a metadatum of the given name. If found,
// returns the value associated with the key. Else, returns an empty string.
// -----------------------------------------------------------------------------

// const
const std::string &
meta(
   const std::string &key,
   bool &found = detail::default_bool
) const {
   // search
   for (const auto &m : metadata)
      if (std::regex_match(m.first, std::regex(key)))
         return found = true, m.second;

   // not found
   found = false;

   // If a "found" flag was not sent to this function, we'll produce an error.
   // Otherwise, we'll assume that the caller intends to deal with the issue
   // in its own way, and therefore that we shouldn't produce such an error.
   // Note that the question of whether a "found" flag was sent is determined
   // by looking at its address. This is entirely different from the question
   // of what found's value proves to be.
   if (!detail::sent(found)) {
      log::error("Key \"{}\" not found in metadata", key);
      log::member("Node.meta(\"{}\")", key);
      throw std::exception{};
   }

   // done
   static std::string empty;
   return empty = "";
}

// non-const
std::string &
meta(
   const std::string &key,
   bool &found = detail::default_bool
) {
   return const_cast<std::string &>(std::as_const(*this).meta(key,found));
}


// -----------------------------------------------------------------------------
// Node.meta(Meta<void>)
// -----------------------------------------------------------------------------

// const
const std::string &
meta(
   const Meta<void> &kwd,
   bool &found = detail::default_bool
) const {
   return meta(kwd.name,found);
}

// non-const
std::string &
meta(
   const Meta<void> &kwd,
   bool &found = detail::default_bool
) {
   return meta(kwd.name,found);
}


// -----------------------------------------------------------------------------
// Node.meta(Meta<non-void>)
// -----------------------------------------------------------------------------

// ------------------------
// TYPE, optional<TYPE>
// ------------------------

template<class T, class CONVERTER>
void meta(
   T &existing,
   const Meta<T,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      if constexpr (!detail::isOptional<T>) {
         // call meta(string), with the Meta's key
         const std::string &str = meta(kwd.name,found);
         // convert str, if any, to an object of the appropriate type
         if (found) {
            #ifdef NJOY_GNDSTK_INSTRUMENT
            for (const auto &m : metadata)
               if (std::regex_match(m.first, std::regex(kwd.name)))
                  detail::instrument::mark(m.first);
            #endif
            kwd.converter(str,existing);
         }
      } else {
         using TYPE = typename T::value_type;
         bool f; // local "found" for TYPE (not optional<TYPE>)
         TYPE obj;
         meta(obj, obj/kwd, f);
         if (f)
            existing = obj;
         else
            existing = std::nullopt;
         // For optional, we always *return* with found == true. After all,
         // being  optional means something can either be there, or not be
         // there. That condition is always true. :-) And, this way, if an
         // optional value isn't there, its absence won't - and shouldn't -
         // break a multi-query.
         found = true;
      }
   } catch (...) {
      log::member("Node.meta(" + detail::keyname(kwd) + ")");
      throw;
   }
}


// ------------------------
// Defaulted<TYPE>
// ------------------------

template<class TYPE, class CONVERTER>
void meta(
   Defaulted<TYPE> &existing,
   const Meta<Defaulted<TYPE>,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   try {
      // Remarks as with those for optional case above
      bool f; // local "found"
      TYPE obj;
      meta(obj, obj/kwd, f);
      if (f)
         existing = obj;
      else
         existing.reset();
      found = true; // always
   } catch (...) {
      log::member("Node.meta(" + detail::keyname(kwd) + ")");
      throw;
   }
}


// ------------------------
// variant
// ------------------------

// With caller-specified type
template<
   class TYPE, class... Ts, class CONVERTER,
   class = std::enable_if_t<detail::is_in_v<TYPE,Ts...>>
>
void meta(
   TYPE &existing,
   const Meta<std::variant<Ts...>,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   meta(existing, existing/kwd, found);
}


// -----------------------------------------------------------------------------
// Formulations that return TYPE, instead of taking an existing TYPE object
// -----------------------------------------------------------------------------

// general
template<class TYPE, class CONVERTER>
TYPE meta(
   const Meta<TYPE,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   TYPE ret;
   meta(ret, kwd, found);
   return ret;
}

// variant
template<
   class TYPE, class... Ts, class CONVERTER,
   class = std::enable_if_t<detail::is_in_v<TYPE,Ts...>>
>
TYPE meta(
   const Meta<std::variant<Ts...>,CONVERTER> &kwd,
   bool &found = detail::default_bool
) const {
   TYPE ret;
   meta<TYPE>(ret, kwd, found);
   return ret;
}
