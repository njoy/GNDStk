
inline bool shades = true;

namespace color {

// makeColor
// Here, not in detail::, because it may be of interest to users.
inline std::string makeColor(const int r, const int g, const int b)
{
   return "\033[38;2;" +
      std::to_string(r < 0 ? 0 : r > 255 ? 255 : r) + ";" +
      std::to_string(g < 0 ? 0 : g > 255 ? 255 : g) + ";" +
      std::to_string(b < 0 ? 0 : b > 255 ? 255 : b) + "m";
}


// -----------------------------------------------------------------------------
// Simple ANSI colors
// -----------------------------------------------------------------------------

// Specific colors:
//    color::plain::*
//    color::bold::*
// Reset/clear:
//    color::reset
// All of these are ANSI color escape sequences. They'll work on many terminals,
// perhaps most, but working isn't guaranteed. The GNDStk::colors flag is false,
// by default, so that colors aren't used unless someone sets it to true.

// color::plain::
namespace plain {
   inline const std::string
   black   = "\033[30;1m",
   red     = "\033[31;1m",
   green   = "\033[32;1m",
   blue    = "\033[34;1m",
   cyan    = "\033[36;1m",
   magenta = "\033[35;1m",
   yellow  = "\033[33;1m",
   white   = "\033[37;1m";
}

// color::bold::
namespace bold {
   inline const std::string
   black   = "\033[30;21m",
   red     = "\033[31;21m",
   green   = "\033[32;21m",
   blue    = "\033[34;21m",
   cyan    = "\033[36;21m",
   magenta = "\033[35;21m",
   yellow  = "\033[33;21m",
   white   = "\033[37;21m";
}

// color::reset
inline const std::string reset = "\033[0m";


// -----------------------------------------------------------------------------
// blue2red
// -----------------------------------------------------------------------------

template<class T, class = std::enable_if_t<std::is_arithmetic_v<T>>>
std::string blue2red(T min, T value, T max)
{
   static const int ncolors = 511;
   static const int rgb[ncolors][3] = {
      {   0,   0, 255 }, // blue...
      {   0,   1, 254 }, // decrease, while increasing green...
      {   0,   2, 253 },
      {   0,   3, 252 },
      {   0,   4, 251 },
      {   0,   5, 250 },
      {   0,   6, 249 },
      {   0,   7, 248 },
      {   0,   8, 247 },
      {   0,   9, 246 },
      {   0,  10, 245 },
      {   0,  11, 244 },
      {   0,  12, 243 },
      {   0,  13, 242 },
      {   0,  14, 241 },
      {   0,  15, 240 },
      {   0,  16, 239 },
      {   0,  17, 238 },
      {   0,  18, 237 },
      {   0,  19, 236 },
      {   0,  20, 235 },
      {   0,  21, 234 },
      {   0,  22, 233 },
      {   0,  23, 232 },
      {   0,  24, 231 },
      {   0,  25, 230 },
      {   0,  26, 229 },
      {   0,  27, 228 },
      {   0,  28, 227 },
      {   0,  29, 226 },
      {   0,  30, 225 },
      {   0,  31, 224 },
      {   0,  32, 223 },
      {   0,  33, 222 },
      {   0,  34, 221 },
      {   0,  35, 220 },
      {   0,  36, 219 },
      {   0,  37, 218 },
      {   0,  38, 217 },
      {   0,  39, 216 },
      {   0,  40, 215 },
      {   0,  41, 214 },
      {   0,  42, 213 },
      {   0,  43, 212 },
      {   0,  44, 211 },
      {   0,  45, 210 },
      {   0,  46, 209 },
      {   0,  47, 208 },
      {   0,  48, 207 },
      {   0,  49, 206 },
      {   0,  50, 205 },
      {   0,  51, 204 },
      {   0,  52, 203 },
      {   0,  53, 202 },
      {   0,  54, 201 },
      {   0,  55, 200 },
      {   0,  56, 199 },
      {   0,  57, 198 },
      {   0,  58, 197 },
      {   0,  59, 196 },
      {   0,  60, 195 },
      {   0,  61, 194 },
      {   0,  62, 193 },
      {   0,  63, 192 },
      {   0,  64, 191 },
      {   0,  65, 190 },
      {   0,  66, 189 },
      {   0,  67, 188 },
      {   0,  68, 187 },
      {   0,  69, 186 },
      {   0,  70, 185 },
      {   0,  71, 184 },
      {   0,  72, 183 },
      {   0,  73, 182 },
      {   0,  74, 181 },
      {   0,  75, 180 },
      {   0,  76, 179 },
      {   0,  77, 178 },
      {   0,  78, 177 },
      {   0,  79, 176 },
      {   0,  80, 175 },
      {   0,  81, 174 },
      {   0,  82, 173 },
      {   0,  83, 172 },
      {   0,  84, 171 },
      {   0,  85, 170 },
      {   0,  86, 169 },
      {   0,  87, 168 },
      {   0,  88, 167 },
      {   0,  89, 166 },
      {   0,  90, 165 },
      {   0,  91, 164 },
      {   0,  92, 163 },
      {   0,  93, 162 },
      {   0,  94, 161 },
      {   0,  95, 160 },
      {   0,  96, 159 },
      {   0,  97, 158 },
      {   0,  98, 157 },
      {   0,  99, 156 },
      {   0, 100, 155 },
      {   0, 101, 154 },
      {   0, 102, 153 },
      {   0, 103, 152 },
      {   0, 104, 151 },
      {   0, 105, 150 },
      {   0, 106, 149 },
      {   0, 107, 148 },
      {   0, 108, 147 },
      {   0, 109, 146 },
      {   0, 110, 145 },
      {   0, 111, 144 },
      {   0, 112, 143 },
      {   0, 113, 142 },
      {   0, 114, 141 },
      {   0, 115, 140 },
      {   0, 116, 139 },
      {   0, 117, 138 },
      {   0, 118, 137 },
      {   0, 119, 136 },
      {   0, 120, 135 },
      {   0, 121, 134 },
      {   0, 122, 133 },
      {   0, 123, 132 },
      {   0, 124, 131 },
      {   0, 125, 130 },
      {   0, 126, 129 },
      {   0, 127, 128 },
      {   0, 128, 127 },
      {   0, 129, 126 },
      {   0, 130, 125 },
      {   0, 131, 124 },
      {   0, 132, 123 },
      {   0, 133, 122 },
      {   0, 134, 121 },
      {   0, 135, 120 },
      {   0, 136, 119 },
      {   0, 137, 118 },
      {   0, 138, 117 },
      {   0, 139, 116 },
      {   0, 140, 115 },
      {   0, 141, 114 },
      {   0, 142, 113 },
      {   0, 143, 112 },
      {   0, 144, 111 },
      {   0, 145, 110 },
      {   0, 146, 109 },
      {   0, 147, 108 },
      {   0, 148, 107 },
      {   0, 149, 106 },
      {   0, 150, 105 },
      {   0, 151, 104 },
      {   0, 152, 103 },
      {   0, 153, 102 },
      {   0, 154, 101 },
      {   0, 155, 100 },
      {   0, 156,  99 },
      {   0, 157,  98 },
      {   0, 158,  97 },
      {   0, 159,  96 },
      {   0, 160,  95 },
      {   0, 161,  94 },
      {   0, 162,  93 },
      {   0, 163,  92 },
      {   0, 164,  91 },
      {   0, 165,  90 },
      {   0, 166,  89 },
      {   0, 167,  88 },
      {   0, 168,  87 },
      {   0, 169,  86 },
      {   0, 170,  85 },
      {   0, 171,  84 },
      {   0, 172,  83 },
      {   0, 173,  82 },
      {   0, 174,  81 },
      {   0, 175,  80 },
      {   0, 176,  79 },
      {   0, 177,  78 },
      {   0, 178,  77 },
      {   0, 179,  76 },
      {   0, 180,  75 },
      {   0, 181,  74 },
      {   0, 182,  73 },
      {   0, 183,  72 },
      {   0, 184,  71 },
      {   0, 185,  70 },
      {   0, 186,  69 },
      {   0, 187,  68 },
      {   0, 188,  67 },
      {   0, 189,  66 },
      {   0, 190,  65 },
      {   0, 191,  64 },
      {   0, 192,  63 },
      {   0, 193,  62 },
      {   0, 194,  61 },
      {   0, 195,  60 },
      {   0, 196,  59 },
      {   0, 197,  58 },
      {   0, 198,  57 },
      {   0, 199,  56 },
      {   0, 200,  55 },
      {   0, 201,  54 },
      {   0, 202,  53 },
      {   0, 203,  52 },
      {   0, 204,  51 },
      {   0, 205,  50 },
      {   0, 206,  49 },
      {   0, 207,  48 },
      {   0, 208,  47 },
      {   0, 209,  46 },
      {   0, 210,  45 },
      {   0, 211,  44 },
      {   0, 212,  43 },
      {   0, 213,  42 },
      {   0, 214,  41 },
      {   0, 215,  40 },
      {   0, 216,  39 },
      {   0, 217,  38 },
      {   0, 218,  37 },
      {   0, 219,  36 },
      {   0, 220,  35 },
      {   0, 221,  34 },
      {   0, 222,  33 },
      {   0, 223,  32 },
      {   0, 224,  31 },
      {   0, 225,  30 },
      {   0, 226,  29 },
      {   0, 227,  28 },
      {   0, 228,  27 },
      {   0, 229,  26 },
      {   0, 230,  25 },
      {   0, 231,  24 },
      {   0, 232,  23 },
      {   0, 233,  22 },
      {   0, 234,  21 },
      {   0, 235,  20 },
      {   0, 236,  19 },
      {   0, 237,  18 },
      {   0, 238,  17 },
      {   0, 239,  16 },
      {   0, 240,  15 },
      {   0, 241,  14 },
      {   0, 242,  13 },
      {   0, 243,  12 },
      {   0, 244,  11 },
      {   0, 245,  10 },
      {   0, 246,   9 },
      {   0, 247,   8 },
      {   0, 248,   7 },
      {   0, 249,   6 },
      {   0, 250,   5 },
      {   0, 251,   4 },
      {   0, 252,   3 },
      {   0, 253,   2 },
      {   0, 254,   1 },
      {   0, 255,   0 }, // green...
      {   1, 254,   0 }, // decrease, while increasing red...
      {   2, 253,   0 },
      {   3, 252,   0 },
      {   4, 251,   0 },
      {   5, 250,   0 },
      {   6, 249,   0 },
      {   7, 248,   0 },
      {   8, 247,   0 },
      {   9, 246,   0 },
      {  10, 245,   0 },
      {  11, 244,   0 },
      {  12, 243,   0 },
      {  13, 242,   0 },
      {  14, 241,   0 },
      {  15, 240,   0 },
      {  16, 239,   0 },
      {  17, 238,   0 },
      {  18, 237,   0 },
      {  19, 236,   0 },
      {  20, 235,   0 },
      {  21, 234,   0 },
      {  22, 233,   0 },
      {  23, 232,   0 },
      {  24, 231,   0 },
      {  25, 230,   0 },
      {  26, 229,   0 },
      {  27, 228,   0 },
      {  28, 227,   0 },
      {  29, 226,   0 },
      {  30, 225,   0 },
      {  31, 224,   0 },
      {  32, 223,   0 },
      {  33, 222,   0 },
      {  34, 221,   0 },
      {  35, 220,   0 },
      {  36, 219,   0 },
      {  37, 218,   0 },
      {  38, 217,   0 },
      {  39, 216,   0 },
      {  40, 215,   0 },
      {  41, 214,   0 },
      {  42, 213,   0 },
      {  43, 212,   0 },
      {  44, 211,   0 },
      {  45, 210,   0 },
      {  46, 209,   0 },
      {  47, 208,   0 },
      {  48, 207,   0 },
      {  49, 206,   0 },
      {  50, 205,   0 },
      {  51, 204,   0 },
      {  52, 203,   0 },
      {  53, 202,   0 },
      {  54, 201,   0 },
      {  55, 200,   0 },
      {  56, 199,   0 },
      {  57, 198,   0 },
      {  58, 197,   0 },
      {  59, 196,   0 },
      {  60, 195,   0 },
      {  61, 194,   0 },
      {  62, 193,   0 },
      {  63, 192,   0 },
      {  64, 191,   0 },
      {  65, 190,   0 },
      {  66, 189,   0 },
      {  67, 188,   0 },
      {  68, 187,   0 },
      {  69, 186,   0 },
      {  70, 185,   0 },
      {  71, 184,   0 },
      {  72, 183,   0 },
      {  73, 182,   0 },
      {  74, 181,   0 },
      {  75, 180,   0 },
      {  76, 179,   0 },
      {  77, 178,   0 },
      {  78, 177,   0 },
      {  79, 176,   0 },
      {  80, 175,   0 },
      {  81, 174,   0 },
      {  82, 173,   0 },
      {  83, 172,   0 },
      {  84, 171,   0 },
      {  85, 170,   0 },
      {  86, 169,   0 },
      {  87, 168,   0 },
      {  88, 167,   0 },
      {  89, 166,   0 },
      {  90, 165,   0 },
      {  91, 164,   0 },
      {  92, 163,   0 },
      {  93, 162,   0 },
      {  94, 161,   0 },
      {  95, 160,   0 },
      {  96, 159,   0 },
      {  97, 158,   0 },
      {  98, 157,   0 },
      {  99, 156,   0 },
      { 100, 155,   0 },
      { 101, 154,   0 },
      { 102, 153,   0 },
      { 103, 152,   0 },
      { 104, 151,   0 },
      { 105, 150,   0 },
      { 106, 149,   0 },
      { 107, 148,   0 },
      { 108, 147,   0 },
      { 109, 146,   0 },
      { 110, 145,   0 },
      { 111, 144,   0 },
      { 112, 143,   0 },
      { 113, 142,   0 },
      { 114, 141,   0 },
      { 115, 140,   0 },
      { 116, 139,   0 },
      { 117, 138,   0 },
      { 118, 137,   0 },
      { 119, 136,   0 },
      { 120, 135,   0 },
      { 121, 134,   0 },
      { 122, 133,   0 },
      { 123, 132,   0 },
      { 124, 131,   0 },
      { 125, 130,   0 },
      { 126, 129,   0 },
      { 127, 128,   0 },
      { 128, 127,   0 },
      { 129, 126,   0 },
      { 130, 125,   0 },
      { 131, 124,   0 },
      { 132, 123,   0 },
      { 133, 122,   0 },
      { 134, 121,   0 },
      { 135, 120,   0 },
      { 136, 119,   0 },
      { 137, 118,   0 },
      { 138, 117,   0 },
      { 139, 116,   0 },
      { 140, 115,   0 },
      { 141, 114,   0 },
      { 142, 113,   0 },
      { 143, 112,   0 },
      { 144, 111,   0 },
      { 145, 110,   0 },
      { 146, 109,   0 },
      { 147, 108,   0 },
      { 148, 107,   0 },
      { 149, 106,   0 },
      { 150, 105,   0 },
      { 151, 104,   0 },
      { 152, 103,   0 },
      { 153, 102,   0 },
      { 154, 101,   0 },
      { 155, 100,   0 },
      { 156,  99,   0 },
      { 157,  98,   0 },
      { 158,  97,   0 },
      { 159,  96,   0 },
      { 160,  95,   0 },
      { 161,  94,   0 },
      { 162,  93,   0 },
      { 163,  92,   0 },
      { 164,  91,   0 },
      { 165,  90,   0 },
      { 166,  89,   0 },
      { 167,  88,   0 },
      { 168,  87,   0 },
      { 169,  86,   0 },
      { 170,  85,   0 },
      { 171,  84,   0 },
      { 172,  83,   0 },
      { 173,  82,   0 },
      { 174,  81,   0 },
      { 175,  80,   0 },
      { 176,  79,   0 },
      { 177,  78,   0 },
      { 178,  77,   0 },
      { 179,  76,   0 },
      { 180,  75,   0 },
      { 181,  74,   0 },
      { 182,  73,   0 },
      { 183,  72,   0 },
      { 184,  71,   0 },
      { 185,  70,   0 },
      { 186,  69,   0 },
      { 187,  68,   0 },
      { 188,  67,   0 },
      { 189,  66,   0 },
      { 190,  65,   0 },
      { 191,  64,   0 },
      { 192,  63,   0 },
      { 193,  62,   0 },
      { 194,  61,   0 },
      { 195,  60,   0 },
      { 196,  59,   0 },
      { 197,  58,   0 },
      { 198,  57,   0 },
      { 199,  56,   0 },
      { 200,  55,   0 },
      { 201,  54,   0 },
      { 202,  53,   0 },
      { 203,  52,   0 },
      { 204,  51,   0 },
      { 205,  50,   0 },
      { 206,  49,   0 },
      { 207,  48,   0 },
      { 208,  47,   0 },
      { 209,  46,   0 },
      { 210,  45,   0 },
      { 211,  44,   0 },
      { 212,  43,   0 },
      { 213,  42,   0 },
      { 214,  41,   0 },
      { 215,  40,   0 },
      { 216,  39,   0 },
      { 217,  38,   0 },
      { 218,  37,   0 },
      { 219,  36,   0 },
      { 220,  35,   0 },
      { 221,  34,   0 },
      { 222,  33,   0 },
      { 223,  32,   0 },
      { 224,  31,   0 },
      { 225,  30,   0 },
      { 226,  29,   0 },
      { 227,  28,   0 },
      { 228,  27,   0 },
      { 229,  26,   0 },
      { 230,  25,   0 },
      { 231,  24,   0 },
      { 232,  23,   0 },
      { 233,  22,   0 },
      { 234,  21,   0 },
      { 235,  20,   0 },
      { 236,  19,   0 },
      { 237,  18,   0 },
      { 238,  17,   0 },
      { 239,  16,   0 },
      { 240,  15,   0 },
      { 241,  14,   0 },
      { 242,  13,   0 },
      { 243,  12,   0 },
      { 244,  11,   0 },
      { 245,  10,   0 },
      { 246,   9,   0 },
      { 247,   8,   0 },
      { 248,   7,   0 },
      { 249,   6,   0 },
      { 250,   5,   0 },
      { 251,   4,   0 },
      { 252,   3,   0 },
      { 253,   2,   0 },
      { 254,   1,   0 },
      { 255,   0,   0 } // red
   };

   if (max == min)
      return makeColor(rgb[0][0], rgb[0][1], rgb[0][2]);
   if (max < min)
      std::swap(min,max);
   value = value < min ? min : value > max ? max : value;

   int n = ncolors*(value-min)/(max-min);
   n = n < 0 ? 0 : n > ncolors-1 ? ncolors-1 : n;

   return makeColor(rgb[n][0], rgb[n][1], rgb[n][2]);
} // blue2red


// -----------------------------------------------------------------------------
// Some custom colors
// -----------------------------------------------------------------------------

// color::custom::
namespace custom {
   inline const std::string
   red    = makeColor( 240,  40,  80 ),
   yellow = makeColor( 220, 220,  40 ),
   green  = makeColor(  20, 200, 120 ),
   blue   = makeColor(  40, 160, 240 ),
   purple = makeColor( 142, 110, 202 ),
   brown  = makeColor( 136,  68,  32 ),
   teal   = makeColor(   0, 128, 128 );

