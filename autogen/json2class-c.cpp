
// -----------------------------------------------------------------------------
// For the C interface
// -----------------------------------------------------------------------------

// two
// Forward args to two places: header and source
template<class... Ts>
void two(writer &hdr, writer &src, Ts &&...args)
{
   hdr(std::forward<Ts>(args)...);
   src(std::forward<Ts>(args)...);
}

// ext
// For writing (or not writing) 'extern "C"'
template<class... Ts>
void ext(writer &hdr, writer &src, const std::string &str, Ts &&...args)
{
   hdr("extern_c "+str, std::forward<Ts>(args)...);
   src(            str, std::forward<Ts>(args)...);
}

// ppp
// Comment, prefixed in header file with "+++"
template<class... Ts>
void ppp(writer &hdr, writer &src, const std::string &str, Ts &&...args)
{
   hdr("// +++ "+str, std::forward<Ts>(args)...);
   src("// "    +str, std::forward<Ts>(args)...);
}
template<class... Ts>
void PPP(writer &hdr, writer &src, Ts &&...args)
{
   two(hdr,src);
   ppp(hdr,src,std::forward<Ts>(args)...);
}

// mmm
// Comment, prefixed in header file with "---"
template<class... Ts>
void mmm(writer &hdr, writer &src, const std::string &str, Ts &&...args)
{
   hdr("// --- "+str, std::forward<Ts>(args)...);
   src("// "    +str, std::forward<Ts>(args)...);
}
template<class... Ts>
void MMM(writer &hdr, writer &src, Ts &&...args)
{
   two(hdr,src);
   mmm(hdr,src,std::forward<Ts>(args)...);
}

// sig
// End C interface function signature; style dependent on hadFields bool
void sig(writer &hdr, writer &src, const bool hadFields = false)
{
   // header: end of parameters, semicolon for declaration
   hdr(");");
   // source: end of parameters, left brace for definition
   src(hadFields ? ") {" : ")\n{");
}

// ctype_param
// Get metadata type for parameter
std::string ctype_param(const InfoMetadata &m)
{
   return m.type == "std::string"
      ? "char *const"
      : m.type;
}

// ctype_return
// Get metadata type for a return
std::string ctype_return(const InfoMetadata &m)
{
   return m.type == "std::string"
      ? "const char *"
      : m.type;
}

// ctype
// Get child-node type, for the C interface
std::string ctype(const InfoChildren &c)
{
   // Why not ...2Const... in the first case? See:
   //    https://stackoverflow.com/questions/5055655
   // and:
   //    https://c-faq.com/ansi/constmismatch.html
   // Remember that we're generating C code here, not C++ code.
   return c.isVector
      ? "ConstHandle2" + c.plain + " *const"
      : "ConstHandle2Const" + c.plain;
}

// section
template<class... Ts>
void section(writer &hdr, writer &src, const std::string &str, Ts &&...args)
{
   two(hdr,src);
   two(hdr,src);
   two(hdr,src,largeComment);
   two(hdr,src,str, std::forward<Ts>(args)...);
   two(hdr,src,largeComment);
}


// -----------------------------------------------------------------------------
// fileCInterfaceCreateParams
// -----------------------------------------------------------------------------

void fileCInterfaceCreateParams(writer &hdr, writer &src, const PerClass &per)
{
   int count = 0;
   const int total = per.nfields();

   // metadata
   for (const auto &m : per.metadata) {
      two(hdr,src);
      two(hdr,src,1,"const @ @@",
          ctype_param(m),
          m.name,
          ++count < total ? "," : "",
          false);
   }

   // children
   for (const auto &c : per.children) {
      two(hdr,src);
      two(hdr,src,1,"@ @@@",
          ctype(c),
          c.name,
          c.isVector ? ", const size_t "+c.name+"Size" : "",
          ++count < total ? "," : "",
          false
      );
   }

   // variants
   // todo

   if (total)
      two(hdr,src);
}


// -----------------------------------------------------------------------------
// fileCInterfaceCreateCall
// -----------------------------------------------------------------------------

