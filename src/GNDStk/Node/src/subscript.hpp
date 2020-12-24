
// -----------------------------------------------------------------------------
// Discussion
// -----------------------------------------------------------------------------

/*
Node's subscript operators, operator[], complement its call operators, but with
some crucial differences.

The generalized call operators, operator(), allow for any number of arguments,
where the arguments (generally child_t and possibly meta_t at the end, with some
caveats) represent a path down which to follow, in the node, to get to a final
child node or metadatum that should be retrieved. Unless the final value is
retrieved with a <void> child_t or meta_t - meaning raw form - a conversion to
some stipulated type is applied. In the latter case, the result is necessarily
returned by value, not by reference, and thus cannot be used as an lvalue.

So, for example, for child_t A, B, and C, and meta_t<int> D, we *cannot* write:

   // no! :-(
   node(A,B,C,D) = 10; // compiler error

because the left-hand side isn't an lvalue. It is, rather, a returned-by-value
int that became an int in the first place because D, being a meta_t<int>, caused
the internal raw std::string metadatum value (that's paired with node(A,B,C)'s
D metadata key) to be converted to an int.

The above then raises a question: how can we *set* some metadatum or child node,
as we clearly intend to above?

The answer: use [], our bracket operator. First, however, realize that C++ does
not, at present, allow operator[] to have multiple arguments. So, to use it, we
must split off the last parameter:

   // yes! :-)
   node(A,B,C)[D] = 10; // yay, does what we want!

That's easy, and of course if we'd dug down to the A,B,C node already, it would
involve just a plain old [] call:

   auto abc = node(A,B,C);
   abc[D] = 10; // <== like this

One might ask: If we can trick out the [] operator to produce an lvalue, so that
assignment is allowed, then why didn't we just do the same thing for the call
operator? That is, couldn't operator() have gotten the same treatment we gave to
operator[], so that having the latter isn't necessary?

The answer is the infamous "yes, BUT" - and that's a big "but." Consider our
bracket-based construct,

   node(A,B,C)[D]

or equivalently abc[D] as in our second working example. For this to be usable
as an lvalue, and with the effect we want to achieve, it can't simply be an int,
like the superficially similar "node(A,B,C,D)" construct. Rather, it must be
some sort of "smart object" that retains information about (1) the location of
the internal raw std::string metadatum value that we wish to change; and (2) D's
converter from int to std::string. Armed with this information, the smart object
can have an assignment operator, operator=, that (1) accepts a right-hand side
value (10, in our example), (2) applies D's conversion from int to std::string,
and (3) finally, places the std::string into the internal metadata value.

Again, though, why couldn't we have done that with the call operator? Well, we
could have, but with some unpleasant surprises. With our existing call operator,
you can write either of the following and get the expected result:

   int i = node(A,B,C,D);
   auto j = node(A,B,C,D); // j is an int :-)

The right-hand side produces an int. Not something that's merely convertible to
an int, but a hard int. So, "auto" in the second line evaluates as you'd expect.

Consider, however, the bracket form:

   int k = node(A,B,C)[D]; // ok, RHS is in fact convertible to int
   auto L = node(A,B,C)[D]; // um, well... :-/

Surprise! The second expression may compile, but "auto" doesn't give an int -
as a user would probably anticipate and want. Instead, it gives an unexpected
type: that of the smart object we spoke of. The object that stores information
that we need in order for it to behave as an lvalue.

The smart object produced by operator[] is equipped with assignment from, and
conversion to, both the raw metadatum type std::string, and the type (here, int)
that's encoded in the meta_t object. (Recall that D in our examples above is a
meta_t<int>.) So, one *could* write this:

   auto L = int(node(A,B,C)[D]); // the int(...) forces auto to be int

However, we don't want to require that users deploy additional syntactic fluff
just to force the result of a query to behave, type-wise, as expected.

CONCLUSION. Use our general call operator, operator(), for queries, and you'll
get results with expected and predictable types. Use operator[] instead if you
wish to produce lvalues, which allow you to write to - not just read from - a
(non-const) GNDStk tree or node. You can use operator[] as a "right-hand side"
too, just as you can with operator(), but should do so with the understanding
that it won't play well with "auto," or with similar auto-like processes such
as a compiler's determination of a function template parameter's type.
*/



