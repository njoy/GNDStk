
// -----------------------------------------------------------------------------
// Some classes we'll use in a couple of places, for testing the compGetter()
// functions in detail::, or the getter() functions in class Component.
// -----------------------------------------------------------------------------

// Empty
// Has neither index nor label
struct Empty {
   struct {
   } Content;
};


// Index
// Has index
struct Index {
   struct {
      int index;
      std::string value;
   } Content;

   const int &index() const { return Content.index; };
   int &index() { return Content.index; };
   const std::string &value() const { return Content.value; };
   std::string &value() { return Content.value; };

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
   } Content;

   const std::string &label() const { return Content.label; };
   std::string &label() { return Content.label; };
   const std::string &value() const { return Content.value; };
   std::string &value() { return Content.value; };

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
   } Content;

   const int &index() const { return Content.index; };
   int &index() { return Content.index; };
   const std::string &label() const { return Content.label; };
   std::string &label() { return Content.label; };
   const std::string &value() const { return Content.value; };
   std::string &value() { return Content.value; };

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
