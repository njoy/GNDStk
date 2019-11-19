class Axes : public Node< noValidKeys, Axis, Grid >  {
public:
  using Node_t = Node< noValidKeys, Axis >;

  auto axis() const { return this->children< Axis >(); }
  auto grid() const { return this->children< Grid >(); }

};
