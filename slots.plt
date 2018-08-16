#スクリプト
set terminal pngcairo monochrome enhanced size 480,360
set xlabel "Request number"
set ylabel "Average slots"
set key right bottom
plot[1:15][0:400] 'slots.dat' using 1:2 title "SDS" with linespoints pt 2,\
                  'slots.dat' using 1:3 title "LD" with linespoints pt 8,\
                  'slots.dat' using 1:4 title "DD" with linespoints pt 6
set out "slots.png"
replot
