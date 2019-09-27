Node()
try:
  Node_t( Node_t::makeMap() ),
  metadata_()
{
} catch( std::exception& ){
  Log::info( "Creation of generic::Node failed." );
  throw;
}


