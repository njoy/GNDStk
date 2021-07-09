
// -----------------------------------------------------------------------------
// BodyText::toNode
// This is called by Component's conversion-to-Node (not toNode()) function.
// It's "toNode()" here, not a conversion, because we're simply writing data
// into a piece of the Node that's made in Component's conversion-to-Node.
// -----------------------------------------------------------------------------

// Use the original raw string or the vector, depending on which one is active.
// Also: length, start, and valueType might be computed - which means changing
// them in the derived class too, in order to keep everything consistent.
template<class DERIVED>
void toNode(std::string &text, DERIVED &derived) const
{
   // Use the raw string?
   if (active == Active::string) {
      text = rawstring;
      return;
   }

   // Use the vector...
   const bool isString =
      std::holds_alternative<std::vector<std::string>>(variant);
   if (isString && !trim &&
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

   // Re: leading/trailing 0s
   const auto bounds =
      trim || isString
    ? std::visit([](auto &&vec) { return detail::getBounds(vec); }, variant)
    : std::pair<std::size_t,std::size_t>(0,size());

   // Compute length, start, and valueType
   vars.length = size(); // independent of trim
   vars.start  = bounds.first; // dependent on trim, per the bounds computation
   vars.valueType =
      std::holds_alternative<std::vector<Integer32>>(variant) ? "Integer32"
    : std::holds_alternative<std::vector<Float64  >>(variant) ? "Float64"
    : ""; // fallback
   pushToDerived(derived);

   // Values
   std::ostringstream oss;
   std::visit(
      [bounds,&oss](auto &&vec)
      {
         std::size_t count = 0;
         for (auto i = bounds.first; i < bounds.second; ++i)
            oss << (count++ ? " " : "") << vec[i];
      },
      variant
   );
   text = oss.str();
}
