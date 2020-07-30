
// -----------------------------------------------------------------------------
// Helpers
// Private, for use by sort(). Could lead to surprises for users if not used
// in the proper sort() context. In particular, less() assumes that any child
// nodes it inspects were sorted already; if they weren't, then transitivity
// in sort()'s strict weak ordering requirement would in general be violated,
// leading to undefined behavior. I suppose less() could chuck this assumption
// and instead take it upon itself to sort its child nodes, recursively, before
// proceeding with the relevant comparisons. This would render the full sort()
// as s-l-o-w as molasses, and would trash up the principle that less() should
// compare nodes, not mess with them. As it stands, our full node::sort() does
// things in the right order, so that less() works as it should in that context.
// -----------------------------------------------------------------------------

private:

// less
bool less(const Node &b) const
{
   const Node &a = *this;

   if (a.name < b.name) return true;
   if (b.name < a.name) return false;

   if (a.metadata.size() < b.metadata.size()) return true;
   if (b.metadata.size() < a.metadata.size()) return false;

   for (auto i = a.metadata.begin(),
             j = b.metadata.begin();  i != a.metadata.end();  ++i, ++j) {
      if (*i < *j) return true;
      if (*j < *i) return false;
   }

   if (a.children.size() < b.children.size()) return true;
   if (b.children.size() < a.children.size()) return false;

   for (auto i = a.children.begin(),
             j = b.children.begin();  i != a.children.end();  ++i, ++j) {
      if ((*i)->less(**j)) return true;
      if ((*j)->less(**i)) return false;
   }

   return false;
}

// sort_metadata
void sort_metadata()
{
   std::sort(
      metadata.begin(),
      metadata.end(),
      [](const metaPair &a, const metaPair &b) { return a < b; }
   );
}

// sort_childptr
void sort_childptr()
{
   std::sort(
      children.begin(),
      children.end(),
      [](const childPtr &a, const childPtr &b) { return a->less(*b); }
   );
}



// -----------------------------------------------------------------------------
// sort
// Public, for us[ers].
// -----------------------------------------------------------------------------

public:

Node &sort()
{
   // recurse to children *first*
   for (auto &c : children)
      c->sort();

   // sort metadata pairs
   sort_metadata();

   // sort children pointers
   sort_childptr();

   // done
   return *this;
}
