
namespace detail {

// Helper
template<class T>
void check_index(const std::vector<T> &vec, const std::size_t n)
{
   const std::size_t size = vec.size();
   if (!(n < size)) {
      if (size > 0)
         log::error(
           "Index ({}) is out of range [0..{}] (the vector size is {})",
            n, size-1, size
         );
      else
         log::error(
           "Index ({}) is out of range; in fact the vector is empty",
            n
         );
      throw std::exception{};
   }
}



// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// getter()
// Various cases.
// Intended for use in our auto-generated Standard Interface classes.
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// getter(vector,n,...)
// Index into vector data member of class.
// -----------------------------------------------------------------------------

// const
template<class T>
const T &getter(
   const std::vector<T> &vec,
   const std::size_t n,
   const std::string &nsname, // enclosing class' namespace
   const std::string &clname, // enclosing class
   const std::string &field   // enclosing class' field we're accessing
) {
   try {
      check_index(vec,n);
      return vec[n];
   } catch (...) {
      // context
      // Example: prints "getter containers::Axes.axis(100)"
      log::member(
        "getter {}::{}.{}({}) on vector",
         nsname, clname, field, n);
      throw;
   }
}

// non-const
template<class T>
T &getter(
   std::vector<T> &vec,
   const std::size_t n,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   return const_cast<T &>(
      getter(std::as_const(vec), n, nsname, clname, field)
   );
}



// -----------------------------------------------------------------------------
// getter(vector,label,...)
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
                  if (alternative.label() == label)
                     ptr = &v;
               },
               v
            );
         } else {
            // T != variant
            if (v.label() == label)
               ptr = &v;
         }

         if (!ptr)
            continue;

         if (selected) {
            log::warning(
              "Element with label \"\" was already found in the vector."
              "Keeping the first element that was found.",
               label
            );
            log::member(context, nsname, clname, field, label);
         } else
            selected = ptr;
      } // for

      if (!selected) {
         log::error(
           "Element with label \"\" was not found in the vector" +
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

// non-const
template<class T>
T &getter(
   std::vector<T> &vec,
   const std::string &label,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   return const_cast<T &>(
      getter(std::as_const(vec), label, nsname, clname, field)
   );
}



// -----------------------------------------------------------------------------
// getter(optional<vector>,n,...)
// As earlier, but for optional<vector> data member.
// -----------------------------------------------------------------------------

// const
template<class T>
const T &getter(
   const std::optional<std::vector<T>> &opt,
   const std::size_t n,
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
      return getter((*opt), n, nsname, clname, field);
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}({}) on optional<vector>",
         nsname, clname, field, n);
      throw;
   }
}

// non-const
template<class T>
T &getter(
   std::optional<std::vector<T>> &opt,
   const std::size_t n,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   return const_cast<T &>(
      getter(std::as_const(opt), n, nsname, clname, field)
   );
}



// -----------------------------------------------------------------------------
// getter(optional<vector>,label,...)
// As earlier, but for optional<vector> data member.
// -----------------------------------------------------------------------------

// const
template<class T>
const T &getter(
   const std::optional<std::vector<T>> &opt,
   const std::string &label,
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
      return getter((*opt), label, nsname, clname, field);
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}(\"{}\") on optional<vector>",
         nsname, clname, field, label);
      throw;
   }
}

// non-const
template<class T>
T &getter(
   std::optional<std::vector<T>> &opt,
   const std::string &label,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   return const_cast<T &>(
      getter(std::as_const(opt), label, nsname, clname, field)
   );
}



// -----------------------------------------------------------------------------
// getter<T>(...)
// With caller-specified type, when variant is involved
// -----------------------------------------------------------------------------

// ------------------------
// variant,...
// ------------------------

template<class T, class... Ts>
const std::optional<T> getter(
   const std::variant<Ts...> &var,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      return std::holds_alternative<T>(var)
         ? std::optional<T>(std::get<T>(var))
         : std::optional<T>();
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}() on variant",
         nsname, clname, field);
      throw;
   }
}

// ------------------------
// vector<variant>,n,...
// ------------------------

template<class T, class... Ts>
const std::optional<T> getter(
   const std::vector<std::variant<Ts...>> &vec,
   const std::size_t n,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      return getter<T>(
         // no <T>, so it calls getter(generic vector); it isn't recursive...
         getter(vec, n, nsname, clname, field), // <== returns scalar variant
         nsname, clname, field
      );
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}({}) on vector<variant>",
         nsname, clname, field, n);
      throw;
   }
}

// ------------------------
// vector<variant>,label,...
// ------------------------

template<class T, class... Ts>
const std::optional<T> getter(
   const std::vector<std::variant<Ts...>> &vec,
   const std::string &label,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      return getter<T>(
         getter(vec, label, nsname, clname, field),
         nsname, clname, field
      );
   } catch (...) {
      // context
      log::member(
        "getter {}::{}.{}(\"{}\") on vector<variant>",
         nsname, clname, field, label);
      throw;
   }
}



// -----------------------------------------------------------------------------
// setter(vector<variant>,n,optional,...)
// That is, setter(), not getter() as the earlier functions were.
// Intended for use in our auto-generated Standard Interface classes.
// -----------------------------------------------------------------------------

template<class T, class... Ts>
void setter(
   std::vector<std::variant<Ts...>> &vec,
   const std::size_t n,
   const std::optional<T> &opt,
   const std::string &nsname,
   const std::string &clname,
   const std::string &field
) {
   try {
      check_index(vec,n);
      if (opt)
         vec[n] = *opt;
   } catch (...) {
      // context
      log::member(
        "setter {}::{}.{}({})",
         nsname, clname, field, n);
      throw;
   }
}

} // namespace detail
