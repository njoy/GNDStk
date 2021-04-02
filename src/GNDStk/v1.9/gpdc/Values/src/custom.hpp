/**
 *  @brief Custom constructor
 *
 *  @param[in] values    the values of the node
 *  @param[in] start     the starting index (default = 0)
 */
Values( const std::vector< double >& values, unsigned int start = 0 ) :
 Values( std::nullopt, start, "Float64", values ) {}
