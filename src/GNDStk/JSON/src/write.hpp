
// -----------------------------------------------------------------------------
// JSON::write()
// -----------------------------------------------------------------------------

// ------------------------
// write(ostream)
// ------------------------

std::ostream &write(std::ostream &os) const
{
   // intentional: no << std::endl
   os << std::setw(indent) << doc;

   // check for errors
   if (!os) {
      log::error("Problem during ostream << nlohmann::json");
      log::context("JSON::write(ostream)");
   }

   // done
   return os;
}


// ------------------------
// write(filename)
// ------------------------

bool write(const std::string &filename) const
{
   // open file
   std::ofstream ofs(filename.c_str());
   if (!ofs) {
      log::error(
         "Could not open file in call to JSON::write(filename=\"{}\")",
         filename
      );
      return false;
   }

   // write to stream
   write(ofs);
   if (ofs.fail()) {
      log::context("JSON::write(filename=\"{}\")", filename);
      return false;
   }

   // done
   return true;
}
