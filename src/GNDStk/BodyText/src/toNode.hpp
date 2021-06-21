
// -----------------------------------------------------------------------------
// toNode(Node)
// This is called by Component's conversion-to-Node (not toNode()) function.
// It's "toNode()" here, not a conversion, because we're simply writing data
// into part of the Node that's being made from a Component.
// -----------------------------------------------------------------------------

void toNode(Node &node) const
{
   // Recall that GNDStk's tree structure stores nodes with XML "plain
   // character data" - what we're informally calling "values nodes" -
   // in the following manner:
   //    Parent
   //       "pcdata" child
   //          "text" metadatum
   // This particular layout is translated from/to the actual form needed
   // in XML, or in JSON, in GNDStk's respective I/O functionality.

   // ------------------------
   // pcdata
   // ------------------------

   // In the given node, get or make a "pcdata" child
   bool found;
   Node *pc = &node.one("pcdata",found);

   if (found) {
      // a pcdata child is already there :-/
      log::warning(
        "Child node of name \"pcdata\" already exists in node \"{}\".\n"
        "We'll replace any text content, but it's unexpected "
        "that a \"pcdata\"\n"
        "child already exists in this context.",
         node.name
      );
      log::member("BodyText::toNode(Node)");
   } else {
      // create a pcdata child
      pc = &node.add("pcdata");
   }

   // ------------------------
   // text
   // ------------------------

   // In the "pcdata" child, get or make a "text" metadatum
   std::string *text = &pc->meta("text",found);
   if (found) {
      // a text metadatum is already there :-/
      log::warning(
        "Metadatum of name \"text\" already exists in node \"pcdata\".\n"
        "We'll replace its content, but it's unexpected "
        "that a \"text\"\n"
        "metadatum already exists in this context.",
         node.name
      );
      log::member("BodyText::toNode(Node)");
   } else {
      // create a text metadatum
      text = &pc->add("text","").second; // creates a "text" metadatum
   }

   // At this point, text points to a std::string into which we should
   // place the final data string

   // ------------------------
   // data...
   // ------------------------

   // ------------------------
   // remake == true
   // ------------------------

   // Similar remark to the one in the remake == true case in write.hpp.
   if (remake)
      *text = rawstring;

   // ------------------------
   // remake == false
   // ------------------------

   // qqq Should figure out start and length, and probably guess valueType,
   // too, in the way we do that elsewhere. In fact, the valueType guessing
   // here and elsewhere should probably be put into its own function.

   // qqq Aside: Go ahead and do the finish vs. construct thing.
   // take into account the trim flag

   std::ostringstream oss;
   std::visit(
      [&oss](auto &&alt)
      {
         std::size_t count = 0;
         for (auto &element : alt)
            oss << (count++ ? " " : "") << element;
      },
      variant
   );
   *text = oss.str();
}
