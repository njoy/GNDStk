Values() = delete;

Values( std::vector< ValueType >&& values ):
  Node_t( { { "length", std::to_string( values.size() ) } } ),
  values_( std::move( values ) )
{ }

Values( std::vector< ValueType >&& values, 
        unsigned int start, unsigned int length ):
  Node_t( { { "length", std::to_string( length ) },
            { "start", std::to_string( start ) } } ),
  values_( std::move( values ) )
{ }
