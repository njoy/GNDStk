
// -----------------------------------------------------------------------------
// writeClassPrefix
// -----------------------------------------------------------------------------

void writeClassPrefix(writer &out, const PerClass &per)
{
   // namespace
   out("namespace @ {", per.nsname);

   // comment introducing class
   out();
   out(largeComment);
   out("// @::", per.nsname);
   out("// class @", per.clname);
   out(largeComment);

   // class begin
   // A namespace prefix in Component<> prevents possible ambiguities with the
   // Child<> object, for the class, brought in through key.hpp. Normally the
   // class name is capitalized while the Child<> object isn't, but if the node
   // name was already capitalized in the specs (an example we encountered was
   // the name "XYs1d"), then the Child<> key would reflect that. Then, without
   // the nsname:: below, we'd have an ambiguity.
   out();
   out("class @ :", per.clname);

   if (per.isDataVector && per.elementType == "") {
      out(1,"public Component<@::@,true>", per.nsname, per.clname);
   } else if (per.isDataVector) {
      out(1,"public Component<@::@>,", per.nsname, per.clname);
      out(1,"public DataNode<std::vector<@>,@>", per.elementType,
          per.cdata ? "true" : "false");
   } else if (per.isDataString) {
      out(1,"public Component<@::@>,", per.nsname, per.clname);
      out(1,"public DataNode<std::string,@>",
          std::string(per.cdata ? "true" : "false"));
   } else {
      out(1,"public Component<@::@>", per.nsname, per.clname);
   }

   out("{");
   out(1,"friend class Component;");
} // writeClassPrefix


// -----------------------------------------------------------------------------
// writeClassForComponent
// -----------------------------------------------------------------------------

