
// -----------------------------------------------------------------------------
// fromNode(Node)
// -----------------------------------------------------------------------------

void fromNode(const Node &node)
{
   // length, start, and valueType might be present in the Node, but we won't
   // fetch them here. Elsewhere, the current object (a BodyText) will have
   // its length, start, and valueType synced with those in an object of a
   // class derived from Component. (That object's content will have been
   // pulled from the same Node.) Here, we just get the actual body text:
   // plain character data in XML parlance.

   bool found = false;
   rawstring = node.pcdata(found);

   if (!found) {
      rawstring = "";
      // Warning, re: why are we in BodyText<true> if there's no body text?
      // Perhaps it's possible that length or start is nonzero, so that the
      // values are all *supposed* to be "" or 0, but we don't know why such
      // a Node would have been created in the first place. :-/
      log::warning(
         "Component marked as having \"body text\", a.k.a. XML \"pcdata\" "
         "(plain\ncharacter data), but none was found in the GNDS node."
      );
      log::member("BodyText::fromNode(Node, with name \"{}\")", node.name);
   }

   remake = true;
}
