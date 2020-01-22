
// -----------------------------------------------------------------------------
// ansi
// ANSI text-color codes
// See: https://stackoverflow.com/questions/2616906/
// Bold means bold *or* "bright"
// E.g. bold::black is actually a gray
// -----------------------------------------------------------------------------

class ansi {
public:

   // bold::*
   class bold {
   public:
      static constexpr const char *const black   = "\033[30;1m";
      static constexpr const char *const red     = "\033[31;1m";
      static constexpr const char *const green   = "\033[32;1m";
      static constexpr const char *const blue    = "\033[34;1m";
      static constexpr const char *const cyan    = "\033[36;1m";
      static constexpr const char *const magenta = "\033[35;1m";
      static constexpr const char *const yellow  = "\033[33;1m";
      static constexpr const char *const white   = "\033[37;1m";
   };

   // lite::*
   class lite {
   public:
      static constexpr const char *const black   = "\033[30;21m";
      static constexpr const char *const red     = "\033[31;21m";
      static constexpr const char *const green   = "\033[32;21m";
      static constexpr const char *const blue    = "\033[34;21m";
      static constexpr const char *const cyan    = "\033[36;21m";
      static constexpr const char *const magenta = "\033[35;21m";
      static constexpr const char *const yellow  = "\033[33;21m";
      static constexpr const char *const white   = "\033[37;21m";
   };

   // reset
   static constexpr const char *const reset = "\033[0m";
};



// -----------------------------------------------------------------------------
// color
// -----------------------------------------------------------------------------

// ------------------------
// color_t
// ------------------------

namespace detail {

// The following class is templated so that static data member definitions
// don't cause multiply-defined symbol errors when our (header-only) library
// is #included in multiple user source files.
template<class unused>
class color_t {
   static bool on;/// = true;

public:

   // operator=
   color_t &operator=(const bool value)
   {
      on = value;
      return *this;
   }

   bool operator()() const { return on; }

   static std::string debug;///   = ansi::bold::white;
   static std::string note;///    = ansi::lite::green;
   static std::string warning;/// = ansi::bold::yellow;
   static std::string error;///   = ansi::lite::red;
   static std::string fatal;///   = ansi::lite::red;
   static std::pair<std::string,std::string> report;
   /*
     = std::make_pair(
        ansi::bold::blue,
        ansi::bold::cyan
     };
   */

   static std::string reset;/// = ansi::reset;
};

// initialization

template<class unused>
bool color_t<unused>::on = true;

template<class unused>
std::string color_t<unused>::debug   = ansi::bold::white;
template<class unused>
std::string color_t<unused>::note    = ansi::lite::green;
template<class unused>
std::string color_t<unused>::warning = ansi::bold::yellow;
template<class unused>
std::string color_t<unused>::error   = ansi::lite::red;
template<class unused>
std::string color_t<unused>::fatal   = ansi::lite::red;
// fixme Maybe fatal errors colored magenta?

template<class unused>
std::pair<std::string,std::string> color_t<unused>::report = {
   ansi::bold::blue,
   ansi::bold::cyan
};

template<class unused>
std::string color_t<unused>::reset = ansi::reset;

} // namespace detail



// ------------------------
// color
// ------------------------

inline detail::color_t<char> color;



// -----------------------------------------------------------------------------
// markup
// -----------------------------------------------------------------------------

// ------------------------
// markup_t
// ------------------------

namespace detail {

class markup_t {
   // fixme Consider making these public; if so, include in examples/tests
   std::string prefix = "";
   std::string suffix = "";

public:

   /*
   // ------------------------
   // prefix, suffix
   // ------------------------

   void prefix(const std::string &p) { _prefix = p; }
   void suffix(const std::string &s) { _suffix = s; }
   */


   // ------------------------
   // printing schemes
   // ------------------------

   /*
   static std::string debug   = ansi::bold::white;
   static std::string note    = ansi::lite::green;
   static std::string warning = ansi::bold::yellow;
   static std::string error   = ansi::lite::red;
   static std::string fatal   = ansi::lite::red;
   static std::pair<std::string,std::string> report = std::make_pair(
      ansi::bold::blue,
      ansi::bold::cyan
   };
   static std::string reset = ansi::reset;
   */

   // ansi
   void ansi()
   {
      prefix = "";
      color.debug   = ansi::bold::white;
      color.note    = ansi::lite::green;
      color.warning = ansi::bold::yellow;
      color.error   = ansi::lite::red;
      color.fatal   = ansi::lite::red;
      color.report  ={ansi::bold::blue,ansi::bold::cyan};
      color.reset   = ansi::reset;
      suffix = "";
   }

