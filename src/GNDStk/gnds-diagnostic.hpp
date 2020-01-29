
// -----------------------------------------------------------------------------
// ansi
// ANSI text-color codes
// See: https://stackoverflow.com/questions/2616906/
// Bold means bold *or* "bright"
// E.g. bold.black is actually a gray
// -----------------------------------------------------------------------------

namespace detail {

class ansi_t {
public:

   // bold.*
   struct bold_t {
      static constexpr const char *const black   = "\033[30;1m";
      static constexpr const char *const red     = "\033[31;1m";
      static constexpr const char *const green   = "\033[32;1m";
      static constexpr const char *const blue    = "\033[34;1m";
      static constexpr const char *const cyan    = "\033[36;1m";
      static constexpr const char *const magenta = "\033[35;1m";
      static constexpr const char *const yellow  = "\033[33;1m";
      static constexpr const char *const white   = "\033[37;1m";
   } bold;

   // lite.*
   // On some terminals I'm seeing these get underlined, which probably isn't
   // best for a default. So, I'll use only the "bold" versions for defaults.
   struct lite_t {
      static constexpr const char *const black   = "\033[30;21m";
      static constexpr const char *const red     = "\033[31;21m";
      static constexpr const char *const green   = "\033[32;21m";
      static constexpr const char *const blue    = "\033[34;21m";
      static constexpr const char *const cyan    = "\033[36;21m";
      static constexpr const char *const magenta = "\033[35;21m";
      static constexpr const char *const yellow  = "\033[33;21m";
      static constexpr const char *const white   = "\033[37;21m";
   } lite;

   // reset
   static constexpr const char *const reset = "\033[0m";
};

} // namespace detail

inline detail::ansi_t ansi;



// -----------------------------------------------------------------------------
// color
// colour
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
   static bool on;

public:
   static std::string debug;
   static std::string note;
   static std::string warning;
   static std::string error;
   static std::string internal;
   static std::string fatal;
   static std::pair<std::string,std::string> report;
   static std::string reset;

   // as bool
   color_t &operator=(const bool value) { return on = value, *this; }
   operator bool() const { return on; }
};

// initialization
template<class unused>
bool color_t<unused>::on = true;

template<class unused>
std::string color_t<unused>::debug    = ansi.bold.white;

template<class unused>
std::string color_t<unused>::note     = ansi.bold.green;

template<class unused>
std::string color_t<unused>::warning  = ansi.bold.yellow;

template<class unused>
std::string color_t<unused>::error    = ansi.bold.red;

template<class unused>
std::string color_t<unused>::internal = ansi.bold.magenta;

template<class unused>
std::string color_t<unused>::fatal    = ansi.bold.red;

template<class unused>
std::pair<std::string,std::string> color_t<unused>::report = {
   ansi.bold.blue,
   ansi.bold.cyan
};

template<class unused>
std::string color_t<unused>::reset = ansi.reset;

} // namespace detail


// for users
inline detail::color_t<char> color;
inline detail::color_t<char> &colour = color;



// -----------------------------------------------------------------------------
// output
// -----------------------------------------------------------------------------

// ------------------------
// output_t
// ------------------------

namespace detail {

template<class unused>
class output_t {
   static std::string prefix;
   static std::string suffix;

public:

   // bools
   static bool brief; // short mode for diagnostic printing?
   static bool space; // extra spacing around diagnostics?
   static bool colon; // print colon after diagnostic label?

   // ------------------------
   // printing schemes
   // ------------------------

   // ansi
   void ansi()
   {
      color.debug    = gnds::ansi.bold.white;
      color.note     = gnds::ansi.bold.green;
      color.warning  = gnds::ansi.bold.yellow;
      color.error    = gnds::ansi.bold.red;
      color.internal = gnds::ansi.bold.magenta;
      color.fatal    = gnds::ansi.bold.red;
      color.report   = {
         gnds::ansi.bold.blue,
         gnds::ansi.bold.cyan
      };
      color.reset = gnds::ansi.reset;
      prefix = "";
      suffix = "";
   }

