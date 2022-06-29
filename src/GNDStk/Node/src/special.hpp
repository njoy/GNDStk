
// -----------------------------------------------------------------------------
// documentation
// doc (short version, for user ease)
//
// Look around for the CDATA content that appears in places like this:
//
//    <documentations>
//       <documentation>
//          <![CDATA[...]]>
//       </documentation>
//    </documentations>
//
// in typical GNDS data. (XML is shown for illustration.) We cast a broad net,
// so we can find this content whether we're in the outer Tree/Node (above the
// top-level GNDS node), or inside the top-level node, or in fact inside *any*
// node from which we can drill down as above, beginning with a documentations,
// documentation, or CDATA node, or even directly to a #text metadatum.
//
// Note: CDATA nodes that we've seen in available GNDS files always begin with
// a newline. It's tempting, perhaps, to chuck the newline, except that (1) we
// intentionally return a reference to the data, for maximum usability including
// the ability to set it if non-const; and (2) throughout GNDStk, we're mindful
// to maintain a GNDS hierarchy's exact content.
// -----------------------------------------------------------------------------

// const
const std::string &documentation(bool &found = detail::default_bool) const
{
   auto look = [](const Node &n, const std::string *&s)
   {
      auto docs  = basic::child::documentations;
      auto doc   = basic::child::documentation;
      auto cdata = basic::child::cdata;
      auto text  = basic::meta ::text;

      // In the node parameter, tries to find CDATA text at any layer of:
      //    <documentations>
      //       <documentation name="endfDoc">
      //          <![CDATA[...]]>
      //       </documentation>
      //    </documentations>
      // or rather in the GNDS tree equivalent (XML is for illustration).
      bool found = false;
      return
            (s = &n(               text,found), found)
         || (s = &n(         cdata,text,found), found)
         || (s = &n(     doc,cdata,text,found), found)
         || (s = &n(docs,doc,cdata,text,found), found);
   };

   // this?
   // I.e., look in the present Node
   const std::string *s;
   if (look(*this,s))
      return found = true, *s;

   // top-level?
   // If we're in what looks like the root node of a tree (named "" - the empty
   // string), then look in all of the top-level nodes. In a properly formatted
   // GNDS file, there will be just one such node, e.g. reactionSuite.
   if (name == "")
      for (auto &ptr : children)
         if (look(*ptr,s))
            return found = true, *s;

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
// Character and plain character data
// -----------------------------------------------------------------------------

// ------------------------
// cdata
// ------------------------

// const
const std::string &cdata(bool &found = detail::default_bool) const
{
   return (*this)(basic::child::cdata, basic::meta::text, found);
}

// non-const
std::string &cdata(bool &found = detail::default_bool)
{
   return (*this)(basic::child::cdata, basic::meta::text, found);
}


// ------------------------
// pcdata
// ------------------------

// const
const std::string &pcdata(bool &found = detail::default_bool) const
{
   return (*this)(basic::child::pcdata, basic::meta::text, found);
}

// non-const
std::string &pcdata(bool &found = detail::default_bool)
{
   return (*this)(basic::child::pcdata, basic::meta::text, found);
}



// -----------------------------------------------------------------------------
// Comments
// -----------------------------------------------------------------------------

// ------------------------
// comment()
// comment(std::size_t)
// ------------------------

// const
const std::string &comment(
   const std::size_t i = 0,
   bool &found = detail::default_bool
) const {
   std::size_t count = 0;

   for (auto &c : children)
      if (c->name == "#comment" && count++ == i)
         return c->meta("#text",found);

   // not found
   static std::string empty;
   return found = false, empty = "";
}

// non-const
std::string &comment(
   const std::size_t i = 0,
   bool &found = detail::default_bool
) {
   return const_cast<std::string &>(std::as_const(*this).comment(i,found));
}


// ------------------------
// comments()
// plural :-)
// Returns: std::vector,
// or other container
// ------------------------

// We provide this because comments occasionally appear *multiple* times
// within a given GNDS parent node. Example:
//    <data>
//       <!--  energy | capture | elastic  -->
//       <!--         |  width  |  width   -->
//       ... numeric data ...
//    </data>
// One could argue that the second comment here really isn't important.
// However, GNDStk is careful to maintain ALL information that's present
// in a GNDS file it reads; it does not make decisions about importance.

// const
template<
   template<class...> class CONTAINER = std::vector,
   class... Args
>
CONTAINER<std::string,Args...>
comments(bool &found = detail::default_bool) const
{
   CONTAINER<std::string,Args...> container;
   const std::string *text;
   for (auto &c : children)
      if (c->name == "#comment" && (text = &c->meta("#text",found),found))
         container.push_back(*text);
   return container;
}

// non-const
// Not needed, because the const version returns by value
