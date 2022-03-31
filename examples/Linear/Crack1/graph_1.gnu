set term postscript landscape monochrom noenhanced 
#set term x11 
set out "graph_1.ps"
set grid
set title "Values at Nodes (path.fbd)"
set ylabel " D2       "
set xlabel " Length "
plot "graph_1.out" using 2:3 title 'Setname Nsym' with linespoints