void fileCInterfaceCreateCall(writer &hdr, writer &src, const PerClass &per)
{
   // metadata
   for (const auto &m : per.metadata) {
      src(",");
      src(2,"@", m.name, false);
   }

   // children
   for (const auto &c : per.children) {
      src(",");
      const std::string Child = c.plain;
      const std::string child = c.name;
      c.isVector
         ? src(2,"std::vector<CPP@>{}", Child, false)
         : src(2,"detail::tocpp<CPP@>(@)", Child, child, false);
   }

   // variants
   // todo

   src();
   src(1,");");
   for (const auto &c : per.children) {
      if (!c.isVector)
         continue;
      const std::string Child = c.plain;
      const std::string child = c.name;
      src(1,"for (size_t @N = 0; @N < @Size; ++@N)",
          Child, Child, child, Child);
      src(2,"@@Add(handle, @[@N]);",
          per.clname, Child, child, Child);
   }
   src(1,"return handle;");
   src("}");
}


// -----------------------------------------------------------------------------
// fileCInterfaceBasics
// -----------------------------------------------------------------------------

void fileCInterfaceBasics(writer &hdr, writer &src, const PerClass &per)
{
   // section comment
   section(
      hdr,src,
      "// Basics\n"
      "// Create, Assign, Delete"
   );

   // create: default, const
   MMM(hdr,src,"Create, default, const");
   ext(hdr,src,"Handle2Const@", per.clname);
   two(hdr,src,"@DefaultConst(", per.clname, false);
   sig(hdr,src);
   src(1,"return detail::createHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"DefaultConst\");");
   src("}");

   // create: default
   PPP(hdr,src,"Create, default");
   ext(hdr,src,"Handle2@", per.clname);
   two(hdr,src,"@Default(", per.clname, false);
   sig(hdr,src);
   src(1,"return detail::createHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"Default\");");
   src("}");

   // create: general, const
   MMM(hdr,src,"Create, general, const");
   ext(hdr,src,"Handle2Const@", per.clname);
   two(hdr,src,"@CreateConst(", per.clname, false);
   fileCInterfaceCreateParams(hdr,src,per);
   sig(hdr,src, per.nfields() != 0);
   src(1,"ConstHandle2@ handle = detail::createHandle<CPP,C>(", per.clname);
   src(2,"CLASSNAME, CLASSNAME+\"CreateConst\"", false);
   fileCInterfaceCreateCall(hdr,src,per);

   // create: general
   PPP(hdr,src,"Create, general");
   ext(hdr,src,"Handle2@", per.clname);
   two(hdr,src,"@Create(", per.clname, false);
   fileCInterfaceCreateParams(hdr,src,per);
   sig(hdr,src, per.nfields() != 0);
   src(1,"ConstHandle2@ handle = detail::createHandle<CPP,C>(", per.clname);
   src(2,"CLASSNAME, CLASSNAME+\"Create\"", false);
   fileCInterfaceCreateCall(hdr,src,per);

   // assign
   PPP(hdr,src,"Assign");
   ppp(hdr,src,"Use this to assign one handled object to another. "
       "Don't assign handles,");
   ppp(hdr,src,"as with to = from. That has a meaning that you probably "
       "don't intend.");
   ext(hdr,src,"void");
   two(hdr,src,"@Assign(", per.clname, false);
   two(hdr,src,"ConstHandle2@ self, ConstHandle2Const@ from",
       per.clname, per.clname, false);
   sig(hdr,src);
   src(1,"detail::assignHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"Assign\", self, from);");
   src("}");

   // delete
   PPP(hdr,src,"Delete");
   ppp(hdr,src,"We'll attempt to remove no-longer-used objects "
       "automatically, but you");
   ppp(hdr,src,"may improve performance if you delete them when "
       "you're done with them.");
   ext(hdr,src,"void");
   two(hdr,src,"@Delete(", per.clname, false);
   two(hdr,src,"ConstHandle2Const@ self", per.clname, false);
   sig(hdr,src);
   src(1,"detail::deleteHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"Delete\", self);");
   src("}");
} // fileCInterfaceBasics


// -----------------------------------------------------------------------------
// fileCInterfaceIO
// -----------------------------------------------------------------------------

