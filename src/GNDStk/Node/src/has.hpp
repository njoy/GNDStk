
// -----------------------------------------------------------------------------
// Convenience functions, so you don't need to bother with the "found" flag
// in each respective function as outlined below. (The "found" flag in turn
// was a convenience, for when you *expected* that something might or might
// not be there, and you just want to know as much, without fussing with
// diagnostics or exceptions.)
//
// Note: don't call any of these with your own bool "found" trailing parameter;
// they put that in themselves, and the underlying functions shouldn't get two
// of them. We could write extra code to deal with that, but we judge that the
// additional complexity isn't worth it.
// -----------------------------------------------------------------------------

/*
Usage sketch:

   // The following will throw an exception if the GNDS tree's structure
   // is such that the given path, down into the tree, doesn't exist...
   auto foo = tree(reactionSuite,PoPs,chemicalElements);

   // Option 1: use a "found" out-parameter directly:
   bool found;
   auto foo = tree(reactionSuite,PoPs,chemicalElements,found);
   if (found) {
      ...
   }

   // Option 2: use has() to "pre-check" the call:
   if (tree.has(reactionSuite,PoPs,chemicalElements)) {
      auto foo = tree(reactionSuite,PoPs,chemicalElements);
      ...
   }

Node's (by extension Tree's) "call operator", operator(), is illustrated
in the above example. There are, however, several data-access functions,
not just the call operator. Here's what you should use for each:

   Use this:       To see if this will succeed:
   --------------------------------------------
   has_meta(*)     meta(*)
   has_one(*)      one(*)
   has_many(*)     many(*)
   has_child(*)    child(*)
   has(*)          (*), a.k.a. operator()(*)
   --------------------------------------------

Avoid a mistake we've seen: n.has_many(parameters) does NOT check if Node n
contains each of the given parameters (say, interpreted as child nodes and/or
metadata); and, likewise, n.has_one(parameter) does not check if n has the
given parameter. Rather, each has_foo(something) function "tests" the call
foo(something) to see if it will work, i.e., if it won't throw an exception.
Multiple parameters don't mean multiple checks; it means multiple parameters
in a single underlying function call that's checked.

For simplicity, each "has" function (left column) just does a std::forward
of its arguments to the function it's designed to test (right column). Some
of the respective functions (technically function templates) use SFINAE to
constrain overload resolution, but for simplicity here, our has*() functions
do *not* replicate that. If a given "has" call triggers compiler gibberish,
consider looking at the call you mean to test, and see if that produces a
more useful diagnostic. (We may reconsider this choice - of doing a simple
forwarding of arguments - if users report significant issues with compiler
diagnostics. Doing so, however, would somewhat complicate the present code.)
Also, be sure that you never send the "found" bool (available in all of the
underlying functions) to any has*(), as we provide that automatically.
*/


// Node.has_meta(...)
template<class... ARGS>
bool has_meta(ARGS &&...args) const
{
   try {
      bool found = false;
      return meta(std::forward<ARGS>(args)..., found), found;
   } catch (...) {
      log::function("Node.has_meta(...)");
      throw;
   }
}

// Node.has_one(...)
template<class... ARGS>
bool has_one(ARGS &&...args) const
{
   try {
      bool found = false;
      return one(std::forward<ARGS>(args)..., found), found;
   } catch (...) {
      log::function("Node.has_one(...)");
      throw;
   }
}

// Node.has_many(...)
template<class... ARGS>
bool has_many(ARGS &&...args) const
{
   try {
      bool found = false;
      return many(std::forward<ARGS>(args)..., found), found;
   } catch (...) {
      log::function("Node.has_many(...)");
      throw;
   }
}

// Node.has_child(...)
template<class... ARGS>
bool has_child(ARGS &&...args) const
{
   try {
      bool found = false;
      return child(std::forward<ARGS>(args)..., found), found;
   } catch (...) {
      log::function("Node.has_child(...)");
      throw;
   }
}

// Node.has(...)
template<class... ARGS>
bool has(ARGS &&...args) const
{
   try {
      bool found = false;
      return (*this)(std::forward<ARGS>(args)..., found), found;
   } catch (...) {
      log::function("Node.has(...)");
      throw;
   }
}
