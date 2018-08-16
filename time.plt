#スクリプト
set terminal pngcairo monochrome enhanced size 480,360
set xlabel "Request number"
set ylabel "Calculation time"
set key right top
plot[1:15][0:1200] 'time.dat' using 1:2 title "SDS" with linespoints pt 2,\
                  'time.dat' using 1:3 title "LD" with linespoints pt 8,\
                  'time.dat' using 1:4 title "DD" with linespoints pt 6
set out "time.png"
replot
