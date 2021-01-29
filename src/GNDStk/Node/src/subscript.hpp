
// -----------------------------------------------------------------------------
// Discussion
// -----------------------------------------------------------------------------

/*
Node's subscript operators, operator[], complement its call operators, but with
some crucial differences.

The generalized call operators, operator(), allow for any number of arguments,
where the arguments (generally Child, and possibly Meta at the end, with some
caveats) represent a path down which to follow, in the node, to get to a final
child node or metadatum that should be retrieved. Unless the final value is
retrieved with a <void> Child or Meta - meaning raw form - a conversion to some
stipulated type is applied. In that case, the result is necessarily returned by
value, not by reference, and thus cannot be used as an lvalue.

So, for example, with Child A, B, and C, and Meta<int> D, we *cannot* write:

   // no! :-(
   node(A,B,C,D) = 10; // compiler error

because the left-hand side isn't an lvalue. It is, rather, a returned-by-value
int, because D, being a Meta<int>, caused the internal std::string metadatum
(that's paired with node(A,B,C)'s D metadata key) to be converted to an int.

The above raises a question: how can we *set* some metadatum or child node,
as we clearly intend to above?

The answer: use [], our bracket operator. First, however, realize that C++ does
not, at present, allow operator[] to have multiple arguments. So, to use it, we
split off the last parameter:

   // yes! :-)
   node(A,B,C)[D] = 10; // yay, does what we want!

That's easy, and of course if we'd dug down to the A,B,C node already, it would
involve a plain old [] call:

   auto abc = node(A,B,C);
   abc[D] = 10; // <== like this

One might ask: If we can trick out the [] operator to produce an lvalue, so that
assignment is allowed, then why didn't we just do the same thing for the call
operator? That is, couldn't operator() have gotten the same treatment, so that
having the latter isn't necessary?

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
conversion to, both the raw metadatum type (std::string), and the type (here,
int) that's encoded in the Meta object. (Recall that D in our examples above
is a Meta<int>.) So, one *could* write this:

   auto L = int(node(A,B,C)[D]); // int(...) forces auto to be int

However, we don't want to require that users deploy additional syntactic fluff
in order to force the result of a query to behave, type-wise, as expected.

CONCLUSION:

   - Use our general call operator, operator(), for queries, and you'll get
     results with expected and predictable types.

   - Use operator[] instead if you wish to produce lvalues, which allow you
     to write to - not just read from - a (non-const) GNDStk tree or node.

You can use operator[] as a "right-hand side" too, as you can with operator(),
but should do so with the understanding that it doesn't play well with "auto,"
or with auto-like processes such as a compiler's determination of a function
template parameter's type.
*/



// -----------------------------------------------------------------------------
// node[Meta]
// -----------------------------------------------------------------------------

// ------------------------
// <void>
// const and non-const
// ------------------------

// These cases are special and can use operator(), which already
// gives [const] std::string & (thus lvalue if non-const).

// Returns: const std::string &
const std::string &operator[](const Meta<void> &kwd) const
{
   return (*this)(kwd);
}

// Returns: std::string &
std::string &operator[](const Meta<void> &kwd)
{
   return (*this)(kwd);
}


// ------------------------
// <TYPE>
// const and non-const
// ------------------------

// Note: meta_ref<Node,true,...>, in contrast to meta_ref<Node,false,...>,
// dispenses with the assignment operators, for obvious reasons. You can
// still use the result of the const operator[] as an rvalue, though, and
// it has the same conversion operators that the non-const operator[] has.

// Returns: meta_ref, knowing it references const
template<class TYPE, class CONVERTER>
auto operator[](const Meta<TYPE,CONVERTER> &kwd) const
{
   return detail::meta_ref<Node,true, TYPE,CONVERTER>(kwd,*this);
}

// Returns: meta_ref, knowing it references non-const
template<class TYPE, class CONVERTER>
auto operator[](const Meta<TYPE,CONVERTER> &kwd)
{
   return detail::meta_ref<Node,false,TYPE,CONVERTER>(kwd,*this);
}



// -----------------------------------------------------------------------------
// node[Child]
// -----------------------------------------------------------------------------

// ------------------------
// <void,one>
// const and non-const
// ------------------------

// These cases are special and can use operator(), which already
// gives [const] Node & (thus lvalue if non-const).

// Returns: const Node &
template<class FILTER>
const Node &operator[](const Child<void,Allow::one,void,FILTER> &kwd) const
{
   return (*this)(kwd);
}

// Returns: Node &
template<class FILTER>
Node &operator[](const Child<void,Allow::one,void,FILTER> &kwd)
{
   return (*this)(kwd);
}


// ------------------------
// general: not <void,one>
// const and non-const
// ------------------------

// Returns: child_ref, knowing it references const
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
auto operator[](const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd) const
{
   return detail::child_ref<Node,true, TYPE,ALLOW,CONVERTER,FILTER>(kwd,*this);
}

// Returns: child_ref, knowing it references non-const
template<class TYPE, Allow ALLOW, class CONVERTER, class FILTER>
auto operator[](const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd)
{
   return detail::child_ref<Node,false,TYPE,ALLOW,CONVERTER,FILTER>(kwd,*this);
}
