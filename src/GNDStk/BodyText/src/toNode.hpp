
// -----------------------------------------------------------------------------
// BodyText::toNode
// This is called by Component's conversion-to-Node (not toNode()) function.
// It's "toNode()" here, not a conversion, because we're simply writing text
// that Component's full conversion-to-Node will place into the Node itself.
// -----------------------------------------------------------------------------

// Use either (1) the original raw string, or (2) the variant of vectors or the
// vector (depending on DATA ==/!= void), based on whether or not the string
// is active. length, start, and valueType might be computed too, in which case
// they're also changed in the derived class in order to keep things consistent.
template<class DERIVED>
void toNode(std::string &text, DERIVED &derived) const
{
   // Use the raw string?
   if (active() == Active::string) {
      text = rawstring;
      return;
   }

   // Use the vector...
   const bool isStringVector =
      ( runtime && std::holds_alternative<std::vector<std::string>>(variant)) ||
      (!runtime && std::is_same_v<std::string,DATA>);

   if constexpr (
        runtime ||
      (!runtime && std::is_same_v<std::string,DATA>)
   ) {
      // the run-time if's get<std::string>() calls below won't
      // necessarily make sense without the above if-constexpr
      if (isStringVector && !trim &&
          // only bother with the warning if trim would make a difference...
          size() > 0 &&
          (get<std::string>(0) == "" || get<std::string>(size()-1) == "")
      ) {
         log::warning(
            "BodyText.toNode() called with BodyText "
            "trim flag == false, but active\n"
            "data are in a vector<string>. Printing "
            "leading/trailing empty strings\n"
            "won't preserve them, so we'll treat as if trim == true."
         );
      }
   }

   // Re: leading/trailing 0s
   const auto bounds =
      trim || isStringVector
    ? runtime
    ? std::visit([](auto &&vec) { return detail::getBounds(vec); }, variant)
    : detail::getBounds(vector)
    : std::make_pair(size_t(0),size());

   // Compute length, start, and valueType
   vars.length = size(); // independent of trim
   vars.start  = bounds.first; // dependent on trim, per the bounds computation
   if constexpr (runtime) {
      vars.valueType =
         std::holds_alternative<std::vector<Integer32>>(variant) ? "Integer32"
       : std::holds_alternative<std::vector<Float64  >>(variant) ? "Float64"
       : ""; // fallback
   } else {
      vars.valueType =
         std::is_same_v<Integer32,DATA> ? "Integer32"
       : std::is_same_v<Float64,  DATA> ? "Float64"
       : ""; // fallback
   }
   pushToDerived(derived);

   // Values
   std::ostringstream oss;

   const auto toNodeLambda =
      [bounds,&oss](auto &&vec)
      {
         using T = std::decay_t<decltype(vec[0])>;
         std::size_t count = 0;

         for (auto i = bounds.first; i < bounds.second; ++i) {
            oss << (count++ ? " " : "");
            if constexpr (std::is_floating_point_v<T>) {
               oss << detail::Precision<
                         detail::PrecisionContext::data,
                         T
                      >{}.write(vec[i]);
            } else {
               oss << vec[i];
            }
         }
      };

   if constexpr (runtime)
      std::visit(toNodeLambda,variant);
   else
      toNodeLambda(vector);

   text = oss.str();
}
