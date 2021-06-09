private:

  static inline std::map< std::string, std::string > documentation = {

    { "", "A GNDS 1.9 basic container component: an axis with an index, label and\n"
          "optional unit\n\n"
          "This component in used in the axes node, which in turn is used in most\n"
          "functional containers." },
    { "constructor", "Initialise the axis component\n\n"
                     "Arguments:\n"
                     "    self    the axis component\n"
                     "    index   the index of the axis component\n"
                     "    label   the label of the axis component\n"
                     "    unit    the unit of the axis component\n" },
    { "index", "The index of the axis component" },
    { "label", "The label of the axis component" },
    { "unit", "The unit of the axis component" }
  };

public:

/**
 *  Customise the python binding help documentation
 */
static std::string help( const std::string& type = "" )
{

  try {

    return documentation.at( type );
  }
  catch ( ... ) {

    return "No help information available";
  }
}
