
// -----------------------------------------------------------------------------
// filePythonAll
// -----------------------------------------------------------------------------

void filePythonAll(const InfoSpecs &specs)
{
   writer out(specs.allPython);

   // ------------------------
   // core
   // ------------------------

   // comment
   out();
   out(largeComment);
   out("// core");
   out(largeComment);

   // includes
   out();
   out("// core");
   out("#include \"GNDStk.python.cpp\"");
   out();
   out("// node");
   out("#include \"core/Node.python.cpp\"");
   out();

   // ------------------------
   // version
   // ------------------------

   // comment
   out();
   out(largeComment);
   out("// @", specs.Version);
   out(largeComment);

   // version
   out();
   out("// @", specs.Version);
   out("#include \"@.python.cpp\"", specs.Version);

   // enumerations
   if (specs.Enumerators.size()) {
      out();
      out("// enumerations");
      for (const auto &e : specs.Enumerators)
         out("#include \"enums/@.python.cpp\"", e.first);
   }

   // each namespace and its classes
   for (const std::pair<std::string,PerNamespace> &ns : specs.namespace2data) {
      out();
      out("// namespace @", ns.second.nsname);
      out("#include \"@/@.python.cpp\"", specs.Version, ns.second.nsname);
      for (const auto &c : specs.class2data) {
         const std::string nsname = c.first.nsname;
         const std::string clname = c.first.clname;
         if (nsname == ns.second.nsname)
            out("#include \"@/@/@.python.cpp\"", specs.Version, nsname, clname);
      }
   }
} // filePythonAll


// -----------------------------------------------------------------------------
// filePythonVersion
// -----------------------------------------------------------------------------

void filePythonVersion(const InfoSpecs &specs)
{
   writer out(specs.cppPython);
   out();
   out("#include <pybind11/pybind11.h>");
   out("#include <pybind11/stl.h>");
   out();
   out("// project @", specs.Project);
   out("namespace python_@ {", specs.Project);

   if (specs.Enumerators.size()) {
      out();
      out(1,"// version @: enum wrapper declarations", specs.Version);
      out(1,"namespace python_@ {", specs.VersionUnderscore);
      out(1,"namespace python_enums {");
      for (const auto &e : specs.Enumerators)
         out(2,"void wrap@(pybind11::module &);", e.first);
      out(1,"} // namespace python_enums");
      out(1,"} // namespace python_@", specs.VersionUnderscore);
   }

   out();
   out(1,"// version @: namespace wrapper declarations", specs.Version);
   out(1,"namespace python_@ {", specs.VersionUnderscore);
   for (const std::pair<std::string,PerNamespace> &ns : specs.namespace2data)
      out(2,"void wrap@(pybind11::module &);", capital(ns.second.nsname));
   out(1,"} // namespace python_@", specs.VersionUnderscore);

   out();
   out(1,"// version @: wrapper", specs.Version);
   out(1,"void wrap@(pybind11::module &module)", capital(specs.VersionUnderscore));
   out(1,"{");
   out(2,"// @", specs.Version);
   out(2,"pybind11::module submodule = module.def_submodule(");
   out(3,"\"@\",", specs.VersionUnderscore);
   if (specs.Project == "GNDStk")
      out(3,"\"GNDS @\"", specs.Version); // "GNDS", not "GNDStk"
   else
      out(3,"\"@ @\"", specs.Project, specs.Version);
   out(2,");");

   if (specs.Enumerators.size()) {
      out();
      out(2,"// @ enumerations", specs.Version);
      for (const auto &e : specs.Enumerators)
         out(2,"python_@::python_enums::wrap@(submodule);",
             specs.VersionUnderscore, e.first);
   }

   out();
   out(2,"// @ namespaces", specs.Version);
   for (const std::pair<std::string,PerNamespace> &ns : specs.namespace2data)
      out(2,"python_@::wrap@(submodule);",
          specs.VersionUnderscore, capital(ns.second.nsname));
   out(1,"}");
   out();
   out("} // namespace python_@", specs.Project);
} // filePythonVersion


// -----------------------------------------------------------------------------
// filePythonNamespace
// -----------------------------------------------------------------------------

