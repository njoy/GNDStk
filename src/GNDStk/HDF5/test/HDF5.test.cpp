
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "GNDStk.hpp"

using namespace njoy::GNDStk;


// -----------------------------------------------------------------------------
// writeReadHDF5
// Helper function
// -----------------------------------------------------------------------------

void writeReadHDF5(
   const Tree &oldTree,
   const bool reduced, const bool typed,
   const std::string &correct,
   const std::string &baseName
) {
   // Set flags
   HDF5::reduced = reduced;
   HDF5::typed = typed;

   // Compute file names
   const std::string newFile = baseName + ".h5";
   const std::string vettedFile = "correct-" + newFile;

   // Write the Tree to an HDF5 file
   oldTree.write(newFile);

   // Read from the HDF5 file into a brand-new Tree
   Tree newTree(newFile);

   // Test #1. Ensure that the newly-read Tree prints (in our debug format)
   // in exactly the same way as the original Tree did. Given that the present
   // function is called with each combination of the "reduced" and "typed"
   // flags, which affect precisely how the HDF5 file is created, this tests
   // that, regardless of which flags we used when writing the HDF5 file, the
   // reading process correctly recovers what we originally had in the internal
   // Tree format. IMPORTANT NOTE: It's actually not hard to create situations
   // where the Tree would look slightly different. Leading or trailing white
   // space in #pcdata Nodes could, in some cases, disappear during the process
   // of write-to-HDF5-then-read-back-in. Also, in the HDF5::typed cases,
   // strings that look like floating-point numbers may be converted to doubles
   // and back again. That could lead to differences, depending on how floating-
   // point numbers are written. We've *tried* to write our test files in such
   // a way that these issues won't appear here; if they do arise, somehow,
   // then we're sure we'll hear about it. :-)
   std::ostringstream oss;
   newTree.sort().top().write(oss,"text");
   CHECK(oss.str() == correct);

   // Test #2. Ensure that file newFile (written above, from the original Tree)
   // is identical to the vetted HDF file vettedFile that we put into the git
   // repository. BUT...we'll actually have this test if'd out in the repo! We
   // believe that that's the safe thing to do, because HDF5 is a binary format.
   // We can't know if the HDF5 files produced on any particular platform will
   // compare favorably with the vetted binary files we've placed into the repo.
   // So, this is more a "know what you're doing" test that can be put back in,
   // say by writing #if 1, by people who know how to deal with this situation.
   // ADDITIONAL REMARK. Even on the same computer, I'm seeing non-comparable
   // results, between runs, for each of the two HDF5::reduced == true cases.
   // The offending files are equal in size (for what limited worth that has),
   // and appear to be the same when I compare the output that the h5dump tool
   // gives for each. (Also: in terms of recovering original Tree information -
   // our Test #1 above - the newly created files check out.) todo: Determine
   // what's going on with the vetted-vs-new-file comparison. Could a timestamp,
   // or some other non-constant construct, be going into the file? And why does
   // this happen only when HDF5::reduced == true? That flag simply means that
   // the HDF5 writer simplifies certain special Tree constructs (relating to
   // #cdata, #comment, and #pcdata). (In a predictable and reversible manner,
   // of course, hence Test #1 working.) UPDATE: h5diff says the files match.
   // Also, google [hdf5 file comparison] to see some relevant discussions.
#if 0
   std::ifstream ifsWant(vettedFile);
   std::stringstream bufWant;
   bufWant << ifsWant.rdbuf();
   std::cout << "bufWant.str().size() == " << bufWant.str().size() << std::endl;

   std::ifstream ifsHave(newFile);
   std::stringstream bufHave;
   bufHave << ifsHave.rdbuf();
   std::cout << "bufHave.str().size() == " << bufHave.str().size() << std::endl;

   CHECK(bufWant.str() == bufHave.str());
#endif
}


// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk HDF5, Part I") {
   WHEN("We create a Tree from an XML with various constructs in it") {
      // Read Tree
      Tree tree("various.xml");

      // Write to a string, in our simple debug format
      std::ostringstream oss;
      tree.sort().top().write(oss,"text");
      const std::string correct = oss.str();

      // Write/read to/from HDF5, for each combination of the available flags
      // for doing so: HDF5::reduced = false/true (x) HDF5::typed = false/true
      writeReadHDF5(tree, false, false, correct, "raw-string");
      writeReadHDF5(tree, false, true,  correct, "raw-typed");
      writeReadHDF5(tree, true,  false, correct, "reduced-string");
      writeReadHDF5(tree, true,  true,  correct, "reduced-typed");
   }
}