void fileCInterfaceIO(writer &hdr, writer &src, const PerClass &per)
{
   // section comment
   section(
      hdr,src,
      "// I/O\n"
      "// Read, Write, Print\n"
      "// Each returns 0 if failure, 1 if success."
   );

   // read from file
   PPP(hdr,src,"Read from file");
   ppp(hdr,src,"File can be XML, JSON, or HDF5.");
   ppp(hdr,src,"We'll examine the file's contents to determine "
       "its type automatically.");
   ext(hdr,src,"int");
   two(hdr,src,"@Read(", per.clname, false);
   two(hdr,src,"ConstHandle2@ self, const char *const filename",
       per.clname, false);
   sig(hdr,src);
   src(1,"return detail::readHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"Read\", self, filename);");
   src("}");

   // write to file
   PPP(hdr,src,"Write to file");
   ppp(hdr,src,"File can be XML, JSON, or HDF5.");
   ppp(hdr,src,"We'll use filename's extension to determine "
       "the type you want written.");
   ext(hdr,src,"int");
   two(hdr,src,"@Write(", per.clname, false);
   two(hdr,src,"ConstHandle2Const@ self, const char *const filename",
       per.clname, false);
   sig(hdr,src);
   src(1,"return detail::writeHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"Write\", self, filename);");
   src("}");

   // print
   PPP(hdr,src,"Print to standard output, in our prettyprinting format");
   ext(hdr,src,"int");
   two(hdr,src,"@Print(", per.clname, false);
   two(hdr,src,"ConstHandle2Const@ self", per.clname, false);
   sig(hdr,src);
   src(1,"return detail::printHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"Print\", self);");
   src("}");

   // print, XML
   PPP(hdr,src,"Print to standard output, as XML");
   ext(hdr,src,"int");
   two(hdr,src,"@PrintXML(", per.clname, false);
   two(hdr,src,"ConstHandle2Const@ self", per.clname, false);
   sig(hdr,src);
   src(1,"return detail::printHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"PrintXML\", self, \"XML\");");
   src("}");

   // print, JSON
   PPP(hdr,src,"Print to standard output, as JSON");
   ext(hdr,src,"int");
   two(hdr,src,"@PrintJSON(", per.clname, false);
   two(hdr,src,"ConstHandle2Const@ self", per.clname, false);
   sig(hdr,src);
   src(1,"return detail::printHandle<CPP,C>");
   src(2,"(CLASSNAME, CLASSNAME+\"PrintJSON\", self, \"JSON\");");
   src("}");
} // fileCInterfaceIO


// -----------------------------------------------------------------------------
// fileCInterfaceVector
// -----------------------------------------------------------------------------

