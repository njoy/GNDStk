
// -----------------------------------------------------------------------------
// For the Fortran 2003 interface
// -----------------------------------------------------------------------------

// nameMapFortran
const std::map<std::string,std::string> nameMapFortran =
{
   { "type", "type1" }
};

// fname
std::string fname(const std::string &varname)
{
   const auto it = nameMapFortran.find(varname);
   return it == nameMapFortran.end() ? varname : it->second;
}

// ftype
// Get metadata type, for the Fortran interface
std::string ftype(const std::string &type)
{
   // string
   if (type == "std::string")
      return "type(c_ptr)";

   // bool
   if (type == "bool")
      return "logical(c_bool)";

   // integral
   if (type == "int")
      return "integer(c_int)";
   if (type == "unsigned")
      return "integer(c_unsigned)"; // todo Actually, no unsigned in Fortran

   // floating-point
   if (type == "float")
      return "real(c_float)";
   if (type == "double")
      return "real(c_double)";
   if (type == "long double")
      return "real(c_long_double)";

   // fixme
   return "unknownType";
}


// -----------------------------------------------------------------------------
// fileF03InterfaceCreateParams
// -----------------------------------------------------------------------------

void fileF03InterfaceCreateParams(writer &src, const PerClass &per)
{
   int count = 0;
   const int total = per.nfields();
   std::vector<std::string> sizes;

   // Determine if any parameters will need need to have their sizes at the
   // end of the parameter list. This is determined here because it affects
   // whether or not commas may be needed earlier, after other parameters.
   bool hasSizes = false;
   for (const auto &m : per.metadata)
      if (m.type == "std::string")
         hasSizes = true;

   // metadata
   for (const auto &m : per.metadata) {
      const std::string varname = fname(m.name);
      src();
      src(1,"@@ &", varname, ++count < total || hasSizes ? "," : "", false);
      if (m.type == "std::string")
         sizes.push_back(varname+"Size");
   }

   // children
   for (const auto &c : per.children) {
      const std::string varname = fname(c.name);
      src();
      c.isVector
         ? src(1,"@, @Size@ &", varname, varname,
               ++count < total || hasSizes ? "," : "", false)
         : src(1,"@@ &", varname,
               ++count < total || hasSizes ? "," : "", false);
   }

   // variants
   // todo

   src();

   // sizes
   count = 0;
   for (const std::string &s : sizes)
      src(1,"@@ &", s, ++count < sizes.size() ? "," : "");
}


// -----------------------------------------------------------------------------
// fileF03InterfaceDeclareParams
// -----------------------------------------------------------------------------

void fileF03InterfaceDeclareParams(writer &src, const PerClass &per)
{
   // metadata
   for (const auto &m : per.metadata) {
      const std::string varname = fname(m.name);
      if (m.type == "std::string") {
         src(1,"integer(c_size_t), intent(in), value :: @Size", varname);
         src(1,"character(c_char), intent(in) :: @(@Size)", varname, varname);
      } else
         src(1,"@, intent(in), value :: @", ftype(m.type), varname);
   }

   // children
   for (const auto &c : per.children) {
      const std::string varname = fname(c.name);
      if (c.isVector) {
         src(1,"integer(c_size_t), intent(in), value :: @Size", varname);
         src(1,"type(c_ptr), intent(in) :: @(@Size)", varname, varname);
      } else
         src(1,"type(c_ptr), intent(in), value :: @", varname);
   }

   // variants
   // todo
}


// -----------------------------------------------------------------------------
// fileF03InterfaceBasics
// -----------------------------------------------------------------------------