// -----------------------------------------------------------------------------
// node[meta_t]
// -----------------------------------------------------------------------------

// ------------------------
// <void>
// ------------------------

// These cases are special and can just fall back on operator(), which
// gives [const] std::string reference (thus lvalue if non-const) already.

// <void> const
// Return type: const std::string &
const std::string &operator[](const meta_t<void> &kwd) const
{
   return (*this)(kwd);
}

// <void>
// Return type: std::string &
std::string &operator[](const meta_t<void> &kwd)
{
   return (*this)(kwd);
}


// ------------------------
// <TYPE>
// ------------------------

// meta_ref<CONST=true>, in contrast to meta_ref<CONST=false>, dispenses
// with the assignment operators of the latter class, for obvious reasons.
// You can still use the result of this function as an rvalue, though, and
// it has the same conversion operators that meta_ref<CONST=false> has.

// <TYPE> const
// Return type: meta_ref, knowing that what's "referenced" is const
template<class TYPE, class CONVERTER>
auto operator[](const meta_t<TYPE,CONVERTER> &kwd) const
{
   return detail::meta_ref<Node,true, TYPE,CONVERTER>(kwd,*this);
}

// <TYPE>
// Return type: meta_ref, knowing that what's "referenced" is non-const
template<class TYPE, class CONVERTER>
auto operator[](const meta_t<TYPE,CONVERTER> &kwd)
{
   return detail::meta_ref<Node,false,TYPE,CONVERTER>(kwd,*this);
}



// -----------------------------------------------------------------------------
// node[child_t]
// -----------------------------------------------------------------------------

// fixme We can probably do some consolidation of the last 6 of these 8 cases...

// ------------------------
// <void,one>
// const and non-const
// ------------------------

// These cases are special and can just fall back on operator(), which
// gives [const] Node reference (thus lvalue if non-const) already.

// Return type: const Node &
template<class FILTER>
decltype(auto) operator[](
   const child_t<void,allow::one,void,FILTER> &kwd
) const {
   return (*this)(kwd);
}

// Return type: Node &
template<class FILTER>
decltype(auto) operator[](
   const child_t<void,allow::one,void,FILTER> &kwd
) {
   return (*this)(kwd);
}


// ------------------------
// <TYPE,one>
// const and non-const
// ------------------------

// Return type: child_ref
template<class TYPE, class CONVERTER, class FILTER>
auto operator[](const child_t<TYPE,allow::one,CONVERTER,FILTER> &kwd) const
{
   return detail::child_ref<
      Node, true,
      TYPE, allow::one, CONVERTER, FILTER
   >(kwd,*this);
}

// Return type: child_ref
template<class TYPE, class CONVERTER, class FILTER>
auto operator[](const child_t<TYPE,allow::one,CONVERTER,FILTER> &kwd)
{
   return detail::child_ref<
      Node, false,
      TYPE, allow::one, CONVERTER, FILTER
   >(kwd,*this);
}


// ------------------------
// <void,many>
// const and non-const
// ------------------------

// Return type: child_ref
template<class FILTER>
decltype(auto) operator[](
   const child_t<void,allow::many,void,FILTER> &kwd
) const {
   return detail::child_ref<
      Node, true,
      void, allow::many, void, FILTER
   >(kwd,*this);
}

// Return type: child_ref
template<class FILTER>
decltype(auto) operator[](
   const child_t<void,allow::many,void,FILTER> &kwd
) {
   return detail::child_ref<
      Node, false,
      void, allow::many, void, FILTER
   >(kwd,*this);
}


// ------------------------
// <TYPE,many>
// const and non-const
// ------------------------

// Return type: child_ref
template<class TYPE, class CONVERTER, class FILTER>
auto operator[](const child_t<TYPE,allow::many,CONVERTER,FILTER> &kwd) const
{
   return detail::child_ref<
      Node, true,
      TYPE, allow::many, CONVERTER, FILTER
   >(kwd,*this);
}

// Return type: child_ref
template<class TYPE, class CONVERTER, class FILTER>
auto operator[](const child_t<TYPE,allow::many,CONVERTER,FILTER> &kwd)
{
   return detail::child_ref<
      Node, false,
      TYPE, allow::many, CONVERTER, FILTER
   >(kwd,*this);
}