void fileCInterfaceVector(
   writer &hdr, writer &src,
   const PerClass &per, const std::string &type,
   const bool isSection = true
) {
   // section comment
   if (isSection)
      section(hdr,src,"// Data vector");
   else {
      assert(type != "");
      two(hdr,src);
      two(hdr,src,smallComment);
      two(hdr,src,"// @", type);
      two(hdr,src,smallComment);
   }

   // dynamic type?
   if (type == "") {
      // for a C interface, these are probably sufficient
      fileCInterfaceVector(hdr,src,per,"int",     false);
      fileCInterfaceVector(hdr,src,per,"unsigned",false);
      fileCInterfaceVector(hdr,src,per,"float",   false);
      fileCInterfaceVector(hdr,src,per,"double",  false);
      return;
   }

   // Example:
   //    type:  "double" (parameter to the present function)
   // Then:
   //    Class: "Foobar" (example class name)
   //    Types: "Doubles"
   // fixme The determination of Types should probably be more general.
   const std::string Class = per.clname;
   const std::string Types = type == "std::string"
      ? "Strings"
      : capital(type) + 's';

   // clear
   PPP(hdr,src,"Clear");
   ext(hdr,src,"void");
   two(hdr,src,"@@Clear(", Class, Types, false);
   two(hdr,src,"ConstHandle2@ self", Class, false);
   sig(hdr,src);
   src(1,"detail::vectorClear<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Clear\", self);", Types);
   src("}");

   // get size
   PPP(hdr,src,"Get size");
   ext(hdr,src,"size_t");
   two(hdr,src,"@@Size(", Class, Types, false);
   two(hdr,src,"ConstHandle2Const@ self", Class, false);
   sig(hdr,src);
   src(1,"return detail::vectorSize<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Size\", self);", Types);
   src("}");

   // get value
   PPP(hdr,src,"Get value");
   ppp(hdr,src,"By index \\in [0,size)");
   ext(hdr,src,"@", type);
   two(hdr,src,"@@Get(", Class, Types, false);
   two(hdr,src,"ConstHandle2Const@ self, const size_t index", Class, false);
   sig(hdr,src);
   src(1,"return detail::vectorGet<CPP,@>", type);
   src(2,"(CLASSNAME, CLASSNAME+\"@Get\", self, index);", Types);
   src("}");

   // set value
   PPP(hdr,src,"Set value");
   ppp(hdr,src,"By index \\in [0,size)");
   ext(hdr,src,"void");
   two(hdr,src,"@@Set(", Class, Types, false);
   two(hdr,src,"ConstHandle2@ self, const size_t index, const @ value",
       Class, type, false);
   sig(hdr,src);
   src(1,"detail::vectorSet<CPP,@>", type);
   src(2,"(CLASSNAME, CLASSNAME+\"@Set\", self, index, value);", Types);
   src("}");

   // fixme
   // For now, we only have the following for non-std::string types.
   // Supporting std::string here means we really need the equivalent
   // of char** (pointer to pointer to char).
   if (type != "std::string") {
      // get pointer to existing values, const
      MMM(hdr,src,"Get pointer to existing values, const");
      ext(hdr,src,"const @ *", type);
      two(hdr,src,"@@GetArrayConst(", Class, Types, false);
      two(hdr,src,"ConstHandle2Const@ self", Class, false);
      sig(hdr,src);
      src(1,"return detail::vectorGet<CPP,@>", type);
      src(2,"(CLASSNAME, CLASSNAME+\"@GetArrayConst\", self);", Types);
      src("}");

      // get pointer to existing values
      PPP(hdr,src,"Get pointer to existing values");
      ext(hdr,src,"@ *", type);
      two(hdr,src,"@@GetArray(", Class, Types, false);
      two(hdr,src,"ConstHandle2@ self", Class, false);
      sig(hdr,src);
      src(1,"return detail::vectorGet<CPP,@>", type);
      src(2,"(CLASSNAME, CLASSNAME+\"@GetArray\", self);", Types);
      src("}");

      // set completely new values and size
      PPP(hdr,src,"Set completely new values and size");
      ext(hdr,src,"void");
      two(hdr,src,"@@SetArray(", Class, Types, false);
      two(hdr,src,"ConstHandle2@ self, const @ *const values, "
         "const size_t size",
          Class, type, false);
      sig(hdr,src);
      src(1,"return detail::vectorSet<CPP,@>", type);
      src(2,"(CLASSNAME, CLASSNAME+\"@SetArray\", self, size, values);", Types);
      src("}");
   }
} // fileCInterfaceVector


// -----------------------------------------------------------------------------
// fileCInterfaceMeta
// -----------------------------------------------------------------------------

void fileCInterfaceMeta(
   writer &hdr, writer &src,
   const PerClass &per, const InfoMetadata &m
) {
   const std::string Class = per.clname;
   const std::string Meta  = UpperCamel(m.name);
   const std::string meta  = m.name;

   // section comment
   section(hdr,src,"// Metadatum: @", meta);

   // has
   PPP(hdr,src,"Has");
   ext(hdr,src,"int");
   two(hdr,src,"@@Has(", Class, Meta, false);
   two(hdr,src,"ConstHandle2Const@ self", Class, false);
   sig(hdr,src);
   src(1,"return detail::hasField<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Has\", self, extract::@);", Meta, meta);
   src("}");

   // get
   PPP(hdr,src,"Get");
   ppp(hdr,src,"Returns by value");
   ext(hdr,src,"@", ctype_return(m));
   two(hdr,src,"@@Get(", Class, Meta, false);
   two(hdr,src,"ConstHandle2Const@ self", Class, false);
   sig(hdr,src);
   src(1,"return detail::getField<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Get\", self, extract::@);", Meta, meta);
   src("}");

   // set
   PPP(hdr,src,"Set");
   ext(hdr,src,"void");
   two(hdr,src,"@@Set(", Class, Meta, false);
   two(hdr,src,"ConstHandle2@ self, const @ @",
       Class, ctype_param(m), meta, false);
   sig(hdr,src);
   src(1,"detail::setField<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Set\", self, extract::@, @);",
       Meta, meta, meta);
   src("}");
} // void fileCInterfaceMeta