void fileF03InterfaceBasics(writer &src, const PerClass &per)
{
   std::string sub;

   // section comment
   sectionFortran(
      src,
      "!! Basics\n"
      "!! Create, Assign, Delete"
   );

   // create: default, const
   sub = per.clname + "DefaultConst";
   src();
   src("!! Create, default, const");
   src("function @() &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr) :: @", sub);
   src("end function @", sub);

   // create: default, non-const
   sub = per.clname + "Default";
   src();
   src("!! Create, default, non-const");
   src("function @() &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr) :: @", sub);
   src("end function @", sub);

   // create: general, const
   sub = per.clname + "CreateConst";
   src();
   src("!! Create, general, const");
   src("function @( &", sub, false);
   fileF03InterfaceCreateParams(src,per);
   src(") &");
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   fileF03InterfaceDeclareParams(src,per);
   src(1,"type(c_ptr) :: @", sub);
   src("end function @", sub);

   // create: general, non-const
   sub = per.clname + "Create";
   src();
   src("!! Create, general, non-const");
   src("function @( &", sub, false);
   fileF03InterfaceCreateParams(src,per);
   src(") &");
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   fileF03InterfaceDeclareParams(src,per);
   src(1,"type(c_ptr) :: @", sub);
   src("end function @", sub);

   // assign
   sub = per.clname + "Assign";
   src();
   src("!! Assign");
   src("subroutine @(handleLHS, handleRHS) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handleLHS");
   src(1,"type(c_ptr), intent(in), value :: handleRHS");
   src("end subroutine @", sub);

   // delete
   sub = per.clname + "Delete";
   src();
   src("!! Delete");
   src("subroutine @(handle) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src("end subroutine @", sub);
}


// -----------------------------------------------------------------------------
// fileF03InterfaceIO
// -----------------------------------------------------------------------------

void fileF03InterfaceIO(writer &src, const PerClass &per)
{
   std::string sub;

   // section comment
   sectionFortran(
      src,
      "!! I/O\n"
      "!! Read, Write, Print\n"
      "!! Each returns 0 if failure, 1 if success."
   );

   // read from file
   sub = per.clname + "Read";
   src();
   src("!! Read from file");

   src("!! File can be XML, JSON, or HDF5.");
   src("!! We'll examine the file's contents to determine "
       "its type automatically.");
   src("function @(handle, filename, filenameSize) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src(1,"integer(c_size_t), intent(in), value :: filenameSize");
   src(1,"character(c_char), intent(in) :: filename(filenameSize)");
   src(1,"integer(c_int) :: @", sub);
   src("end function @", sub);

   // write to file
   sub = per.clname + "Write";
   src();
   src("!! Write to file");
   src("!! File can be XML, JSON, or HDF5.");
   src("!! We'll use filename's extension to determine "
       "the type you want written.");
   src("function @(handle, filename, filenameSize) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_size_t), intent(in), value :: filenameSize");
   src(1,"character(c_char), intent(in) :: filename(filenameSize)");
   src(1,"integer(c_int) :: @", sub);
   src("end function @", sub);

   // print
   sub = per.clname + "Print";
   src();
   src("!! Print to standard output, in our prettyprinting format");
   src("function @(handle) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_int) :: @", sub);
   src("end function @", sub);

   // print, XML
   sub = per.clname + "PrintXML";
   src();
   src("!! Print to standard output, as XML");
   src("function @(handle) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_int) :: @", sub);
   src("end function @", sub);

   // print, JSON
   sub = per.clname + "PrintJSON";
   src();
   src("!! Print to standard output, as JSON");
   src("function @(handle) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_int) :: @", sub);
   src("end function @", sub);
}


// -----------------------------------------------------------------------------
// fileF03InterfaceVector
// -----------------------------------------------------------------------------

void fileF03InterfaceVector(
   writer &src,
   const PerClass &per, const std::string &type,
   const bool isSection = true
) {
   // section comment
   if (isSection)
      sectionFortran(src,"!! Data vector");
   else {
      assert(type != "");
      src();
      src(smallFortran);
      src("!! @", type);
      src(smallFortran);
   }

   // dynamic type?
   if (type == "") {
      // Mirrors what we support in the C interface.
      fileF03InterfaceVector(src, per, "int",      false);
      fileF03InterfaceVector(src, per, "unsigned", false);
      fileF03InterfaceVector(src, per, "float",    false);
      fileF03InterfaceVector(src, per, "double",   false);
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
   std::string sub;

   // clear
   sub = Class + Types + "Clear";
   src();
   src("!! Clear");
   src("subroutine @(handle) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src("end subroutine @", sub);

   // get size
   sub = Class + Types + "Size";
   src();
   src("!! Get size");
   src("function @(handle) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_size_t) :: @", sub);
   src("end function @", sub);

   // get value
   sub = Class + Types + "Get";
   src();
   src("!! Get value");
   src("!! By index \\in [0,size)");
   src("function @(handle, arrayIndex) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_size_t), intent(in), value :: arrayIndex");
   type == "std::string"
      ? src(1,"type(c_ptr) :: @", sub)
      : src(1,"@ :: @", ftype(type), sub);
   src("end function @", sub);

   // set value
   // Note: the type == std::string case occurs when we're dealing with
   // basically an "array of strings", as would appear in XML as something
   // like <node>foo bar baz</node>. Here, we're sending the array index,
   // for example 1 for bar (always 0-indexed, even for Fortran, because
   // we're interfacing down to C and then C++). The "valueAtIndexSize"
   // parameter is, here, what its name suggests: the size of the to-be-set
   // string value, for example 6 if we're replacing "bar" with "abcdef".
   // It should not be confused with the size of the <node> array. If it
   // were that, then we'd call it arraySize, not valueAtIndexSize.
   sub = Class + Types + "Set";
   src();
   src("!! Set value");
   src("!! By index \\in [0,size)");
   type == "std::string"
      ? src("subroutine @(handle, arrayIndex, valueAtIndex, "
            "valueAtIndexSize) &", sub)
      : src("subroutine @(handle, arrayIndex, valueAtIndex) "
            "&", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src(1,"integer(c_size_t), intent(in), value :: arrayIndex");
   if (type == "std::string") {
      src(1,"integer(c_size_t), intent(in), value :: valueAtIndexSize");
      src(1,"character(c_char), intent(in) :: valueAtIndex(valueAtIndexSize)");
   } else
      src(1,"@, intent(in), value :: valueAtIndex", ftype(type));
   src("end subroutine @", sub);

   // fixme
   // For now, we only have the following for non-std::string types.
   // Supporting std::string here means we really need the equivalent
   // of char** (pointer to pointer to char) in the C interface, and
   // something compatible with that in this (the Fortran) interface.
   if (type != "std::string") {
      // get pointer to existing values, const
      sub = Class + Types + "GetArrayConst";
      src();
      src("!! Get pointer to existing values, const");
      src("function @(handle) &", sub);
      src(2,"bind(C, name='@')", sub);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), intent(in), value :: handle");
      src(1,"type(c_ptr) :: @", sub);
      src("end function @", sub);

      // get pointer to existing values, non-const
      sub = Class + Types + "GetArray";
      src();
      src("!! Get pointer to existing values, non-const");
      src("function @(handle) &", sub);
      src(2,"bind(C, name='@')", sub);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), value :: handle");
      src(1,"type(c_ptr) :: @", sub);
      src("end function @", sub);

      // set completely new values and size
      sub = Class + Types + "SetArray";
      src();
      src("!! Set completely new values and size");
      src("subroutine @(handle, values, valuesSize) &", sub);
      src(2,"bind(C, name='@')", sub);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), value :: handle");
      src(1,"integer(c_size_t), intent(in), value :: valuesSize");
      src(1,"@, intent(in) :: values(valuesSize)", ftype(type));
      src("end subroutine @", sub);
   }
}


// -----------------------------------------------------------------------------
// fileF03InterfaceMeta
// -----------------------------------------------------------------------------

void fileF03InterfaceMeta(
   writer &src,
   const PerClass &per, const InfoMetadata &m
) {
   const std::string Class = per.clname;
   const std::string Meta = UpperCamel(m.name);
   const std::string varname = fname(m.name);
   std::string sub;

   // section comment
   sectionFortran(src,"!! Metadatum: @", m.name);

   // has
   sub = Class + Meta + "Has";
   src();
   src("!! Has");
   src("function @(handle) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_int) :: @", sub);
   src("end function @", sub);

   // get
   sub = Class + Meta + "Get";
   src();
   src("!! Get");
   src("function @(handle) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"@ :: @", ftype(m.type), sub);
   src("end function @", sub);

   // set
   sub = Class + Meta + "Set";
   src();
   src("!! Set");
   m.type == "std::string"
      ? src("subroutine @(handle, @, @Size) &", sub, varname, varname)
      : src("subroutine @(handle, @) &", sub, varname);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   if (m.type == "std::string") {
      src(1,"integer(c_size_t), intent(in), value :: @Size", varname);
      src(1,"character(c_char), intent(in) :: @(@Size)", varname, varname);
   } else
      src(1,"@, intent(in), value :: @", ftype(m.type), varname);
   src("end subroutine @", sub);
}


// -----------------------------------------------------------------------------
// fileF03InterfaceChild
// -----------------------------------------------------------------------------

void fileF03InterfaceChild(
   writer &src,
   const PerClass &per, const InfoChildren &c, const InfoSpecs &specs
) {
   const std::string Class = per.clname;
   const std::string Child = c.plain;
   const std::string child = c.name;
   std::string sub;

   // section comment
   sectionFortran(src,"!! Child: @", child);

   // has
   // Applies to both the scalar and the vector cases,
   // which are otherwise distinguished below
   sub = Class + Child + "Has";
   src();
   src("!! Has");
   src("function @(handle) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_int) :: @", sub);
   src("end function @", sub);

   // ------------------------
   // scalar case
   // ------------------------

   if (!c.isVector) {
      // get, const
      sub = Class + Child + "GetConst";
      src();
      src("!! Get, const");
      src("function @(handle) &", sub);
      src(2,"bind(C, name='@')", sub);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), intent(in), value :: handle");
      src(1,"type(c_ptr) :: @", sub);
      src("end function @", sub);

      // get, non-const
      sub = Class + Child + "Get";
      src();
      src("!! Get, non-const");
      src("function @(handle) &", sub);
      src(2,"bind(C, name='@')", sub);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), value :: handle");
      src(1,"type(c_ptr) :: @", sub);
      src("end function @", sub);

      // set
      sub = Class + Child + "Set";
      src();
      src("!! Set");
      src("subroutine @(handle, fieldHandle) &", sub);
      src(2,"bind(C, name='@')", sub);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), value :: handle");
      src(1,"type(c_ptr), intent(in), value :: fieldHandle");
      src("end subroutine @", sub);

      // done with this child
      return;
   }

   // ------------------------
   // vector case
   // ------------------------

   // clear
   sub = Class + Child + "Clear";
   src();
   src("!! Clear");
   src("subroutine @(handle) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src("end subroutine @", sub);

   // size
   sub = Class + Child + "Size";
   src();
   src("!! Size");
   src("function @(handle) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_size_t) :: @", sub);
   src("end function @", sub);

   // add
   sub = Class + Child + "Add";
   src();
   src("!! Add");
   src("subroutine @(handle, fieldHandle) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src(1,"type(c_ptr), intent(in), value :: fieldHandle");
   src("end subroutine @", sub);

   // get, by index, const
   sub = Class + Child + "GetConst";
   src();
   src("!! Get, by index \\in [0,size), const");
   src("function @(handle, index) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_size_t), intent(in), value :: index");
   src(1,"type(c_ptr) :: @", sub);
   src("end function @", sub);

   // get, by index, non-const
   sub = Class + Child + "Get";
   src();
   src("!! Get, by index \\in [0,size), non-const");
   src("function @(handle, index) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src(1,"integer(c_size_t), intent(in), value :: index");
   src(1,"type(c_ptr) :: @", sub);
   src("end function @", sub);

   // set, by index
   sub = Class + Child + "Set";
   src();
   src("!! Set, by index \\in [0,size)");
   src("subroutine @(handle, index, fieldHandle) &", sub);
   src(2,"bind(C, name='@')", sub);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src(1,"integer(c_size_t), intent(in), value :: index");
   src(1,"type(c_ptr), intent(in), value :: fieldHandle");
   src("end subroutine @", sub);

   // ------------------------
   // for this child's
   // metadata
   // ------------------------

   // first make sure that we know about this class
   const auto it = specs.class2data.find(NamespaceAndClass(c.ns,c.plain));
   if (it == specs.class2data.end()) {
      log::warning(
         "Unable to generate Fortran interface has/get/set functions for:\n"
         "   class: {}::{}\n"
         "   child: {}::{}\n"
         "Child class is unknown, so its metadata for has/get/set are unknown.",
         per.nsname, Class,
         c.ns, Child
      );
      return;
   }

   // has, get const, get non-const, set
   for (const auto &m : it->second.metadata) {
      const std::string Meta = UpperCamel(m.name);
      const std::string meta = m.name;

      // subsection header
      src();
      src(smallFortran);
      src("!! Re: metadatum @", meta);
      src(smallFortran);

      // has, by metadatum
      sub = Class + Child + "HasBy" + Meta;
      src();
      src("!! Has, by @", meta);
      m.type == "std::string"
         ? src("function @(handle, meta, metaSize) &", sub)
         : src("function @(handle, meta) &", sub);
      src(2,"bind(C, name='@')", sub);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), intent(in), value :: handle");
      if (m.type == "std::string") {
         src(1,"integer(c_size_t), intent(in), value :: metaSize");
         src(1,"character(c_char), intent(in) :: meta(metaSize)");
      } else
         src(1,"@, intent(in), value :: meta", ftype(m.type));
      src(1,"integer(c_int) :: @", sub);
      src("end function @", sub);

      // get, by metadatum, const
      sub = Class + Child + "GetBy" + Meta + "Const";
      src();
      src("!! Get, by @, const", meta);
      m.type == "std::string"
         ? src("function @(handle, meta, metaSize) &", sub)
         : src("function @(handle, meta) &", sub);
      src(2,"bind(C, name='@')", sub);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), intent(in), value :: handle");
      if (m.type == "std::string") {
         src(1,"integer(c_size_t), intent(in), value :: metaSize");
         src(1,"character(c_char), intent(in) :: meta(metaSize)");
      } else
         src(1,"@, intent(in), value :: meta", ftype(m.type));
      src(1,"type(c_ptr) :: @", sub);
      src("end function @", sub);

      // get, by metadatum, non-const
      sub = Class + Child + "GetBy" + Meta;
      src();
      src("!! Get, by @, non-const", meta);
      m.type == "std::string"
       ? src("function @(handle, meta, metaSize) &", sub)
       : src("function @(handle, meta) &", sub);
      src(2,"bind(C, name='@')", sub);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), value :: handle");
      if (m.type == "std::string") {
         src(1,"integer(c_size_t), intent(in), value :: metaSize");
         src(1,"character(c_char), intent(in) :: meta(metaSize)");
      } else
         src(1,"@, intent(in), value :: meta", ftype(m.type));
      src(1,"type(c_ptr) :: @", sub);
      src("end function @", sub);

      // set, by metadatum
      sub = Class + Child + "SetBy" + Meta;
      src();
      src("!! Set, by @", meta);
      m.type == "std::string"
         ? src("subroutine @(handle, meta, metaSize, fieldHandle) &", sub)
         : src("subroutine @(handle, meta, fieldHandle) &", sub);
      src(2,"bind(C, name='@')", sub);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), value :: handle");
      if (m.type == "std::string") {
         src(1,"integer(c_size_t), intent(in), value :: metaSize");
         src(1,"character(c_char), intent(in) :: meta(metaSize)");
      } else
         src(1,"@, intent(in), value :: meta", ftype(m.type));
      src(1,"type(c_ptr), intent(in), value :: fieldHandle");
      src("end subroutine @", sub);
   } // metadata
}


// -----------------------------------------------------------------------------
// fileF03Interface
// -----------------------------------------------------------------------------

void fileF03Interface(
   const InfoSpecs &specs, const PerClass &per, const Class2Dependencies &c2d
) {
   writer src(per.sourceF03, true, "!!");
   const std::string mod = per.nsname + per.clname;

   // Module begin
   src();
   src("module @", mod);
   src("use iso_c_binding");
   src("interface");

   // Basics: create, assign, delete
   fileF03InterfaceBasics(src, per);

   // IO: read, write, print
   fileF03InterfaceIO(src, per);

   // Array support, if BlockData
   if (per.isDataVector)
      fileF03InterfaceVector(src, per, per.elementType);

   // Functions regarding metadata
   for (const auto &m : per.metadata)
      fileF03InterfaceMeta(src, per, m);

   // Functions regarding children
   for (const auto &c : per.children)
      fileF03InterfaceChild(src, per, c, specs);

   // Functions regarding variants
   // todo

   // Module end
   src();
   src();
   src(largeFortran);
   src(largeFortran);
   src();
   src("end interface");
   src("end module @", mod);
}