void writeClassForComponent(writer &out, const PerClass &per)
{
   // using [name for variant] = ...
   if (per.variants.size())
      out();
   for (const auto &v : per.variants) {
      out(1,"using @ = std::variant<", v.type);
      int count = 0;
      const int total = v.children.size();
      for (const auto &c : v.children)
         out(2,"@@", c.type, sep(count,total));
      out(1,">;");
   }

   // ------------------------
   // Simple functions
   // ------------------------

   out();
   out(1,smallComment);
   out(1,"// For Component");
   out(1,smallComment);
   out();
   out(1,"// Names: this namespace and class, "
       "and original nodes (as in XML <...>)");
   out(1,"static auto NAMESPACE() { return \"@\"; }", per.nsname);
   out(1,"static auto CLASS() { return \"@\"; }", per.clname);
   out(1,"static auto NODENAME() { return \"@\"; }", per.nameGNDS);

   // ------------------------
   // KEYS()
   // ------------------------

   // KEYS() begin
   out();
   out(1,"// Core Interface multi-query to transfer information "
       "to/from core Nodes");
   out(1,"static auto KEYS()");
   out(1,"{");

   // KEYS() contents
   int count = 0;
   const int total = per.nfields() + int(per.isDataNode);
   out(2,"return");

   // comment
   out(3,"// comment");
   out(3,"++Child<std::string>(special::comment) / CommentConverter{}@",
       std::string(total ? " |" : ""));

   // metadata
   if (per.metadata.size()) {
      out();
      out(3,"// metadata");
   }
   for (const auto &m : per.metadata) {
      out(3,"@{@}", m.typeFull, initializer(m));
      out(4,"/ Meta<>(\"@\")@@",
          m.original,
          // direct-specified converter, if any
          m.converter == "" ? "" : (" / " + m.converter),
          // separator between next entry
          ++count < total ? " |" : ""
      );
   }

   // children
   if (per.children.size() || per.variants.size()) {
      out();
      out(3,"// children");
   }
   for (const auto &c : per.children) {
      out(3,"@Child<@>",
          c.isVector ? "++" : "--",
          c.typeHalf // without any std::vector
      );
      out(4,"(\"@\")@@@@",
          c.original,
          // direct-specified converter, if any
          c.converter == "" ? "" : (" / " + c.converter),
          // direct-specified filter, if any
          c.filter == "" ? "" : (" + " + c.filter),
          // simple filter: value required for metadatum label, if any;
          // this augments (it doesn't replace) any direct-given filter
          c.label == "" ? "" : (" | \"" + c.label + '"'),
          // separator between next entry
          ++count < total ? " |" : ""
      );
   }

   // variants
   for (const auto &v : per.variants) {
      out(3,"@{}", v.typeHalf); // without any std::vector
      out(4,"/ @(", v.isVector ? "++" : "--", false);
      int n = 0; // for alternatives; not to be confused w/count
      for (const auto &c : v.children)
         out("@Child<>(\"@\")", n++ == 0 ? "" : " || ", c.name, false);
      out(")@",
          ++count < total ? " |" : ""
         );
   }

   // data
   if (per.isDataNode) {
      out();
      out(3,"// data");
      out(3,"--Child<DataNode>(special::self) / DataConverter{}");
   }

   // KEYS() end
   out(2,";");
   out(1,"}");

   // ------------------------
   // FIELDNAMES()
   // ------------------------

   out();
   out(1,"// Data member names. "
       "Usually - but not necessarily - the same as the node");
   out(1,"// names appearing in KEYS(). "
       "These are used by Component's prettyprinter.");
   out(1,"static const auto &FIELDNAMES()");
   out(1,"{");
   out(2,"static const std::vector<std::string> names = {");

   count = 0;
   out(3,"\"comment\"@", std::string(total ? "," : ""));
   for (const auto &m : per.metadata)
      out(3,"\"@\"@", m.name, ++count < total ? "," : "");
   for (const auto &c : per.children)
      out(3,"\"@\"@", c.name, ++count < total ? "," : "");
   for (const auto &v : per.variants)
      out(3,"\"@\"@", v.name, ++count < total ? "," : "");

   // Here, and in the Python case below, I'm not - for now - dealing with
   // the case of a dynamic data type, as with the "valueType" flag discussed
   // in the original GNDS specs. We may or may not really need support for
   // that If we do, we'll perhaps end up with several names: at least ints,
   // doubles, and strings. The way we use *references* in the C++ classes
   // (referring from inside the class to the base DataNode<vector> in the
   // vector case), isn't compatible, as-is, with the dynamic data type case.
   // There, I suppose we'd need a reference to the variant that can contain
   // vector<various types>. (For python bindings we call functions, rather
   // than having references of some sort.)
   if (per.isDataNode) {
      if (per.isDataString)
         out(3,"\"string\"");
      else {
         auto it = nameMap.find(per.elementType);
         if (it != nameMap.end())
            out(3,"\"@\"", it->second.second);
         else
            out(3,"\"\""); // really shouldn't happen
      }
   }

   out(2,"};");
   out(2,"return names;");
   out(1,"}");

   // ------------------------
   // PYTHONNAMES()
   // ------------------------

   out();
   out(1,"// Data member names, as they'll be presented "
       "in the Python bindings.");
   out(1,"static const auto &PYTHONNAMES()");
   out(1,"{");
   out(2,"static const std::vector<std::string> names = {");

   count = 0;
   out(3,"\"comment\"@", std::string(total ? "," : ""));
   for (const auto &m : per.metadata)
      out(3,"\"@\"@", namePython(m.name), ++count < total ? "," : "");
   for (const auto &c : per.children)
      out(3,"\"@\"@", namePython(c.name), ++count < total ? "," : "");
   for (const auto &v : per.variants)
      out(3,"\"@\"@", namePython(v.name), ++count < total ? "," : "");

   if (per.isDataNode) {
      if (per.isDataString)
         out(3,"\"string\"");
      else {
         auto it = nameMap.find(per.elementType);
         if (it != nameMap.end())
            out(3,"\"@\"", it->second.second);
         else
            out(3,"\"\""); // really shouldn't happen
      }
   }

   out(2,"};");
   out(2,"return names;");
   out(1,"}");
} // writeClassForComponent


// -----------------------------------------------------------------------------
// writeClassSuffix
// -----------------------------------------------------------------------------