   // color::custom::faded::
   namespace faded {
      inline const std::string
      red    = makeColor( (240+128)/2, ( 40+128)/2, ( 80+128)/2 ),
      yellow = makeColor( (220+128)/2, (220+128)/2, ( 40+128)/2 ),
      green  = makeColor( ( 20+128)/2, (200+128)/2, (120+128)/2 ),
      blue   = makeColor( ( 40+128)/2, (160+128)/2, (240+128)/2 ),
      purple = makeColor( (142+128)/2, (110+128)/2, (202+128)/2 ),
      brown  = makeColor( (136+128)/2, ( 68+128)/2, ( 32+128)/2 );
   }

   inline const std::string
   black = makeColor(   0,   0,   0 ),
   gray  = makeColor( 128, 128, 128 ),
   white = makeColor( 255, 255, 255 );
}


// -----------------------------------------------------------------------------
// For Component prettyprinting
// Non-const, so you can change them if they don't work well with your window's
// color scheme, or if you just prefer something else. All of the following are
// in color::. The empty string, "", means no special color treatment, so that
// you'll get the text color your terminal already uses.
// -----------------------------------------------------------------------------

// Component labels, and their begin and end curly braces
inline std::string component = custom::purple;
inline std::string brace = component;

// General labels, and the colon separator between it and the value
inline std::string label = custom::blue;
inline std::string colon = label;

// Vector labels, and their begin and end square brackets
inline std::string vector = custom::green;
inline std::string bracket = vector;

// General values
inline std::string value = custom::red;

// General comments that the prettyprinter creates
inline std::string comment = custom::teal;

// Re: data nodes
namespace data {
   // Comments that appear in a Component.comment vector<string>.
   inline std::string comment = custom::yellow;
   // Strings and vectors in data nodes. Emphasis: only strings and vectors
   // specifically in DATA NODES, not those appearing in other ways.
   inline std::string string  = custom::white;
   inline std::string vector  = custom::white;
}

// If an object is optional or GNDStk::Defaulted, the color for its label (but
// not for its braces, brackets, or colon separator, where applicable), or for
// its value, can be modified by using the following.
namespace optional {
   inline std::string component = custom::faded::purple;
   inline std::string label     = custom::faded::blue;
   inline std::string vector    = custom::faded::green;
   inline std::string value     = custom::faded::red;
}


// -----------------------------------------------------------------------------
// simple
// Set the color strings to use simple ANSI colors.
// These may work on your terminal if full RGB terminal-text colors don't.
// -----------------------------------------------------------------------------

inline void simple()
{
   // Shading isn't compatible with *simple* coloring.
   shades = false;

   // Note: the given values seemed to work reasonably well on terminal
   // applications we tried. One such app, in particular, was "terminator"
   // on a Linux platform. We like terminator - it allows a single terminal
   // window to be split, recursively, horizontally or vertically, allowing
   // someone to run multiple logically-related codes on different command
   // prompts, within the same overall window on their screen.) We noticed,
   // however, that terminator prints all of the basic ANSI "bold" colors
   // not just colored, but *underlined* as well. So, we avoided using bold
   // colors, as we found underlines to be more distracting than helpful.

   component = plain::magenta;
   brace     = component;
   label     = plain::blue;
   colon     = label;
   vector    = plain::green;
   bracket   = vector;
   value     = plain::red;
   comment   = "";

   data::comment = plain::yellow;
   data::string  = plain::white;
   data::vector  = plain::white;

   optional::component = component;
   optional::label     = label;
   optional::vector    = vector;
   optional::value     = value;
}

} // namespace color