// -----------------------------------------------------------------------------
// SCENARIO
// -----------------------------------------------------------------------------

SCENARIO("Testing GNDStk HDF5, Part II") {

   // read an HDF5
   HDF5 h("n-069_Tm_170-covar.hdf5");

   // construct a Tree from the HDF5
   Tree t(h);

   // the Tree should be non-empty
   CHECK(!t.empty());

   // ------------------------
   // clear
   // ------------------------

   WHEN("We clear() an HDF5, and convert() it to a Tree") {
      convert(h.clear(),t);
      THEN("The Tree should have only an empty declaration node") {
         CHECK(t.children.size() == 1);
         CHECK(t.has_decl());
         CHECK(t.decl().name == "#hdf5");
         CHECK(t.decl().metadata.size() == 0);
         CHECK(t.decl().children.size() == 0);
      }
   }

   // ------------------------
   // empty
   // ------------------------

   WHEN("We call empty() on a clear()d HDF5") {
      h.clear();
      CHECK(h.empty());
   }

   // ------------------------
   // constructors
   // ------------------------

   // default
   WHEN("We call HDF5's default constructor") {
      const HDF5 h;
      CHECK(h.empty());
   }

   // move
   WHEN("We call HDF5's move constructor") {
      const HDF5 h(HDF5{"n-069_Tm_170-covar.hdf5"});
      CHECK(!h.empty());
      // and ensure it moved correctly
      std::ostringstream oss1; oss1 << HDF5{"n-069_Tm_170-covar.hdf5"};
      std::ostringstream oss2; oss2 << h;
      CHECK(oss1.str() == oss2.str());
   }

   // copy
   WHEN("We call HDF5's copy constructor") {
      const HDF5 a("n-069_Tm_170-covar.hdf5");
      const HDF5 h(a);
      CHECK(!h.empty());
      // and ensure it copied correctly
      std::ostringstream oss1; oss1 << a;
      std::ostringstream oss2; oss2 << h;
      CHECK(oss1.str() == oss2.str());
   }

   // Note: below, HDF5::typed sometimes had to be set to false (as opposed
   // to its default, true) in order for the relevant test to pass. The issue
   // with HDF5::typed == true wasn't really a failure, in principle; rather,
   // it related to how floating-point numbers look, relative to an original
   // text form, after being converted to binary, read back, and then written
   // again as text. An example we actually saw here: begin with "1.35e-4",
   // see "0.000135" later. Using HDF5::typed == false means values will be
   // kept in string form, so that we don't see this problem.

   // For the next three tests...
   HDF5::reduced = true; HDF5::typed = false;

   // from XML
   WHEN("We construct an HDF5 from an XML") {
      const XML x("n-069_Tm_170-covar.xml");
      const HDF5 h(x);
      THEN("They should produce equivalent Trees") {
         CHECK(!h.empty());
         CHECK(Tree(x) == Tree(h));
      }
   }

   // from Tree
   HDF5::reduced = true; HDF5::typed = false;
   WHEN("We construct an HDF5 from a Tree") {
      const Tree t("n-069_Tm_170-covar.xml");
      const HDF5 h(t);
      THEN("It should produce an equivalent Tree") {
         CHECK(!h.empty());
         CHECK(t == Tree(h));
      }
   }

   // from file
   HDF5::reduced = true; HDF5::typed = true;
   WHEN("We construct an HDF5 from a file") {
      const HDF5 h("n-069_Tm_170-covar.hdf5");
      THEN("It should produce an equivalent to the Tree made from the file") {
         CHECK(!h.empty());
         std::ostringstream oss1; oss1 << Tree("n-069_Tm_170-covar.hdf5");
         std::ostringstream oss2; oss2 << Tree(h);
         CHECK(oss1.str() == oss2.str());
      }
   }

   // For here on out, it seems that we can return to the default...
   HDF5::reduced = true; HDF5::typed = true;

   // from istream
   WHEN("We construct an HDF5 from an istream") {
      std::ifstream ifs("n-069_Tm_170-covar.hdf5");
      const HDF5 h(ifs);
      THEN("It should produce an equivalent to the Tree made from the file") {
         CHECK(!h.empty());
         std::ostringstream oss1; oss1 << Tree("n-069_Tm_170-covar.hdf5");
         std::ostringstream oss2; oss2 << Tree(h);
         CHECK(oss1.str() == oss2.str());
      }
   }

   // ------------------------
   // assignment
   // ------------------------

   // move
   WHEN("We call HDF5's move assignment") {
      HDF5 h;
      h = HDF5{"n-069_Tm_170-covar.hdf5"};
      CHECK(!h.empty());
      // and ensure it moved correctly
      std::ostringstream oss1; oss1 << HDF5{"n-069_Tm_170-covar.hdf5"};
      std::ostringstream oss2; oss2 << h;
      CHECK(oss1.str() == oss2.str());
   }

   // copy
   WHEN("We call HDF5's copy assignment") {
      const HDF5 a("n-069_Tm_170-covar.hdf5");
      HDF5 h;
      h = a;
      CHECK(!h.empty());
      // and ensure it copied correctly
      std::ostringstream oss1; oss1 << a;
      std::ostringstream oss2; oss2 << h;
      CHECK(oss1.str() == oss2.str());
   }

   // ------------------------
   // read
   // ------------------------

   // from istream
   WHEN("We read an HDF5 from an istream") {
      std::ifstream ifs("n-069_Tm_170-covar.hdf5");
      const HDF5 h(ifs);
      THEN("It should produce an equivalent to the Tree made from the file") {
         CHECK(!h.empty());
         std::ostringstream oss1; oss1 << Tree("n-069_Tm_170-covar.hdf5");
         std::ostringstream oss2; oss2 << Tree(h);
         CHECK(oss1.str() == oss2.str());
      }
   }

   // from file
   WHEN("We read an HDF5 from a file") {
      const HDF5 h("n-069_Tm_170-covar.hdf5");
      THEN("It should produce an equivalent to the Tree made from the file") {
         CHECK(!h.empty());
         std::ostringstream oss1; oss1 << Tree("n-069_Tm_170-covar.hdf5");
         std::ostringstream oss2; oss2 << Tree(h);
         CHECK(oss1.str() == oss2.str());
      }
   }

   // ------------------------
   // string_real_hdf5, for
   // use in upcoming tests
   // ------------------------

   // Read our test .hdf5 file into a string, which we'll call string_real_hdf5.
   // For the JSON tests analogous to our HDF5 tests below, we used a *literal*
   // string called string_real_json. That isn't so viable here, because HDF5
   // is binary. We *could* use some command-line tool to convert a binary file
   // into a form that's usable directly in C++ code. But then there's the issue
   // of compute platforms, across which binaries aren't generally compatible
   // anyway. The behavior of what we're testing, below, should be such that the
   // original file's contents, placed here into string_real_hdf5, compare as in
   // the CHECK calls below.
   std::ifstream ifs("n-069_Tm_170-covar.hdf5");   // original file
   std::stringstream buf; buf << ifs.rdbuf();      // read into a stringstream
   const std::string string_real_hdf5 = buf.str(); // make into a string

   // ------------------------
   // write
   // ------------------------

   // to ostream
   WHEN("We write an HDF5 to an ostream") {
      const HDF5 h("n-069_Tm_170-covar.hdf5");
      std::ostringstream oss;
      h.write(oss);
      THEN("We can check that the result is what we expect") {
         // Now, compare the HDF5 that was written to the ostream (h.write(oss),
         // above - the thing we're testing) with the original file's contents.
         CHECK(oss.str() == string_real_hdf5);
      }
   }

   // ------------------------
   // stream I/O
   // ------------------------

   // operator>>
   WHEN("We do istream >> HDF5") {
      std::ifstream ifs("n-069_Tm_170-covar.hdf5");
      HDF5 h;
      ifs >> h;
      THEN("It should give what we expect") {
         // Well, we also end up testing << here, which we test
         // more directly in the next block, below
         std::ostringstream oss;
         oss << h;
         CHECK(oss.str() == string_real_hdf5);
      }
   }

   // operator<<
   WHEN("We do ostream << HDF5") {
      const HDF5 h("n-069_Tm_170-covar.hdf5");
      std::ostringstream oss;
      oss << h;
      THEN("It should give what we expect") {
         CHECK(oss.str() == string_real_hdf5);
      }
   }
}