   // html
   void html(const std::string &indent = "")
   {
      color.debug    = indent + "<span style=\"color:lightgray\">";
      color.note     = indent + "<span style=\"color:green\">";
      color.warning  = indent + "<span style=\"color:orange\">";
      color.error    = indent + "<span style=\"color:red\">";
      color.internal = indent + "<span style=\"color:magenta\">";
      color.fatal    = indent + "<span style=\"color:red\">";
      color.report   = {
         indent + "<span style=\"color:blue\">",
         indent + "<span style=\"color:darkturquoise\">"
      };
      color.reset = "</span>";
      prefix = "";
      suffix = "";
   }

   // rst
   void rst()
   {
      html("   ");
      prefix = ".. raw:: html\n   <pre class=\"code literal-block\">\n";
      suffix = "   </pre>\n";
   }

   // tex
   void tex(const std::string &pfx = "\\", const std::string &sfx = "{}")
   {
      color.debug    = pfx + "textWhite"   + sfx;
      color.note     = pfx + "textGreen"   + sfx;
      color.warning  = pfx + "textYellow"  + sfx;
      color.error    = pfx + "textRed"     + sfx;
      color.internal = pfx + "textMagenta" + sfx;
      color.fatal    = pfx + "textRed"     + sfx;
      color.report   = {
         pfx + "textBlueViolet" + sfx,
         pfx + "textCyan"       + sfx
      };
      color.reset = pfx + "textBlack" + sfx;
      prefix = "";
      suffix = "";
   }

   // listing
   void listing()
   {
      tex("`","``");
      prefix = "";
      suffix = "";
   }

   // ------------------------
   // begin, destructor
   // ------------------------

   // begin
   bool begin(const bool print = true) const
   {
      static bool first = true;
      if (first) {
         if (print)
            std::cout << prefix;
         first = false;
         return false; // not called before
      } else
         return true;  // called before
   }

   // destructor
  ~output_t()
   {
      if (begin(false))
         std::cout << suffix << (suffix == "" ? "" : "\n");
   }
};

// initialization
template<class unused> std::string output_t<unused>::prefix = "";
template<class unused> std::string output_t<unused>::suffix = "";

template<class unused> bool output_t<unused>::brief = false;
template<class unused> bool output_t<unused>::space = false;
template<class unused> bool output_t<unused>::colon = true;

} // namespace detail


// for users
inline detail::output_t<char> output;



// -----------------------------------------------------------------------------
// debug
// -----------------------------------------------------------------------------

// ------------------------
// debug_t
// ------------------------

namespace detail {

template<class unused>
class debug_t {
   static bool on;

public:

   // operator=
   debug_t &operator=(const bool value) { return on = value, *this; }
   operator bool() const { return on; }

   // operator()
   void operator()(const std::string &text) const;

   void operator()(const std::ostringstream &oss) const
   {
      (*this)(oss.str());
   }

   template<class T>
   void operator()(const std::string &name, const T &value) const
   {
      std::ostringstream oss;
      oss << name << " == " << value;
      (*this)(oss);
   }
};

template<class unused>
bool debug_t<unused>::on = false;

} // namespace detail



// ------------------------
// debug_t::operator()
// ------------------------

namespace detail {

template<class unused>
void debug_t<unused>::operator()(const std::string &text) const
{
   // nothing, if debugging isn't on
   if (!on)
      return;

   // initial markup, if needed
   output.begin();

   // color
   const std::string &color = gnds::color ? gnds::color.debug : "";
   const std::string &reset = gnds::color ? gnds::color.reset : "";

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
      std::cout << '\n';
   std::cout << std::flush;
}

} // namespace detail


// for users
inline detail::debug_t<char> debug;



// -----------------------------------------------------------------------------
// diagnostic
//
// Templated, so that we don't need to say "inline" in a header-only context.
// It's long enough that we don't want it to be inline. (Not that this likely
// matters, as compilers generally decide for themselves about inlining.)
// -----------------------------------------------------------------------------

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

template<class unused>
void diagnostic(
   const std::string &label,
   const std::string &text,
   std::string maincolor,      // color for label
   std::string textcolor = "", // color for text
   const bool keep_verbose = false // force long form
) {
   // initial markup, if needed
   output.begin();

   // spacing
   static bool first = true;
   if (output.space && !first)
      std::cout << '\n';
   first = false;

   // color
   if (!gnds::color)
      textcolor = maincolor = "";
   else if (textcolor == "")
      textcolor = maincolor;
   const std::string &reset = gnds::color ? gnds::color.reset : "";

   // content
   if (label == "" || (output.brief && !keep_verbose))
      std::cout << maincolor << text << reset;
   else {
      std::cout
         << maincolor << label
         << (output.colon ? ":" : "")
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
      std::cout << '\n';
   std::cout << std::flush;
}

} // namespace detail



