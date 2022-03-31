set term postscript landscape monochrom noenhanced 
#set term x11 
set out "graph_0.ps"
set grid
set title "Values at Nodes (path.fbd)"
set ylabel " SYY      "
set xlabel " Length "
plot "graph_0.out" using 2:3 title 'Setname Nsym' with linespoints
