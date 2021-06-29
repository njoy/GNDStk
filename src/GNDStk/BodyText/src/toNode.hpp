
// -----------------------------------------------------------------------------
// BodyText::toNode(Node)
// This is called by Component's conversion-to-Node (not toNode()) function.
// It's "toNode()" here, not a conversion, because we're simply writing data
// into part of the Node that's being made in Component's conversion-to-Node.
// -----------------------------------------------------------------------------

// const
// Use the original raw string, even if it has been processed into a vector.
// For an object that's regarded as being const, preserving the original form
// makes sense. Any vector that was derived from the raw string wouldn't have
// been changed, and should represent only what's in the raw string.
template<class CONTENT>
void toNode(Node &node, const CONTENT &) const
{
   // Make+get std::string, in node, where the output should go
   std::string *const text = detail::makeText(node);

   // Data
   // Use string
   *text = rawstring;
}


// non-const
// Possibly use vector.
// Also: length, start, and valueType might be changed, which means changing
// them in the derived class too, in order to keep everything consistent. The
// possible need to do this is why we split this function (which normally would
// only need a const version) into separate const and non-const versions.
template<class CONTENT>
void toNode(Node &node, CONTENT &content)
{
   // Make+get std::string, in node, where the output should go
   std::string *const text = detail::makeText(node);

   // Data...

   // ------------------------
   // Use string,
   // if it's active
   // ------------------------

   if (active == Active::string) {
      *text = rawstring;
      return;
   }

   // ------------------------
   // Use vector,
   // otherwise
   // ------------------------

   const auto bounds = trim
    ? std::visit(
         [](auto &&vec) { return detail::getBounds(vec); },
         variant
      )
    : std::pair<std::size_t,std::size_t>(0,size());

   vars.length = size();
   vars.start  = bounds.first;
   vars.valueType =
       std::holds_alternative<std::vector<Integer32>>(variant)
    ? "Integer32"
    :  std::holds_alternative<std::vector<Float64  >>(variant)
    ? "Float64"
    : "";

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

   pushToDerived(content);
   *text = oss.str();
}
