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

    if ( this->length() != std::nullopt ) {

      if ( this->length() != this->size() + this->start() ) {

        log::error( "Inconsistent size for \"values\" array" );
        log::info( "start: {}", this->start() );
        log::info( "length: {}", this->length().value() );
        log::info( "number of values: {}", this->size() );
        throw std::exception();
      }
    }
  }

public:

  template < typename T,
             typename = std::enable_if_t<
                detail::isAlternative< T, VariantOfScalars > > >
  Values( const std::optional< Integer32 >& length,
          const std::optional< Integer32 >& start,
          const std::optional< UTF8Text >& valueType,
          const std::vector< T >& values ) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
  {

    if ( length ) this->length( length );
    if ( start ) this->start( start );
    if ( valueType ) this->valueType( valueType );
    this->get< std::vector< T > >() = values;

    Component::finish(); // ensure that construct() gets called
  }

  template < typename T,
             typename = std::enable_if_t<
                detail::isAlternative< T, VariantOfScalars > > >
  Values( const std::vector< T >& values ) :
    Values( std::nullopt, std::nullopt, std::nullopt, values ) {}