// -----------------------------------------------------------------------------
// note
// warning
// error
// internal
// fatal
// -----------------------------------------------------------------------------

// ------------------------
// classes
// ------------------------

namespace detail {

// note_t
template<class unused>
class note_t {
   static bool on;

public:

   // as bool
   note_t &operator=(const bool value) { return on = value, *this; }
   operator bool() const { return on; }

   // operator()
   void operator()(const std::string &text) const
   {
      if (on)
         diagnostic<char>("Note", text, gnds::color.note);
   }

   void operator()(const std::ostringstream &oss) const { (*this)(oss.str()); }
};


// warning_t
template<class unused>
class warning_t {
   static bool on;

public:

   // as bool
   warning_t &operator=(const bool value) { return on = value, *this; }
   operator bool() const { return on; }

   // operator()
   void operator()(const std::string &text) const
   {
      if (on)
         diagnostic<char>("Warning", text, gnds::color.warning);
   }

   void operator()(const std::ostringstream &oss) const { (*this)(oss.str()); }
};


// error_t
template<class unused>
class error_t {
   static bool on;

public:

   // as bool
   error_t &operator=(const bool value) { return on = value, *this; }
   operator bool() const { return on; }

   // operator()
   void operator()(const std::string &text) const
   {
      if (on)
         diagnostic<char>("Error", text, gnds::color.error);
   }

   void operator()(const std::ostringstream &oss) const { (*this)(oss.str()); }
};


// internal_t
template<class unused>
class internal_t {
   static bool on;

public:

   // as bool
   internal_t &operator=(const bool value) { return on = value, *this; }
   operator bool() const { return on; }

   // operator()
   void operator()(const std::string &text) const
   {
      if (on)
         diagnostic<char>("Internal Error", text, gnds::color.internal);
   }

   void operator()(const std::ostringstream &oss) const { (*this)(oss.str()); }
};


// fatal_t
template<class unused>
class fatal_t {
public:

   // operator()
   void operator()(const std::string &text) const
   {
      // No "on" test as with other error types; these can't be suppressed
      diagnostic<char>("Fatal Error", text, gnds::color.fatal);
   }

   void operator()(const std::ostringstream &oss) const { (*this)(oss.str()); }
};

} // namespace detail



// ------------------------
// initialization
// ------------------------

namespace detail {
   template<class unused> bool note_t    <unused>::on = true;
   template<class unused> bool warning_t <unused>::on = true;
   template<class unused> bool error_t   <unused>::on = true;
   template<class unused> bool internal_t<unused>::on = true;
} // namespace detail



// ------------------------
// for users
// ------------------------

inline detail::note_t    <char> note;
inline detail::warning_t <char> warning;
inline detail::error_t   <char> error;
inline detail::internal_t<char> internal;
inline detail::fatal_t   <char> fatal;



// -----------------------------------------------------------------------------
// report
// -----------------------------------------------------------------------------

namespace detail {

template<class unused>
class report_t {
   static bool on;

public:

   // as bool
   report_t &operator=(const bool value) { return on = value, *this; }
   operator bool() const { return on; }

   // ------------------------
   // operator()
   // ------------------------

   void operator()(
      const std::string &label,
      const std::string &text = "",
      const bool keep_verbose = false
   ) const {
      if (!on || (label == "" && text == ""))
         // reports are off, or this report has no content
         return;
      else if (text == "")
         // caller only gave one string
         diagnostic<char>(
            "",    // assume label wasn't actually label...
            label, // but was text
            gnds::color.report.first,
            gnds::color.report.second,
            keep_verbose
         );
      else
         // normal case: label + text
         diagnostic<char>(
            label,
            text,
            gnds::color.report.first,
            gnds::color.report.second,
            keep_verbose
         );
   }
};

template<class unused>
bool report_t<unused>::on = true;

} // namespace detail


// for users
inline detail::report_t<char> report;
