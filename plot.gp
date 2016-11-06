set term png
set out 'rysunek.png'
set xlabel "x"
set ylabel "T(x)" rotate parallel
plot 'dane.dat' u 1:2 w l

set term png
set out 'rysunek2.png'
set xlabel "t"
set ylabel "x(t)" rotate parallel
plot 'dane2.dat' u 1:2 w l
l
