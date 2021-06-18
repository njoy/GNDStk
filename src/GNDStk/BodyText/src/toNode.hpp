
// -----------------------------------------------------------------------------
// toNode(Node)
// -----------------------------------------------------------------------------

void toNode(Node &node) const
{
   // In the given node, get or make a "pcdata" child
   bool found;
   Node *nptr = &node.one("pcdata",found);
   if (found) {
      log::warning(
        "Child node of name \"pcdata\" already exists in node \"{}\".\n"
        "We'll replace any text content, but it's unexpected "
        "that a \"pcdata\"\n"
        "child already exists in this context.",
         node.name
      );
      log::member("BodyText::toNode(Node)");
   } else
      nptr = &node.add("pcdata"); // creates a "pcdata" child

   // In the "pcdata" child, get or make a "text" metadatum
   std::string *sptr = &nptr->meta("text",found);
   if (found) {
      log::warning(
        "Metadatum of name \"text\" already exists in node \"pcdata\".\n"
        "We'll replace its content, but it's unexpected "
        "that a \"text\"\n"
        "metadatum already exists in this context.",
         node.name
      );
      log::member("BodyText::toNode(Node)");
   } else
      sptr = &nptr->add("text","").second; // creates a "text" metadatum

   // Finally, put our raw data string into the metadatum's value
   // fixme Consider doing some formatting, like write() does
   *sptr = rawstring;
}