void writeClassSuffix(
   writer &out, const PerClass &per, const InfoSpecs &specs
) {
   // ------------------------
   // assignment
   // ------------------------

   out();
   out(1,smallComment);
   out(1,"// Assignment operators");
   out(1,smallComment);
   out();

   // copy
   out(1,"// copy");
   out(1,"@ &operator=(const @ &other)", per.clname, per.clname);
   out(1,"{");
   out(2,"if (this != &other) {");
   if (printCtorCalls)
      out(3,"std::cout << \"assign: @: copy\" << std::endl;", per.clname);
   out(3,"Component::operator=(other);");
   if (per.isDataNode)
      out(3,"DataNode::operator=(other);");
   out(3,"comment = other.comment;");
   if (per.nfields() > 0) {
      for (const auto &m : per.metadata)
         out(3,"@ = other.@;", m.name, m.name);
      for (const auto &c : per.children)
         out(3,"@ = other.@;", c.name, c.name);
      for (const auto &v : per.variants)
         out(3,"@ = other.@;", v.name, v.name);
   }
   out(2,"}");
   out(2,"return *this;");
   out(1,"}");
   out();

   // move
   out(1,"// move");
   out(1,"@ &operator=(@ &&other)", per.clname, per.clname);
   out(1,"{");
   out(2,"if (this != &other) {");
   if (printCtorCalls)
      out(3,"std::cout << \"assign: @: move\" << std::endl;", per.clname);
   out(3,"Component::operator=(std::move(other));");
   if (per.isDataNode)
      out(3,"DataNode::operator=(std::move(other));");
   out(3,"comment = std::move(other.comment);");
   if (per.nfields() > 0) {
      for (const auto &m : per.metadata)
         out(3,"@ = std::move(other.@);", m.name, m.name);
      for (const auto &c : per.children)
         out(3,"@ = std::move(other.@);", c.name, c.name);
      for (const auto &v : per.variants)
         out(3,"@ = std::move(other.@);", v.name, v.name);
   }
   out(2,"}");
   out(2,"return *this;");
   out(1,"}");

   // ------------------------
   // customization #include
   // ------------------------

   out();
   out(1,smallComment);
   out(1,"// Custom functionality");
   out(1,smallComment);
   out();
   out(1,"#include \"@/@/@/@/src/custom.hpp\"",
       specs.Project, specs.Version, per.nsname, per.clname);

   // this *follows* the customization #include (because it might be used there)
   out(1,"#undef NJOY_GNDSTK_COMPONENT");

   // ------------------------
   // class+namespace end
   // ------------------------

   out("}; // class @", per.clname);
   out();
   out("} // namespace @", per.nsname);
} // writeClassSuffix


// -----------------------------------------------------------------------------
// writeClass*
// For metadata, children, and variant children
// -----------------------------------------------------------------------------

// writeClassContentMetadata
void writeClassContentMetadata(
   writer &out, const PerClass &per,
   std::string &title
) {
   if (per.metadata.size()) {
      out();
      out(1,"// metadata");
   }

   for (const auto &m : per.metadata) {
      if (m.type == "bool" && m.isOptional) {
         std::cout
            << title
            << color::custom::red
            << "   Metadatum will be an optional bool (not recommended): "
            << color::custom::blue << m.name
            << color::reset << std::endl;
         title = "";
      }

      if (per.isDataVector && per.elementType == "" &&
         (m.name == "length" || m.name == "start" || m.name == "valueType")
      ) {
         out(1,"mutable Field<@>", m.typeFull);
         out(2,"@{this", m.name, false);
      } else {
         out(1,"Field<@>", m.typeFull);
         out(2,"@{this", m.name, false);
      }
      if (m.defaultValue != "")
         out(",defaults.@", m.name, false);
      out("};");
   }
}