// -----------------------------------------------------------------------------
// fileCInterfaceChild
// -----------------------------------------------------------------------------

void fileCInterfaceChild(
   writer &hdr, writer &src,
   const PerClass &per, const InfoChildren &c, const InfoSpecs &specs
) {
   const std::string Class = per.clname;
   const std::string Child = c.plain;
   const std::string child = c.name;

   // section comment
   section(hdr,src,"// Child: @", child);

   // has
   PPP(hdr,src,"Has");
   ext(hdr,src,"int");
   two(hdr,src,"@@Has(", Class, Child, false);
   two(hdr,src,"ConstHandle2Const@ self", Class, false);
   sig(hdr,src);
   src(1,"return detail::hasField<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Has\", self, extract::@);", Child, child);
   src("}");

   // ------------------------
   // scalar case
   // ------------------------

   if (!c.isVector) {
      // get, const
      MMM(hdr,src,"Get, const");
      ext(hdr,src,"Handle2Const@", Child);
      two(hdr,src,"@@GetConst(", Class, Child, false);
      two(hdr,src,"ConstHandle2Const@ self", Class, false);
      sig(hdr,src);
      src(1,"return detail::getField<CPP,Handle2Const@>", Child);
      src(2,"(CLASSNAME, CLASSNAME+\"@GetConst\", self, extract::@);",
          Child, child);
      src("}");

      // get
      PPP(hdr,src,"Get");
      ext(hdr,src,"Handle2@", Child);
      two(hdr,src,"@@Get(", Class, Child, false);
      two(hdr,src,"ConstHandle2@ self", Class, false);
      sig(hdr,src);
      src(1,"return detail::getField<CPP,Handle2@>", Child);
      src(2,"(CLASSNAME, CLASSNAME+\"@Get\", self, extract::@);", Child, child);
      src("}");

      // set
      PPP(hdr,src,"Set");
      ext(hdr,src,"void");
      two(hdr,src,"@@Set(", Class, Child, false);
      two(hdr,src,"ConstHandle2@ self, ConstHandle2Const@ @",
          Class, Child, child, false);
      sig(hdr,src);
      src(1,"detail::setField<CPP,CPP@>", Child);
      src(2,"(CLASSNAME, CLASSNAME+\"@Set\", self, extract::@, @);",
          Child, child, child);
      src("}");

      // done with this child
      return;
   }

   // ------------------------
   // vector case
   // ------------------------

   // clear
   PPP(hdr,src,"Clear");
   ext(hdr,src,"void");
   two(hdr,src,"@@Clear(", Class, Child, false);
   two(hdr,src,"ConstHandle2@ self", Class, false);
   sig(hdr,src);
   src(1,"detail::clearContainer<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Clear\", self, extract::@);", Child, child);
   src("}");

   // size
   PPP(hdr,src,"Size");
   ext(hdr,src,"size_t");
   two(hdr,src,"@@Size(", Class, Child, false);
   two(hdr,src,"ConstHandle2Const@ self", Class, false);
   sig(hdr,src);
   src(1,"return detail::sizeOfContainer<CPP>");
   src(2,"(CLASSNAME, CLASSNAME+\"@Size\", self, extract::@);", Child, child);
   src("}");

   // add
   PPP(hdr,src,"Add");
   ext(hdr,src,"void");
   two(hdr,src,"@@Add(", Class, Child, false);
   two(hdr,src,"ConstHandle2@ self, ", Class, false);
   two(hdr,src,"ConstHandle2Const@ @", Child, child, false);
   sig(hdr,src);
   src(1,"detail::addToContainer<CPP,CPP@>", Child);
   src(2,"(CLASSNAME, CLASSNAME+\"@Add\", self, extract::@, @);",
       Child, child, child);
   src("}");

   // get, by index, const
   MMM(hdr,src,"Get, by index \\in [0,size), const");
   ext(hdr,src,"Handle2Const@", Child);
   two(hdr,src,"@@GetConst(", Class, Child, false);
   two(hdr,src,"ConstHandle2Const@ self, ", Class, false);
   two(hdr,src,"const size_t index_", false);
   sig(hdr,src);
   src(1,"return detail::getByIndex<CPP,Handle2Const@>", Child);
   src(2,"(CLASSNAME, CLASSNAME+\"@GetConst\", self, extract::@, index_);",
       Child, child);
   src("}");

   // get, by index
   PPP(hdr,src,"Get, by index \\in [0,size)");
   ext(hdr,src,"Handle2@", Child);
   two(hdr,src,"@@Get(", Class, Child, false);
   two(hdr,src,"ConstHandle2@ self, ", Class, false);
   two(hdr,src,"const size_t index_", false);
   sig(hdr,src);
   src(1,"return detail::getByIndex<CPP,Handle2@>", Child);
   src(2,"(CLASSNAME, CLASSNAME+\"@Get\", self, extract::@, index_);",
       Child, child);
   src("}");

   // set, by index
   PPP(hdr,src,"Set, by index \\in [0,size)");
   ext(hdr,src,"void");
   two(hdr,src,"@@Set(", Class, Child, false);
   two(hdr,src);
   two(hdr,src,1,"ConstHandle2@ self,", Class);
   two(hdr,src,1,"const size_t index_,");
   two(hdr,src,1,"ConstHandle2Const@ @", Child, child);
   sig(hdr,src,true);
   src(1,"detail::setByIndex<CPP,CPP@>", Child);
   src(2,"(CLASSNAME, CLASSNAME+\"@Set\", self, extract::@, index_, @);",
       Child, child, child);
   src("}");

   // ------------------------
   // for this child's metadata:
   // has, get const, get, set
   // ------------------------

   // first make sure that we know about this class
   const auto it = specs.class2data.find(NamespaceAndClass(c.ns,c.plain));
   if (it == specs.class2data.end()) {
      log::warning(
         "Unable to generate C interface has/get/set functions for:\n"
         "   class: {}::{}\n"
         "   child: {}::{}\n"
         "Child class is unknown, so its metadata for has/get/set are unknown.",
         per.nsname, Class,
         c.ns, Child
      );
      return;
   }

   // has, get const, get, set
   for (const auto &m : it->second.metadata) {
      const std::string Meta = UpperCamel(m.name);
      const std::string meta = m.name;

      // subsection header
      two(hdr,src);
      two(hdr,src,smallComment);
      two(hdr,src,"// Re: metadatum @", meta);
      two(hdr,src,smallComment);

      // has, by metadatum
      PPP(hdr,src,"Has, by @", meta);
      ext(hdr,src,"int");
      two(hdr,src,"@@HasBy@(", Class, Child, Meta, false);
      two(hdr,src);
      two(hdr,src,1,"ConstHandle2Const@ self,", Class);
      two(hdr,src,1,"const @ @", ctype_param(m), meta);
      sig(hdr,src,true);
      src(1,"return detail::hasByMetadatum<CPP>");
      src(2,"(CLASSNAME, CLASSNAME+\"@HasBy@\",", Child, Meta);
      src(2," self, extract::@, meta::@, @);", child, meta, meta);
      src("}");

      // get, by metadatum, const
      MMM(hdr,src,"Get, by @, const", meta);
      ext(hdr,src,"Handle2Const@", Child);
      two(hdr,src,"@@GetBy@Const(", Class, Child, Meta, false);
      two(hdr,src);
      two(hdr,src,1,"ConstHandle2Const@ self,", Class);
      two(hdr,src,1,"const @ @", ctype_param(m), meta);
      sig(hdr,src,true);
      src(1,"return detail::getByMetadatum<CPP,Handle2Const@>", Child);
      src(2,"(CLASSNAME, CLASSNAME+\"@GetBy@Const\",", Child, Meta);
      src(2," self, extract::@, meta::@, @);", child, meta, meta);
      src("}");

      // get, by metadatum
      PPP(hdr,src,"Get, by @", meta);
      ext(hdr,src,"Handle2@", Child);
      two(hdr,src,"@@GetBy@(", Class, Child, Meta, false);
      two(hdr,src);
      two(hdr,src,1,"ConstHandle2@ self,", Class);
      two(hdr,src,1,"const @ @", ctype_param(m), meta);
      sig(hdr,src,true);
      src(1,"return detail::getByMetadatum<CPP,Handle2@>", Child);
      src(2,"(CLASSNAME, CLASSNAME+\"@GetBy@\",", Child, Meta);
      src(2," self, extract::@, meta::@, @);", child, meta, meta);
      src("}");

      // set, by metadatum
      PPP(hdr,src,"Set, by @", meta);
      ext(hdr,src,"void");
      two(hdr,src,"@@SetBy@(", Class, Child, Meta, false);
      two(hdr,src);
      two(hdr,src,1,"ConstHandle2@ self,", Class);
      two(hdr,src,1,"const @ @,", ctype_param(m), meta);
      two(hdr,src,1,"ConstHandle2Const@ @", Child, child);
      sig(hdr,src,true);
      src(1,"detail::setByMetadatum<CPP,CPP@>", Child);
      src(2,"(CLASSNAME, CLASSNAME+\"@SetBy@\",", Child, Meta);
      src(2," self, extract::@, meta::@, @, @);", child, meta, meta, child);
      src("}");
   } // metadata
} // fileCInterfaceChild


