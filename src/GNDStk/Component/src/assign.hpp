
// Copy
Component &operator=(const Component &other)
{
   BLOCKDATA::operator=(other);
   return *this;
}

// Move
Component &operator=(Component &&other)
{
   BLOCKDATA::operator=(std::move(other));
   return *this;
}
