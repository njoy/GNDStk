
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
template<allow ALLOW>
bool is_void(const child_t<void,ALLOW>)
{ return true; }

template<class TYPE, allow ALLOW, class CONVERTER>
bool is_void(const child_t<TYPE,ALLOW,CONVERTER>)
{ return false; }


// is_int(child_t)
template<allow ALLOW, class CONVERTER>
bool is_int(const child_t<int,ALLOW,CONVERTER>)
{ return true; }

template<class TYPE, allow ALLOW, class CONVERTER>
bool is_int(const child_t<TYPE,ALLOW,CONVERTER>)
{ return false; }


// is_float(child_t)
template<allow ALLOW, class CONVERTER>
bool is_float(const child_t<float,ALLOW,CONVERTER>)
{ return true; }

template<class TYPE, allow ALLOW, class CONVERTER>
bool is_float(const child_t<TYPE,ALLOW,CONVERTER>)
{ return false; }


// is_double(child_t)
template<allow ALLOW, class CONVERTER>
bool is_double(const child_t<double,ALLOW,CONVERTER>)
{ return true; }

template<class TYPE, allow ALLOW, class CONVERTER>
bool is_double(const child_t<TYPE,ALLOW,CONVERTER>)
{ return false; }


// is_converterA(child_t)
template<class TYPE, allow ALLOW>
bool is_converterA(const child_t<TYPE,ALLOW,converterA>)
{ return true; }

template<class TYPE, allow ALLOW>
bool is_converterA(const child_t<TYPE,ALLOW,converterB>)
{ return false; }


// is_converterB(child_t)
template<class TYPE, allow ALLOW>
bool is_converterB(const child_t<TYPE,ALLOW,converterB>)
{ return true; }

template<class TYPE, allow ALLOW>
bool is_converterB(const child_t<TYPE,ALLOW,converterA>)
{ return false; }


// is_one(child_t)
template<class TYPE, class CONVERTER>
bool is_one(const child_t<TYPE,allow::one,CONVERTER>)
{ return true; }

template<class TYPE, class CONVERTER>
bool is_one(const child_t<TYPE,allow::many,CONVERTER>)
{ return false; }


// is_many(child_t)
template<class TYPE, class CONVERTER>
bool is_many(const child_t<TYPE,allow::many,CONVERTER>)
{ return true; }

template<class TYPE, class CONVERTER>
bool is_many(const child_t<TYPE,allow::one,CONVERTER>)
{ return false; }



// ------------------------
// SCENARIO
// ------------------------

SCENARIO("Testing GNDStk child_t operators") {

   // ------------------------
   // -child_t
   // ------------------------

   GIVEN("A child_t<type,one|many,converter>") {
      child_t<char,allow::one, converterA> foo("foo");
      child_t<int, allow::many,converterB> bar("bar");
      WHEN("We apply operator-") {
         // both become <void>
         CHECK(is_void(-foo));
         CHECK(is_void(-bar));
      }
   }

   GIVEN("A child_t<void,one|many>") {
      child_t<void,allow::one > foo("foo");
      child_t<void,allow::many> bar("bar");
      WHEN("We apply operator-") {
         // both remain <void>
         CHECK(is_void(-foo));
         CHECK(is_void(-bar));
      }
   }

   // ------------------------
   // type/child_t
   // ------------------------

   GIVEN("A child_t<type,one|many,converter>") {
      child_t<char,allow::one, converterA> foo("foo");
      child_t<int, allow::many,converterB> bar("bar");
      WHEN("We apply type/child_t") {
         // change the type to the new one
         CHECK(is_float(float{}/foo));
         CHECK(is_double(double{}/bar));
      }
   }

   GIVEN("A child_t<void,one|many>") {
      child_t<void,allow::one > foo("foo");
      child_t<void,allow::many> bar("bar");
      WHEN("We apply type/child_t") {
         // change the type to the new one
         CHECK(is_float(float{}/foo));
         CHECK(is_double(double{}/bar));
      }
   }

   // ------------------------
   // child_t/converter
   // ------------------------

   GIVEN("A child_t<type,one|many,converter>") {
      child_t<char,  allow::one, converterA> foo("foo");
      child_t<int,   allow::many,converterB> bar("bar");
      child_t<float, allow::one            > one("one");
      child_t<double,allow::many           > two("two");
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
   // one(child_t)
   // ------------------------

   GIVEN("A child_t<void|type,one|many[,converter]>") {
      child_t<char,allow::one, converterA> a("a");
      child_t<int, allow::many,converterB> b("b");
      child_t<void,allow::one            > c("c");
      child_t<void,allow::many           > d("d");
      WHEN("We apply one(child_t)") {
         // one() downgrades to find::one
         CHECK(is_one(a.one()));
         CHECK(is_one(b.one()));
         CHECK(is_one(c.one()));
         CHECK(is_one(d.one()));
      }
   }

   // ------------------------
   // many(child_t)
   // ------------------------

   GIVEN("A child_t<void|type,one|many[,converter]>") {
      child_t<char,allow::one, converterA> a("a");
      child_t<int, allow::many,converterB> b("b");
      child_t<void,allow::one            > c("c");
      child_t<void,allow::many           > d("d");
      WHEN("We apply many(child_t)") {
         // many() upgrades to find::many
         CHECK(is_many(a.many()));
         CHECK(is_many(b.many()));
         CHECK(is_many(c.many()));
         CHECK(is_many(d.many()));
      }
   }

   // ------------------------
   // Try some combos
   // ------------------------

   GIVEN("Various child_t objects") {
      child_t<void,allow::one > voidone("voidone");
      child_t<void,allow::many> voidmany("voidmany");

      auto foo = (1.2/voidmany/converterA{}).one();
      CHECK(is_one(foo));
      CHECK(is_double(foo));
      CHECK(is_converterA(foo));
      CHECK(is_void(-foo));
      CHECK(is_one(-foo));

      auto bar = (100/voidone/converterB{}).many();
      CHECK(is_many(bar));
      CHECK(is_int(bar));
      CHECK(is_converterB(bar));
      CHECK(is_void(-bar));
      CHECK(is_many(-bar));
   }
}
