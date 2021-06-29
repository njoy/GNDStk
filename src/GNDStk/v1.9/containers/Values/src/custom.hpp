private:

  static inline helpMap help = {

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
      log::info( "number of values: {}", this->size() );
      throw std::exception();
    }
  }

public:

  template < typename T,
             typename = std::enable_if_t< detail::isAlternative< std::vector<T>, variant_t > > >
  Values( const std::optional< Integer32 >& length,
          const Integer32& start,
          const UTF8Text& valueType,
          const std::vector< T >& values ) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
  {

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
    this->get(); // need to call get() to properly initialise the variant<vector>

    Component::finish(); // ensure that construct() gets called
  }

  template < typename T,
             typename = std::enable_if_t< detail::isAlternative< std::vector<T>, variant_t > > >
  Values( const std::vector< T >& values,
          const Integer32& start = 0,
          const UTF8Text& valueType = "Float64" ) :
    Values( values.size() + start, start, valueType, values ) {}
