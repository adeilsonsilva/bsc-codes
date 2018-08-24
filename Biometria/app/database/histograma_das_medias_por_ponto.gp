set autoscale                        # scale axes automatically
set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set terminal png font arial 14 size 2000,600 enhanced
set key horizontal center
set output 'histograma_das_medias_por_ponto.png'
set xlabel 'Ponto marcado' font ',20' offset 0,-1
set ylabel 'Média das distâncias' font ',20' offset 2.5,0
set style data histogram
set style histogram cluster gap 1
set style fill solid border -1
#set boxwidth 0.9
set style data histogram
plot "medias_por_ponto" using 2:xtic(1) ti col lw 2 lc rgb 'red',\
    '' using 3 ti col lw 2 lc rgb 'green', \
    '' using 4 ti col lw 2 lc rgb 'blue', \
    '' using 5 ti col lw 2 lc rgb 'black'
