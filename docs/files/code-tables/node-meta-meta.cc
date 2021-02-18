
const   string  &meta ( const Meta<          void            > &kwd ) const;
        string  &meta ( const Meta<          void            > &kwd );
          TYPE   meta ( const Meta<          TYPE,  CONVERTER> &kwd ) const;
optional <TYPE>  meta ( const Meta<optional <TYPE>, CONVERTER> &kwd ) const;
Defaulted<TYPE>  meta ( const Meta<Defaulted<TYPE>, CONVERTER> &kwd ) const;
          TYPE   meta ( const Meta<variant  <Ts...>,CONVERTER> &kwd ) const;
