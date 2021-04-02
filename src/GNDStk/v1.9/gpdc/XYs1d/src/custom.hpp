private:

  /* additional fields */
  std::vector< double > x_;
  std::vector< double > y_;

  /* auxiliary functions */
  static std::vector< Float64 >
  flattenPoints( const std::vector< Float64 >& x,
                 const std::vector< Float64 >& y ) {

    std::vector< Float64 > list;
    list.reserve( 2 * x.size() );

    // verify size
    if ( x.size() != y.size() ) {

      log::error( "The x and y values for the XYs1d are not of the same size" );
      log::info( "Found x size: {}", x.size() );
      log::info( "Found y size: {}", y.size() );
      throw std::exception();
    }

    unsigned int size = x.size();
    for ( unsigned int i = 0; i < size; ++i ) {

      list.push_back( x[i] );
      list.push_back( y[i] );
    }
    return list;
  }

public:

  /* custom construct function */
  void construct() {

    // verify size
    if ( this->values().values().size() % 2 != 0 ) {

      log::error( "Expected an even number of values in the XYs1d values node" );
      log::info( "Found size: {}", this->values().values().size() );
      throw std::exception();
    }

    // construct the x and y vectors
    unsigned int number = this->values().values().size() / 2;
    for ( unsigned int i = 0; i < number; ++i ) {

      this->x_.push_back( this->values().values()[ 2 * i ] );
      this->y_.push_back( this->values().values()[ 2 * i + 1 ] );
    }
  }

  /**
   *  @brief Custom constructor with x and y values
   *
   */
  XYs1d( const std::string& label,
         const std::vector< double >& x, const std::vector< double >& y,
         const std::string& xLabel, const std::string& xUnit,
         const std::string& yLabel, const std::string& yUnit,
         Interpolation interpolation = Interpolation::linlin,
         std::optional<Integer32> index = std::nullopt,
         std::optional<Float64> outerDomainValue = std::nullopt ) :
    XYs1d( index, interpolation, std::make_optional( label ),
           outerDomainValue,
           Axes( { Axis( 0, yLabel, yUnit ),
                   Axis( 1, xLabel, xUnit ) } ),
           Values( flattenPoints( x, y ) ) ) {}
