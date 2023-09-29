
// string, value
metaPair &add( const string &key, const           T  &val, const CONVERTER &converter = CONVERTER{} );
metaPair &add( const string &key, const Defaulted<T> &def, const CONVERTER &converter = CONVERTER{} );

// Meta<void>, value
metaPair &add( const Meta<void> &kwd, const T &val = T{}, const CONVERTER &converter = CONVERTER{} );

// Meta<TYPE>, value
metaPair &add( const Meta<TYPE,CONVERTER> &kwd, const           T  &val = T{} );
metaPair &add( const Meta<TYPE,CONVERTER> &kwd, const Defaulted<T> &def );

// Meta<optional>, value
metaPair &add( const Meta<optional<TYPE>,CONVERTER> &kwd, const           T  &val = T{} );
bool      add( const Meta<optional<TYPE>,CONVERTER> &kwd, const optional <T> &opt );
bool      add( const Meta<optional<TYPE>,CONVERTER> &kwd, const Defaulted<T> &def );

// Meta<Defaulted>, value
metaPair &add( const Meta<Defaulted<TYPE>,CONVERTER> &kwd, const           T  &val = T{} );
bool      add( const Meta<Defaulted<TYPE>,CONVERTER> &kwd, const optional <T> &opt );
bool      add( const Meta<Defaulted<TYPE>,CONVERTER> &kwd, const Defaulted<T> &def );
