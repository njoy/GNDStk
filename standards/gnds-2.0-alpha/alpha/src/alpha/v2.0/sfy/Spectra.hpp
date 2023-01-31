
// THIS FILE WAS AUTOGENERATED!
// DO NOT MODIFY!

#ifndef ALPHA_V2_0_SFY_SPECTRA
#define ALPHA_V2_0_SFY_SPECTRA

#include "alpha/v2.0/sfy/Spectrum.hpp"

namespace alpha {
namespace v2_0 {
namespace sfy {

// -----------------------------------------------------------------------------
// sfy::
// class Spectra
// -----------------------------------------------------------------------------

class Spectra :
   public Component<sfy::Spectra>
{
   friend class Component;

   // ------------------------
   // For Component
   // ------------------------

   // Names: this namespace, this class, and a field/node of this type
   static auto NAMESPACE() { return "sfy"; }
   static auto CLASS() { return "Spectra"; }
   static auto FIELD() { return "spectra"; }

   // Core Interface multi-query to transfer information to/from Nodes
   static auto KEYS()
   {
      return
         // comment
         ++Child<std::string>(special::comment) / CommentConverter{} |

         // children
         ++Child<sfy::Spectrum>("spectrum")
      ;
   }

public:
   using Component::construct;

   // comment
   Field<std::vector<std::string>> comment{this};

   // children
   Field<std::vector<sfy::Spectrum>> spectrum{this};

   // ------------------------
   // Constructors
   // ------------------------

   #define GNDSTK_COMPONENT(blockdata) Component(blockdata, \
      this->comment, \
      this->spectrum)

   // default
   Spectra() :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish();
   }

   // from fields, comment excluded
   explicit Spectra(
      const wrapper<std::vector<sfy::Spectrum>> &spectrum
   ) :
      GNDSTK_COMPONENT(BlockData{}),
      spectrum(this,spectrum)
   {
      Component::finish();
   }

   // from node
   explicit Spectra(const Node &node) :
      GNDSTK_COMPONENT(BlockData{})
   {
      Component::finish(node);
   }

   // copy
   Spectra(const Spectra &other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,other.comment),
      spectrum(this,other.spectrum)
   {
      Component::finish(other);
   }

   // move
   Spectra(Spectra &&other) :
      GNDSTK_COMPONENT(other.baseBlockData()),
      comment(this,std::move(other.comment)),
      spectrum(this,std::move(other.spectrum))
   {
      Component::finish(other);
   }

   // ------------------------
   // Assignment operators
   // ------------------------

   Spectra &operator=(const Spectra &) = default;
   Spectra &operator=(Spectra &&) = default;

   // ------------------------
   // Custom functionality
   // ------------------------

   #include "alpha/v2.0/sfy/Spectra/src/custom.hpp"
   #undef GNDSTK_COMPONENT
}; // class Spectra

} // namespace sfy
} // namespace v2_0
} // namespace alpha

#endif
