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
             typename = typename std::enable_if< std::is_arithmetic< T >::value, T >::type >
  Values( const std::optional< Integer32 >& length,
          const Integer32& start,
          const UTF8Text& valueType,
          const std::vector< T >& values ) : /* Values() */
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
  {

    /*
    We generally do NOT want to use delegating constructors with Component-
    based classes. If we wrote Values() above, then that constructor calls
    Component::finish(). Component::finish(), in turn, first calls BodyText::
    pullFromDerived(content), which sets BodyText's length/start/valueType
    to those in this (the derived) class. That much is, I think, harmless
    here, but isn't needed yet. However, Component::finish() then calls
    construct(). Meaning the *custom* one, if we have one here, which we
    do. Under the circumstances, the above custom construct() may be called
    prematurely. It needs this->length() etc. to be set up reasonably, but
    that doesn't happen until right below here.

    Another potential source of errors in the test code: ALL constructors,
    not just these CUSTOM constructors, will end up calling the above
    construct() function - because it's there. length, start, and size()
    may not yet be consistent at that time. I think size() is the main
    problem: it's the vector size, which is 0 until someone does a get().
    The deferred evaluation of the vector - until a get() is called - was
    intentional, so that the extra work of creating a vector isn't done
    until, and unless, someone needs the vector. Perhaps I should, however,
    arrange for it to be done automatically, in Component::finish(), before
    any custom construct() is called...?

    Finally, in general I'm inclined to think that constructors, and any
    construct() functions we may have (which are meant to be run by
    constructors), should perhaps *make* things consistent rather than
    check that they *are* consistent already.  -- MFS
    */

    this->length( length );
    this->start( start );
    this->valueType( valueType );

    /*
    I now have a Component::finish(vector), which (among other things)
    uses BodyText's (Component's base) operator=(vector). However, it
    assumes that a vector you provide is complete - already with leading
    and trailing 0s if it needs them. If we think - as these custom
    constructors suggest - that users will wish to send partial vectors,
    without leading or trailing 0s that really belong there, then I
    should support that situation natively, so that the below conversion
    to string (and, later, probably back to a vector with 0s) isn't
    needed. That way, there's nothing lost in translation. :-)  --MFS
    */

    std::ostringstream out;
    for ( unsigned int i = 0; i < values.size(); ++i ) {

      if ( i != 0 ) {

        out << ' ';
      }
      out << values[i];
    }
    this->string( out.str() );
    this->get(); // need to call get() to properly initialise the variant<vector>

    // not needed; is in finish(): BodyText::pullFromDerived(content);
    Component::finish();
  }

  template < typename T,
             typename = typename std::enable_if< std::is_arithmetic< T >::value, T >::type >
  Values( const std::vector< T >& values,
          const Integer32& start = 0,
          const UTF8Text& valueType = "Float64" ) :
    Values( values.size() + start, start, valueType, values ) {}
// The delegating the constructor should be fine *here*;
// this is basically just a variation of the earlier custom constructor.
