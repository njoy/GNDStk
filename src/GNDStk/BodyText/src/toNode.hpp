
// -----------------------------------------------------------------------------
// BodyText::toNode
// This is called by Component's conversion-to-Node (not toNode()) function.
// It's "toNode()" here, not a conversion, because we're simply writing data
// into a piece of the Node that's made in Component's conversion-to-Node.
// -----------------------------------------------------------------------------

// const
// Use the original raw string, even if it has been processed into a vector.
// For an object that's regarded as being const, preserving the original form
// makes sense. Any vector that was derived from the raw string wouldn't have
// been changed, and represents only what was in the raw string. Had we wished
// to modify the original data in any manner, we should have used non-const.
template<class CONTENT>
void toNode(std::string &text, const CONTENT &) const
{
   text = rawstring;
}


// non-const
// Use the original raw string OR the vector, depending on which one is active.
// Also: length, start, and valueType might be computed - which means changing
// them in the derived class too, in order to keep everything consistent. The
// possible need to do this is why we split this function (which would normally
// warrant only a const version) into const (above) and non-const (below).
template<class CONTENT>
void toNode(std::string &text, CONTENT &content)
{
   // Use the raw string?
   if (active == Active::string) {
      text = rawstring;
      return;
   }

   // Use the vector...

   // Re: leading/trailing 0s
   const auto bounds = trim
    ? std::visit([](auto &&vec) { return detail::getBounds(vec); }, variant)
    : std::pair<std::size_t,std::size_t>(0,size());

   // Compute length, start, and valueType
   vars.length = size(); // independent of trim
   vars.start  = bounds.first; // dependent on trim, per the bounds computation
   vars.valueType =
      std::holds_alternative<std::vector<Integer32>>(variant) ? "Integer32"
    : std::holds_alternative<std::vector<Float64  >>(variant) ? "Float64"
    : ""; // fallback
   pushToDerived(content);

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