// writeClassContentChildren
void writeClassContentChildren(writer &out, const PerClass &per)
{
   if (per.children.size()) {
      out();
      out(1,"// children");
   }

   for (const auto &c : per.children) {
      out(1,"Field<@>", c.typeFull);
      out(2,"@{this};", c.name);

      if (debugging && c.name == "xs") {
         // todo
         // Consider some terminology changes...
         //    ns ==> nsname
         //    plain ==> key (as in, the JSON key)
         //    typeFull ==> ?
         //    typeHalf ==> ?
         // Also ordering:
         //    nsname
         //    key
         //    name
         //    type
         //    typeFull
         //    typeHalf
         std::cout << "name     == " << c.name     << std::endl;
         std::cout << "ns       == " << c.ns       << std::endl;
         std::cout << "plain    == " << c.plain    << std::endl;
         std::cout << "type     == " << c.type     << std::endl;
         std::cout << "typeFull == " << c.typeFull << std::endl;
         std::cout << "typeHalf == " << c.typeHalf << std::endl;
      }
   }
}

// writeClassContentVariants
void writeClassContentVariants(writer &out, const PerClass &per)
{
   if (per.variants.size()) {
      out();
      out(1,"// children - variant");
   }

   for (const auto &v : per.variants) {
      out(1,"Field<@>", v.typeFull);
      out(2,"@{this};", v.name);

      for (const auto &c : v.children) {
         out(1,"FieldPart<decltype(@),@> @{@};",
             v.name, c.type, c.name, v.name);
      }
   }
}


// -----------------------------------------------------------------------------
// writeClassCtor*
// -----------------------------------------------------------------------------

// writeClassCtorComponent
void writeClassCtorComponent(
   writer &out, const PerClass &per, const bool copyOrMove,
   const bool newline = true
) {
   out(2,"NJOY_GNDSTK_COMPONENT(@)",
       std::string(copyOrMove ? "other.baseBlockData()" : "BlockData{}"),
       newline);
}


// writeClassCtorBody
void writeClassCtorBody(
   writer &out,
   const std::string &kind,
   const std::string &clname,
   const std::string &argName
) {
   out(1,"{");
   if (printCtorCalls)
      out(2,"std::cout << \"ctor: @: @\" << std::endl;", clname, kind);
   out(2,"Component::finish(@);", argName);
   out(1,"}");
}


