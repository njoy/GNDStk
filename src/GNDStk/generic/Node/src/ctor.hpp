Node()
try:
  Base( Base::makeMap() ),
  metadata_()
{
} catch( std::exception& ){
  Log::info( "Creation of generic::Node failed." );
  throw;
}


