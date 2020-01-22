
#include "gnds.hpp"

/*
// reset
inline void reset()
{
   std::cout << gnds::ansi::reset << std::endl;
}
*/

// main
int main()
{
   std::cout << std::endl;

   // bold
   std::cout << gnds::ansi::bold::black   << "bold::black"   << std::endl;
   std::cout << gnds::ansi::bold::red     << "bold::red"     << std::endl;
   std::cout << gnds::ansi::bold::green   << "bold::green"   << std::endl;
   std::cout << gnds::ansi::bold::blue    << "bold::blue"    << std::endl;
   std::cout << gnds::ansi::bold::cyan    << "bold::cyan"    << std::endl;
   std::cout << gnds::ansi::bold::magenta << "bold::magenta" << std::endl;
   std::cout << gnds::ansi::bold::yellow  << "bold::yellow"  << std::endl;
   std::cout << gnds::ansi::bold::white   << "bold::white"   << std::endl;
   std::cout << gnds::ansi::reset << std::endl;
///reset();

   // lite
   std::cout << gnds::ansi::lite::black   << "lite::black"   << std::endl;
   std::cout << gnds::ansi::lite::red     << "lite::red"     << std::endl;
   std::cout << gnds::ansi::lite::green   << "lite::green"   << std::endl;
   std::cout << gnds::ansi::lite::blue    << "lite::blue"    << std::endl;
   std::cout << gnds::ansi::lite::cyan    << "lite::cyan"    << std::endl;
   std::cout << gnds::ansi::lite::magenta << "lite::magenta" << std::endl;
   std::cout << gnds::ansi::lite::yellow  << "lite::yellow"  << std::endl;
   std::cout << gnds::ansi::lite::white   << "lite::white"   << std::endl;
   std::cout << gnds::ansi::reset << std::endl;
///reset();

   // color
   gnds::color = false;
   assert(gnds::color() == false);
   gnds::color = true;
   assert(gnds::color() == true);

   std::cout << gnds::color.debug         << "color.debug"         << std::endl;
   std::cout << gnds::color.note          << "color.note"          << std::endl;
   std::cout << gnds::color.warning       << "color.warning"       << std::endl;
   std::cout << gnds::color.error         << "color.error"         << std::endl;
   std::cout << gnds::color.fatal         << "color.fatal"         << std::endl;
   std::cout << gnds::color.report.first  << "color.report.first"  << std::endl;
   std::cout << gnds::color.report.second << "color.report.second" << std::endl;
   std::cout << gnds::color.reset << std::endl;

   // markup
   gnds::markup.ansi();
   gnds::markup.html();
   gnds::markup.html("   ");
   gnds::markup.rst();
   gnds::markup.tex();
   gnds::markup.tex_listing();

   gnds::markup.ansi();
   gnds::markup.begin();

   // debug
   gnds::debug = false;
   assert(gnds::debug() == false);
   gnds::debug = true;
   assert(gnds::debug() == true);

   gnds::debug("foo");
   std::ostringstream oss;
   oss << "bar";
   gnds::debug(oss);

   // brief
   gnds::brief = false;
   assert(gnds::brief == false);
   gnds::brief = true;
   assert(gnds::brief == true);
   gnds::brief = false;
}