// -----------------------------------------------------------------------------
// For the C interface
// -----------------------------------------------------------------------------

// ------------------------
// fileCInterfaceHeader
// ------------------------

void fileCInterfaceHeader(
   writer &hdr, const InfoSpecs &specs,
   const PerClass &per, const Class2Dependencies &c2d
) {
   // Initial remarks
   hdr();
   hdr("// Interface for C");
   hdr("// This header file is designed to work with both C and C++");
   hdr("// Function definitions are in this file's .cpp source");
   hdr();

   // Instructions
   hdr(largeComment);
   hdr(largeComment);
   hdr("// Instructions for Users");
   hdr("//");
   hdr("// Constructs you're MORE likely to care about are preceded with:");
   hdr("//    // +++ remark");
   hdr("// Constructs you're LESS likely to care about are preceded with:");
   hdr("//    // --- remark");
   hdr("// Anything not marked as above can be ignored by most users.");
   hdr("//");
   hdr("// @ is the basic handle type in this file. Example:", per.clname);
   hdr("//    // Create a default @ object:", per.clname);
   hdr("//    @ handle = @Default();", per.clname, per.clname);
   hdr("// Functions involving @ are declared throughout this file.",
       per.clname);
   hdr(largeComment);
   hdr(largeComment);

   // Preliminaries
   section(hdr, "// Preliminaries");
   const std::string guard =
      allcaps(specs.Project) + "_" +
      allcaps(specs.VersionUnderscore) + "_" +
      allcaps(per.nsname) + "_" +
      allcaps(per.clname);

   hdr();
   hdr("#ifndef C_INTERFACE_@", guard);
   hdr("#define C_INTERFACE_@", guard);
   hdr();
   hdr("#include \"GNDStk.h\"");
   for (const auto &dep : c2d.dependencies)
      hdr("#include \"@/@/@.h\"", specs.Version, dep.nsname, dep.clname);
   hdr();
   hdr("#ifdef __cplusplus");
   hdr(1,"#define extern_c extern \"C\"");
   hdr("#else");
   hdr(1,"#define extern_c");
   hdr("#endif");
   hdr();
   hdr("// Proxy C struct for the handled C++ class");
   hdr("struct @Class { };", per.clname);

   // Handle types
   section(hdr, "// Handle types");
   hdr();
   hdr("// +++ @", per.clname);
   hdr("// +++ General handle, suitable for most users. "
       "If you're not concerned about");
   hdr("// +++ strict \"const correctness\" in your C code, "
       "you can probably use this in");
   hdr("// +++ place of any function parameter of a const-aware handle type.");
   hdr("typedef struct @Class *@;", per.clname, per.clname);
   hdr();
   hdr("// --- Const-aware handles.");
   hdr("typedef const struct @Class *const ConstHandle2Const@;",
       per.clname, per.clname);
   hdr("typedef       struct @Class *const ConstHandle2@;",
       per.clname, per.clname);
   hdr("typedef const struct @Class *      Handle2Const@;",
       per.clname, per.clname);
   hdr("typedef       struct @Class *      Handle2@;",
       per.clname, per.clname);
} // fileCInterfaceHeader


