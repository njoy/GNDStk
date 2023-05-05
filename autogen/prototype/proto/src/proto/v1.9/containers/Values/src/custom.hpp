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
             typename = std::enable_if_t<detail::is_in_v<T,VariantOfScalars>>>
  Values( const std::optional< int >& length,
          const std::optional< int >& start,
          const std::optional< std::string >& valueType,
          const std::vector< T >& values ) :
      GNDSTK_COMPONENT(BlockData{}),
      valueType(this,defaults.valueType,valueType),
      start(this,defaults.start,start),
      length(this,length)
  {

    *this = values;
    Component::finish(); // ensure that construct() gets called
  }
