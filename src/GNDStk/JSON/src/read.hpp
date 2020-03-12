
// -----------------------------------------------------------------------------
// read
// -----------------------------------------------------------------------------

// read(string)
bool read(const std::string &file)
{
   // calls read(istream) below
   std::ifstream ifs(file.c_str());
   return not read(ifs).fail();
}


// read(istream)
std::istream &read(std::istream &is)
{
   is >> doc;
   /*
   if (is.eof ()) std::cout << "eof"  << std::endl;
   if (is.bad ()) std::cout << "bad"  << std::endl;
   if (is.fail()) std::cout << "fail" << std::endl;
   */
   return is;
}
