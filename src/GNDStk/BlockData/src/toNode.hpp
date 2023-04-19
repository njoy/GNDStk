
// -----------------------------------------------------------------------------
// BlockData::toNode
// This is called by Component's conversion-to-Node (not toNode()) function.
// It's "toNode()" here, not a conversion, because we're simply writing text
// that Component's full conversion-to-Node will place into the Node itself.
// -----------------------------------------------------------------------------

// Use either (1) the original raw string, or (2) either the variant of vectors
// or the vector (depending on DATATYPE ==/!= void), based on whether or not the
// raw string is active. If a vector (not the raw string) is active, then we'll
// also compute length, start, and valueType.
void toNode(std::string &text) const
{
   // Use the raw string?
   if (active() == Active::string) {
      text = rawstring;
      return;
   }

   // Use the vector...
   const bool isStringVector =
      ( runtime && std::holds_alternative<std::vector<std::string>>(variant)) ||
      (!runtime && std::is_same_v<std::string,DATATYPE>);

   if constexpr (
        runtime ||
      (!runtime && std::is_same_v<std::string,DATATYPE>)
   ) {
      // the runtime if's get<std::string>() calls below won't
      // necessarily make sense without the above if-constexpr
      if (isStringVector && !trim &&
          // only bother with the warning if trim would make a difference...
          size() > 0 &&
          (get<std::string>(0) == "" || get<std::string>(size()-1) == "")
      ) {
         log::warning(
            "BlockData.toNode() called with BlockData "
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
    : std::make_pair(std::size_t(0),size());

   // Compute length, start, and valueType
   vars.length = size(); // independent of trim
   vars.start  = bounds.first; // dependent on trim, per the bounds computation
   if constexpr (runtime)
      vars.valueType = detail::visitType2Names(variant);
   else
      vars.valueType = detail::Type2Names<DATATYPE>::value[0];

   // Values
   std::ostringstream oss;

   const auto toNodeLambda =
      [bounds,&oss](auto &&vec)
      {
         using T = std::decay_t<decltype(vec[0])>;
         std::size_t count = 0;

         for (std::size_t i = bounds.first; i < bounds.second; ++i) {
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
