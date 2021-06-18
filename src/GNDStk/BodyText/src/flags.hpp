
// -----------------------------------------------------------------------------
// Flags
// -----------------------------------------------------------------------------

// These are intentionally public, as it's fine for anyone to set them, provided
// that they understand how they work. I suppose we could have setters instead,
// for uniformity with other member data in this class.


// remake
// A setter or something else may set this to true, in order to indicate that
// a vector in the variant should be (re)made from the raw string upon the next
// attempt to access the vector or one of its elements. Initializes to true,
// because that's the correct value in the common case that we're initializing
// a BodyText from an existing Node - whose data string will be read into our
// raw string, prompting a need to make the vector for the very first time.
mutable bool remake = true;


// trim
// The following indicates whether the process of converting a BodyText object
// back into data - in a Node - should, or should not, trim zeros from the start
// and/or the end of the vector. See the description in BodyText's toNode()
// function to understand precisely how this flag works.
mutable bool trim = true;