   // html
   void html(const std::string &indent = "")
   {
      prefix = "";
      color.debug   = indent + "<span style=\"color:lightgray\">";
      color.note    = indent + "<span style=\"color:green\">";
      color.warning = indent + "<span style=\"color:orange\">";
      color.error   = indent + "<span style=\"color:red\">";
      color.fatal   = indent + "<span style=\"color:red\">";
      color.report  = {
         indent + "<span style=\"color:blue\">",
         indent + "<span style=\"color:darkturquoise\">"
      };
      color.reset   = "</span>";
      suffix = "";
   }

   // rst
   void rst()
   {
      html("   ");
      // modify from html()'s...
      prefix = ".. raw:: html\n\n   <pre class=\"code literal-block\">\n";
      suffix = "   </pre>\n";
   }

   // tex
   void tex()
   {
      prefix = "";
      color.debug   = "\\textWhite{}";
      color.note    = "\\textGreen{}";
      color.warning = "\\textYellow{}";
      color.error   = "\\textRed{}";
      color.fatal   = "\\textRed{}";
      color.report  ={"\\textBlueViolet{}", "\\textCyan{}"};
      color.reset   = "\\textBlack{}";
      suffix = "";
   }

   // tex_listing
   void tex_listing()
   {
      prefix = "";
      color.debug   = "`textWhite``";
      color.note    = "`textGreen``";
      color.warning = "`textYellow``";
      color.error   = "`textRed``";
      color.fatal   = "`textRed``";
      color.report  ={"`textBlueViolet``", "`textCyan``"};
      color.reset   = "`textBlack";
      suffix = "";
   }

   // ------------------------
   // ctor/dtor/etc.
   // ------------------------

   // begin()
   void begin() const
   {
      // print the markup prefix
      static auto &once = std::cout << prefix;
      (void)once;
   }

   // constructor
   markup_t()
   {
      // initialize color scheme
      ansi();
   }

   // destructor
  ~markup_t()
   {
      // print the markup suffix
      static auto &once = std::cout << suffix;
      (void)once;
   }
};

} // namespace detail



// ------------------------
// markup
// ------------------------

inline detail::markup_t markup;



// -----------------------------------------------------------------------------
// debug
// -----------------------------------------------------------------------------

// ------------------------
// debug_t
// ------------------------

namespace detail {

class debug_t {
   bool on = false;

public:

   // operator=
   debug_t &operator=(const bool value)
   {
      on = value;
      return *this;
   }

   bool operator()() const { return on; }

   // operator()
   void operator()(const std::string &text) const;
   void operator()(const std::ostringstream &oss) const
   {
      (*this)(oss.str());
   }

   /*
   template<class T>
   void operator()(const std::string &varname, const T &value) const
   {
      std::ostringstream oss;
      oss << varname << " == " << value;
      (*this)(oss);
   }
   */
};

} // namespace detail



// ------------------------
// debug_t::operator()
// ------------------------

namespace detail {

inline void debug_t::operator()(const std::string &text) const
{
   markup.begin();

   if (!on)
      return;

   // color
   const std::string &color = gnds::color() ? gnds::color.debug : "";
   const std::string &reset = gnds::color() ? gnds::color.reset : "";

   // content
   std::cout << color << "Debug: ";
   const std::size_t size = text.size();
   for (std::size_t i = 0;  i < size;  ++i) {
      const bool internal_newline = text[i] == '\n' && i < size-1;
      if (internal_newline) std::cout << reset;
      std::cout << text[i];
      if (internal_newline) std::cout << color << "Debug: ";
   }
   std::cout << reset;

   // finish
   if (text != "" && text.back() != '\n')
      std::cout << "\n";
   std::cout << std::flush;
}

} // namespace detail



// ------------------------
// debug
// ------------------------

inline detail::debug_t debug;



// -----------------------------------------------------------------------------
// diagnostic()
// -----------------------------------------------------------------------------

inline bool brief = false;

