
// -----------------------------------------------------------------------------
// many
// -----------------------------------------------------------------------------

namespace detail {

template<class T, class U, class ELEMENT>
std::string many(
   std::vector<ELEMENT> &vec, std::istream &is,
   const int litFlags, const int as,
   const int prefix, const int suffix, const std::string &context
) {
   vec.clear();
   detail::expect(is,prefix,context);
   const bool thisLiteral = litFlags & as;
   std::string text(1,char(prefix));

   int ch;
   while ((ch = (is >> std::ws).peek()) != EOF && ch != suffix) {
      // comma
      if (vec.size()) {
         detail::expect(is,',',context);
         if (thisLiteral)
            text += ',';
      }

      // value or key:value, with value read in-place for efficiency
      value *vptr = nullptr;
      if constexpr (std::is_same_v<ELEMENT,value>) {
         // array
         // ELEMENT == value (from array's base std::vector<value>)
         vec.push_back(value());
         vptr = &vec.back();
      } else {
         // object
         // ELEMENT == pair (from object's base std::vector<pair>)
         string key; // <== json::string, not std::string, to handle escapes
         key.read<T,U>(is);
         detail::expect(is,':',context);
         if (thisLiteral)
            text += '"' + key + "\":";
         vec.push_back({key,value()});
         vptr = &vec.back().second;
      }

      thisLiteral // if so, read all contained objects as literals too
         ? text += vptr->read<T,U>(is,as_literal::all)
         : vptr->read<T,U>(is,litFlags);
   }

   detail::expect(is,suffix,context);
   return thisLiteral ? text + char(suffix) : "";
} // many

} // namespace detail
