
namespace detail {

// -----------------------------------------------------------------------------
// remove_cvref
// remove_cvrefs
// -----------------------------------------------------------------------------

// C++20 will have this
template<class T>
struct remove_cvref {
   using type = std::remove_cv_t<std::remove_reference_t<T>>;
};

template<class T>
using remove_cvref_t = typename remove_cvref<T>::type;


// With -s, for tuple
template<class T>
struct remove_cvrefs {
};

template<class... Ts>
struct remove_cvrefs<std::tuple<Ts...>> {
   using type = std::tuple<remove_cvref_t<Ts> ...>;
};

template<class... Ts>
using remove_cvrefs_t = typename remove_cvrefs<Ts...>::type;


// -----------------------------------------------------------------------------
// has_*
// SFINAE constructs for detecting whether or not a class has certain members.
// Adapted from an answer here: https://stackoverflow.com/questions/1005476
// -----------------------------------------------------------------------------

// ------------------------
// Helpers
// ------------------------

// has_length
template<class T, class = int>
struct has_length : std::false_type { };
template<class T>
struct has_length<T,decltype((void)T::length,0)>
   : std::true_type { };

// has_start
template<class T, class = int>
struct has_start : std::false_type { };
template<class T>
struct has_start<T,decltype((void)T::start,0)>
   : std::true_type { };

// has_valueType
template<class T, class = int>
struct has_valueType : std::false_type { };
template<class T>
struct has_valueType<T,decltype((void)T::valueType,0)>
   : std::true_type { };

// ------------------------
// Use these; they deal
// with CV and reference
// qualifiers, and don't
// require ::value
// ------------------------

template<class T>
inline constexpr bool hasLength =
   has_length<detail::remove_cvref_t<T>>::value;

template<class T>
inline constexpr bool hasStart =
   has_start<detail::remove_cvref_t<T>>::value;

template<class T>
inline constexpr bool hasValueType =
   has_valueType<detail::remove_cvref_t<T>>::value;



// -----------------------------------------------------------------------------
// element2element
// -----------------------------------------------------------------------------

// We don't use to_string() below, so that we can eventually deal with
// precision; to_string() might be insufficient for our needs in that respect.
// todo: see if GNDStk's convert() functions are appropriate for doing all
// possible cases here, or could be extended to be.

// arithmetic ==> string
template<class FROM, class=std::enable_if_t<!std::is_same_v<FROM,std::string>>>
inline void element2element(const FROM &from, std::string &to)
{
   std::ostringstream oss;
   oss << from; // <== precision would be relevant here
   to = oss.str();
}

// string ==> arithmetic
template<class TO, class=std::enable_if_t<!std::is_same_v<TO,std::string>>>
inline void element2element(const std::string &from, TO &to)
{
   std::istringstream iss(from);
   iss >> to;
}

// arithmetic ==> arithmetic
template<class FROM, class TO>
inline void element2element(const FROM &from, TO &to)
{
   to = TO(from);
}


// -----------------------------------------------------------------------------
// getBounds
// -----------------------------------------------------------------------------

// T
template<class T>
inline auto getBounds(const std::vector<T> &vec)
{
   std::pair<std::size_t,std::size_t> bnd(0,vec.size());
   while (bnd.first < bnd.second && vec[bnd.first   ] == T(0)) ++bnd.first;
   while (bnd.first < bnd.second && vec[bnd.second-1] == T(0)) --bnd.second;
   return bnd;
}

// string
inline auto getBounds(const std::vector<std::string> &vec)
{
   std::pair<std::size_t,std::size_t> bnd(0,vec.size());
   while (bnd.first < bnd.second && vec[bnd.first   ] == "") ++bnd.first;
   while (bnd.first < bnd.second && vec[bnd.second-1] == "") --bnd.second;
   return bnd;
}


// -----------------------------------------------------------------------------
// makeText
// Helper for BodyText::toNode()
// -----------------------------------------------------------------------------

inline std::string *makeText(Node &node)
{
   // Recall that GNDStk's tree structure stores nodes with XML "plain
   // character data" - what we're informally calling "values nodes" -
   // in the following manner:
   //    Parent
   //       "pcdata" child
   //          "text" metadatum
   // This particular layout is translated from/to the actual form needed
   // in XML, or in JSON, in GNDStk's respective I/O functionality. Here,
   // therefore, we only create what GNDStk's tree structure needs.

   // ------------------------
   // pcdata
   // ------------------------

   // In the given node, get or make a "pcdata" child
   bool found;
   Node *pc = &node.one("pcdata",found);

   if (found) {
      // a pcdata child is already there :-/
      log::warning(
        "Child node \"pcdata\" already exists in node \"{}\".\n"
        "We'll replace any text content, but it's unexpected "
        "that a \"pcdata\"\n"
        "child already exists in this context.",
         node.name
      );
      log::member("BodyText::toNode(Node)");
   } else {
      // create a pcdata child
      pc = &node.add("pcdata");
   }

   // ------------------------
   // text
   // ------------------------

   // In the "pcdata" child, get or make a "text" metadatum
   std::string *text = &pc->meta("text",found);
   if (found) {
      // a text metadatum is already there :-/
      log::warning(
        "Metadatum \"text\" already exists in node \"{}\"'s \"pcdata\" child.\n"
        "We'll replace its value, but it's unexpected "
        "that a \"text\"\n"
        "metadatum already exists in this context.",
         node.name
      );
      log::member("BodyText::toNode(Node)");
   } else {
      // create a text metadatum
      text = &pc->add("text","").second;
   }

   return text;
}

} // namespace detail
