
// -----------------------------------------------------------------------------
// Get the value; various forms
// -----------------------------------------------------------------------------

// value(), const
const T &value() const
{
   if (ptr == nullptr) {
      log::error("Call to .value() of a GNDStk::Optional with no value");
      throw std::exception{};
   }
   return *ptr;
}

// value()
T &value()
{
   return const_cast<T &>(std::as_const(*this).value());
}

// *, const
const T &operator*() const
{
   return *ptr;
}

// *
T &operator*()
{
   return *ptr;
}

// ->, const
// Helpful mainly if T is a nontrivial type. With a Optional<std::vector>
// object, for example, you could write object->size().
const T *operator->() const
{
   return &value();
}

// ->
T *operator->()
{
   return &value();
}
