
// -----------------------------------------------------------------------------
// BlockData::fromNode(Node)
// -----------------------------------------------------------------------------

void fromNode(const Node &node)
{
   // length, start, and valueType might be present in the Node, but we won't
   // fetch any of them here. Elsewhere, the current BlockData object should
   // have had its length, start, and valueType pulled from those respective
   // values in an object of a class derived from Component, which in turn
   // derived from BlockData. That object's content will have been pulled from
   // the same Node. Here, we just get the Node's values: plain character data,
   // in XML terminology.

   bool found = false;
   rawstring = node.data(found);

   if (!found) {
      rawstring = "";

      // Warning, re: why are we in BlockData<true,...> if there's no block
      // data? Perhaps the Node has a non-default length and/or start, so that
      // the values are all supposed to be...zero. Until and unless we discover
      // otherwise, however, we doubt that that would be the case, and will
      // consider a Node's lack of plain character data, in the present context,
      // to be something that merits a warning.
      log::warning(
         "Component marked as having block data, "
         "but no such content was found in the GNDS node."
      );
      log::member("BlockData::fromNode(Node, with name \"{}\")", node.name);
   }

   // Above, we set the raw string. The following reflects this, so that the
   // vector, or a vector in the variant, will be rebuilt from the raw string
   // if and when a caller asks for it.
   act = Active::string;
}
