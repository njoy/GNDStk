
// -----------------------------------------------------------------------------
// Tool for autogenerating GNDStk classes from JSON specifications
// -----------------------------------------------------------------------------

#include "GNDStk.hpp"
#include <cstring>

using namespace njoy::GNDStk;

// Report cases of nodes that have no metadata, and zero or one child node(s).
// Where these exist, a simplification of the spec may be worth considering.
const bool singletons = true;

// Extra debug/informational printing?
const bool debugging = false;

// Put print statements in constructor and assignment calls. For debugging.
const bool printCtorCalls = false;

// Shortcut levels to utilize
// 0 = all
// 1 = none (child nodes are already there, by definition)
// 2 = to grandchildren
// 3 = to great-grandchildren
// ...
const int ShortcutLevels = 3;


// -----------------------------------------------------------------------------
// Local #includes
// -----------------------------------------------------------------------------

// nameMap
// A map<string,pair<string,string>> for certain name-change purposes
#include "json2class-map.cpp"

// Data structures
#include "json2class-struct.cpp"

// writer class
#include "json2class-writer.cpp"

// Miscellaneous functions
#include "json2class-fun.cpp"

// Interfaces
#include "json2class-cpp.cpp"
#include "json2class-c.cpp"
#include "json2class-f03.cpp"
#include "json2class-python.cpp"


// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main(const int argc, const char *const *const argv)
{
   // For GNDStk's diagnostics
   colors = true;

   // ------------------------
   // Read primary .json
   // ------------------------

   // READ INFORMATION from the JSON file on the command line
   action(
      "GNDStk Code Generator",
      "Author: Martin Staley",
      "Los Alamos National Laboratory"
   );
   InfoSpecs specs;
   commandLine(argc, argv, specs);

   // ------------------------
   // Simplifications?
   // ------------------------

   // REPORT regarding potential simplifications
   if (singletons) {
      action("Finding Potential Simplifications");
      for (const std::string &file : specs.JSONFiles)
         printSingletons(file);
   }

   // ------------------------
   // Preprocessing
   // ------------------------

   // PREPROCESS, to get information needed upfront for detailed processing
   action("Preprocessing");
   preprocessFiles(specs);
   getFilesAndClasses(specs);

   // COMPUTE AN ORDERING that respects dependencies
   sortDependencies(specs);

   // ------------------------
   // Shortcuts
   // ------------------------

   // COMPUTE SHORTCUTS
   // The boolean tells us whether or not the code should print information
   // about potential shortcuts that end up being unused for whatever reason.
   // I suppose that this boolean should eventually be a command-line argument.
   const int levelsDown = argc >= 3 ? atoi(argv[2]) : ShortcutLevels;
   if (levelsDown != 1)
      action("Computing Shortcuts");
   shortcuts(specs, levelsDown, false);

   // ------------------------
   // C++
   // ------------------------

   // PRINT CLASS CODE into temporary strings, which are written to the
   // class-specific files later, after class dependencies are computed
   action("Writing Code: C++");
   for (auto &c : specs.class2data) {
      const std::string &nsname = c.first.nsname;
      const std::string &clname = c.first.clname;
      std::string title =
         color::custom::faded::purple + nsname + "::" +
         color::custom::purple + clname + color::reset + '\n';
      PerClass &per = c.second;
      // after the following, per.code will contain printed
      // C++ code for the class itself
      writeClass(specs, title, per, per.code);
   }

   // Create GNDStk hpp file for this GNDS version
   fileGNDStkVersion(specs);

   // Create GNDStk hpp file for Meta and Child keys
   fileGNDStkKey(specs);

   // For each namespace::class:
   // ...create GNDStk hpp file
   for (const auto &obj : specs.ClassDependenciesSorted)
      fileGNDStkClass(
         specs, specs.class2data.find(obj.theClass)->second, obj);

   // ------------------------
   // C Interface
   // ------------------------

   // For each namespace::class:
   // ...create header file for the C interface
   // ...create source file for the C interface
   action("Writing Code: C Interface");
   for (const auto &obj : specs.ClassDependenciesSorted)
      fileCInterface(
         specs, specs.class2data.find(obj.theClass)->second, obj);

   // ------------------------
   // Fortran Interface
   // ------------------------

   // For each namespace::class:
   // ...create source file for the Fortran interface
   action("Writing Code: Fortran Interface");
   for (const auto &obj : specs.ClassDependenciesSorted)
      fileF03Interface(
         specs, specs.class2data.find(obj.theClass)->second, obj);

   // ------------------------
   // Python Interface
   // ------------------------

   // For each namespace:
   // ...create Python cpp file
   // For each namespace::class:
   // ...create Python cpp file
   action("Writing Code: Python Interface");
   filePythonAll(specs);
   filePythonVersion(specs);
   for (const auto &obj : specs.namespace2data)
      filePythonNamespace(specs, obj.second);
   for (const auto &obj : specs.class2data)
      filePythonClass(specs, obj.second);
   std::cout << std::endl;
}
