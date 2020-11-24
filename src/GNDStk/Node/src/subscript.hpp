
// -----------------------------------------------------------------------------
// DISCUSSION
// -----------------------------------------------------------------------------

/*
Node's subscript operators, operator[], complement its call operators, but with
some crucial differences.

The generalized call operators, operator(), allow for any number of arguments,
where the arguments (generally child_t and possibly meta_t at the end, with some
caveats) represent a path down which to follow, in the node, to get to some
final child node or metadatum that should be retrieved. Unless the final value
is retrieved with a <void> child_t or meta_t - meaning raw form - a conversion
to some stipulated type is applied. In the latter case the result is necessarily
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
must split off the "last argument":

   // yes! :-)
   node(A,B,C)[D] = 10; // yay, does what we want!

That's easy, and of course if we'd dug down to the A,B,C node already, it means
just a plain old [] call:

   auto abc = node(A,B,C);
   abc[D] = 10; // <== like this

One might ask: If we can trick out the [] operator to produce an lvalue, so as
to allow for the assignment, then why didn't we just do the same thing for the
call operator? That is, couldn't operator() have gotten the same treatment we
gave to operator[], so that having the latter isn't necessary?

The answer is the infamous "yes, BUT" - and that's a big "but." Consider our
bracket-based construct,

   node(A,B,C)[D]

or equivalently abc[D] as in the second working example. For this to be usable
as an lvalue, and with the effect we want to achieve, it can't simply be an int,
like the superficially similar "node(A,B,C,D)" construct. Rather, it must be
some sort of "smart object" that retains information about (1) the location of
the internal raw std::string metadatum value that we wish to change; and (2) D's
converter from int to std::string. Armed with this information, the smart object
can then have an assignment operator, operator=, that (1) accepts a right-hand
side value (10, in our example), applies D's conversion from int to std::string,
and finally places the std::string into the internal metadata storage.

Again, though, why couldn't we have done that with the call operator? Well, we
could have, but with some unpleasant surprises. With our existing call operator,
you can write either of the following and get the expected result:

   int i = node(A,B,C,D);
   auto j = node(A,B,C,D); // j is an int :-)

The right-hand side produces an int. Not something that's merely convertible to
an int, but a hard int. So, "auto" in the second line evaluates as you'd expect.

Consider, however the bracket form:

   int k = node(A,B,C)[D]; // ok, RHS is in fact convertible to int
   auto L = node(A,B,C)[D]; // um, well... :-/

Surprise! The second expression may compile, but "auto" doesn't give an int -
as a user would probably anticipate it would. Instead, it gives an unexpected
type: that of the smart object we spoke of. The object that stores information
that we need in order for it to behave as an lvalue.

The smart object produced by operator[] is equipped with assignment from, and
conversion to, both the raw metadatum type std::string, and the type (here, int)
that's encoded in the meta_t object. (Recall that D in our examples here is a
meta_t<int>.) So, one *could* write this:

   auto L = int(node(A,B,C)[D]); // int(...) forces auto to be int

However, we don't want to require that users deploy additional syntactic fluff
in order for the result of a query to behave, type-wise, as expected.

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

// The <void> cases are special and can just fall back on operator(), which
// gives [const] std::string *reference* (thus lvalue if non-const) already.


// ------------------------
// <void>
// ------------------------

// <void> const
const std::string &operator[](const meta_t<void> &kwd) const
{
   return (*this)(kwd);
}

// <void>
std::string &operator[](const meta_t<void> &kwd)
{
   return (*this)(kwd);
}


// ------------------------
// <TYPE>
// ------------------------

// <TYPE> const
template<class TYPE, class CONVERTER>
auto operator[](const meta_t<TYPE,CONVERTER> &kwd) const
{
   // meta_ref<CONST=true>, in contrast to meta_ref<CONST=false>, dispenses
   // with the assignment operators of the latter class, for obvious reasons.
   // You can still use the result of this function as an rvalue, though, and
   // it has the same conversion operators that meta_ref<CONST=false> has.
   return detail::meta_ref<Node,true, TYPE,CONVERTER>(kwd,*this);
}

// <TYPE>
template<class TYPE, class CONVERTER>
auto operator[](const meta_t<TYPE,CONVERTER> &kwd)
{
   return detail::meta_ref<Node,false,TYPE,CONVERTER>(kwd,*this);
}



// -----------------------------------------------------------------------------
// node[child_t]
// -----------------------------------------------------------------------------

/*
For now, we won't make or use our lvalue-enabling class, child_ref, for the
case of allow::many, because it isn't clear what semantics we'd want when the
lvalue represents a container of some kind. Say, for example, that we're in
an <axes> node n, and wrote:

   n[axis];

where axis (not axes) is of course an allow::many. The call operator analog,

   n(axis)

returns a container (default std::vector) of nodes. We could have child_ref in
this case contain, for example, a std::vector<std::reference_wrapper<node>>,
or even just a std::vector<node*>. As an lvalue, though, what would assignment
mean? Replace each container element, requiring that the assignment's RHS has
the same container size? Remove all the existing axis nodes of the parent node,
completely replacing them with the nodes in the assignment's RHS? Until/unless
we decide what's best, I'll have operator[] for allow::many child_t objects do
what operator() does. So, fow now: defined, but not usable as an lvalue.

Note: for now, eight cases are written separately:

   - <void> or <TYPE>
   - const or non-const
   - allow::one or allow::many

in order to avoid overload ambiguities. If and when we make a viable child_ref
for allow::many, we can probably reduce this to four (two <void>, two <TYPE>).
*/


