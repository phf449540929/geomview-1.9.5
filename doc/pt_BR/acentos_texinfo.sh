#!/bin/bash
#powered by Jorge Barros de Abreu under GPL
#ficmatin01 at solar dot com dot br
# this script needs "sed" and "mktemp" command
#adjust iso8859-1 characters to texinfo 
ARQ_TMP='mkstemp'
if [ $# = 0 ] #testa se nao existe parametro
 then
                echo -e "\n\tScript for diacritical marks in texinfo"
  echo -e "\n\tThis script needs "sed" and "mktemp" command"
                echo -e "\tusage: $0 file.texi"
                echo -e "\tthe output is renamed to file.texi itself"
                echo
                exit 1
fi
cat $1 | sed "/�/s/�/@'{e}/g" > $ARQ_TMP
cat $ARQ_TMP | sed "/�/s/�/@'{a}/g" > $1
# cat $1 | sed "/�/s/�/@value{cedilha}/g" > $ARQ_TMP
# cat $1 | sed "/�/s/�/@value{Cedilha}/g" > $ARQ_TMP
cat $1 | sed "/�/s/�/@,{c}/g" > $ARQ_TMP
cat $ARQ_TMP | sed "/�/s/�/@~{a}/g" > $1
cat $1 | sed "/�/s/�/@'{A}/g" > $ARQ_TMP
cat $ARQ_TMP | sed "/�/s/�/@\`{a}/g" > $1
cat $1 | sed "/�/s/�/@\`{A}/g" > $ARQ_TMP
cat $ARQ_TMP | sed "/�/s/�/@'{E}/g" > $1
cat $1 | sed "/�/s/�/@'{I}/g" > $ARQ_TMP
cat $ARQ_TMP | sed "/�/s/�/@'{u}/g" > $1
cat $1 | sed "/�/s/�/@'{U}/g" > $ARQ_TMP
cat $ARQ_TMP | sed "/�/s/�/@,{C}/g" > $1
cat $1 | sed "/�/s/�/@~{o}/g" > $ARQ_TMP
cat $ARQ_TMP | sed "/�/s/�/@~{O}/g" > $1
cat $1 | sed "/�/s/�/@\"{u}/g" > $ARQ_TMP
cat $ARQ_TMP | sed "/�/s/�/@\"{U}/g" > $1
cat $1 | sed "/�/s/�/@~{A}/g" > $ARQ_TMP
cat $ARQ_TMP | sed "/�/s/�/@'{o}/g" > $1
cat $1 | sed "/�/s/�/@^{E}/g" > $ARQ_TMP
cat $ARQ_TMP | sed "/�/s/�/@^{e}/g" > $1
cat $1 | sed "/�/s/�/@'{i}/g" > $ARQ_TMP
cat $ARQ_TMP | sed "/�/s/�/@^{e}/g" > $1
cat $1 | sed "/�/s/�/@^{o}/g" > $ARQ_TMP
cat $ARQ_TMP | sed "/�/s/�/@^{O}/g" > $1
cat $1 | sed "/�/s/�/@^{a}/g" > $ARQ_TMP
cat $ARQ_TMP | sed "/�/s/�/@^{A}/g" > $1
rm $ARQ_TMP