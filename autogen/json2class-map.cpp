
// -----------------------------------------------------------------------------
// nameMap
// -----------------------------------------------------------------------------

const std::map<std::string,std::pair<std::string,std::string>> nameMap =
{
   // ----------------------   -----------            -----------------
   // In per.elementType       The                    A name to use
   // or in per.metadata's     appropriate            for the function
   // valueType defaultValue   C++ type               that returns them
   // ----------------------   -----------            -----------------

   // Described in the GNDS manual.
   // I'm not sure which of the several types that map to std::string can,
   // or would, appear in any GNDS specifications in such a way that we'd
   // need it here, but listing all "string-like" types shouldn't hurt.
   { "Integer32"          , { "int"                , "ints"        } },
   { "UInteger32"         , { "unsigned"           , "uints"       } },
   { "Float64"            , { "double"             , "doubles"     } },
   { "XMLName"            , { "std::string"        , "strings"     } },
   { "UTF8Text"           , { "std::string"        , "strings"     } },
   { "printableText"      , { "std::string"        , "strings"     } },
   { "quotedText"         , { "std::string"        , "strings"     } },
   { "tdText"             , { "std::string"        , "strings"     } },

   // We allow these as well.
   { "int"                , { "int"                , "ints"        } },
   { "unsigned"           , { "unsigned"           , "uints"       } },
   { "double"             , { "double"             , "doubles"     } },
   { "string"             , { "std::string"        , "strings"     } },
   { "std::string"        , { "std::string"        , "strings"     } },

   // Allow other sensible things.
   { "char"               , { "char"               , "chars"       } },
   { "signed char"        , { "signed char"        , "schars"      } },
   { "short"              , { "short"              , "shorts"      } },
   { "long"               , { "long"               , "longs"       } },
   { "long long"          , { "long long"          , "longlongs"   } },
   { "unsigned char"      , { "unsigned char"      , "uchars"      } },
   { "unsigned short"     , { "unsigned short"     , "ushorts"     } },
   { "unsigned int"       , { "unsigned"           , "uints"       } },
   { "unsigned long"      , { "unsigned long"      , "ulongs"      } },
   { "unsigned long long" , { "unsigned long long" , "ulonglongs"  } },
   { "float"              , { "float"              , "floats"      } },
   { "long double"        , { "long double"        , "longdoubles" } },
   { "quad"               , { "long double"        , "quads"       } }
};
