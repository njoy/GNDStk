
namespace GNDStk {
namespace proto {

using namespace njoy::GNDStk::core;

// -----------------------------------------------------------------------------
// class Values
// -----------------------------------------------------------------------------

class Values : public Component<Values,true> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "proto"; }
   static auto className() { return "Values"; }
   static auto GNDSName() { return "values"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<Integer32>{}
            / Meta<>("length") |
         Defaulted<Integer32>{0}
            / Meta<>("start") |
         Defaulted<UTF8Text>{"Float64"}
            / Meta<>("valueType")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
      const Integer32 start{0};
      const UTF8Text valueType{"Float64"};
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      mutable std::optional<Integer32> length;
      mutable Defaulted<Integer32> start{0};
      mutable Defaulted<UTF8Text> valueType{"Float64"};
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // length
   const auto &length() const
    { return content.length; }
   auto &length()
    { return content.length; }

   // start
   const auto &start() const
    { return content.start.value(); }
   auto &start()
    { return content.start.value(); }

   // valueType
   const auto &valueType() const
    { return content.valueType.value(); }
   auto &valueType()
    { return content.valueType.value(); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // length(value)
   auto &length(const std::optional<Integer32> &obj)
    { BodyText::length(length() = obj); return *this; }

   // start(value)
   auto &start(const Defaulted<Integer32> &obj)
    { BodyText::start(content.start = obj); return *this; }
   auto &start(const Integer32 &obj)
    { BodyText::start(content.start = obj); return *this; }

   // valueType(value)
   auto &valueType(const Defaulted<UTF8Text> &obj)
    { BodyText::valueType(content.valueType = obj); return *this; }
   auto &valueType(const UTF8Text &obj)
    { BodyText::valueType(content.valueType = obj); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Values() :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish();
   }

   // copy
   Values(const Values &other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Values(Values &&other) :
      Component{
         other,
         content.length,
         content.start,
         content.valueType
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Values(const Node &node) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Values(
      const std::optional<Integer32> &length,
      const Defaulted<Integer32> &start,
      const Defaulted<UTF8Text> &valueType
   ) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      },
      content{
         length,
         start,
         valueType
      }
   {
      Component::finish();
   }

   // from fields, with T replacing Defaulted<T>
   explicit Values(
      const std::optional<Integer32> &length,
      const Integer32 &start,
      const UTF8Text &valueType
   ) :
      Component{
         BodyText{},
         content.length,
         content.start,
         content.valueType
      },
      content{
         length,
         start == 0
            ? Defaulted<Integer32>{0}
            : Defaulted<Integer32>{0,start},
         valueType == "Float64"
            ? Defaulted<UTF8Text>{"Float64"}
            : Defaulted<UTF8Text>{"Float64",valueType}
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Values &operator=(const Values &) = default;

   // move
   Values &operator=(Values &&) = default;

}; // class Values



// -----------------------------------------------------------------------------
// class Link
// -----------------------------------------------------------------------------

class Link : public Component<Link> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "proto"; }
   static auto className() { return "Link"; }
   static auto GNDSName() { return "link"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         UTF8Text{}
            / Meta<>("href")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      UTF8Text href;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // href
   const auto &href() const
    { return content.href; }
   auto &href()
    { return content.href; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // href(value)
   auto &href(const UTF8Text &obj)
    { href() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Link() :
      Component{
         BodyText{},
         content.href
      }
   {
      Component::finish();
   }

   // copy
   Link(const Link &other) :
      Component{
         other,
         content.href
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Link(Link &&other) :
      Component{
         other,
         content.href
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Link(const Node &node) :
      Component{
         BodyText{},
         content.href
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Link(
      const UTF8Text &href
   ) :
      Component{
         BodyText{},
         content.href
      },
      content{
         href
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Link &operator=(const Link &) = default;

   // move
   Link &operator=(Link &&) = default;

}; // class Link



// -----------------------------------------------------------------------------
// class Grid
// -----------------------------------------------------------------------------

class Grid : public Component<Grid> {

   using VARIANT = std::variant<
      proto::Link,
      proto::Values
   >;

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "proto"; }
   static auto className() { return "Grid"; }
   static auto GNDSName() { return "grid"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<Integer32>{}
            / Meta<>("index") |
         Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            / Meta<>("interpolation") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<enums::GridStyle>{}
            / Meta<>("style") |
         std::optional<XMLName>{}
            / Meta<>("unit") |
         // children
         VARIANT{}
            / --Child<>("link values")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
      const enums::Interpolation interpolation{enums::Interpolation::linlin};
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<Integer32> index;
      Defaulted<enums::Interpolation> interpolation{enums::Interpolation::linlin};
      std::optional<XMLName> label;
      std::optional<enums::GridStyle> style;
      std::optional<XMLName> unit;

      // children
      VARIANT choice;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // index
   const auto &index() const
    { return content.index; }
   auto &index()
    { return content.index; }

   // interpolation
   const auto &interpolation() const
    { return content.interpolation.value(); }
   auto &interpolation()
    { return content.interpolation.value(); }

   // label
   const auto &label() const
    { return content.label; }
   auto &label()
    { return content.label; }

   // style
   const auto &style() const
    { return content.style; }
   auto &style()
    { return content.style; }

   // unit
   const auto &unit() const
    { return content.unit; }
   auto &unit()
    { return content.unit; }

   // choice
   const auto &choice() const
    { return content.choice; }
   auto &choice()
    { return content.choice; }

   // link
   auto link() const
    { return getter<proto::Link>(choice(), "link"); }
   auto link()
    { return getter<proto::Link>(choice(), "link"); }

   // values
   auto values() const
    { return getter<proto::Values>(choice(), "values"); }
   auto values()
    { return getter<proto::Values>(choice(), "values"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // index(value)
   auto &index(const std::optional<Integer32> &obj)
    { index() = obj; return *this; }

   // interpolation(value)
   auto &interpolation(const Defaulted<enums::Interpolation> &obj)
    { content.interpolation = obj; return *this; }
   auto &interpolation(const enums::Interpolation &obj)
    { content.interpolation = obj; return *this; }

   // label(value)
   auto &label(const std::optional<XMLName> &obj)
    { label() = obj; return *this; }

   // style(value)
   auto &style(const std::optional<enums::GridStyle> &obj)
    { style() = obj; return *this; }

   // unit(value)
   auto &unit(const std::optional<XMLName> &obj)
    { unit() = obj; return *this; }

   // choice(value)
   auto &choice(const VARIANT &obj)
    { choice() = obj; return *this; }

   // link(value)
   auto &link(const std::optional<proto::Link> &obj)
    { if (obj) choice(obj.value()); return *this; }

   // values(value)
   auto &values(const std::optional<proto::Values> &obj)
    { if (obj) choice(obj.value()); return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Grid() :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.choice
      }
   {
      Component::finish();
   }

   // copy
   Grid(const Grid &other) :
      Component{
         other,
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.choice
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Grid(Grid &&other) :
      Component{
         other,
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.choice
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Grid(const Node &node) :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.choice
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Grid(
      const std::optional<Integer32> &index,
      const Defaulted<enums::Interpolation> &interpolation,
      const std::optional<XMLName> &label,
      const std::optional<enums::GridStyle> &style,
      const std::optional<XMLName> &unit,
      const VARIANT &choice
   ) :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.choice
      },
      content{
         index,
         interpolation,
         label,
         style,
         unit,
         choice
      }
   {
      Component::finish();
   }

   // from fields, with T replacing Defaulted<T>
   explicit Grid(
      const std::optional<Integer32> &index,
      const enums::Interpolation &interpolation,
      const std::optional<XMLName> &label,
      const std::optional<enums::GridStyle> &style,
      const std::optional<XMLName> &unit,
      const VARIANT &choice
   ) :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.style,
         content.unit,
         content.choice
      },
      content{
         index,
         interpolation == enums::Interpolation::linlin
            ? Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            : Defaulted<enums::Interpolation>{enums::Interpolation::linlin,interpolation},
         label,
         style,
         unit,
         choice
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Grid &operator=(const Grid &) = default;

   // move
   Grid &operator=(Grid &&) = default;

}; // class Grid



// -----------------------------------------------------------------------------
// class Axis
// -----------------------------------------------------------------------------

class Axis : public Component<Axis> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "proto"; }
   static auto className() { return "Axis"; }
   static auto GNDSName() { return "axis"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<Integer32>{}
            / Meta<>("index") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<XMLName>{}
            / Meta<>("unit")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<Integer32> index;
      std::optional<XMLName> label;
      std::optional<XMLName> unit;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // index
   const auto &index() const
    { return content.index; }
   auto &index()
    { return content.index; }

   // label
   const auto &label() const
    { return content.label; }
   auto &label()
    { return content.label; }

   // unit
   const auto &unit() const
    { return content.unit; }
   auto &unit()
    { return content.unit; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // index(value)
   auto &index(const std::optional<Integer32> &obj)
    { index() = obj; return *this; }

   // label(value)
   auto &label(const std::optional<XMLName> &obj)
    { label() = obj; return *this; }

   // unit(value)
   auto &unit(const std::optional<XMLName> &obj)
    { unit() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Axis() :
      Component{
         BodyText{},
         content.index,
         content.label,
         content.unit
      }
   {
      Component::finish();
   }

   // copy
   Axis(const Axis &other) :
      Component{
         other,
         content.index,
         content.label,
         content.unit
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Axis(Axis &&other) :
      Component{
         other,
         content.index,
         content.label,
         content.unit
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Axis(const Node &node) :
      Component{
         BodyText{},
         content.index,
         content.label,
         content.unit
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Axis(
      const std::optional<Integer32> &index,
      const std::optional<XMLName> &label,
      const std::optional<XMLName> &unit
   ) :
      Component{
         BodyText{},
         content.index,
         content.label,
         content.unit
      },
      content{
         index,
         label,
         unit
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Axis &operator=(const Axis &) = default;

   // move
   Axis &operator=(Axis &&) = default;

}; // class Axis



// -----------------------------------------------------------------------------
// class Axes
// -----------------------------------------------------------------------------

class Axes : public Component<Axes> {

   using VARIANT = std::variant<
      proto::Axis,
      proto::Grid
   >;

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "proto"; }
   static auto className() { return "Axes"; }
   static auto GNDSName() { return "axes"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<UTF8Text>{}
            / Meta<>("href") |
         // children
         VARIANT{}
            / ++Child<>("axis grid")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<UTF8Text> href;

      // children
      std::vector<VARIANT> choice;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // href
   const auto &href() const
    { return content.href; }
   auto &href()
    { return content.href; }

   // choice
   const auto &choice() const
    { return content.choice; }
   auto &choice()
    { return content.choice; }

   // choice(index)
   const auto &choice(const std::size_t index) const
    { return getter(choice(), index, "choice"); }
   auto &choice(const std::size_t index)
    { return getter(choice(), index, "choice"); }

   // choice(label)
   const auto &choice(const std::string &label) const
    { return getter(choice(), label, "choice"); }
   auto &choice(const std::string &label)
    { return getter(choice(), label, "choice"); }

   // axis(index)
   auto axis(const std::size_t index) const
    { return getter<proto::Axis>(choice(), index, "axis"); }
   auto axis(const std::size_t index)
    { return getter<proto::Axis>(choice(), index, "axis"); }

   // axis(label)
   auto axis(const std::string &label) const
    { return getter<proto::Axis>(choice(), label, "axis"); }
   auto axis(const std::string &label)
    { return getter<proto::Axis>(choice(), label, "axis"); }

   // grid(index)
   auto grid(const std::size_t index) const
    { return getter<proto::Grid>(choice(), index, "grid"); }
   auto grid(const std::size_t index)
    { return getter<proto::Grid>(choice(), index, "grid"); }

   // grid(label)
   auto grid(const std::string &label) const
    { return getter<proto::Grid>(choice(), label, "grid"); }
   auto grid(const std::string &label)
    { return getter<proto::Grid>(choice(), label, "grid"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // href(value)
   auto &href(const std::optional<UTF8Text> &obj)
    { href() = obj; return *this; }

   // choice(value)
   auto &choice(const std::vector<VARIANT> &obj)
    { choice() = obj; return *this; }

   // choice(index,value)
   auto &choice(
      const std::size_t index,
      const VARIANT &obj
   ) {
      choice(index) = obj; return *this;
   }

   // choice(label,value)
   auto &choice(
      const std::string &label,
      const VARIANT &obj
   ) {
      choice(label) = obj; return *this;
   }

   // axis(index,value)
   auto &axis(
      const std::size_t index,
      const std::optional<proto::Axis> &obj
   ) {
      if (obj) choice(index,obj.value());
      return *this;
   }

   // axis(label,value)
   auto &axis(
      const std::string &label,
      const std::optional<proto::Axis> &obj
   ) {
      if (obj) choice(label,obj.value());
      return *this;
   }

   // grid(index,value)
   auto &grid(
      const std::size_t index,
      const std::optional<proto::Grid> &obj
   ) {
      if (obj) choice(index,obj.value());
      return *this;
   }

   // grid(label,value)
   auto &grid(
      const std::string &label,
      const std::optional<proto::Grid> &obj
   ) {
      if (obj) choice(label,obj.value());
      return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Axes() :
      Component{
         BodyText{},
         content.href,
         content.choice
      }
   {
      Component::finish();
   }

   // copy
   Axes(const Axes &other) :
      Component{
         other,
         content.href,
         content.choice
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Axes(Axes &&other) :
      Component{
         other,
         content.href,
         content.choice
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Axes(const Node &node) :
      Component{
         BodyText{},
         content.href,
         content.choice
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Axes(
      const std::optional<UTF8Text> &href,
      const std::vector<VARIANT> &choice
   ) :
      Component{
         BodyText{},
         content.href,
         content.choice
      },
      content{
         href,
         choice
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Axes &operator=(const Axes &) = default;

   // move
   Axes &operator=(Axes &&) = default;

}; // class Axes



// -----------------------------------------------------------------------------
// class XYs1d
// -----------------------------------------------------------------------------

class XYs1d : public Component<XYs1d> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "proto"; }
   static auto className() { return "XYs1d"; }
   static auto GNDSName() { return "XYs1d"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<Integer32>{}
            / Meta<>("index") |
         Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            / Meta<>("interpolation") |
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<Float64>{}
            / Meta<>("outerDomainValue") |
         // children
         std::optional<proto::Axes>{}
            / --Child<>("axes") |
         proto::Values{}
            / --Child<>("values")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
      const enums::Interpolation interpolation{enums::Interpolation::linlin};
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<Integer32> index;
      Defaulted<enums::Interpolation> interpolation{enums::Interpolation::linlin};
      std::optional<XMLName> label;
      std::optional<Float64> outerDomainValue;

      // children
      std::optional<proto::Axes> axes;
      proto::Values values;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // index
   const auto &index() const
    { return content.index; }
   auto &index()
    { return content.index; }

   // interpolation
   const auto &interpolation() const
    { return content.interpolation.value(); }
   auto &interpolation()
    { return content.interpolation.value(); }

   // label
   const auto &label() const
    { return content.label; }
   auto &label()
    { return content.label; }

   // outerDomainValue
   const auto &outerDomainValue() const
    { return content.outerDomainValue; }
   auto &outerDomainValue()
    { return content.outerDomainValue; }

   // axes
   const auto &axes() const
    { return content.axes; }
   auto &axes()
    { return content.axes; }

   // values
   const auto &values() const
    { return content.values; }
   auto &values()
    { return content.values; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // index(value)
   auto &index(const std::optional<Integer32> &obj)
    { index() = obj; return *this; }

   // interpolation(value)
   auto &interpolation(const Defaulted<enums::Interpolation> &obj)
    { content.interpolation = obj; return *this; }
   auto &interpolation(const enums::Interpolation &obj)
    { content.interpolation = obj; return *this; }

   // label(value)
   auto &label(const std::optional<XMLName> &obj)
    { label() = obj; return *this; }

   // outerDomainValue(value)
   auto &outerDomainValue(const std::optional<Float64> &obj)
    { outerDomainValue() = obj; return *this; }

   // axes(value)
   auto &axes(const std::optional<proto::Axes> &obj)
    { axes() = obj; return *this; }

   // values(value)
   auto &values(const proto::Values &obj)
    { values() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   XYs1d() :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      }
   {
      Component::finish();
   }

   // copy
   XYs1d(const XYs1d &other) :
      Component{
         other,
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   XYs1d(XYs1d &&other) :
      Component{
         other,
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   XYs1d(const Node &node) :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit XYs1d(
      const std::optional<Integer32> &index,
      const Defaulted<enums::Interpolation> &interpolation,
      const std::optional<XMLName> &label,
      const std::optional<Float64> &outerDomainValue,
      const std::optional<proto::Axes> &axes,
      const proto::Values &values
   ) :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      },
      content{
         index,
         interpolation,
         label,
         outerDomainValue,
         axes,
         values
      }
   {
      Component::finish();
   }

   // from fields, with T replacing Defaulted<T>
   explicit XYs1d(
      const std::optional<Integer32> &index,
      const enums::Interpolation &interpolation,
      const std::optional<XMLName> &label,
      const std::optional<Float64> &outerDomainValue,
      const std::optional<proto::Axes> &axes,
      const proto::Values &values
   ) :
      Component{
         BodyText{},
         content.index,
         content.interpolation,
         content.label,
         content.outerDomainValue,
         content.axes,
         content.values
      },
      content{
         index,
         interpolation == enums::Interpolation::linlin
            ? Defaulted<enums::Interpolation>{enums::Interpolation::linlin}
            : Defaulted<enums::Interpolation>{enums::Interpolation::linlin,interpolation},
         label,
         outerDomainValue,
         axes,
         values
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   XYs1d &operator=(const XYs1d &) = default;

   // move
   XYs1d &operator=(XYs1d &&) = default;

}; // class XYs1d



// -----------------------------------------------------------------------------
// class Regions1d
// -----------------------------------------------------------------------------

class Regions1d : public Component<Regions1d> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "proto"; }
   static auto className() { return "Regions1d"; }
   static auto GNDSName() { return "regions1d"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         std::optional<XMLName>{}
            / Meta<>("label") |
         std::optional<Float64>{}
            / Meta<>("outerDomainValue") |
         // children
         proto::XYs1d{}
            / ++Child<>("XYs1d") |
         std::optional<proto::Axes>{}
            / --Child<>("axes")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      std::optional<XMLName> label;
      std::optional<Float64> outerDomainValue;

      // children
      std::vector<proto::XYs1d> XYs1d;
      std::optional<proto::Axes> axes;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // label
   const auto &label() const
    { return content.label; }
   auto &label()
    { return content.label; }

   // outerDomainValue
   const auto &outerDomainValue() const
    { return content.outerDomainValue; }
   auto &outerDomainValue()
    { return content.outerDomainValue; }

   // XYs1d
   const auto &XYs1d() const
    { return content.XYs1d; }
   auto &XYs1d()
    { return content.XYs1d; }

   // XYs1d(index)
   const auto &XYs1d(const std::size_t index) const
    { return getter(XYs1d(), index, "XYs1d"); }
   auto &XYs1d(const std::size_t index)
    { return getter(XYs1d(), index, "XYs1d"); }

   // XYs1d(label)
   const auto &XYs1d(const std::string &label) const
    { return getter(XYs1d(), label, "XYs1d"); }
   auto &XYs1d(const std::string &label)
    { return getter(XYs1d(), label, "XYs1d"); }

   // axes
   const auto &axes() const
    { return content.axes; }
   auto &axes()
    { return content.axes; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // label(value)
   auto &label(const std::optional<XMLName> &obj)
    { label() = obj; return *this; }

   // outerDomainValue(value)
   auto &outerDomainValue(const std::optional<Float64> &obj)
    { outerDomainValue() = obj; return *this; }

   // XYs1d(value)
   auto &XYs1d(const std::vector<proto::XYs1d> &obj)
    { XYs1d() = obj; return *this; }

   // XYs1d(index,value)
   auto &XYs1d(
      const std::size_t index,
      const proto::XYs1d &obj
   ) {
      XYs1d(index) = obj; return *this;
   }

   // XYs1d(label,value)
   auto &XYs1d(
      const std::string &label,
      const proto::XYs1d &obj
   ) {
      XYs1d(label) = obj; return *this;
   }

   // axes(value)
   auto &axes(const std::optional<proto::Axes> &obj)
    { axes() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Regions1d() :
      Component{
         BodyText{},
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      }
   {
      Component::finish();
   }

   // copy
   Regions1d(const Regions1d &other) :
      Component{
         other,
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Regions1d(Regions1d &&other) :
      Component{
         other,
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Regions1d(const Node &node) :
      Component{
         BodyText{},
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Regions1d(
      const std::optional<XMLName> &label,
      const std::optional<Float64> &outerDomainValue,
      const std::vector<proto::XYs1d> &XYs1d,
      const std::optional<proto::Axes> &axes
   ) :
      Component{
         BodyText{},
         content.label,
         content.outerDomainValue,
         content.XYs1d,
         content.axes
      },
      content{
         label,
         outerDomainValue,
         XYs1d,
         axes
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Regions1d &operator=(const Regions1d &) = default;

   // move
   Regions1d &operator=(Regions1d &&) = default;

}; // class Regions1d



// -----------------------------------------------------------------------------
// class CrossSection
// -----------------------------------------------------------------------------

class CrossSection : public Component<CrossSection> {

   using VARIANT = std::variant<
      proto::XYs1d,
      proto::Regions1d
   >;

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "proto"; }
   static auto className() { return "CrossSection"; }
   static auto GNDSName() { return "crossSection"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         VARIANT{}
            / ++Child<>("XYs1d regions1d")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // children
      std::vector<VARIANT> choice;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // choice
   const auto &choice() const
    { return content.choice; }
   auto &choice()
    { return content.choice; }

   // choice(index)
   const auto &choice(const std::size_t index) const
    { return getter(choice(), index, "choice"); }
   auto &choice(const std::size_t index)
    { return getter(choice(), index, "choice"); }

   // choice(label)
   const auto &choice(const std::string &label) const
    { return getter(choice(), label, "choice"); }
   auto &choice(const std::string &label)
    { return getter(choice(), label, "choice"); }

   // XYs1d(index)
   auto XYs1d(const std::size_t index) const
    { return getter<proto::XYs1d>(choice(), index, "XYs1d"); }
   auto XYs1d(const std::size_t index)
    { return getter<proto::XYs1d>(choice(), index, "XYs1d"); }

   // XYs1d(label)
   auto XYs1d(const std::string &label) const
    { return getter<proto::XYs1d>(choice(), label, "XYs1d"); }
   auto XYs1d(const std::string &label)
    { return getter<proto::XYs1d>(choice(), label, "XYs1d"); }

   // regions1d(index)
   auto regions1d(const std::size_t index) const
    { return getter<proto::Regions1d>(choice(), index, "regions1d"); }
   auto regions1d(const std::size_t index)
    { return getter<proto::Regions1d>(choice(), index, "regions1d"); }

   // regions1d(label)
   auto regions1d(const std::string &label) const
    { return getter<proto::Regions1d>(choice(), label, "regions1d"); }
   auto regions1d(const std::string &label)
    { return getter<proto::Regions1d>(choice(), label, "regions1d"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // choice(value)
   auto &choice(const std::vector<VARIANT> &obj)
    { choice() = obj; return *this; }

   // choice(index,value)
   auto &choice(
      const std::size_t index,
      const VARIANT &obj
   ) {
      choice(index) = obj; return *this;
   }

   // choice(label,value)
   auto &choice(
      const std::string &label,
      const VARIANT &obj
   ) {
      choice(label) = obj; return *this;
   }

   // XYs1d(index,value)
   auto &XYs1d(
      const std::size_t index,
      const std::optional<proto::XYs1d> &obj
   ) {
      if (obj) choice(index,obj.value());
      return *this;
   }

   // XYs1d(label,value)
   auto &XYs1d(
      const std::string &label,
      const std::optional<proto::XYs1d> &obj
   ) {
      if (obj) choice(label,obj.value());
      return *this;
   }

   // regions1d(index,value)
   auto &regions1d(
      const std::size_t index,
      const std::optional<proto::Regions1d> &obj
   ) {
      if (obj) choice(index,obj.value());
      return *this;
   }

   // regions1d(label,value)
   auto &regions1d(
      const std::string &label,
      const std::optional<proto::Regions1d> &obj
   ) {
      if (obj) choice(label,obj.value());
      return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   CrossSection() :
      Component{
         BodyText{},
         content.choice
      }
   {
      Component::finish();
   }

   // copy
   CrossSection(const CrossSection &other) :
      Component{
         other,
         content.choice
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   CrossSection(CrossSection &&other) :
      Component{
         other,
         content.choice
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   CrossSection(const Node &node) :
      Component{
         BodyText{},
         content.choice
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit CrossSection(
      const std::vector<VARIANT> &choice
   ) :
      Component{
         BodyText{},
         content.choice
      },
      content{
         choice
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   CrossSection &operator=(const CrossSection &) = default;

   // move
   CrossSection &operator=(CrossSection &&) = default;

}; // class CrossSection



// -----------------------------------------------------------------------------
// class Reaction
// -----------------------------------------------------------------------------

class Reaction : public Component<Reaction> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "proto"; }
   static auto className() { return "Reaction"; }
   static auto GNDSName() { return "reaction"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         Integer32{}
            / Meta<>("ENDF_MT") |
         std::optional<XMLName>{}
            / Meta<>("fissionGenre") |
         XMLName{}
            / Meta<>("label") |
         // children
         proto::CrossSection{}
            / --Child<>("crossSection")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      Integer32 ENDF_MT;
      std::optional<XMLName> fissionGenre;
      XMLName label;

      // children
      proto::CrossSection crossSection;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // ENDF_MT
   const auto &ENDF_MT() const
    { return content.ENDF_MT; }
   auto &ENDF_MT()
    { return content.ENDF_MT; }

   // fissionGenre
   const auto &fissionGenre() const
    { return content.fissionGenre; }
   auto &fissionGenre()
    { return content.fissionGenre; }

   // label
   const auto &label() const
    { return content.label; }
   auto &label()
    { return content.label; }

   // crossSection
   const auto &crossSection() const
    { return content.crossSection; }
   auto &crossSection()
    { return content.crossSection; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // ENDF_MT(value)
   auto &ENDF_MT(const Integer32 &obj)
    { ENDF_MT() = obj; return *this; }

   // fissionGenre(value)
   auto &fissionGenre(const std::optional<XMLName> &obj)
    { fissionGenre() = obj; return *this; }

   // label(value)
   auto &label(const XMLName &obj)
    { label() = obj; return *this; }

   // crossSection(value)
   auto &crossSection(const proto::CrossSection &obj)
    { crossSection() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Reaction() :
      Component{
         BodyText{},
         content.ENDF_MT,
         content.fissionGenre,
         content.label,
         content.crossSection
      }
   {
      Component::finish();
   }

   // copy
   Reaction(const Reaction &other) :
      Component{
         other,
         content.ENDF_MT,
         content.fissionGenre,
         content.label,
         content.crossSection
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Reaction(Reaction &&other) :
      Component{
         other,
         content.ENDF_MT,
         content.fissionGenre,
         content.label,
         content.crossSection
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Reaction(const Node &node) :
      Component{
         BodyText{},
         content.ENDF_MT,
         content.fissionGenre,
         content.label,
         content.crossSection
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Reaction(
      const Integer32 &ENDF_MT,
      const std::optional<XMLName> &fissionGenre,
      const XMLName &label,
      const proto::CrossSection &crossSection
   ) :
      Component{
         BodyText{},
         content.ENDF_MT,
         content.fissionGenre,
         content.label,
         content.crossSection
      },
      content{
         ENDF_MT,
         fissionGenre,
         label,
         crossSection
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Reaction &operator=(const Reaction &) = default;

   // move
   Reaction &operator=(Reaction &&) = default;

}; // class Reaction



// -----------------------------------------------------------------------------
// class Reactions
// -----------------------------------------------------------------------------

class Reactions : public Component<Reactions> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "proto"; }
   static auto className() { return "Reactions"; }
   static auto GNDSName() { return "reactions"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // children
         proto::Reaction{}
            / ++Child<>("reaction")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // children
      std::vector<proto::Reaction> reaction;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // reaction
   const auto &reaction() const
    { return content.reaction; }
   auto &reaction()
    { return content.reaction; }

   // reaction(index)
   const auto &reaction(const std::size_t index) const
    { return getter(reaction(), index, "reaction"); }
   auto &reaction(const std::size_t index)
    { return getter(reaction(), index, "reaction"); }

   // reaction(label)
   const auto &reaction(const std::string &label) const
    { return getter(reaction(), label, "reaction"); }
   auto &reaction(const std::string &label)
    { return getter(reaction(), label, "reaction"); }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // reaction(value)
   auto &reaction(const std::vector<proto::Reaction> &obj)
    { reaction() = obj; return *this; }

   // reaction(index,value)
   auto &reaction(
      const std::size_t index,
      const proto::Reaction &obj
   ) {
      reaction(index) = obj; return *this;
   }

   // reaction(label,value)
   auto &reaction(
      const std::string &label,
      const proto::Reaction &obj
   ) {
      reaction(label) = obj; return *this;
   }

   // ------------------------
   // Construction
   // ------------------------

   // default
   Reactions() :
      Component{
         BodyText{},
         content.reaction
      }
   {
      Component::finish();
   }

   // copy
   Reactions(const Reactions &other) :
      Component{
         other,
         content.reaction
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   Reactions(Reactions &&other) :
      Component{
         other,
         content.reaction
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   Reactions(const Node &node) :
      Component{
         BodyText{},
         content.reaction
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit Reactions(
      const std::vector<proto::Reaction> &reaction
   ) :
      Component{
         BodyText{},
         content.reaction
      },
      content{
         reaction
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   Reactions &operator=(const Reactions &) = default;

   // move
   Reactions &operator=(Reactions &&) = default;

}; // class Reactions



// -----------------------------------------------------------------------------
// class ReactionSuite
// -----------------------------------------------------------------------------

class ReactionSuite : public Component<ReactionSuite> {

   // ------------------------
   // For Component
   // ------------------------

   friend class Component;

   // Current namespace, current class, and GNDS node name
   static auto namespaceName() { return "proto"; }
   static auto className() { return "ReactionSuite"; }
   static auto GNDSName() { return "reactionSuite"; }

   // Core Interface object to extract metadata and child nodes
   static auto keys()
   {
      return
         // metadata
         XMLName{}
            / Meta<>("evaluation") |
         XMLName{}
            / Meta<>("format") |
         std::optional<enums::Interaction>{}
            / Meta<>("interaction") |
         XMLName{}
            / Meta<>("projectile") |
         enums::Frame{}
            / Meta<>("projectileFrame") |
         XMLName{}
            / Meta<>("target") |
         // children
         std::optional<proto::Reactions>{}
            / --Child<>("reactions")
      ;
   }

public:

   using Component::construct;

   // ------------------------
   // Relevant defaults
   // FYI for users
   // ------------------------

   static const struct {
   } defaults;

   // ------------------------
   // Raw GNDS content
   // ------------------------

   struct {
      // metadata
      XMLName evaluation;
      XMLName format;
      std::optional<enums::Interaction> interaction;
      XMLName projectile;
      enums::Frame projectileFrame;
      XMLName target;

      // children
      std::optional<proto::Reactions> reactions;
   } content;

   // ------------------------
   // Getters
   // const and non-const
   // ------------------------

   // evaluation
   const auto &evaluation() const
    { return content.evaluation; }
   auto &evaluation()
    { return content.evaluation; }

   // format
   const auto &format() const
    { return content.format; }
   auto &format()
    { return content.format; }

   // interaction
   const auto &interaction() const
    { return content.interaction; }
   auto &interaction()
    { return content.interaction; }

   // projectile
   const auto &projectile() const
    { return content.projectile; }
   auto &projectile()
    { return content.projectile; }

   // projectileFrame
   const auto &projectileFrame() const
    { return content.projectileFrame; }
   auto &projectileFrame()
    { return content.projectileFrame; }

   // target
   const auto &target() const
    { return content.target; }
   auto &target()
    { return content.target; }

   // reactions
   const auto &reactions() const
    { return content.reactions; }
   auto &reactions()
    { return content.reactions; }

   // ------------------------
   // Setters
   // non-const
   // All return *this
   // ------------------------

   // evaluation(value)
   auto &evaluation(const XMLName &obj)
    { evaluation() = obj; return *this; }

   // format(value)
   auto &format(const XMLName &obj)
    { format() = obj; return *this; }

   // interaction(value)
   auto &interaction(const std::optional<enums::Interaction> &obj)
    { interaction() = obj; return *this; }

   // projectile(value)
   auto &projectile(const XMLName &obj)
    { projectile() = obj; return *this; }

   // projectileFrame(value)
   auto &projectileFrame(const enums::Frame &obj)
    { projectileFrame() = obj; return *this; }

   // target(value)
   auto &target(const XMLName &obj)
    { target() = obj; return *this; }

   // reactions(value)
   auto &reactions(const std::optional<proto::Reactions> &obj)
    { reactions() = obj; return *this; }

   // ------------------------
   // Construction
   // ------------------------

   // default
   ReactionSuite() :
      Component{
         BodyText{},
         content.evaluation,
         content.format,
         content.interaction,
         content.projectile,
         content.projectileFrame,
         content.target,
         content.reactions
      }
   {
      Component::finish();
   }

   // copy
   ReactionSuite(const ReactionSuite &other) :
      Component{
         other,
         content.evaluation,
         content.format,
         content.interaction,
         content.projectile,
         content.projectileFrame,
         content.target,
         content.reactions
      },
      content{other.content}
   {
      Component::finish(other);
   }

   // move
   ReactionSuite(ReactionSuite &&other) :
      Component{
         other,
         content.evaluation,
         content.format,
         content.interaction,
         content.projectile,
         content.projectileFrame,
         content.target,
         content.reactions
      },
      content{std::move(other.content)}
   {
      Component::finish(other);
   }

   // from node
   ReactionSuite(const Node &node) :
      Component{
         BodyText{},
         content.evaluation,
         content.format,
         content.interaction,
         content.projectile,
         content.projectileFrame,
         content.target,
         content.reactions
      }
   {
      Component::finish(node);
   }

   // from fields
   explicit ReactionSuite(
      const XMLName &evaluation,
      const XMLName &format,
      const std::optional<enums::Interaction> &interaction,
      const XMLName &projectile,
      const enums::Frame &projectileFrame,
      const XMLName &target,
      const std::optional<proto::Reactions> &reactions
   ) :
      Component{
         BodyText{},
         content.evaluation,
         content.format,
         content.interaction,
         content.projectile,
         content.projectileFrame,
         content.target,
         content.reactions
      },
      content{
         evaluation,
         format,
         interaction,
         projectile,
         projectileFrame,
         target,
         reactions
      }
   {
      Component::finish();
   }

   // ------------------------
   // Assignment
   // ------------------------

   // copy
   ReactionSuite &operator=(const ReactionSuite &) = default;

   // move
   ReactionSuite &operator=(ReactionSuite &&) = default;

}; // class ReactionSuite

} // namespace proto
} // namespace GNDStk
