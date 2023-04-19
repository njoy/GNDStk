
// -----------------------------------------------------------------------------
// documentation
// doc (short version, for user ease)
//
// Look around for CDATA content that may appear in places like this:
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
// documentation, or CDATA node, or even directly to a special::text metadatum.
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
      static const Child<void,Allow::one>
         docs ("documentations"),
         doc  ("documentation"),
         cdata(special::cdata);
      static const Meta<void> text(special::text);

      // In Node n, we try to find CDATA text at any level of:
      //    <documentations>
      //       <documentation name="endfDoc">
      //          <![CDATA[...]]>
      //       </documentation>
      //    </documentations>
      // in our internal structure. (XML for illustration only).
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
   // If we're in what looks like the root node of a tree, then look in all
   // of the top-level nodes. In a properly formatted GNDS file, there will
   // be just one such top-level node, e.g. reactionSuite.
   if (name == "/")
      for (const childPtr &ptr : children)
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
   static const Child<void,Allow::one> cdata(special::cdata);
   static const Meta<void> text(special::text);
   return (*this)(cdata, text, found);
}

// non-const
std::string &cdata(bool &found = detail::default_bool)
{
   static const Child<void,Allow::one> cdata(special::cdata);
   static const Meta<void> text(special::text);
   return (*this)(cdata, text, found);
}


// ------------------------
// data
// ------------------------

// const
const std::string &data(bool &found = detail::default_bool) const
{
   static const Child<void,Allow::one> data(special::data);
   static const Meta<void> text(special::text);
   return (*this)(data, text, found);
}

// non-const
std::string &data(bool &found = detail::default_bool)
{
   static const Child<void,Allow::one> data(special::data);
   static const Meta<void> text(special::text);
   return (*this)(data, text, found);
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

   for (const childPtr &c : children)
      if (c->name == special::comment && count++ == i)
         return c->meta(special::text,found);

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
//    <foo>
//       <!--  energy | capture | elastic  -->
//       <!--         |  width  |  width   -->
//       ...
//    </foo>
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
   for (const childPtr &c : children)
      if (c->name == special::comment &&
         (text = &c->meta(special::text,found), found))
         container.push_back(*text);
   return container;
}

// non-const
// Not needed, because the const version returns by value
