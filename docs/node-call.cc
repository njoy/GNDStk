
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,                          KEYWORDS &&...kwds ) const;
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,                          KEYWORDS &&...kwds );
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, const string label,      KEYWORDS &&...kwds ) const;
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, const string label,      KEYWORDS &&...kwds );
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, const char *const label, KEYWORDS &&...kwds ) const;
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, const char *const label, KEYWORDS &&...kwds );
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, const regex labelRegex,  KEYWORDS &&...kwds ) const;
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, const regex labelRegex,  KEYWORDS &&...kwds );
