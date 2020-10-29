
// -----------------------------------------------------------------------------
// documentation
// doc (short version, for user ease)
//
// Look around for the "..." content that appears in places like this:
//
//    <documentations>
//       <documentation name="endfDoc">
//          <![CDATA[...]]>
//       </documentation>
//    </documentations>
//
// in typical GNDS data. (XML is shown for illustration.) We cast a broad net,
// so we can find this content whether we're in the outer tree/node (above the
// top-level GNDS node), or inside the top-level node, or in fact inside *any*
// node from which we can drill down as above, beginning with a documentations,
// documentation, or CDATA node, or even directly to a text metadatum.
//
// Note: such CDATA nodes as I've seen in available GNDS files always begin with
// a newline. It's perhaps tempting to chuck the newline, except that (1) we're
// intentionally returning a *reference* to the data, for maximum usability
// including the ability to set it in the non-const case; and (2) throughout
// GNDStk, we're mindful of maintaining a GNDS hierarchy's exact content.
// -----------------------------------------------------------------------------

// const
const std::string &documentation(bool &found = detail::default_bool) const
{
   auto look = [](const Node &n, const std::string *&s)
   {
      auto docs  = plain::child::documentations;
      auto doc   = plain::child::documentation;
      auto cdata = plain::child::cdata;
      auto text  = plain::meta ::text;

      // In the node parameter, tries to find CDATA text at any layer of:
      //    <documentations>
      //       <documentation name="endfDoc">
      //          <![CDATA[...]]>
      //       </documentation>
      //    </documentations>
      // or rather in the GNDS tree equivalent (XML is for illustration).
      bool found = false;
      return
         (s = &n(               text,found), found) ||
         (s = &n(         cdata,text,found), found) ||
         (s = &n(     doc,cdata,text,found), found) ||
         (s = &n(docs,doc,cdata,text,found), found);
   };

   // this?
   // I.e., look in the present node
   const std::string *s;
   if (look(*this,s))
      return found = true, *s;

   // top-level?
   // I.e., assume we're perhaps in the root tree node, a.k.a. "over the top"
   // node, look for any of our allowable top-level nodes, e.g. reactionSuite,
   // and, if found, perform the above lookup (in the lambda) in that node.
   for (auto &top : detail::AllowedTop) {
      bool fnd = false; // f = found this particular top-level node?
      const Node &n = one(top,fnd);
      if (fnd && look(n,s))
         return found = true, *s;
   }

   // not found
   // Static, for reference return. Set to "" each time, just in case someone
   // got it before and somehow managed to change it in spite of constness.
   static std::string empty;
   return found = false, empty = "";
}

// non-const
std::string &documentation(bool &found = detail::default_bool)
{
   return const_cast<std::string &>(std::as_const(*this).documentation(found));
}

// doc
// const
const std::string &doc(bool &found = detail::default_bool) const
{
   return documentation(found);
}

// doc
// non-const
std::string &doc(bool &found = detail::default_bool)
{
   return documentation(found);
}



// -----------------------------------------------------------------------------
// Character and plain-character data
// -----------------------------------------------------------------------------

// ------------------------
// cdata
// ------------------------

// const
const std::string &cdata(bool &found = detail::default_bool) const
{
   return (*this)(plain::child::cdata, plain::meta::text, found);
}

// non-const
std::string &cdata(bool &found = detail::default_bool)
{
   return const_cast<std::string &>(std::as_const(*this).cdata(found));
}


// ------------------------
// pcdata
// ------------------------

// const
const std::string &pcdata(bool &found = detail::default_bool) const
{
   return (*this)(plain::child::pcdata, plain::meta::text, found);
}

// non-const
std::string &pcdata(bool &found = detail::default_bool)
{
   return const_cast<std::string &>(std::as_const(*this).pcdata(found));
}



// -----------------------------------------------------------------------------
// Comments
// -----------------------------------------------------------------------------

// ------------------------
// comment(size_t)
// ------------------------

// const
const std::string &comment(
   const size_t i = 0,
   bool &found = detail::default_bool
) const {
   size_t count = 0;

   for (auto c : children)
      if (c->name == "comment" && count++ == i)
         return c->meta("text",found);

   // not found
   static std::string empty;
   return found = false, empty = "";
}

// non-const
std::string &comment(
   const size_t i,
   bool &found = detail::default_bool
) {
   return const_cast<std::string &>(std::as_const(*this).comment(i,found));
}


// ------------------------
// comments() // plural; returns std::vector or other container
// ------------------------

// const
template<
   template<class...> class CONTAINER = std::vector,
   class T = std::string, class... Args
>
typename std::enable_if<
   std::is_convertible<std::string,T>::value,
   CONTAINER<T,Args...>
>::type
comments(bool &found = detail::default_bool) const
{
   CONTAINER<T,Args...> ret;
   const std::string *text;
   for (auto c : children)
      if (c->name == "comment" && (text = &c->meta("text",found),found))
         ret.push_back(T(*text));
   return ret;
}

// non-const
// Not needed, because the const version returns by value