// ------------------------
// <void>
// ------------------------

// We'll write decltype(auto) everywhere here, so that return types won't need
// to be changed if and when we can fold allow::one and allow::many together.

// <void> const
// The return type will be const Node & or std::vector<Node>,
// depending on whether ALLOW is allow::one or allow::many.
template<class FILTER>
decltype(auto) operator[](
   const child_t<void,allow::one,void,FILTER> &kwd
) const {
   // std::cout << "case 1" << std::endl;
   return (*this)(kwd);
}

template<class FILTER>
decltype(auto) operator[](
   const child_t<void,allow::many,void,FILTER> &kwd
) const {
   // std::cout << "case 2" << std::endl;
   return (*this)(kwd);
}

// <void>
// The return type will be Node & or std::vector<Node>,
// depending on whether ALLOW is allow::one or allow::many.
template<class FILTER>
decltype(auto) operator[](
   const child_t<void,allow::one,void,FILTER> &kwd
) {
   // std::cout << "case 3" << std::endl;
   return (*this)(kwd);
}

template<class FILTER>
decltype(auto) operator[](
   const child_t<void,allow::many,void,FILTER> &kwd
) {
   // std::cout << "case 4" << std::endl;
   return (*this)(kwd);
}


// ------------------------
// <TYPE>
// ------------------------

// <TYPE> const
template<class TYPE, class CONVERTER, class FILTER>
auto operator[](const child_t<TYPE,allow::one,CONVERTER,FILTER> &kwd) const
{
   // std::cout << "case 5" << std::endl;
   // Comment similar to the one for the meta_t analog of this function
   return detail::child_ref<
      Node, true,
      TYPE, allow::one, CONVERTER, FILTER
   >(kwd,*this);
}

template<class TYPE, class CONVERTER, class FILTER>
auto operator[](const child_t<TYPE,allow::many,CONVERTER,FILTER> &kwd) const
{
   // std::cout << "case 6" << std::endl;
   return (*this)(kwd);
}

// <TYPE>
template<class TYPE, class CONVERTER, class FILTER>
auto operator[](const child_t<TYPE,allow::one,CONVERTER,FILTER> &kwd)
{
   // std::cout << "case 7" << std::endl;
   return detail::child_ref<
      Node, false,
      TYPE, allow::one, CONVERTER, FILTER
   >(kwd,*this);
}

template<class TYPE, class CONVERTER, class FILTER>
auto operator[](const child_t<TYPE,allow::many,CONVERTER,FILTER> &kwd)
{
   // std::cout << "case 8" << std::endl;
   return (*this)(kwd);
}
