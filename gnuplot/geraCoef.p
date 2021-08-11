set terminal png size 500,500
set output 'METRIC_geraCoef.png'
set xlabel "Tamanhos"
set ylabel "METRIC"
plot "../METRIC_geraCoeficientes.txt" using 1:2 title 'Geração de Coeficientes' w l lc 2 lw 3