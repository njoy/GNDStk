
// -----------------------------------------------------------------------------
// Randomly shuffle the metadata and children. This capability should
// be helpful for validating functions like Node's sort() and operator==.
// -----------------------------------------------------------------------------

Node &shuffle()
{
   // recurse to children
   for (const childPtr &c : children)
      c->shuffle();

   // random number seed
   const unsigned seed =
      std::chrono::system_clock::now().time_since_epoch().count();

   // shuffle metadata
   std::shuffle(
      metadata.begin(), metadata.end(),
      std::default_random_engine(seed)
   );

   // shuffle children
   std::shuffle(
      children.begin(), children.end(),
      std::default_random_engine(seed+1)
   );

   // done
   return *this;
}
