
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
// Helpers
// -----------------------------------------------------------------------------

// fileF03InterfaceCreateParams
void fileF03InterfaceCreateParams(
   writer &src, const PerClass &per
) {
   int count = 0;
   const int total = per.nfields();
   std::vector<std::string> sizes;

   // Determine what parameters will have sizes that appear at the end of the
   // parameter list. This is determined in advance for convenience, and also
   // because the presence or absence of additional size parameters will affect
   // whether or not commas are needed after parameters.
   bool hasSizes = false;
   for (const auto &m : per.metadata)
      if (m.type == "std::string")
         hasSizes = true;

   // metadata
   for (const auto &m : per.metadata) {
      const std::string varname = fname(m.name);
      src();
      src(1,"@@", varname, ++count < total || hasSizes ? ", &" : " &", false);
      if (m.type == "std::string")
         sizes.push_back(varname+"Size");
   }

   // children
   for (const auto &c : per.children) {
      const std::string varname = fname(c.name);
      src();
      if (c.isVector)
         src(1,"@, @Size@", varname, varname, ++count < total || hasSizes ? ", &" : " &", false);
      else
         src(1,"@@", varname, ++count < total || hasSizes ? ", &" : " &", false);
   }

   // variants
   // todo

   src();

   // sizes
   count = 0;
   for (const std::string &s : sizes)
      src(1,"@@", s, ++count < sizes.size() ? ", &" : " &");
}

// fileF03InterfaceDeclareParams
void fileF03InterfaceDeclareParams(
   writer &src, const PerClass &per
) {
   // metadata
   for (const auto &m : per.metadata) {
      const std::string varname = fname(m.name);
      if (m.type == "std::string") {
         src(1,"integer(c_size_t), intent(in), value :: @Size", varname);
         src(1,"character(c_char), intent(in) :: @(@Size)", varname, varname);
      } else
         src(1,"@, value, intent(in) :: @", ftype(m.type), varname);
   }

   // children
   for (const auto &c : per.children) {
      const std::string varname = fname(c.name);
      if (c.isVector) {
         src(1,"integer(c_size_t), value :: @Size", varname);
         src(1,"type(c_ptr) :: @(@Size)", varname, varname);
      } else
         src(1,"type(c_ptr), value :: @", varname);
   }

   // variants
   // todo
}


// -----------------------------------------------------------------------------
// fileF03InterfaceBasics
// -----------------------------------------------------------------------------

void fileF03InterfaceBasics(
   writer &src, const PerClass &per
) {
   // section comment
   sectionFortran(
      src,
      "!! Basics\n"
      "!! Create, Assign, Delete"
   );

   // create: default, const
   src();
   src("!! Create, default, const");
   src("function @DefaultConst() &", per.clname);
   src(2,"bind(C, name='@DefaultConst')", per.clname);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr) :: @DefaultConst", per.clname);
   src("end function @DefaultConst", per.clname);

   // create: default
   src();
   src("!! Create, default");
   src("function @Default() &", per.clname);
   src(2,"bind(C, name='@Default')", per.clname);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr) :: @Default", per.clname);
   src("end function @Default", per.clname);

   // create: general, const
   src();
   src("!! Create, general, const");
   src("function @CreateConst( &", per.clname, false);
   fileF03InterfaceCreateParams(src,per);
   src(") &");
   src(2,"bind(C, name='@CreateConst')", per.clname);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   fileF03InterfaceDeclareParams(src,per);
   src(1,"type(c_ptr) :: @CreateConst", per.clname);
   src("end function @CreateConst", per.clname);

   // create: general
   src();
   src("!! Create, general");
   src("function @Create( &", per.clname, false);
   fileF03InterfaceCreateParams(src,per);
   src(") &");
   src(2,"bind(C, name='@Create')", per.clname);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   fileF03InterfaceDeclareParams(src,per);
   src(1,"type(c_ptr) :: @Create", per.clname);
   src("end function @Create", per.clname);

   // assign
   src();
   src("!! Assign");
   src("subroutine @Assign(handleLHS, handleRHS) &", per.clname);
   src(2,"bind(C, name='@Assign')", per.clname);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handleLHS, handleRHS");
   src("end subroutine @Assign", per.clname);

   // delete
   src();
   src("!! Delete");
   src("subroutine @Delete(handle) &", per.clname);
   src(2,"bind(C, name='@Delete')", per.clname);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src("end subroutine @Delete", per.clname);
}


// -----------------------------------------------------------------------------
// fileF03InterfaceIO
// -----------------------------------------------------------------------------

