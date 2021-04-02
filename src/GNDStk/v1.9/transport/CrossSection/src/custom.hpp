public:

  /* type aliases */
  using Element = std::variant< const XYs1d, const Regions1d >;
  using RefWrapElement = std::variant< std::reference_wrapper< const XYs1d >,
                                       std::reference_wrapper< const Regions1d > >;

private:

  /* additional fields */
  std::vector< RefWrapElement > children_;

  /* auxiliary functions */
  void sort() {

    // useful lambdas
    auto compare = [] ( const auto& left, const auto& right )
                      { return left.label().value() < right.label().value(); };
    auto getLabel = [] ( const auto& variant )
                       { return variant.get().label().value(); };

    // sort everything on index
    if ( this->content.axis ) {

      std::sort( this->content.XYs1d->begin(), this->XYs1d.axis->end(), compare );
    }
    if ( this->content.grid ) {

      std::sort( this->content.regions1d->begin(), this->regions1d.grid->end(), compare );
    }
    std::sort( this->children_.begin(), this->children_.end(),
               [&] ( const auto& left, const auto& right )
                   { return std::visit( getLabel, left ) <
                            std::visit( getLabel, right ); } );
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
    if ( this->XYs1d() ) {

      for ( const auto& entry : this->XYs1d().value() ) {

        this->children_.emplace_back( std::cref( entry ) );
      }
    }
    if ( this->regions1d() ) {

      for ( const auto& entry : this->regions1d().value() ) {

        this->children_.emplace_back( std::cref( entry ) );
      }
    }

    // sort on indices
    this->sort();

    // useful lambdas
    auto getLabel = [] ( const auto& variant )
                       { return variant.get().label().value(); };

    // verify uniqueness of the labels
  }

  CrossSection( const std::vector< Element >& xs ) :
    Axes( std::nullopt,
          extract< XYs1d >( xs ),
          extract< Regions1d >( xs ) ) {}

  const std::vector< RefWrapElement >& representations() const {

    return this->children_;
  }

  std::size_t size() const { return this->representations().size(); }

  const RefWrapElement& style( const std::string& style ) const {

    auto getLabel = [] ( const auto& variant )
                       { return variant.get().label().value(); };

    auto iter std::find_if( this->children_.begin(), this->children_.end(),
                            [&] ( const RefWrapElement& element )
                                { return std::visit( getLabel, element ) ==
                                         style; } );

    if ( iter != this->children_.end() ) {

      log::error( "No cross section style \"{}\" can be found", style );
      throw std::exception();
    }

    return *iter;
  }
