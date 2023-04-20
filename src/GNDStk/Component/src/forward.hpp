
/*
Remark about terminology.

Elsewhere in GNDStk, we often refer to objects of type Meta or Child as "keys".

However, in the context of classes generated by our code generator, and in
general when working with classes that derive from Component, we sometimes use
the term "key" to mean some kind of "lookup key".

Code that appears later in this file involves both of the above contexts. So,
in order to keep confusion to a minimum, we'll write "MC" or "mc" (where we
might otherwise write "KEY" or "key") when Meta/Child are involved, and KEY
or "key" where lookup keys are involved.

Optionally continue reading, if you care....

Example. Say that an object of class Element has a vector<Isotope>, where each
object of type Isotope contains an int called mass_number. In this scenario, the
code generator will create mechanisms by which we can look up a specific Isotope
in an Element's vector<Isotope>, given the wanted Isotope's mass_number.

We'll also get functionality, via functions called replace(), to look up and
replace an isotope, given a lookup key like mass_number. Here's an admittedly
very contrived example of how such a replace function might be called:

   // Helium!
   Element He("He",2); // element #2

   // Give it some Isotopes
   He += Isotope(2); // <== oops, Helium 2 doesn't really exist
   He += Isotope(4);

   // We meant to create Helium 3, not Helium 2, so let's replace the bad value
   He.isotope.replace(mass_number(2),Isotope(3));

The last line will search through He.isotope (a vector<Isotope>), find the
element (the Isotope) with mass_number == 2, and replace that entire Isotope
with an Isotope that has the correct mass_number. (While the above example is
very contrived, one could imagine a real-world example in which we look up an
object that's known to have faulty data, and replace it with a fixed object.)

The replace() function later in this file allows the last line of code, above,
to be rewritten with something shorter:

   // He.replace, not He.isotope.replace
   He.replace(mass_number(2),Isotope(3));

in the event that the code can determine, unambiguously, via some SFINAE
shenanigans, that we must mean He.isotope, not other member data that an
Element (like He) might happen to contain.

To make a long story short (glossing over the fact that the above story is
perhaps already somewhat long :-/), the term "key" will relate to the mass
number lookup here. Whereas, Meta/Child objects are involved in the process
of examining what metadatum and child-node member data appear in class Element,
this examination being to determine that He.isotope is intended.
*/


// -----------------------------------------------------------------------------
// Helpers
// -----------------------------------------------------------------------------

private:

// Matches
template<class FROM, class D = DERIVED>
static inline constexpr bool Matches =
   detail::MatchesExact <FROM,decltype(D::Keys().tup)>::count == 1 ||
   detail::MatchesViable<FROM,decltype(D::Keys().tup)>::count == 1;

// added
// MC = Meta or Child
template<class FROM, class MC>
bool added(
   const FROM &elem, const MC &mc,
   const bool exact, const size_t n
) {
   // Silence warnings that seem to crop up with some compilers, when neither
   // of the below constexpr ifs passes.
   (void)n;

   // Remark. The below conditional code (involving both runtime and constexpr
   // ifs) doesn't simplify in what may seem like obvious ways. Note that bool
   // exact is runtime, and came from looking over all types in the caller's
   // fold expression. For a given type from the fold expression, either or both
   // of the following constexpr ifs may fail, and their bodies not make sense
   // or not be something we'd necessarily want to call. (Specifically, if exact
   // and viable matches both == 1, and the viable match is found before the
   // exact one, we want to skip the [return setter] and wait for the exact.)
   using T = std::decay_t<decltype(Node{}(mc))>;
   if ( exact) if constexpr (detail::isMatchExact <FROM,T>::count)
      return setter(*(T *)links[n],elem), true;
   if (!exact) if constexpr (detail::isMatchViable<FROM,T>::count)
      return setter(*(T *)links[n],elem), true;
   return false;
}

// replaced
template<class KEY, class FROM, class MC>
bool replaced(
   const KEY &key, const FROM &elem, const MC &mc,
   const bool exact, const size_t n
) {
   using T = std::decay_t<decltype(Node{}(mc))>;
   if ( exact) if constexpr (detail::isMatchExact <FROM,T>::count)
      return getter(*(T *)links[n],key) = elem, true;
   if (!exact) if constexpr (detail::isMatchViable<FROM,T>::count)
      return getter(*(T *)links[n],key) = elem, true;
   return false;
}

public:


// -----------------------------------------------------------------------------
// add(element)
// -----------------------------------------------------------------------------

// add
template<class FROM, class = std::enable_if_t<Matches<FROM>>>
DERIVED &add(const FROM &elem)
{
   // match exact? (else viable, per SFINAE requirement)
   using TUP = decltype(Keys().tup);
   const bool exact = detail::MatchesExact<FROM,TUP>::count == 1;

   // scan until match
   std::apply(
      [this,&elem,exact](const auto &... mc) {
         size_t n = 0; bool found = false;
         ((found || (found = this->added(elem,mc,exact,n++))), ...);
      },
      Keys().tup
   );

   // done
   return derived();
}

// ()
template<class FROM, class = std::enable_if_t<Matches<FROM>>>
DERIVED &operator()(const FROM &elem) { return add(elem); }

// +=
template<class FROM, class = std::enable_if_t<Matches<FROM>>>
DERIVED &operator+=(const FROM &elem) { return add(elem); }


// -----------------------------------------------------------------------------
// replace(index/label/Lookup, element)
// -----------------------------------------------------------------------------

// replace
template<
   class KEY, class = detail::isLookupRefReturn_t<KEY>,
   class FROM, class = std::enable_if_t<Matches<FROM>>
>
DERIVED &replace(const KEY &key, const FROM &elem)
{
   // match exact? (else viable, per SFINAE requirement)
   using TUP = decltype(Keys().tup);
   const bool exact = detail::MatchesExact<FROM,TUP>::count == 1;

   // scan until match
   std::apply(
      [this,&key,&elem,exact](const auto &... mc) {
         size_t n = 0; bool found = false;
         ((found || (found = this->replaced(key,elem,mc,exact,n++))), ...);
      },
      Keys().tup
   );

   // done
   return derived();
}

// ()
template<
   class KEY, class = detail::isLookupRefReturn_t<KEY>,
   class FROM, class = std::enable_if_t<Matches<FROM>>
>
DERIVED &operator()(const KEY &key, const FROM &elem)
{
   return replace(key,elem);
}
