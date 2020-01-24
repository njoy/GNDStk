
#include "gnds.hpp"

// -----------------------------------------------------------------------------
// write
// Tests: debug, note, warning, error, internal, fatal, report.
// -----------------------------------------------------------------------------

void write(const bool brief, const bool space, const bool colon)
{
   gnds::output.brief = brief;
   gnds::output.space = space;
   gnds::output.colon = colon;

   std::cout << "// ------------------------" << std::endl;
   std::cout << "// write()" << std::endl;
   std::cout << "// ------------------------" << std::endl;

   // ------------------------
   // debug
   // ------------------------

   gnds::debug = false; assert(gnds::debug == false);
   gnds::debug = true;  assert(gnds::debug == true);
   {
      gnds::debug("foo");
      std::ostringstream oss;
      oss << "bar";
      gnds::debug(oss);
      const double x = 1.234;
      gnds::debug("x",x);
   }

   // ------------------------
   // note
   // ------------------------

   gnds::note = false; assert(gnds::note == false);
   gnds::note = true;  assert(gnds::note == true);
   {
      gnds::note("Line #1 of a note\nLine #2 of a note");
      std::ostringstream oss;
      oss << "This is another note";
      gnds::note(oss);
   }

   // ------------------------
   // warning
   // ------------------------

   gnds::warning = false; assert(gnds::warning == false);
   gnds::warning = true;  assert(gnds::warning == true);
   {
      gnds::warning("Line #1 of a warning\nLine #2 of a warning");
      std::ostringstream oss;
      oss << "This is another warning";
      gnds::warning(oss);
   }

   // ------------------------
   // error
   // ------------------------

   gnds::error = false; assert(gnds::error == false);
   gnds::error = true;  assert(gnds::error == true);
   {
      gnds::error("Line #1 of an error\nLine #2 of an error");
      std::ostringstream oss;
      oss << "This is another error";
      gnds::error(oss);
   }

   // ------------------------
   // internal
   // ------------------------

   gnds::internal = false; assert(gnds::internal == false);
   gnds::internal = true;  assert(gnds::internal == true);
   {
      gnds::internal(
         "Line #1 of an internal error\n"
         "Line #2 of an internal error");
      std::ostringstream oss;
      oss << "This is another internal error";
      gnds::internal(oss);
   }

   // ------------------------
   // fatal
   // ------------------------

   {
      gnds::fatal(
         "Line #1 of a fatal error\n"
         "Line #2 of a fatal error");
      std::ostringstream oss;
      oss << "This is another fatal error";
      gnds::fatal(oss);
   }

   // ------------------------
   // report
   // ------------------------

   gnds::report = false; assert(gnds::report == false);
   gnds::report = true;  assert(gnds::report == true);
   {
      gnds::report(
         "Foo",
         "Line #1 of a report\n"
         "Line #2 of a report"
      );
   }
}



// -----------------------------------------------------------------------------
// main
// -----------------------------------------------------------------------------

int main()
{
   // ------------------------
   // misc
   // ------------------------

   gnds::output.space = true;
   gnds::output.colon = false;
   // gnds::output.rst();

   gnds::note("foo");
   gnds::warning("bar");
   gnds::error("baz");

   gnds::report("Label #1", "Description #1");
   gnds::report("Label #2", ""              );
   gnds::report("",         "Description #3");
   gnds::report("",         ""              );

   std::cout << std::endl;

   // ------------------------
   // bold
   // ------------------------

   std::cout << gnds::ansi.bold.black   << "bold.black"   << std::endl;
   std::cout << gnds::ansi.bold.red     << "bold.red"     << std::endl;
   std::cout << gnds::ansi.bold.green   << "bold.green"   << std::endl;
   std::cout << gnds::ansi.bold.blue    << "bold.blue"    << std::endl;
   std::cout << gnds::ansi.bold.cyan    << "bold.cyan"    << std::endl;
   std::cout << gnds::ansi.bold.magenta << "bold.magenta" << std::endl;
   std::cout << gnds::ansi.bold.yellow  << "bold.yellow"  << std::endl;
   std::cout << gnds::ansi.bold.white   << "bold.white"   << std::endl;
   std::cout << gnds::ansi.reset << std::endl;

   // ------------------------
   // lite
   // ------------------------

   std::cout << gnds::ansi.lite.black   << "lite.black"   << std::endl;
   std::cout << gnds::ansi.lite.red     << "lite.red"     << std::endl;
   std::cout << gnds::ansi.lite.green   << "lite.green"   << std::endl;
   std::cout << gnds::ansi.lite.blue    << "lite.blue"    << std::endl;
   std::cout << gnds::ansi.lite.cyan    << "lite.cyan"    << std::endl;
   std::cout << gnds::ansi.lite.magenta << "lite.magenta" << std::endl;
   std::cout << gnds::ansi.lite.yellow  << "lite.yellow"  << std::endl;
   std::cout << gnds::ansi.lite.white   << "lite.white"   << std::endl;
   std::cout << gnds::ansi.reset << std::endl;

   // ------------------------
   // color
   // ------------------------

   gnds::color = false; assert(gnds::color == false);
   gnds::color = true;  assert(gnds::color == true);

   std::cout << gnds::color.debug         << "color.debug"         << std::endl;
   std::cout << gnds::color.note          << "color.note"          << std::endl;
   std::cout << gnds::color.warning       << "color.warning"       << std::endl;
   std::cout << gnds::color.error         << "color.error"         << std::endl;
   std::cout << gnds::color.internal      << "color.internal"      << std::endl;
   std::cout << gnds::color.fatal         << "color.fatal"         << std::endl;
   std::cout << gnds::color.report.first  << "color.report.first"  << std::endl;
   std::cout << gnds::color.report.second << "color.report.second" << std::endl;
   std::cout << gnds::color.reset << std::endl;

   // ------------------------
   // output
   // ------------------------

   gnds::output.ansi();
   gnds::output.html();
   gnds::output.html("   ");
   gnds::output.rst();
   gnds::output.tex();
   gnds::output.listing();
   gnds::output.ansi();
   gnds::output.begin();

   // ------------------------
   // brief, space, colon
   // ------------------------

   gnds::output.brief = false; assert(gnds::output.brief == false);
   gnds::output.brief = true;  assert(gnds::output.brief == true);

   gnds::output.space = false; assert(gnds::output.space == false);
   gnds::output.space = true;  assert(gnds::output.space == true);

   gnds::output.colon = false; assert(gnds::output.colon == false);
   gnds::output.colon = true;  assert(gnds::output.colon == true);

   // ------------------------
   // several kinds
   // of diagnostics
   // ------------------------

   write(true ,true ,true );
   write(true ,true ,false);
   write(true ,false,true );
   write(true ,false,false);
   write(false,true ,true );
   write(false,true ,false);
   write(false,false,true );
   write(false,false,false);

   /*
   using namespace gnds;
   output.brief = true ; output.space = true ; output.colon = true ; write();
   output.brief = true ; output.space = true ; output.colon = false; write();
   output.brief = true ; output.space = false; output.colon = true ; write();
   output.brief = true ; output.space = false; output.colon = false; write();
   output.brief = false; output.space = true ; output.colon = true ; write();
   output.brief = false; output.space = true ; output.colon = false; write();
   output.brief = false; output.space = false; output.colon = true ; write();
   output.brief = false; output.space = false; output.colon = false; write();
   */
}