// ------------------------
// fileCInterfaceSource
// ------------------------

void fileCInterfaceSource(
   writer &src, const InfoSpecs &specs,
   const PerClass &per, const Class2Dependencies &c2d
) {
   // includes
   src();
   src("#include \"@/@/@/@.hpp\"",
       specs.Project, specs.Version, per.nsname, per.clname);
   src("#include \"@.h\"", per.clname);
   src();

   // using namespace
   src("using namespace njoy::GNDStk;");
   src("using namespace @::@;", specs.Project, specs.VersionUnderscore);
   src();

   // using
   src("using C = @Class;", per.clname);
   src("using CPP = multigroup::@;", per.clname);
   src();

   // class name
   src("static const std::string CLASSNAME = \"@\";", per.clname);

   // extract: namespace begin
   if (per.nfields()) {
      src();
      src("namespace extract {");
   }

   // extract: metadata
   for (const auto &m : per.metadata)
      src(1,"static auto @ = [](auto &obj) { return &obj.@; };",
          m.name, m.name);

   // extract: children
   for (const auto &c : per.children)
      src(1,"static auto @ = [](auto &obj) { return &obj.@; };",
          c.name, c.name);

   // extract: variants
   // todo

   // extract: namespace end
   if (per.nfields()) src("}");

   if (c2d.dependencies.size())
      src();
   for (const auto &dep : c2d.dependencies)
      src("using CPP@ = @::@;", dep.clname, dep.nsname, dep.clname);
} // fileCInterfaceSource


