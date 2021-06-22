private:

  static inline helpMap help = {};

  /**
   *  @brief Custom construct function
   *
   +  Sort the elements by index so that the indices are in order
   */
  void construct() {

    // useful lambdas
    auto getIndex = [] ( const auto& variant )
                       { return variant.index().value(); };

    std::sort( this->content.choice.begin(), this->content.choice.end(),
               [&] ( const auto& left, const auto& right )
                   { return std::visit( getIndex, left ) <
                            std::visit( getIndex, right ); } );
  }

public:

  /**
   *  @brief Return the axis and grid elements defined in the axes element
   */
  decltype(auto) size() const {

    return this->choice().size();
  }
