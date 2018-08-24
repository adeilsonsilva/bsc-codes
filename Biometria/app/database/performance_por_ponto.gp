set autoscale                        # scale axes automatically
set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set terminal png font arial 14 size 2000,600 enhanced
set key horizontal center top
set output 'performance_por_ponto.png'
set xlabel 'Pontos detectados' font ',20' offset 0,-1
set ylabel 'Porcentagem de detecção' font ',20' offset 2.5,0
set style data histogram
set style histogram cluster gap 1
set style fill solid border -1
#set boxwidth 0.9
set style data histogram
plot "performance-auto" using 2:xtic(1) ti col lw 2 lc rgb 'blue'
