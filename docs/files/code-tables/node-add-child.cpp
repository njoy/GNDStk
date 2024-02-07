
// string
Node &add( const string &name = emptyNodeName );

// value
Node &add( const           T  &val );
Node &add( const Defaulted<T> &def );

// Child<void>, value
Node &add( const Child<void,ALLOW,void,FILTER> &kwd, const T &val = T{} );

// Child<TYPE>, value
Node &add( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, const           T  &val = T{} );
Node &add( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, const Defaulted<T> &def       );

// Child<optional>, value
Node &add( const Child<optional<TYPE>,ALLOW,CONVERTER,FILTER> &kwd, const           T  &val = T{} );
bool  add( const Child<optional<TYPE>,ALLOW,CONVERTER,FILTER> &kwd, const optional <T> &opt       );
bool  add( const Child<optional<TYPE>,ALLOW,CONVERTER,FILTER> &kwd, const Defaulted<T> &def       );

// Child<Defaulted>, value
Node &add( const Child<Defaulted<TYPE>,ALLOW,CONVERTER,FILTER> &kwd, const           T  &val = T{} );
bool  add( const Child<Defaulted<TYPE>,ALLOW,CONVERTER,FILTER> &kwd, const optional <T> &opt       );
bool  add( const Child<Defaulted<TYPE>,ALLOW,CONVERTER,FILTER> &kwd, const Defaulted<T> &def       );

// Child<*> w/allow::many, container
void add( const Child<TYPE,allow::many,CONVERTER,FILTER> &kwd, const CONTAINER<T,Args...> &container );