void filePythonNamespace(const InfoSpecs &specs, const PerNamespace &per)
{
   writer out(per.cppPython);
   out();
   out("#include <pybind11/pybind11.h>");
   out("#include <pybind11/stl.h>");
   out();
   out("// project @", specs.Project);
   out("// version @", specs.Version);
   out("namespace python_@ {", specs.Project);
   out("namespace python_@ {", specs.VersionUnderscore);

   out();
   out(1,"// namespace @: class wrapper declarations", per.nsname);
   out(1,"namespace python_@ {", per.nsname);
   for (const auto &cl : specs.ClassDependenciesSorted)
      if (cl.theClass.nsname == per.nsname)
         out(2,"void wrap@(pybind11::module &);", cl.theClass.clname);
   out(1,"} // namespace python_@", per.nsname);

   out();
   out(1,"// namespace @: wrapper", per.nsname);
   out(1,"void wrap@(pybind11::module &module)", capital(per.nsname));
   out(1,"{");
   out(2,"// @", per.nsname);
   out(2,"pybind11::module submodule = module.def_submodule(");
   out(3,"\"@\",", per.nsname);
   if (specs.Project == "GNDStk")
      out(3,"\"GNDS @ @\"", specs.Version, per.nsname); // "GNDS", not "GNDStk"
   else
      out(3,"\"@ @ @\"", specs.Project, specs.Version, per.nsname);
   out(2,");");

   out();
   out(2,"// @ classes", per.nsname);
   for (const auto &cl : specs.ClassDependenciesSorted)
      if (cl.theClass.nsname == per.nsname)
         out(2,"python_@::wrap@(submodule);", per.nsname, cl.theClass.clname);
   out(1,"}");
   out();
   out("} // namespace python_@", specs.VersionUnderscore);
   out("} // namespace python_@", specs.Project);
} // filePythonNamespace


// -----------------------------------------------------------------------------
// filePythonClass
// -----------------------------------------------------------------------------

