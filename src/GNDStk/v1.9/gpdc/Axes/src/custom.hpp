public:

  /* type aliases */
  using AxisOrGrid = std::variant< Axis, Grid >;
  using RefWrapAxisOrGrid = std::variant< std::reference_wrapper< const Axis >,
                                          std::reference_wrapper< const Grid > >;

private:

  /* additional fields */
  std::vector< RefWrapAxisOrGrid > children_;

  /* auxiliary functions */
  void sort() {

    // useful lambdas
    auto compare = [] ( const auto& left, const auto& right )
                      { return left.index().value() < right.index().value(); };
    auto getIndex = [] ( const auto& variant )
                       { return variant.get().index().value(); };

    // sort everything on index
    if ( this->content.axis ) {

      std::sort( this->content.axis->begin(), this->content.axis->end(), compare );
    }
    if ( this->content.grid ) {

      std::sort( this->content.grid->begin(), this->content.grid->end(), compare );
    }
    std::sort( this->children_.begin(), this->children_.end(),
               [&] ( const auto& left, const auto& right )
                   { return std::visit( getIndex, left ) <
                            std::visit( getIndex, right ); } );
  }

  template < typename Type, typename... Types >
  static std::optional< std::vector< Type > >
  extract( const std::vector< std::variant< Types... > >& elements ) {

    std::vector< Type > values;
    for ( const auto& value : elements ) {

      if ( std::holds_alternative< Type >( value ) ) {

        values.push_back( std::get< Type >( value ) );
      }
    }
    return values.size() == 0 ? std::nullopt : std::make_optional( values );
  }

public:

  /* custom construct function */
  void construct() {

    // construct the vector of variants
    if ( this->axis() ) {

      for ( const auto& entry : this->axis().value() ) {

        this->children_.emplace_back( std::cref( entry ) );
      }
    }
    if ( this->grid() ) {

      for ( const auto& entry : this->grid().value() ) {

        this->children_.emplace_back( std::cref( entry ) );
      }
    }

    // sort on indices
    this->sort();

    // useful lambdas
    auto getIndex = [] ( const auto& variant )
                       { return variant.get().index().value(); };

    // verify indices
    for ( unsigned int i = 0; i < this->children_.size(); ++i ) {

      auto index = std::visit( getIndex, this->children_[i] );
      if ( i != index ) {

        log::error( "Expected index {} but found {} instead", i, index );
        throw std::exception();
      }
    }

    // href cannot appear together with axis and grid
    if ( this->href() && ( this->axis() || this->grid() ) ) {

      log::error( "An href reference cannot appear in an axes node with axis "
                  "and/or grid child nodes" );
      throw std::exception();
    }
  }

  /**
   *  @brief Custom constructor with a vector of axis or grid elements
   *
   *  The axis in the vector need not be given in order, they will be sorted
   *  by index as required.
   *
   *  @param[in] elements    the axis and grid elements
   */
  Axes( const std::vector< std::variant< Axis, Grid > >& elements ) :
    Axes( std::nullopt,
          extract< Axis >( elements ),
          extract< Grid >( elements ) ) {}

  /**
   *  @brief Custom constructor with an href
   *
   *  @param[in] href    the reference
   */
  Axes( const std::string& href ) :
    Axes( std::make_optional( href ), std::nullopt, std::nullopt ) {}

  /**
   *  @brief Retrieve the axis and grid elements
   *
   *  The order of the axis and grid elements in the vector will correspond to
   *  the order of the index attribute on the Axis and Grid instances.
   *
   *  @return The axis and grid elements in the component
   */
  const std::vector< RefWrapAxisOrGrid >& elements() const {

    return this->children_;
  }

  /**
   *  @brief Return the number of axis and grid elements defined in the axes
   *         component
   *
   *  @return The number of axis and grid elements in the component
   */
  std::size_t size() const { return this->elements().size(); }

  /**
   *  @brief Return the axis or grid element with the given index
   *
   *  @param[in] index    the index of the axis or grid element to be retrieved
   *
   *  An std::out_of_range exception will be thrown when the index is out of
   *  range.
   *
   *  @return The axis or grid element with the given index
   */
  const RefWrapAxisOrGrid& element( unsigned int index ) const {

    return this->elements().at( index );
  }
