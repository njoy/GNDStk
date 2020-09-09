
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


// is_void(child_t)
template<find FIND>
bool is_void(const child_t<void,FIND>)
{ return true; }

template<class TYPE, find FIND, class CONVERTER>
bool is_void(const child_t<TYPE,FIND,CONVERTER>)
{ return false; }


// is_int(child_t)
template<find FIND, class CONVERTER>
bool is_int(const child_t<int,FIND,CONVERTER>)
{ return true; }

template<class TYPE, find FIND, class CONVERTER>
bool is_int(const child_t<TYPE,FIND,CONVERTER>)
{ return false; }


// is_float(child_t)
template<find FIND, class CONVERTER>
bool is_float(const child_t<float,FIND,CONVERTER>)
{ return true; }

template<class TYPE, find FIND, class CONVERTER>
bool is_float(const child_t<TYPE,FIND,CONVERTER>)
{ return false; }


// is_double(child_t)
template<find FIND, class CONVERTER>
bool is_double(const child_t<double,FIND,CONVERTER>)
{ return true; }

template<class TYPE, find FIND, class CONVERTER>
bool is_double(const child_t<TYPE,FIND,CONVERTER>)
{ return false; }


// is_converterA(child_t)
template<class TYPE, find FIND>
bool is_converterA(const child_t<TYPE,FIND,converterA>)
{ return true; }

template<class TYPE, find FIND>
bool is_converterA(const child_t<TYPE,FIND,converterB>)
{ return false; }


// is_converterB(child_t)
template<class TYPE, find FIND>
bool is_converterB(const child_t<TYPE,FIND,converterB>)
{ return true; }

template<class TYPE, find FIND>
bool is_converterB(const child_t<TYPE,FIND,converterA>)
{ return false; }


// is_one(child_t)
template<class TYPE, class CONVERTER>
bool is_one(const child_t<TYPE,find::one,CONVERTER>)
{ return true; }

template<class TYPE, class CONVERTER>
bool is_one(const child_t<TYPE,find::all,CONVERTER>)
{ return false; }


// is_all(child_t)
template<class TYPE, class CONVERTER>
bool is_all(const child_t<TYPE,find::all,CONVERTER>)
{ return true; }

template<class TYPE, class CONVERTER>
bool is_all(const child_t<TYPE,find::one,CONVERTER>)
{ return false; }



// ------------------------
// SCENARIO
// ------------------------

SCENARIO("Testing GNDStk child_t operators") {

   // ------------------------
   // -child_t
   // ------------------------

   GIVEN("A child_t<type,one|all,converter>") {
      child_t<char,find::one,converterA> foo("foo");
      child_t<int, find::all,converterB> bar("bar");
      WHEN("We apply operator-") {
         // both become <void>
         CHECK(is_void(-foo));
         CHECK(is_void(-bar));
      }
   }

   GIVEN("A child_t<void,one|all>") {
      child_t<void,find::one> foo("foo");
      child_t<void,find::all> bar("bar");
      WHEN("We apply operator-") {
         // both remain <void>
         CHECK(is_void(-foo));
         CHECK(is_void(-bar));
      }
   }

   // ------------------------
   // type/child_t
   // ------------------------

   GIVEN("A child_t<type,one|all,converter>") {
      child_t<char,find::one,converterA> foo("foo");
      child_t<int, find::all,converterB> bar("bar");
      WHEN("We apply type/child_t") {
         // change the type to the new one
         CHECK(is_float(float{}/foo));
         CHECK(is_double(double{}/bar));
      }
   }

   GIVEN("A child_t<void,one|all>") {
      child_t<void,find::one> foo("foo");
      child_t<void,find::all> bar("bar");
      WHEN("We apply type/child_t") {
         // change the type to the new one
         CHECK(is_float(float{}/foo));
         CHECK(is_double(double{}/bar));
      }
   }

   // ------------------------
   // child_t/converter
   // ------------------------

   GIVEN("A child_t<type,one|all,converter>") {
      child_t<char,  find::one,converterA> foo("foo");
      child_t<int,   find::all,converterB> bar("bar");
      child_t<float, find::one           > one("one");
      child_t<double,find::all           > two("two");
      WHEN("We apply child_t/converter") {
         // change the converter as given
         CHECK(is_converterB(foo/converterB{}));
         CHECK(is_converterA(bar/converterA{}));
         CHECK(is_converterA(one/converterA{}));
         CHECK(is_converterB(two/converterB{}));
      }
   }

   // Note: /converter is not applicable for child_t<void>

   // ------------------------
   // child_t++, child_t--
   // ------------------------

   GIVEN("A child_t<void|type,one|all[,converter]>") {
      child_t<char,find::one,converterA> a("a");
      child_t<int, find::all,converterB> b("b");
      child_t<void,find::one           > c("c");
      child_t<void,find::all           > d("d");
      WHEN("We apply child_t++") {
         // ++ upgrades to all
         CHECK(is_all(a++));
         CHECK(is_all(b++));
         CHECK(is_all(c++));
         CHECK(is_all(d++));
      }
   }

   GIVEN("A child_t<void|type,one|all[,converter]>") {
      child_t<char,find::one,converterA> a("a");
      child_t<int, find::all,converterB> b("b");
      child_t<void,find::one           > c("c");
      child_t<void,find::all           > d("d");
      WHEN("We apply child_t--") {
         // -- downgrades to one
         CHECK(is_one(a--));
         CHECK(is_one(b--));
         CHECK(is_one(c--));
         CHECK(is_one(d--));
      }
   }

   // ------------------------
   // Try some combos
   // ------------------------

   GIVEN("Various child_t objects") {
      child_t<void,find::one> voidone("voidone");
      child_t<void,find::all> voidall("voidall");
      auto foo = (100/voidone/converterA{})++;
      auto bar = (1.2/voidall/converterB{})--;
      CHECK(is_int(foo));
      CHECK(is_all(foo));
      CHECK(is_converterA(foo));
      CHECK(is_double(bar));
      CHECK(is_one(bar));
      CHECK(is_converterB(bar));
      CHECK(is_void(-foo));
      CHECK(is_all(-foo));
      CHECK(is_void(-bar));
      CHECK(is_one(-bar));
   }
}
