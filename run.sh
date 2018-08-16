#/usr/bin/bash

i="2"
while [ $i -le 25 ]
  do
  j="1"
  while [ $j -le 100 ]
      do
        ./random $i >$i.dat
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
