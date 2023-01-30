
// -----------------------------------------------------------------------------
// Discussion
// -----------------------------------------------------------------------------

/*
These return the std::size_t number of times a child node of the given name is
seen, subject to any filter condition that might be provided.

A Child's TYPE, ALLOW, and CONVERTER are irrelevant for the purposes of these
functions. No conversion (as normally CONVERTER performs) is applied, because no
nodes are converted to TYPE; our purpose is merely to count nodes. We emphasize
in particular that a Child's ALLOW is ignored here; Allow::one does NOT mean
we'll look only for one, as we normally do. Indeed, we anticipate that someone
might use count()'s result in a conditional, e.g.: do nothing if count() == 0;
use an Allow::one Child object for a subsequent query if count() == 1; use an
Allow::many Child object for a subsequent query if count() > 1.

Variations for count(...)'s parameters are as follows:

   (1) const string &key
   (2) const string &key, const FILTER &filter
   (3) const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd
   (4) const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, std::string &label
   (5) const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, std::regex  &labelRegex

All are const, as we're just counting something - not modifying the *this node.

The above variations were chosen to align with what we've provided for doing
child node queries, except that we chose one important simplification in order
to avoid needing considerable extra machinery here: we have no count() analogs
of the variadic operator()s. In practice, this means that instead of writing,
say, something like the following for a Node n and Child objects A-G:

   std::size_t size = n.count(A,B,C,D,E,F,G);

you should instead write:

   std::size_t size = n(A,B,C,D,E,F).count(G);

We write variations (1) and (2) together, with a FILTER default that means,
in effect, no filter. For the Child cases (3)-(5), the selection of nodes for
our "head count" is as with the analogous query functions: the Child's filter,
if any, is applied, and in addition the std::string or std::regex label must
match a "label" metadatum in order for a Node to increment the count. Note also
that, here, we don't need a char *label case explicitly, because we don't have
operator()'s variadic argument pack that a char * would inadvertently match in
lieu of matching std::string. It does implicitly convert to a std::string here.
*/


// -----------------------------------------------------------------------------
// Node.count
// -----------------------------------------------------------------------------

// ------------------------
// string[,filter]
// ------------------------

template<class FILTER = detail::noFilter>
std::size_t count(
   const std::string &key,
   const FILTER &filter = FILTER{}
) const {
   // The empty string "" has a special meaning when used in our query system.
   // For this reason, we anticipate that someone might occasionally make the
   // mistake - probably a mistake - of using it here as well. We'll therefore
   // print a warning (not error) about it, and then actually count the number
   // of child nodes named "". The answer *should* be 0 if the child nodes all
   // have proper, initialized names. However, we do count it anyway.
   if (key == "") {
      log::warning(
         "Node.count(\"\") called; i.e., with an empty name \"\". "
         "We'll go ahead\n"
         "and count the number of nodes with that name. For proper GNDS, the\n"
         "answer should be 0."
      );
   }

   // Search. As elsewhere, key is interpreted as a regex for the purposes of
   // matching the node's name. Don't confuse this behavior with the explicit
   // regex that's required, in another count() function, in order to get a
   // regex label match. GNDS labels tend to contain special regex characters,
   // so we don't want a regex match to be the default with label.
   std::size_t size = 0;
   for (auto &c : children)
      if (std::regex_match(c->name, std::regex(key)) && filter(*c))
         size++;

   // done
   return size;
}

// ------------------------
// Child
// ------------------------

template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
std::size_t count(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd
) const {
   return count(kwd.name,kwd.filter);
}

// ------------------------
// Child, string
// ------------------------

template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
std::size_t count(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   std::string &&label // additional filter: string match label with this
) const {
   return count(
      kwd.name,
      [kwd,label](const Node &n)
         { return kwd.filter(n) && detail::label_is(label)(n); }
   );
}

// ------------------------
// Child, regex
// ------------------------

template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
std::size_t count(
   const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,
   std::regex &&labelRegex // additional filter: regex match label with this
) const {
   return count(
      kwd.name,
      [kwd,labelRegex](const Node &n)
         { return kwd.filter(n) && detail::label_is_regex(labelRegex)(n); }
   );
}
