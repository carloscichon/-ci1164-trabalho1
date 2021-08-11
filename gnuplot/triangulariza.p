set terminal png size 500,500
set output 'METRIC_triangulariza.png'
set xlabel "Tamanhos"
set ylabel "METRIC"
plot "../METRIC_triangulariza.txt" using 1:2 title 'Não otimizado' with lines lc 7 lw 3, \
     "../METRIC_triangulariza.txt" using 1:3 title 'Otimizado' with lines lc 2 lw 3