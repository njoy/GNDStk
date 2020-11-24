
// -----------------------------------------------------------------------------
// Randomly shuffle the metadata and child nodes. This capability should
// be helpful for validating functions like Node's sort() and operator==.
// -----------------------------------------------------------------------------

Node &shuffle()
{
   // recurse to children
   for (auto &c : children)
      c->shuffle();

   // shuffle metadata
   std::random_shuffle(metadata.begin(), metadata.end());

   // shuffle children
   std::random_shuffle(children.begin(), children.end());

   // done
   return *this;
}
