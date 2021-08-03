private:

  static inline helpMap help = {};

public:

  /**
   *  @brief Return the axis and grid elements defined in the axes element
   */
  decltype(auto) size() const {

    return this->choice().size();
  }
