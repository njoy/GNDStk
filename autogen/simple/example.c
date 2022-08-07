
#include <stdio.h>
#include "v3.h"

int main()
{
   // colorize diagnostics
   colors(1);

   printf("1\n"); const Foobar one = FoobarCreate();
   printf("2\n"); const Foobar two = FoobarCreate();
   printf("3\n"); FoobarAssign(one,two);
   printf("4\n"); FoobarPrint(one);
   printf("5\n"); FoobarPrintXML(one);
   printf("6\n"); FoobarPrintJSON(one);
   printf("7\n");

   size_t i = 1234;
   printf("%i",(int)i);
}
