#!/bin/bash

# XMLs: flatten directory, and pretty-print
for foo in fix/*.xml
do
   bar="flat/$(basename $foo)"
   txt="${bar/.xml/}.txt"
   ###one="${bar/.xml/}.one"
   ###two="${bar/.xml/}.two"
   ### ./2 $foo > $bar
   ###echo $bar "==>" $one
   ###echo $bar "==>" $one
   echo $foo "==>" $bar
   ./2 $foo > $bar
   echo $bar "==>" $txt
   cat $bar | uniq | sort | uniq > $txt
done