void fileF03InterfaceIO(
   writer &src, const PerClass &per
) {
   // section comment
   sectionFortran(
      src,
      "!! I/O\n"
      "!! Read, Write, Print\n"
      "!! Each returns 0 if failure, 1 if success."
   );

   // read from file
   src();
   src("!! Read from file");
   src("function @Read(handle, filename, filenameSize) &", per.clname);
   src(2,"bind(C, name='@Read')", per.clname);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src(1,"integer(c_size_t), value :: filenameSize");
   src(1,"character(c_char), intent(in) :: filename(filenameSize)");
   src(1,"integer(c_int) :: @Read", per.clname);
   src("end function @Read", per.clname);

   // write to file
   src();
   src("!! Write to file");
   src("function @Write(handle, filename, filenameSize) &", per.clname);
   src(2,"bind(C, name='@Write')", per.clname);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_size_t), value :: filenameSize");
   src(1,"character(c_char), intent(in) :: filename(filenameSize)");
   src(1,"integer(c_int) :: @Write", per.clname);
   src("end function @Write", per.clname);

   // print
   src();
   src("!! Print to standard output, in our prettyprinting format");
   src("function @Print(handle) &", per.clname);
   src(2,"bind(C, name='@Print')", per.clname);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_int) :: @Print", per.clname);
   src("end function @Print", per.clname);

   // print, XML
   src();
   src("!! Print to standard output, as XML");
   src("function @PrintXML(handle) &", per.clname);
   src(2,"bind(C, name='@PrintXML')", per.clname);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_int) :: @PrintXML", per.clname);
   src("end function @PrintXML", per.clname);

   // print, JSON
   src();
   src("!! Print to standard output, as JSON");
   src("function @PrintJSON(handle) &", per.clname);
   src(2,"bind(C, name='@PrintJSON')", per.clname);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_int) :: @PrintJSON", per.clname);
   src("end function @PrintJSON", per.clname);
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

   // clear
   src();
   src("!! Clear");
   src("subroutine @@Clear(handle) &", Class, Types);
   src(2,"bind(C, name='@@Clear')", Class, Types);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src("end subroutine @@Clear", Class, Types);

   // get size
   src();
   src("!! Get size");
   src("function @@Size(handle) &", Class, Types);
   src(2,"bind(C, name='@@Size')", Class, Types);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_size_t) :: @@Size", Class, Types);
   src("end function @@Size", Class, Types);

   // get value
   src();
   src("!! Get value");
   src("!! By index \\in [0,size)");
   src("function @@Get(handle, arrayIndex) &", Class, Types);
   src(2,"bind(C, name='@@Get')", Class, Types);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_size_t), intent(in), value :: arrayIndex");
   type == "std::string"
      ? src(1,"type(c_ptr) :: @@Get", Class, Types)
      : src(1,"@ :: @@Get", ftype(type), Class, Types);
   src("end function @@Get", Class, Types);

   // set value
   src();
   src("!! Set value");
   src("!! By index \\in [0,size)");
   type == "std::string"
      ? src("subroutine @@Set(handle, arrayIndex, valueAtIndex, valueAtIndexSize) &", Class, Types)
      : src("subroutine @@Set(handle, arrayIndex, valueAtIndex) &", Class, Types);
   src(2,"bind(C, name='@@Set')", Class, Types);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src(1,"integer(c_size_t), intent(in), value :: arrayIndex");
   if (type == "std::string") {
      src(1,"integer(c_size_t), intent(in), value :: valueAtIndexSize");
      src(1,"character(c_char), intent(in) :: valueAtIndex(valueAtIndexSize)");
   } else
      src(1,"@, intent(in), value :: valueAtIndex", ftype(type));
   src("end subroutine @@Set", Class, Types);

   // fixme
   // For now, we only have the following for non-std::string types.
   // Supporting std::string here means we really need the equivalent
   // of char** (pointer to pointer to char) in the C interface, and
   // something compatible with that in this (the Fortran) interface.
   if (type != "std::string") {
      // get pointer to existing values, const
      src();
      src("!! Get pointer to existing values, const");
      src("function @@GetArrayConst(handle) &", Class, Types);
      src(2,"bind(C, name='@@GetArrayConst')", Class, Types);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), intent(in), value :: handle");
      src(1,"type(c_ptr) :: @@GetArrayConst", Class, Types);
      src("end function @@GetArrayConst", Class, Types);

      // get pointer to existing values
      src();
      src("!! Get pointer to existing values");
      src("function @@GetArray(handle) &", Class, Types);
      src(2,"bind(C, name='@@GetArray')", Class, Types);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), value :: handle");
      src(1,"type(c_ptr) :: @@GetArray", Class, Types);
      src("end function @@GetArray", Class, Types);

      // set completely new values and size
      src();
      src("!! Set completely new values and size");
      src("subroutine @@SetArray(handle, values, valuesSize) &", Class, Types);
      src(2,"bind(C, name='@@SetArray')", Class, Types);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), value :: handle");
      src(1,"integer(c_size_t), value :: valuesSize");
      src(1,"@, intent(in) :: values(valuesSize)", ftype(type));
      src("end subroutine @@SetArray", Class, Types);
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

   // section comment
   sectionFortran(src,"!! Metadatum: @", m.name);

   // has
   src();
   src("!! Has");
   src("function @@Has(handle) &", Class, Meta);
   src(2,"bind(C, name='@@Has')", Class, Meta);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_int) :: @@Has", Class, Meta);
   src("end function @@Has", Class, Meta);

   // get
   src();
   src("!! Get");
   src("function @@Get(handle) &", Class, Meta);
   src(2,"bind(C, name='@@Get')", Class, Meta);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"@ :: @@Get", ftype(m.type), Class, Meta);
   src("end function @@Get", Class, Meta);

   // set
   src();
   src("!! Set");
   src("subroutine @@Set(handle, @, @Size) &", Class, Meta, varname, varname);
   src(2,"bind(C, name='@@Set')", Class, Meta);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src(1,"integer(c_size_t), intent(in), value :: @Size", varname);
   src(1,"character(c_char), intent(in) :: @(@Size)", varname, varname);
   src("end subroutine @@Set", Class, Meta);
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

   // section comment
   sectionFortran(src,"!! Child: @", child);

   // has
   // Applies to both the scalar and the vector cases,
   // which are otherwise distinguished below
   src();
   src("!! Has");
   src("function @@Has(handle) &", Class, Child);
   src(2,"bind(C, name='@@Has')", Class, Child);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_int) :: @@Has", Class, Child);
   src("end function @@Has", Class, Child);

   // ------------------------
   // scalar case
   // ------------------------

   if (!c.isVector) {
      // get, const
      src();
      src("!! Get, const");
      src("function @@GetConst(handle) &", Class, Child);
      src(2,"bind(C, name='@@GetConst')", Class, Child);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), intent(in), value :: handle");
      src(1,"type(c_ptr) :: @@GetConst", Class, Child);
      src("end function @@GetConst", Class, Child);

      // get
      src();
      src("!! Get");
      src("function @@Get(handle) &", Class, Child);
      src(2,"bind(C, name='@@Get')", Class, Child);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), intent(in), value :: handle");
      src(1,"type(c_ptr) :: @@Get", Class, Child);
      src("end function @@Get", Class, Child);

      // set
      src();
      src("!! Set");
      src("subroutine @@Set(handle, fieldHandle) &", Class, Child);
      src(2,"bind(C, name='@@Set')", Class, Child);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), value :: handle");
      src(1,"type(c_ptr), value :: fieldHandle");
      src("end subroutine @@Set", Class, Child);

      return;
   }

   // ------------------------
   // vector case
   // ------------------------

   // clear
   src();
   src("!! Clear");
   src("subroutine @@Clear(handle) &", Class, Child);
   src(2,"bind(C, name='@@Clear')", Class, Child);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src("end subroutine @@Clear", Class, Child);

   // size
   src();
   src("!! Size");
   src("function @@Size(handle) &", Class, Child);
   src(2,"bind(C, name='@@Size')", Class, Child);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_size_t) :: @@Size", Class, Child);
   src("end function @@Size", Class, Child);

   // add
   src();
   src("!! Add");
   src("subroutine @@Add(handle, fieldHandle) &", Class, Child);
   src(2,"bind(C, name='@@Add')", Class, Child);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src(1,"type(c_ptr), intent(in), value :: fieldHandle");
   src("end subroutine @@Add", Class, Child);

   // get, by index, const
   src();
   src("!! Get, by index \\in [0,size), const");
   src("function @@GetConst(handle, index) &", Class, Child);
   src(2,"bind(C, name='@@GetConst')", Class, Child);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), intent(in), value :: handle");
   src(1,"integer(c_size_t), intent(in), value :: index");
   src(1,"type(c_ptr) :: @@GetConst", Class, Child);
   src("end function @@GetConst", Class, Child);

   // get, by index
   src();
   src("!! Get, by index \\in [0,size)");
   src("function @@Get(handle, index) &", Class, Child);
   src(2,"bind(C, name='@@Get')", Class, Child);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src(1,"integer(c_size_t), intent(in), value :: index");
   src(1,"type(c_ptr) :: @@Get", Class, Child);
   src("end function @@Get", Class, Child);

   // set, by index
   src();
   src("!! Set, by index \\in [0,size)");
   src("subroutine @@Set(handle, index, fieldHandle) &", Class, Child);
   src(2,"bind(C, name='@@Set')", Class, Child);
   src(1,"use iso_c_binding");
   src(1,"implicit none");
   src(1,"type(c_ptr), value :: handle");
   src(1,"integer(c_size_t), intent(in), value :: index");
   src(1,"type(c_ptr), intent(in), value :: fieldHandle");
   src("end subroutine @@Set", Class, Child);

   // for this child's metadata: has, get const, get, set
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

   for (const auto &m : it->second.metadata) {
      const std::string Meta = UpperCamel(m.name);
      const std::string meta = m.name;

      // qqq Probably put this subsection header into the C interface too...
      src();
      src(smallFortran);
      src("!! Re: metadatum @", meta);
      src(smallFortran);

      // has, by metadatum
      src();
      src("!! Has, by @", meta);
      m.type == "std::string"
         ? src("function @@HasBy@(handle, meta, metaSize) &",
               Class, Child, Meta)
         : src("function @@HasBy@(handle, meta) &",
               Class, Child, Meta);
      src(2,"bind(C, name='@@HasBy@')", Class, Child, Meta);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), intent(in), value :: handle");
      if (m.type == "std::string") {
         src(1,"integer(c_size_t), intent(in), value :: metaSize");
         src(1,"character(c_char), intent(in) :: meta(metaSize)");
      } else
         src(1,"@, value, intent(in) :: meta", ftype(m.type));
      src(1,"integer(c_int) :: @@HasBy@", Class, Child, Meta);
      src("end function @@HasBy@", Class, Child, Meta);

      // get, by metadatum, const
      src();
      src("!! Get, by @, const", meta);
      m.type == "std::string"
         ? src("function @@GetBy@Const(handle, meta, metaSize) &",
               Class, Child, Meta)
         : src("function @@GetBy@Const(handle, meta) &",
               Class, Child, Meta);
      src(2,"bind(C, name='@@GetBy@Const')", Class, Child, Meta);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), intent(in), value :: handle");
      if (m.type == "std::string") {
         src(1,"integer(c_size_t), intent(in), value :: metaSize");
         src(1,"character(c_char), intent(in) :: meta(metaSize)");
      } else
         src(1,"@, value, intent(in) :: meta", ftype(m.type));
      src(1,"type(c_ptr) :: @@GetBy@Const", Class, Child, Meta);
      src("end function @@GetBy@Const", Class, Child, Meta);

      // get, by metadatum
      src();
      src("!! Get, by @", meta);
      m.type == "std::string"
       ? src("function @@GetBy@(handle, meta, metaSize) &", Class, Child, Meta)
       : src("function @@GetBy@(handle, meta) &", Class, Child, Meta);
      src(2,"bind(C, name='@@GetBy@')", Class, Child, Meta);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), value :: handle");
      if (m.type == "std::string") {
         src(1,"integer(c_size_t), intent(in), value :: metaSize");
         src(1,"character(c_char), intent(in) :: meta(metaSize)");
      } else
         src(1,"@, value, intent(in) :: meta", ftype(m.type));
      src(1,"type(c_ptr) :: @@GetBy@", Class, Child, Meta);
      src("end function @@GetBy@", Class, Child, Meta);

      // set, by metadatum
      src();
      src("!! Set, by @", meta);
      m.type == "std::string"
         ? src("subroutine @@SetBy@(handle, meta, metaSize, fieldHandle) &",
               Class, Child, Meta)
         : src("subroutine @@SetBy@(handle, meta, fieldHandle) &",
               Class, Child, Meta);
      src(2,"bind(C, name='@@SetBy@')", Class, Child, Meta);
      src(1,"use iso_c_binding");
      src(1,"implicit none");
      src(1,"type(c_ptr), intent(in), value :: handle");
      if (m.type == "std::string") {
         src(1,"integer(c_size_t), intent(in), value :: metaSize");
         src(1,"character(c_char), intent(in) :: meta(metaSize)");
      } else
         src(1,"@, value, intent(in) :: meta", ftype(m.type));
      src(1,"type(c_ptr), intent(in), value :: fieldHandle");
      src("end subroutine @@SetBy@", Class, Child, Meta);
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