// writeClassCtors
void writeClassCtors(writer &out, const PerClass &per)
{
   // ------------------------
   // macro
   // ------------------------

   int count; const int total = per.nfields();

   out();
   out(1,"#define NJOY_GNDSTK_COMPONENT(blockdata) \\");
   out(1,"Component( \\");
   out(2,"blockdata, \\");
   out(2,"this->comment@ \\", std::string(total || per.isDataNode ? "," : ""));
   count = 0;
   for (const auto &m : per.metadata)
      out(2,"this->@@ \\", m.name,
          ++count < total || per.isDataNode ? "," : "");
   for (const auto &c : per.children)
      out(2,"this->@@ \\", c.name,
          ++count < total || per.isDataNode ? "," : "");
   for (const auto &v : per.variants)
      out(2,"this->@@ \\", v.name,
          ++count < total || per.isDataNode ? "," : "");
   if (per.isDataNode)
      out(2,"static_cast<DataNode &>(*this) \\");
   out(1,")");

   // ------------------------
   // ctor: default
   // ------------------------

   out();
   out(1,"// default");
   out(1,"@() :", per.clname);
   writeClassCtorComponent(out, per, false);
   writeClassCtorBody(out, "default", per.clname, "");

   // ------------------------
   // ctor: from fields
   // ------------------------

   if (total > 0) {
      out();

      // comment for this constructor
      out(1,"// from fields, comment excluded");

      // informational message, if applicable
      for (const auto &m : per.metadata)
         if (m.isDefaulted) {
            out(1,"// optional replaces Defaulted; "
                "this class knows the default(s)");
            break;
         }

      // signature
      count = 0;
      out(1,"explicit @(", per.clname);

      for (const auto &m : per.metadata) {
         out(2,"const wrapper<@>",
             m.isDefaulted ? "std::optional<" + m.type + ">" : m.typeFull);
         out(3,"&@@@",
             m.name, count ? " = {}" : "", count+1 < total ? "," : "");
         count++;
      }
      for (const auto &c : per.children) {
         out(2,"const wrapper<@>",
             c.typeFull);
         out(3,"&@@@",
             c.name, count ? " = {}" : "", count+1 < total ? "," : "");
         count++;
      }
      for (const auto &v : per.variants) {
         out(2,"const wrapper<@>",
             v.typeFull);
         out(3,"&@@@",
             v.name, count ? " = {}" : "", count+1 < total ? "," : "");
         count++;
      }

      // base constructor call
      out(1,") :");
      writeClassCtorComponent(out, per, false, false);

      // initialize fields
      out(",");
      count = 0;
      for (const auto &m : per.metadata)
         if (m.isDefaulted)
            out(2,"@(this,defaults.@,@)@",
                m.name, m.name, m.name, sep(count,total));
         else
            out(2,"@(this,@)@", m.name, m.name, sep(count,total));
      for (const auto &c : per.children)
         out(2,"@(this,@)@", c.name, c.name, sep(count,total));
      for (const auto &v : per.variants)
         out(2,"@(this,@)@", v.name, v.name, sep(count,total));

      // body
      writeClassCtorBody(out, "fields", per.clname, "");
   }

   // ------------------------
   // ctor: node
   // ------------------------

   out();
   out(1,"// from node");
   out(1,"explicit @(const Node &node) :", per.clname);
   writeClassCtorComponent(out, per, false);
   writeClassCtorBody(out, "node", per.clname, "node");

   // ------------------------
   // ctor: vector
   // ------------------------

   if (per.isDataVector && per.elementType == "") {
      out();
      out(1,"// from vector");
      out(1,"template<class T, class = "
          "std::enable_if_t<BLOCKDATA::template supported<T>>>");
      out(1,"explicit @(const std::vector<T> &vector) :",
          per.clname);
      writeClassCtorComponent(out, per, false);
      writeClassCtorBody(out, "vector", per.clname, "vector");
   } else if (per.isDataVector) {
      out();
      out(1,"// from vector<@>", per.elementType);
      out(1,"explicit @(const std::vector<@> &vector) :",
          per.clname, per.elementType);
      writeClassCtorComponent(out, per, false,false);
      out(",");
      out(2,"DataNode(vector)");
      writeClassCtorBody(out, "vector", per.clname, "vector");
   } else if (per.isDataString) {
      // todo
      // Perhaps construction from std::string here, as we do with std::vector
      // above, but we need to be careful. What if the class has a std::string
      // metadatum and no other fields? Then, I think, the constructor created
      // here would conflict with the "from fields" constructor. And, actually,
      // perhaps this sort of thing can happen in relation to std::vector too.
      // With other priorities being more pressing, let's address these concerns
      // only if and when necessary.
   }

   // ------------------------
   // ctor: copy
   // ------------------------

   out();
   out(1,"// copy");
   out(1,"@(const @ &other) :", per.clname, per.clname);
   writeClassCtorComponent(out, per, true, false);
   out(",");
   if (per.isDataNode)
      out(2,"DataNode(other),");
   out(2,"comment(this,other.comment)@", std::string(total ? "," : ""));
   count = 0;
   for (const auto &m : per.metadata)
      out(2,"@(this,other.@)@", m.name, m.name, sep(count,total));
   for (const auto &c : per.children)
      out(2,"@(this,other.@)@", c.name, c.name, sep(count,total));
   for (const auto &v : per.variants)
      out(2,"@(this,other.@)@", v.name, v.name, sep(count,total));
   writeClassCtorBody(out, "copy", per.clname, "other");

   // ------------------------
   // ctor: move
   // ------------------------

   out();
   out(1,"// move");
   out(1,"@(@ &&other) :", per.clname, per.clname);
   writeClassCtorComponent(out, per, true, false);
   out(",");
   if (per.isDataNode)
      out(2,"DataNode(std::move(other)),");
   out(2,"comment(this,std::move(other.comment))@",
       std::string(total ? "," : ""));
   count = 0;
   for (const auto &m : per.metadata)
      out(2,"@(this,std::move(other.@))@", m.name, m.name, sep(count,total));
   for (const auto &c : per.children)
      out(2,"@(this,std::move(other.@))@", c.name, c.name, sep(count,total));
   for (const auto &v : per.variants)
      out(2,"@(this,std::move(other.@))@", v.name, v.name, sep(count,total));
   writeClassCtorBody(out, "move", per.clname, "other");
} // writeClassCtors