// Remark: Our handling of colors, in some of the below functions, may *appear*
// to be more complicated than it needs to be. In particular, we'll explicitly
// set and unset color markup on a per-line, not per-block-of-lines, basis.
// While this clutters the output with more color markup than is necessary,
// we're doing it intentionally: so that colors are preserved if, for example,
// you send the code's output through something that processes individual lines.
// Imagine, for example, using the Unix "grep" command to display lines with the
// word "foo" in them:
//
//    command ... | grep foo
//
// Well, grep isn't the best example, because, depending on how it's configured,
// it may mess with color markup or use its own. You may, however, be able to
// switch that off, for example with:
//
//    command ... | grep --color=never foo
//
// So, we believe that our line-by-line color encoding gives more flexibility in
// terms of what you can do with the output.

namespace detail {

// fixme Might or might not want this...
inline bool first_print = true;

// diagnostic
inline void diagnostic(
   const std::string &label,
   const std::string &text,
   std::string maincolor,      // color for label
   std::string textcolor = "", // color for text
   const bool keep_verbose = false, // force long form
   const bool colon = true // ":" after label?
) {
   markup.begin();

   // spacing
   if (!brief && !first_print)
      std::cout << "\n";
   first_print = false;

   // color
   if (!gnds::color())
      textcolor = maincolor = "";
   else if (textcolor == "")
      textcolor = maincolor;
   const std::string &reset = gnds::color() ? gnds::color.reset : "";

   // content
   if (label == "" || (brief && !keep_verbose))
      std::cout << maincolor << text << reset;
   else {
      std::cout
         << maincolor << label
         << (colon ? ":" : "")
         << reset << "\n   ";
      std::cout << textcolor;

      const std::size_t size = text.size();
      for (std::size_t i = 0;  i < size;  ++i) {
         const bool internal_newline = text[i] == '\n' && i < size-1;
         if (internal_newline) std::cout << reset;
         std::cout << text[i];
         if (internal_newline) std::cout << "   " << textcolor;
      }

      std::cout << reset;
   }

   // finish
   if (text != "" && text.back() != '\n')
      std::cout << "\n";
   std::cout << std::flush;
}

} // namespace detail



#if 0

// -----------------------------------------------------------------------------
// Diagnostics / informational printing
// -----------------------------------------------------------------------------

fixme working here...

// ------------------------
// Flags
// ------------------------

// re: types of printing
inline bool emit_note    = true;
inline bool emit_warning = true;
inline bool emit_error   = true;
inline bool emit_report  = true;



// ------------------------
// report
// ------------------------

inline exit_status_t report(
   const std::string &label,
   const std::string &str,
   const bool keep_verbose,
   const bool colon = true
) {
   if (emit_report)
      diagnostic(
         label, str,
         gnds::color.report.first,
         gnds::color.report.second,
         keep_verbose, colon
      );
   return exit_clean;
}

inline exit_status_t report(
   const std::string &label,
   const std::ostringstream &oss,
   const bool keep_verbose,
   const bool colon = true
) {
   return report(label, oss.str(), keep_verbose, colon);
}



// ------------------------
// note
// ------------------------

inline exit_status_t note(const std::string &str)
{
   if (emit_note)
      diagnostic("Note", str, gnds::color.note);
   return exit_clean;
}

inline exit_status_t note(const std::ostringstream &oss)
{
   return note(oss.str());
}



// ------------------------
// warning
// ------------------------

inline exit_status_t warning(const std::string &str)
{
   if (emit_warning)
      diagnostic("Warning", str, gnds::color.warning);
   return exit_clean;
}

inline exit_status_t warning(const std::ostringstream &oss)
{
   return warning(oss.str());
}

inline exit_status_t intwarn(const std::string &str)
{
   return warning("Internal warning from the gnds API.\n" + str);
}

inline exit_status_t intwarn(const std::ostringstream &oss)
{
   return intwarn(oss.str());
}



// ------------------------
// error
// ------------------------

inline exit_status_t error(const std::string &str)
{
   if (emit_error)
      diagnostic("Error", str, gnds::color.error);
   return exit_error;
}

inline exit_status_t error(const std::ostringstream &oss)
{
   return error(oss.str());
}



// ------------------------
// fatal
// ------------------------

inline exit_status_t fatal(const std::string &str)
{
   // these always print, regardless of emit_error
   diagnostic("Terminal Error", str, gnds::color.fatal);
   return exit_fatal;
}

inline exit_status_t fatal(const std::ostringstream &oss)
{
   return fatal(oss.str());
}



// ------------------------
// internal
// ------------------------

inline exit_status_t internal(const std::string &str)
{
   return fatal("Internal Error: " + str);
}

inline exit_status_t internal(const std::ostringstream &oss)
{
   return internal(oss.str());
}

#endif
