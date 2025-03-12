
    const Node &child( const Child<void,             one,  void,      FILTER> &kwd ) const;
          Node &child( const Child<void,             one,  void,      FILTER> &kwd );
CONTAINER<Node> child( const Child<void,             many, void,      FILTER> &kwd ) const;
          TYPE  child( const Child<TYPE,             one,  CONVERTER, FILTER> &kwd ) const;
 optional<TYPE> child( const Child<optional <TYPE>,  one,  CONVERTER, FILTER> &kwd ) const;
Defaulted<TYPE> child( const Child<Defaulted<TYPE>,  one,  CONVERTER, FILTER> &kwd ) const;
          TYPE  child( const Child<variant  <Ts...>, one,  CONVERTER, FILTER> &kwd ) const;
CONTAINER<TYPE> child( const Child<TYPE,             many, CONVERTER, FILTER> &kwd ) const;
CONTAINER<TYPE> child( const Child<optional <TYPE>,  many, CONVERTER, FILTER> &kwd ) const;
CONTAINER<TYPE> child( const Child<Defaulted<TYPE>,  many, CONVERTER, FILTER> &kwd ) const;
CONTAINER<TYPE> child( const Child<variant  <Ts...>, many, CONVERTER, FILTER> &kwd ) const;