// -----------------------------------------------------------------------------
// writeClass
// -----------------------------------------------------------------------------

void writeClass(
   const InfoSpecs &specs, std::string &title,
   const PerClass &per, std::string &code)
{
   // false: no "file was autogenerated" message, because in writeClass we're
   // writing certain class contents to a string, not writing an entire file.
   writer out(false);

   // output: class begin
   writeClassPrefix(out, per);

   // output: for the Component base
   writeClassForComponent(out, per);

   // section: public interface
   out();
   out(1,smallComment);
   out(1,"// Public interface");
   out(1,smallComment);
   out();
   out("public:");

   // output: using directives
   out();
   out(1,"using component_t = Component;");
   out(1,"using Component::construct;");
   if (per.isDataVector && per.elementType == "")
      out(1,"using BlockData::operator=;");
   else if (per.isDataNode)
      out(1,"using DataNode::operator=;");

   // output: defaults (applicable only to metadata)
   size_t ndefaults = 0;
   for (const auto &m : per.metadata)
      if (m.isDefaulted)
         ++ndefaults;
   if (ndefaults > 0) {
      out();
      out(1,"// defaults");
      out(1,"static inline const struct Defaults {");
      for (const auto &m : per.metadata)
         if (m.isDefaulted)
            out(2,"static inline const @ @ = @;",
                m.type, m.name, initializer(m));
      out(1,"} defaults;");
   }

   // section: data members
   out();
   out(1,smallComment);
   out(1,"// Data members");
   out(1,smallComment);

   // output: comment
   out();
   out(1,"// comment");
   out(1,"Field<std::vector<std::string>> comment{this};");

   // output: fields
   writeClassContentMetadata(out, per, title);
   writeClassContentChildren(out, per);
   writeClassContentVariants(out, per);

   // output: data string or vector reference, if applicable
   if (per.isDataNode) {
      if (per.isDataString) {
         out();
         out(1,"// data");
         out(1,"std::string &string = *this;");
      } else {
         auto it = nameMap.find(per.elementType);
         if (it != nameMap.end()) {
            out();
            out(1,"// data");
            out(1,"std::vector<@> &@ = *this;",
                it->second.first, it->second.second);
         } else {
            // This would mean either than our nameMap is missing something that
            // it ought to have, or that we're dealing with one of those dynamic
            // GNDS valueType-typed vectors, which is probably something we
            // should try to avoid dealing with. Perhaps, here, in the event
            // that we want anything in such a case, we'd make it a variant &
            // to the variant in the base BodyText.
         }
      }
   }

   // output: shortcuts
   if (per.name2path.size()) {
      out();
      out(1,"// shortcuts");
      out(1,"#define NJOY_GNDSTK_SHORTCUT(to,name) "
          "decltype(to.name) &name = to.name");

      for (const auto &cut : per.name2path) {
         const std::string &name = cut.first;
         const std::vector<std::string> &path = cut.second;
         std::string full;
         for (const std::string &field : path)
            full += field + "().";
         full.pop_back(); // trailing '.'
         out(1,"NJOY_GNDSTK_SHORTCUT(@,@);", full, name);
      }

      out(1,"#undef NJOY_GNDSTK_SHORTCUT");
   }

   // output: constructors
   out();
   out(1,smallComment);
   out(1,"// Constructors");
   out(1,smallComment);
   writeClassCtors(out, per);

   // output: class end
   writeClassSuffix(out, per, specs);

   // done
   code = out.str();
} // writeClass


// -----------------------------------------------------------------------------
// For the C++ header files
// fileGNDStkVersion
// fileGNDStkKey
// fileGNDStkClass
// -----------------------------------------------------------------------------

