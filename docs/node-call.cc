
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,                          KEYWORDS &&...keywords ) const;
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd,                          KEYWORDS &&...keywords );
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, const string label,      KEYWORDS &&...keywords ) const;
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, const string label,      KEYWORDS &&...keywords );
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, const char *const label, KEYWORDS &&...keywords ) const;
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, const char *const label, KEYWORDS &&...keywords );
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, const regex labelRegex,  KEYWORDS &&...keywords ) const;
decltype(auto) operator()( const Child<TYPE,ALLOW,CONVERTER,FILTER> &kwd, const regex labelRegex,  KEYWORDS &&...keywords );
