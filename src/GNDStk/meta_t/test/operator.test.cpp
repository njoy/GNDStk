
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


// is_void(meta_t)
bool is_void(const meta_t<void>)
{ return true; }

template<class TYPE, class CONVERTER>
bool is_void(const meta_t<TYPE,CONVERTER>)
{ return false; }


// is_int(meta_t)
template<class CONVERTER>
bool is_int(const meta_t<int,CONVERTER>)
{ return true; }

template<class TYPE, class CONVERTER>
bool is_int(const meta_t<TYPE,CONVERTER>)
{ return false; }


// is_float(meta_t)
template<class CONVERTER>
bool is_float(const meta_t<float,CONVERTER>)
{ return true; }

template<class TYPE, class CONVERTER>
bool is_float(const meta_t<TYPE,CONVERTER>)
{ return false; }


// is_double(meta_t)
template<class CONVERTER>
bool is_double(const meta_t<double,CONVERTER>)
{ return true; }

template<class TYPE, class CONVERTER>
bool is_double(const meta_t<TYPE,CONVERTER>)
{ return false; }


// is_converterA(meta_t)
template<class TYPE>
bool is_converterA(const meta_t<TYPE,converterA>)
{ return true; }

template<class TYPE>
bool is_converterA(const meta_t<TYPE,converterB>)
{ return false; }


// is_converterB(meta_t)
template<class TYPE>
bool is_converterB(const meta_t<TYPE,converterB>)
{ return true; }

template<class TYPE>
bool is_converterB(const meta_t<TYPE,converterA>)
{ return false; }



// ------------------------
// SCENARIO
// ------------------------

SCENARIO("Testing GNDStk meta_t operators") {

   // ------------------------
   // -meta_t
   // ------------------------

   GIVEN("A meta_t<type,converter>") {
      meta_t<char,converterA> foo("foo");
      WHEN("We apply operator-") {
         // it becomes <void>
         CHECK(is_void(-foo));
      }
   }

   GIVEN("A meta_t<void>") {
      meta_t<void> bar("bar");
      WHEN("We apply operator-") {
         // it remains <void>
         CHECK(is_void(-bar));
      }
   }

   // ------------------------
   // type/meta_t
   // ------------------------

   GIVEN("A meta_t<type,converter>") {
      meta_t<int,converterB> bar("bar");
      WHEN("We apply type/meta_t") {
         // change the type to the new one
         CHECK(is_float(float{}/bar));
         CHECK(is_double(double{}/bar));
      }
   }

   GIVEN("A meta_t<void>") {
      meta_t<void> foo("foo");
      WHEN("We apply type/meta_t") {
         // change the type to the new one
         CHECK(is_float(float{}/foo));
         CHECK(is_double(double{}/foo));
      }
   }

   // ------------------------
   // meta_t/converter
   // ------------------------

   GIVEN("A meta_t<type,converter>") {
      meta_t<char,converterA> foo("foo");
      meta_t<float> bar("bar");
      WHEN("We apply meta_t/converter") {
         // change the converter as given
         CHECK(is_converterB(foo/converterB{}));
         CHECK(is_converterA(bar/converterA{}));
      }
   }

   // Note: /converter is not applicable for meta_t<void>

   // ------------------------
   // Try some combos
   // ------------------------

   GIVEN("Various meta_t objects") {
      meta_t<void> voidone("voidone");
      meta_t<void> voidmany("voidmany");
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