// ------------------------
// fileGNDStkVersion
// ------------------------

void fileGNDStkVersion(const InfoSpecs &specs)
{
   // ------------------------
   // Create a C++ header
   // for this version
   // ------------------------

   {
      writer out(specs.hppVersion);

      out();
      out("#ifndef @_@",
          allcaps(specs.Project), allcaps(specs.VersionUnderscore));
      out("#define @_@",
          allcaps(specs.Project), allcaps(specs.VersionUnderscore));

      if (specs.Enumerators.size()) {
         out();
         for (const auto &e : specs.Enumerators)
            out("#include \"@/@/enums/@.hpp\"",
                specs.Project, specs.Version, e.first);
      }

      std::string nsname_last = "";
      for (const auto &c : specs.class2data) {
         const std::string nsname = c.first.nsname;
         const std::string clname = c.first.clname;
         if (nsname != nsname_last)
            out();
         nsname_last = nsname;
         out("#include \"@/@/@/@.hpp\"",
             specs.Project, specs.Version, nsname, clname);
      }

      out();
      out("#endif");
   }

   // ------------------------
   // Create a C/C++ header
   // for the C interface
   // ------------------------

   {
      writer out(specs.hVersion);
      out();
      out(largeComment);
      out("// This header file is designed to work with both C and C++");
      out(largeComment);
      out();
      out("#ifndef C_INTERFACE_@_@",
          allcaps(specs.Project), allcaps(specs.VersionUnderscore));
      out("#define C_INTERFACE_@_@",
          allcaps(specs.Project), allcaps(specs.VersionUnderscore));

      out();
      out("#include \"GNDStk.h\"");
      out();
      out("#ifdef __cplusplus");
      out(1,"// For C++");
      out(1,"#include \"@/@.hpp\"", specs.Project, specs.Version);
      out("#endif");

      std::string nsname_last = "";
      for (const auto &c : specs.class2data) {
         const std::string nsname = c.first.nsname;
         const std::string clname = c.first.clname;
         if (nsname != nsname_last)
            out();
         nsname_last = nsname;
         out("#include \"@/@/@.h\"", specs.Version, nsname, clname);
      }

      out();
      out("#endif");
   }
} // fileGNDStkVersion


// ------------------------
// fileGNDStkKey
// ------------------------