// ------------------------
// fileCInterfaceCommon
// ------------------------

void fileCInterfaceCommon(
   writer &hdr, writer &src,
   const InfoSpecs &specs,
   const PerClass &per, const Class2Dependencies &c2d
) {
   // Basics: create, assign, delete
   fileCInterfaceBasics(hdr,src, per);

   // IO: read, write, print
   fileCInterfaceIO(hdr,src, per);

   // Array support, if BlockData
   if (per.isDataVector)
      fileCInterfaceVector(hdr,src, per, per.elementType);

   // Functions regarding metadata
   for (const auto &m : per.metadata)
      fileCInterfaceMeta(hdr,src, per, m);

   // Functions regarding children
   for (const auto &c : per.children)
      fileCInterfaceChild(hdr,src, per, c, specs);

   // Functions regarding variants
   // todo
} // fileCInterfaceCommon


// ------------------------
// fileCInterface
// ------------------------

void fileCInterface(
   const InfoSpecs &specs, const PerClass &per, const Class2Dependencies &c2d
) {
   // header beginning
   writer hdr(per.headerC);
   fileCInterfaceHeader(hdr, specs, per, c2d);

   // source beginning
   writer src(per.sourceC);
   fileCInterfaceSource(src, specs, per, c2d);

   // common, or partially common, to both header and source
   fileCInterfaceCommon(hdr,src, specs, per, c2d);

   // header: customization #include, then done
   section(hdr, "// Custom functionality");
   hdr();
   hdr("#include \"@/@/@/src/custom.h\"",
       specs.Version, per.nsname, per.clname);
   hdr();
   hdr("#undef extern_c");
   hdr("#endif");

   // source: customization #include, then done
   section(src, "// Custom functionality");
   src();
   src("#include \"@/@/@/src/custom.cpp\"",
       specs.Version, per.nsname, per.clname);
} // fileCInterface