void filePythonClass(const InfoSpecs &specs, const PerClass &per)
{
   const std::string &nsname = per.nsname;
   const std::string &clname = per.clname;
   writer out(per.cppPython);

   std::vector<std::pair<std::string,std::string>> dataTypesNames;
   if (per.isDataVector) {
      // try to find per.elementType in nameMap
      auto it = nameMap.find(per.elementType);
      if (it != nameMap.end()) {
         // node has a fixed data type
         dataTypesNames.emplace_back(it->second.first, it->second.second);
      } else {
         // node has a runtime data type: select types to expose
         static std::array<std::string,3> types = { "int", "double", "string" };
         for (const auto &type : types) {
            it = nameMap.find(type);
            dataTypesNames.emplace_back(it->second.first, it->second.second);
         }
      }
   }

   // ------------------------
   // Begin file
   // ------------------------

   out();
   out("// system includes");
   out("#include <pybind11/pybind11.h>");
   out("#include <pybind11/stl.h>");

   out();
   out("// local includes");
   out("#include \"@/@/@/@.hpp\"",
       specs.Project, specs.Version, nsname, clname);
   out("#include \"definitions.hpp\"");

   out();
   out("namespace python_@ {", specs.Project);
   out("namespace python_@ {", specs.VersionUnderscore);
   out("namespace python_@ {", nsname);

   out();
   out("// wrapper for @::@", nsname, clname);
   out("void wrap@(pybind11::module &module)", clname);
   out("{");
   const std::string prefix = specs.Project == "GNDStk" ? "njoy::" : "";
   out(1,"using namespace @@;",
       prefix, specs.Project);
   out(1,"using namespace @@::@;",
       prefix, specs.Project, specs.VersionUnderscore);
   out();
   out(1,"// type aliases");
   out(1,"using cppCLASS = @::@;", nsname, clname);

   // using [variant name] = std::variant..., if necessary
   for (const auto &v : per.variants) {
      out(1,"using @ = std::variant<", v.type);
      int count = 0;
      const int total = v.children.size();
      for (const auto &c : v.children)
         out(2,"@@", c.type, sep(count,total));
      out(1,">;");
   }

   out();
   out(1,"// create the Python object");
   out(1,"pybind11::class_<cppCLASS> object(");
   out(2,"module, \"@\",", clname);
   out(2,"cppCLASS::component_t::documentation().data()");
   out(1,");");

   // ------------------------
   // pybind11::init<...>
   // for construction from
   // metadata and children
   // ------------------------

   int count = 0;
   const int total = per.nfields();

   out();
   out(1,"// constructor: from fields");
   out(1,"object.def(");
   out(2,"pybind11::init<");
   {
      // init<> arguments
      for (const auto &m : per.metadata)
         out(3,"const @ &@",
             m.isDefaulted ? "std::optional<" + m.type + ">" : m.typeFull,
             sep(count,total));
      for (const auto &c : per.children)
         out(3,"const @ &@", c.typeFull, sep(count,total));
      for (const auto &v : per.variants)
         out(3,"const @ &@", v.typeFull, sep(count,total));
   }
   out(2,">(),");

   for (const auto &m : per.metadata)
      out(2,"pybind11::arg(\"@\")@,",
          namePython(m.name),
          m.isOptional || m.isDefaulted ? " = std::nullopt" : "");
   for (const auto &c : per.children)
      out(2,"pybind11::arg(\"@\")@,",
          namePython(c.name),
          c.isOptional ? " = std::nullopt" : "");
   for (const auto &v : per.variants)
      out(2,"pybind11::arg(\"@\"),",
          namePython(v.name));
   out(2,"cppCLASS::component_t::documentation(\"constructor\").data()");
   out(1,");"); // object.def(

   // ------------------------
   // pybind11::init<...>
   // for construction from
   // vector
   // ------------------------

   // vector type[s], as computed above
   for (const auto &dataTypeName : dataTypesNames) {
      out();
      out(1,"// constructor: from vector");
      out(1,"object.def(");
      out(2,"pybind11::init<");
      out(3,"const std::vector<@> &", dataTypeName.first);
      out(2,">(),");
      out(2,"pybind11::arg(\"@\"),", dataTypeName.second);
      out(2,"cppCLASS::component_t::documentation(\"constructor\").data()");
      out(1,");"); // object.def(
   }

   // ------------------------
   // def_property
   // metadata
   // ------------------------

   // todo
   // We need to ensure that what we're doing, below, works for optional,
   // Defaulted, and variant. (At the time of this writing, I'm not using
   // Defaulted or variant anywhere in the GNDS 2.0 specs.)

   for (const auto &m : per.metadata) {
      const auto pyname = namePython(m.name);
      out();
      out(1,"// get/set @", m.name);
      out(1,"object.def_property(");
      // name
      out(2,"\"@\",", pyname);
      // get
      out(2,"[](const cppCLASS &self) -> decltype(auto)");
      out(2,"{");
      m.isDefaulted
         ? out(3,"return self.@().value();", m.name)
         : out(3,"return self.@();", m.name);
      out(2,"},");
      // set
      m.isDefaulted
         ? out(2,"[](cppCLASS &self, const @ &value)", m.type)
         : out(2,"[](cppCLASS &self, const @ &value)", m.typeFull);
      out(2,"{");
      out(3,"self.@() = value;", m.name);
      out(2,"},");
      // documentation
      out(2,"cppCLASS::component_t::documentation(\"@\").data()", pyname);
      out(1,");");
   }

   // ------------------------
   // def_property
   // children
   // ------------------------

   for (const auto &c : per.children) {
      const auto pyname = namePython(c.name);
      out();
      out(1,"// get/set @", c.name);
      out(1,"object.def_property(");
      // name
      out(2,"\"@\",", pyname);
      // get
      out(2,"[](const cppCLASS &self) -> decltype(auto)");
      out(2,"{");
      out(3,"return self.@();", c.name);
      out(2,"},");
      // set
      out(2,"[](cppCLASS &self, const @ &value)", c.typeFull);
      out(2,"{");
      out(3,"self.@() = value;", c.name);
      out(2,"},");
      // documentation
      out(2,"cppCLASS::component_t::documentation(\"@\").data()", pyname);
      out(1,");");
   }

   // ------------------------
   // def_property
   // variants
   // ------------------------

   for (const auto &v : per.variants) {
      if (!v.isVector) {
         for (const auto &c : v.children) {
            const auto pyname = namePython(c.name);
            out();
            out(1,"object.def_property(");
            // name
            out(2,"\"@\",", pyname);
            // get
            out(2,"[](const cppCLASS &self) -> decltype(auto)");
            out(2,"{");
            out(3,"return self.@();", c.name);
            out(2,"},");
            // set
            out(2,"[](cppCLASS &self, const @ &value)", c.type);
            out(2,"{");
            out(3,"self.@() = value;", c.name);
            out(2,"},");
            // documentation
            out(2,"cppCLASS::component_t::documentation(\"@\").data()", pyname);
            out(1,");");
         }
      }
      const auto pyname = namePython(v.name);
      out();
      out(1,"object.def_property(");
      // name
      out(2,"\"@\",", pyname);
      // get
      out(2,"[](const cppCLASS &self) -> decltype(auto)");
      out(2,"{");
      out(3,"return self.@();", v.name);
      out(2,"},");
      // set
      out(2,"[](cppCLASS &self, const @ &value)", v.typeFull);
      out(2,"{");
      out(3,"self.@() = value;", v.name);
      out(2,"},");
      // documentation
      out(2,"cppCLASS::component_t::documentation(\"@\").data()", pyname);
      out(1,");");
   }

   // ------------------------
   // def_property
   // string
   // ------------------------

   if (per.isDataString) {
      out();
      out(1,"// get/set data string");
      out(1,"object.def_property(");
      out(2,"\"string\",");
      out(2,"[](const cppCLASS &self) -> const std::string &");
      out(2,"{");
      out(3,"return self;");
      out(2,"},");
      out(2,"[](cppCLASS &self, const std::string &value)");
      out(2,"{");
      out(3,"self = value;");
      out(2,"},");
      out(2,"cppCLASS::component_t::documentation(\"string\").data()");
      out(1,");");
   }

   // ------------------------
   // def_property
   // vector(s)
   // ------------------------

   for (const auto &dataTypeName : dataTypesNames) {
      out();
      out(1,"// get/set vector<@>", dataTypeName.first);
      out(1,"object.def_property(");
      // name
      out(2,"\"@\",", dataTypeName.second);
      // get
      out(2,"[](const cppCLASS &self) -> const std::vector<@> &",
          dataTypeName.first);
      out(2,"{");
      per.elementType == "" // vector is...
         ? out(3,"return self.@();", dataTypeName.second) // ...of dynamic type
         : out(3,"return self;"); // ...of a fixed type
      out(2,"},");
      // set
      out(2,"[](cppCLASS &self, const std::vector<@> &value)",
          dataTypeName.first);
      out(2,"{");
      per.elementType == "" // vector is...
         ? out(3,"self.@() = value;", dataTypeName.second) // ...of dynamic type
         : out(3,"self = value;"); // ...of a fixed type
      out(2,"},");
      // documentation
      out(2,"cppCLASS::component_t::documentation(\"@\").data()",
          dataTypeName.second);
      out(1,");");
   }

   // ------------------------
   // def_property
   // shortcuts
   // ------------------------

   for (const auto &cut : per.name2path) {
      const std::string &name = cut.first;
      const auto pyname = namePython(name);
      out();
      out(1,"// shortcut: get/set @", name);
      out(1,"object.def_property(");
      // name
      out(2,"\"@\",", pyname);
      // get
      out(2,"[](const cppCLASS &self) -> decltype(auto)");
      out(2,"{");
      out(3,"return self.@();", name);
      out(2,"},");
      // set
      // todo For the benefit of clarity both here and where the shortcut
      // references appear in the generated C++ classes, I suppose we should
      // determine the direct type of the referenced object. Note that it will
      // be some sort of Field<>, and, because Field<> is defined inside of
      // Component<> (intentionally so - see the remarks where class Field
      // is defined), we need to realize that Field<foo> inside a referencing
      // class will have a different meaning than Field<foo> in a referenced
      // context. We should think about ways to make this clearer in the code.
      out(2,"[](cppCLASS &self, const std::decay_t<decltype(self.@())> &value)",
          name);
      out(2,"{");
      out(3,"self.@() = value;", name);
      out(2,"},");
      // documentation
      out(2,"cppCLASS::component_t::documentation(\"@\").data()", pyname);
      out(1,");");
   }

   // ------------------------
   // finish
   // ------------------------

   out();
   out(1,"// add standard definitions");
   out(1,"addStandardComponentDefinitions<cppCLASS>(object);");
   out("}");

   out();
   out("} // namespace python_@", nsname);
   out("} // namespace python_@", specs.VersionUnderscore);
   out("} // namespace python_@", specs.Project);
} // filePythonClass
