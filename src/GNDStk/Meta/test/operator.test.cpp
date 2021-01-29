
#include "catch.hpp"
#include "GNDStk.hpp"
using namespace njoy::GNDStk;


// converterA
struct converterA {
   template<class FROM, class TO>
   void operator()(const FROM &from, TO &to) const { convert(from,to); }
};

// converterB
struct converterB {
   template<class FROM, class TO>
   void operator()(const FROM &from, TO &to) const { convert(from,to); }
};


// is_void(Meta)
bool is_void(const Meta<void>)
{ return true; }

template<class TYPE, class CONVERTER>
bool is_void(const Meta<TYPE,CONVERTER>)
{ return false; }


// is_int(Meta)
template<class CONVERTER>
bool is_int(const Meta<int,CONVERTER>)
{ return true; }

template<class TYPE, class CONVERTER>
bool is_int(const Meta<TYPE,CONVERTER>)
{ return false; }


// is_float(Meta)
template<class CONVERTER>
bool is_float(const Meta<float,CONVERTER>)
{ return true; }

template<class TYPE, class CONVERTER>
bool is_float(const Meta<TYPE,CONVERTER>)
{ return false; }


// is_double(Meta)
template<class CONVERTER>
bool is_double(const Meta<double,CONVERTER>)
{ return true; }

template<class TYPE, class CONVERTER>
bool is_double(const Meta<TYPE,CONVERTER>)
{ return false; }


// is_converterA(Meta)
template<class TYPE>
bool is_converterA(const Meta<TYPE,converterA>)
{ return true; }

template<class TYPE>
bool is_converterA(const Meta<TYPE,converterB>)
{ return false; }


// is_converterB(Meta)
template<class TYPE>
bool is_converterB(const Meta<TYPE,converterB>)
{ return true; }

template<class TYPE>
bool is_converterB(const Meta<TYPE,converterA>)
{ return false; }



// ------------------------
// SCENARIO
// ------------------------

SCENARIO("Testing GNDStk Meta operators") {

   // ------------------------
   // -Meta
   // ------------------------

   GIVEN("A Meta<type,converter>") {
      Meta<char,converterA> foo("foo");
      WHEN("We apply operator-") {
         // it becomes <void>
         CHECK(is_void(-foo));
      }
   }

   GIVEN("A Meta<void>") {
      Meta<void> bar("bar");
      WHEN("We apply operator-") {
         // it remains <void>
         CHECK(is_void(-bar));
      }
   }

   // ------------------------
   // type/Meta
   // ------------------------

   GIVEN("A Meta<type,converter>") {
      Meta<int,converterB> bar("bar");
      WHEN("We apply type/Meta") {
         // change the type to the new one
         CHECK(is_float(float{}/bar));
         CHECK(is_double(double{}/bar));
      }
   }

   GIVEN("A Meta<void>") {
      Meta<void> foo("foo");
      WHEN("We apply type/Meta") {
         // change the type to the new one
         CHECK(is_float(float{}/foo));
         CHECK(is_double(double{}/foo));
      }
   }

   // ------------------------
   // Meta/converter
   // ------------------------

   GIVEN("A Meta<type,converter>") {
      Meta<char,converterA> foo("foo");
      Meta<float> bar("bar");
      WHEN("We apply Meta/converter") {
         // change the converter as given
         CHECK(is_converterB(foo/converterB{}));
         CHECK(is_converterA(bar/converterA{}));
      }
   }

   // Note: /converter is not applicable for Meta<void>

   // ------------------------
   // Try some combos
   // ------------------------

   GIVEN("Various Meta objects") {
      Meta<void> voidone("voidone");
      Meta<void> voidmany("voidmany");
      auto foo = 100 / voidone / converterA{};
      auto bar = 1.2 / voidmany/ converterB{};
      CHECK(is_int(foo));
      CHECK(is_converterA(foo));
      CHECK(is_double(bar));
      CHECK(is_converterB(bar));
      CHECK(is_void(-foo));
      CHECK(is_void(-bar));
   }
}
