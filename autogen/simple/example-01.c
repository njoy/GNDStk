
#include <stdio.h>
#include "v1.h"

int main()
{
   // colored diagnostics and prettyprinting
   color(1);

   Foobar one = FoobarDefault();
   Foobar two = FoobarDefault();

   FoobarAssign(one,two);
   FoobarPrint(one);
   FoobarPrintXML(one);
   FoobarPrintJSON(one);
}
