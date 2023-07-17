
/*
Description of convert(Node,type)

Brief: Node.child(Child<type>) ==> Node ==> type

These are analogous to the convert(string,type) functions, and the description
of those largely applies here.

The difference is that these are called through child(), not through meta(),
and hence have Nodes, not strings, as their inputs.

Also, we don't have any viable general default here. We simply don't know, for
a general Node, how it would convert to any particular type. And, although the
convert(string,type) functions could default to the behavior of converting the
string to an istream and then punting to operator>>, we can't think of a default
that's both plausible and particularly helpful for similarly converting a Node
to an istream prior to operator>>.
*/

// -----------------------------------------------------------------------------
// convert(Node,Node)
// -----------------------------------------------------------------------------

inline bool convert(const Node &from, Node &to)
{
   try {
      to = from;
      return true;
   } catch (...) {
      log::function("convert(Node,Node)");
      throw;
   }
}
