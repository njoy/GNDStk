
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


// is_void(Child)
template<Allow ALLOW>
bool is_void(const Child<void,ALLOW>)
{ return true; }

template<class TYPE, Allow ALLOW, class CONVERTER>
bool is_void(const Child<TYPE,ALLOW,CONVERTER>)
{ return false; }


// is_int(Child)
template<Allow ALLOW, class CONVERTER>
bool is_int(const Child<int,ALLOW,CONVERTER>)
{ return true; }

template<class TYPE, Allow ALLOW, class CONVERTER>
bool is_int(const Child<TYPE,ALLOW,CONVERTER>)
{ return false; }


// is_float(Child)
template<Allow ALLOW, class CONVERTER>
bool is_float(const Child<float,ALLOW,CONVERTER>)
{ return true; }

template<class TYPE, Allow ALLOW, class CONVERTER>
bool is_float(const Child<TYPE,ALLOW,CONVERTER>)
{ return false; }


// is_double(Child)
template<Allow ALLOW, class CONVERTER>
bool is_double(const Child<double,ALLOW,CONVERTER>)
{ return true; }

template<class TYPE, Allow ALLOW, class CONVERTER>
bool is_double(const Child<TYPE,ALLOW,CONVERTER>)
{ return false; }


// is_converterA(Child)
template<class TYPE, Allow ALLOW>
bool is_converterA(const Child<TYPE,ALLOW,converterA>)
{ return true; }

template<class TYPE, Allow ALLOW>
bool is_converterA(const Child<TYPE,ALLOW,converterB>)
{ return false; }


// is_converterB(Child)
template<class TYPE, Allow ALLOW>
bool is_converterB(const Child<TYPE,ALLOW,converterB>)
{ return true; }

template<class TYPE, Allow ALLOW>
bool is_converterB(const Child<TYPE,ALLOW,converterA>)
{ return false; }


// is_one(Child)
template<class TYPE, class CONVERTER>
bool is_one(const Child<TYPE,Allow::one,CONVERTER>)
{ return true; }

template<class TYPE, class CONVERTER>
bool is_one(const Child<TYPE,Allow::many,CONVERTER>)
{ return false; }


// is_many(Child)
template<class TYPE, class CONVERTER>
bool is_many(const Child<TYPE,Allow::many,CONVERTER>)
{ return true; }

template<class TYPE, class CONVERTER>
bool is_many(const Child<TYPE,Allow::one,CONVERTER>)
{ return false; }



// ------------------------
// SCENARIO
// ------------------------

SCENARIO("Testing GNDStk Child operators") {

   // ------------------------
   // -Child
   // ------------------------

   GIVEN("A Child<type,one/many,converter>") {
      Child<char,Allow::one, converterA> foo("foo");
      Child<int, Allow::many,converterB> bar("bar");
      WHEN("We apply operator-") {
         // both become <void>
         CHECK(is_void(-foo));
         CHECK(is_void(-bar));
      }
   }

   GIVEN("A Child<void,one/many>") {
      Child<void,Allow::one > foo("foo");
      Child<void,Allow::many> bar("bar");
      WHEN("We apply operator-") {
         // both remain <void>
         CHECK(is_void(-foo));
         CHECK(is_void(-bar));
      }
   }

   // ------------------------
   // ~Child
   // !Child
   // top()
   // top(bool)
   // ------------------------

   GIVEN("Some Child objects") {
      const Child<char,Allow::one, converterA> foo("foo");
      const Child<int, Allow::many,converterB> bar("bar");
      Child<void,Allow::one > one("one");
      one.top(true);
      Child<void,Allow::many> two("two");
      two.top(true);

      CHECK(!foo.top());
      CHECK(!bar.top());
      CHECK(one.top());
      CHECK(two.top());

      WHEN("We apply ~Child") {
         THEN("Top-level is enabled") {
            CHECK((~foo).top());
            CHECK((~bar).top());
            CHECK((~one).top());
            CHECK((~two).top());
         }
      }

      WHEN("We apply !Child") {
         THEN("Top-level is disabled") {
            CHECK(!(!foo).top());
            CHECK(!(!bar).top());
            CHECK(!(!one).top());
            CHECK(!(!two).top());
         }
      }
   }

   // ------------------------
   // type/Child
   // ------------------------

   GIVEN("A Child<type,one/many,converter>") {
      Child<char,Allow::one, converterA> foo("foo");
      Child<int, Allow::many,converterB> bar("bar");
      WHEN("We apply type/Child") {
         // change the type to the new one
         CHECK(is_float(float{}/foo));
         CHECK(is_double(double{}/bar));
      }
   }

   GIVEN("A Child<void,one/many>") {
      Child<void,Allow::one > foo("foo");
      Child<void,Allow::many> bar("bar");
      WHEN("We apply type/Child") {
         // change the type to the new one
         CHECK(is_float(float{}/foo));
         CHECK(is_double(double{}/bar));
      }
   }

   // ------------------------
   // Child/converter
   // ------------------------

   GIVEN("A Child<type,one/many,converter>") {
      Child<char,  Allow::one, converterA> foo("foo");
      Child<int,   Allow::many,converterB> bar("bar");
      Child<float, Allow::one            > one("one");
      Child<double,Allow::many           > two("two");
      WHEN("We apply Child/converter") {
         // change the converter as given
         CHECK(is_converterB(foo/converterB{}));
         CHECK(is_converterA(bar/converterA{}));
         CHECK(is_converterA(one/converterA{}));
         CHECK(is_converterB(two/converterB{}));
      }
   }

   // Note: /converter is not applicable for Child<void>

   // ------------------------
   // one(Child)
   // ------------------------

   GIVEN("A Child<void/type,one/many[,converter]>") {
      Child<char,Allow::one, converterA> a("a");
      Child<int, Allow::many,converterB> b("b");
      Child<void,Allow::one            > c("c");
      Child<void,Allow::many           > d("d");
      WHEN("We apply one(Child)") {
         // one() downgrades to find::one
         CHECK(is_one(a.one()));
         CHECK(is_one(b.one()));
         CHECK(is_one(c.one()));
         CHECK(is_one(d.one()));
      }
   }

   // ------------------------
   // many(Child)
   // ------------------------

   GIVEN("A Child<void/type,one/many[,converter]>") {
      Child<char,Allow::one, converterA> a("a");
      Child<int, Allow::many,converterB> b("b");
      Child<void,Allow::one            > c("c");
      Child<void,Allow::many           > d("d");
      WHEN("We apply many(Child)") {
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

   GIVEN("Various Child objects") {
      Child<void,Allow::one > voidone("voidone");
      Child<void,Allow::many> voidmany("voidmany");

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
