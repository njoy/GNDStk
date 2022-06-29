
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

   const int &index() const { return content.index; };
   int &index() { return content.index; };
   const std::string &value() const { return content.value; };
   std::string &value() { return content.value; };

   Index(
      const int index = 0,
      const std::string &value = ""
   ) {
      this->index() = index;
      this->value() = value;
   }
};


// Label
// Has label
struct Label {
   struct {
      std::string label;
      std::string value;
   } content;

   const std::string &label() const { return content.label; };
   std::string &label() { return content.label; };
   const std::string &value() const { return content.value; };
   std::string &value() { return content.value; };

   Label(
      const std::string &label = "",
      const std::string &value = ""
   ) {
      this->label() = label;
      this->value() = value;
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

   const int &index() const { return content.index; };
   int &index() { return content.index; };
   const std::string &label() const { return content.label; };
   std::string &label() { return content.label; };
   const std::string &value() const { return content.value; };
   std::string &value() { return content.value; };

   IndexLabel(
      const int index = 0,
      const std::string &label = "",
      const std::string &value = ""
   ) {
      this->index() = index;
      this->label() = label;
      this->value() = value;
   }
};
