private:

  static inline std::map< std::string, std::string > documentation = {

    { "", "A GNDS basic component: a list of values\n\n"
          "This component is used in the nodes like XYs1D or the grid node." },
    { "constructor", "Initialise the values component\n\n"
                     "Arguments:\n"
                     "    self         the values component\n"
                     "    values       the values\n"
                     "    start        the starting index of the values\n"
                     "    value_type   the value type\n" },
    { "length", "The length of the values" },
    { "start", "The starting index of the values (default = 0)" },
    { "value_type", "The value type (default = 'Float64')" },
    { "doubles", "The underlying values" }
  };

  /**
   *  Custom construct function
   */
  void construct() {

    if ( this->length() == std::nullopt ) {

      this->length( this->size() + this->start() );
    }

    if ( this->length() != this->size() + this->start() ) {

      log::error( "Inconsistent size for \"values\" array" );
      log::info( "start: {}", this->start() );
      log::info( "length: {}", this->length().value() );
      log::info( "number values: {}", this->size() );
      throw std::exception();
    }
  }

  /**
   *  Custom construct function
   */
  void construct( const Values& ) {

    this->construct();
  }

  /**
   *  Custom construct function
   */
  void construct( const Node& ) {

    this->construct();
  }

public:

  template < typename T,
             typename = typename std::enable_if< std::is_arithmetic< T >::value, T >::type >
  Values( const std::optional< Integer32 >& length,
          const Integer32& start,
          const UTF8Text& valueType,
          const std::vector< T >& values ) : Values() {

    this->length( length );
    this->start( start );
    this->valueType( valueType );

    std::ostringstream out;
    for ( unsigned int i = 0; i < values.size(); ++i ) {

      if ( i != 0 ) {

        out << ' ';
      }
      out << values[i];
    }
    this->string( out.str() );

    bodyTextUpdate(content);
    construct();
  }

  template < typename T,
             typename = typename std::enable_if< std::is_arithmetic< T >::value, T >::type >
  Values( const std::vector< T >& values,
          const Integer32& start = 0,
          const UTF8Text& valueType = "Float64" ) :
    Values( values.size() + start, start, valueType, values ) {}

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
