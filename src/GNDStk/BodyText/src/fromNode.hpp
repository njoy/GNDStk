
// -----------------------------------------------------------------------------
// BodyText::fromNode(Node)
// -----------------------------------------------------------------------------

void fromNode(const Node &node)
{
   // length, start, and valueType might be present in the Node, but we won't
   // fetch any of them here. Elsewhere, the current BodyText object should have
   // its length, start, and valueType pulled from those respective values in
   // an object of a class derived from Component (which in turn derives from
   // BodyText). That object's content will have been pulled from the same Node.
   // Here, we just get the Node's values: "plain character data" in XML terms.

   bool found = false;
   rawstring = node.pcdata(found);

   if (!found) {
      rawstring = "";

      // Warning, re: why are we in BodyText<true> if there's no body text?
      // Perhaps it's possible that the Node has a non-default length and/or
      // start, so that the values are all supposed to be...zero. Until and
      // unless we discover otherwise, however, we doubt that that would be
      // the case, and will consider a Node's lack of plain character data,
      // in the present context, to be something we should warn about.
      log::warning(
         "Component marked as having \"body text\", a.k.a. XML \"pcdata\" "
         "(plain\ncharacter data), "
         "but no such content was found in the GNDS node."
      );
      log::member("BodyText::fromNode(Node, with name \"{}\")", node.name);
   }

   // We just set the raw string. The following reflects this, so that a vector
   // in the variant will be rebuilt, from the raw string, if and when a caller
   // asks for it.
   active = Active::string;
}
