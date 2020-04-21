
// -----------------------------------------------------------------------------
// keyword_t::meta()
// -----------------------------------------------------------------------------

/*
------------------------
Examples
------------------------

using namespace GNDStk;

struct version_t {
   int major;
   int minor;
   int patch;
};

struct date_t {
   int year;
   int month;
   int day;
};

struct shape_t {
   int rows;
   int cols;
};

// <>, or <void>: retrieve metadata value as string
auto encoding = keyword.meta<>("encoding");

// <std::string>: also retrieve metadata value as string
auto label = keyword.meta<std::string>("label");

// <type>: retrieve metadata value as type
auto version = keyword.meta<version_t>("version");
auto date    = keyword.meta<date_t   >("date");
auto shape   = keyword.meta<shape_t  >("shape");
*/


// <>
// <RESULT>
template<class RESULT = void>
static auto meta(const std::string &name)
{
   return meta_t<RESULT>{name};
}
