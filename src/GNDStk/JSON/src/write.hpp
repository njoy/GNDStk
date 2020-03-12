
// -----------------------------------------------------------------------------
// write
// -----------------------------------------------------------------------------

// write(string)
bool write(const std::string &file) const
{
   // calls write(ostream) below
   std::ofstream ofs(file.c_str());
   return not write(ofs).fail();
}


// write(ostream)
std::ostream &write(std::ostream &os) const
{
   // intentional: no << std::endl
   os << std::setw(indent) << doc;
   return os;
}
