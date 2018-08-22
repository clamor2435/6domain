#/usr/bin/bash

i="1"
while [ $i -le 3 ]
  do
  j="1"
  while [ $j -le 3 ]
      do
        ./random_request $i >$i.dat
        ./runDD $i > run
        ampl run
        echo DD request=$i $j = times
        ./runLD $i > run
        ampl run
        echo LD request=$i $j =  times
        ./runSDS $i > run
        ampl run
        echo SDS request=$i $j = times
        j=`expr $j + 1`
      done
  i=`expr $i + 1`
  done