void fileGNDStkKey(const InfoSpecs &specs)
{
   // ------------------------
   // Gather information
   // ------------------------

   // pair: key name, GNDS name
   using pair = std::pair<std::string, std::string>;

   // For metadata, collect into one place
   std::set<pair> metadata;

   // For children, process on a per-file basis; *multi*map is
   // in case the same namespace appears in more than one file.
   // The multimap contains: namespace name, set<pair>
   std::multimap<std::string, std::set<pair>> namespace2children;

   for (const auto &file : specs.JSONFiles) {
      const json::object jmain = readJSONFile(file);
      auto it = namespace2children.insert(
         std::make_pair(getFileNamespace(jmain),std::set<pair>{}));

      for (const auto &node : jmain) {
         if (isClass(node)) {
            // nodes ==> children
            it->second.insert(std::make_pair(
               nameField(node,specs),
               nameGNDS(node)));

            // attributes ==> metadata
            const json::object attrs =
               getMetadataJSON(node.second.get<json::object>());
            for (const auto &attr : attrs) {
               if (beginsin(attr.first, "//"))
                  continue;
               metadata.insert(std::make_pair(
                  nameField(attr,specs),
                  nameGNDS(attr)));
            }
         }
      }
   }

   // ------------------------
   // comment, macro guard,
   // outer namespaces
   // ------------------------

   writer out(specs.hppKey);
   out();
   out("#ifndef @_@_KEY",
       allcaps(specs.Project), allcaps(specs.VersionUnderscore));
   out("#define @_@_KEY",
       allcaps(specs.Project), allcaps(specs.VersionUnderscore));
   out();
   out("// GNDStk Core Interface");
   out("#include \"GNDStk.hpp\"");
   out();
   if (specs.Project == "GNDStk") // <== use namespace njoy only for this
      out("namespace njoy {");
   out("namespace @ {", specs.Project);
   out("namespace @ {", specs.VersionUnderscore);
   out();
   out("using namespace njoy;");
   out("using namespace GNDStk;");

   // ------------------------
   // Meta<> objects
   // ------------------------

   section(out,"// meta::");
   out();
   out("namespace meta {");

   if (metadata.size() > 0) {
      out();
      out(0,"#define NJOY_GNDSTK_MAKE_LOOKUP(nameField,nameGNDS) \\");
      out(1,"inline const auto nameField = makeLookup( \\");
      out(2,"#nameGNDS, \\");
      out(2,"[](const auto &obj) -> decltype(obj.nameField()) \\");
      out(2,"{ \\");
      out(3,"return obj.nameField(); \\");
      out(2,"} \\");
      out(1,")");
      out(0,"// nameField vs. nameGNDS: e.g. Double, vs. double in GNDS; "
          "usually identical");
      out();
      for (const auto &meta : metadata)
         out("NJOY_GNDSTK_MAKE_LOOKUP(@,@);", meta.first, meta.second);
      out();
      out(0,"#undef NJOY_GNDSTK_MAKE_LOOKUP");
      out();
   }

   out("} // namespace meta");

   // ------------------------
   // Child<> objects
   // ------------------------

   for (const auto &nspace : namespace2children) {
      section(out, "// @::child::", nspace.first);
      out();
      out("namespace @ {", nspace.first);
      out("namespace child {");

      const auto &children = nspace.second;
      if (children.size() > 0) {
         out();
         for (const auto &child : children)
            out("inline const Child<> @(\"@\");", child.first, child.second);
         out();
      }

      out("} // namespace child");
      out("using namespace child;");
      out("} // namespace @", nspace.first);
   }

   // ------------------------
   // Using directives
   // ------------------------

   section(out, "// For convenience: using directives");
   out();
   out("namespace key {");
   out(1,"using namespace meta;");
   for (const auto &nspace : namespace2children)
      out(1,"using namespace @::child;", nspace.first);
   out("} // namespace key");
   out();
   out("using namespace key;");
   for (const auto &nspace : namespace2children)
      out("using namespace @;", nspace.first);

   // ------------------------
   // finish
   // ------------------------

   out();
   out();
   out(largeComment);
   out(largeComment);
   out();
   out("} // namespace @", specs.VersionUnderscore);
   out("} // namespace @", specs.Project);
   if (specs.Project == "GNDStk") // <== end namespace njoy only for this
      out("} // namespace njoy");
   out();
   out("#endif");
} // fileGNDStkKey


// ------------------------
// fileGNDStkClass
// ------------------------

void fileGNDStkClass(
   const InfoSpecs &specs, const PerClass &per, const Class2Dependencies &c2d
) {
   // class-specific hpp file
   writer out(per.hppGNDStk);
   const std::string guard =
      allcaps(specs.Project) + "_" +
      allcaps(specs.VersionUnderscore) + "_" +
      allcaps(per.nsname) + "_" +
      allcaps(per.clname);

   out();
   out("#ifndef @", guard);
   out("#define @", guard);

   out();
   if (c2d.dependencies.size() == 0) // <== otherwise, comes in through deps
      out("#include \"@/@/key.hpp\"", specs.Project, specs.Version);
   for (const auto &dep : c2d.dependencies)
      out("#include \"@/@/@/@.hpp\"",
          specs.Project, specs.Version, dep.nsname, dep.clname);

   out();
   if (specs.Project == "GNDStk")
      out("namespace njoy {");
   out("namespace @ {", specs.Project);
   out("namespace @ {", specs.VersionUnderscore);
   out(per.code,false);
   out("} // namespace @", specs.VersionUnderscore);
   out("} // namespace @", specs.Project);
   if (specs.Project == "GNDStk")
      out("} // namespace njoy");
   out();
   out("#endif");
} // fileGNDStkClass
