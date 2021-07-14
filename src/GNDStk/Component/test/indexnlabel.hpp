
// -----------------------------------------------------------------------------
// Some classes we'll use in a couple of places, for testing either the
// getter() functions in detail::, or the ones in the Component class.
// -----------------------------------------------------------------------------

// Empty
// Has neither index nor label
struct Empty {
   struct {
   } content;
};


// Index
// Has index
struct Index {
   struct {
      int index;
      std::string value;
   } content;

   std::size_t index() const { return content.index; };
   std::string value() const { return content.value; };

   Index(
      const int index = 0,
      const std::string &value = ""
   ) {
      content.value = value;
      content.index = index;
   }
};


// Label
// Has label
struct Label {
   struct {
      std::string label;
      std::string value;
   } content;

   std::string label() const { return content.label; };
   std::string value() const { return content.value; };

   Label(
      const std::string &label = "",
      const std::string &value = ""
   ) {
      content.value = value;
      content.label = label;
   }
};


// IndexLabel
// Has both index and label
struct IndexLabel {
   struct {
      int index;
      std::string label;
      std::string value;
   } content;

   std::size_t index() const { return content.index; };
   std::string label() const { return content.label; };
   std::string value() const { return content.value; };

   IndexLabel(
      const int index = 0,
      const std::string &label = "",
      const std::string &value = ""
   ) {
      content.value = value;
      content.index = index;
      content.label = label;
   }
};
