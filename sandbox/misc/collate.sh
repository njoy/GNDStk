#!/bin/bash

# XMLs: flatten directory, and pretty-print
for xmlin in fix/*.xml
do
   xmlout="flat/$(basename $xmlin)" # not actually xml
   echo $xmlin "==>" $xmlout
   /bin/rm $xmlout
   ./collate $xmlin > $xmlout

   uniqout="${xmlout/.xml/}.txt"
   echo $xmlout "==>" $uniqout
   /bin/rm $uniqout
   cat $xmlout | uniq | sort | uniq > $uniqout
done
