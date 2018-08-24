set autoscale                        # scale axes automatically
set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set terminal png font arial 14 size 2000,600 enhanced
set key horizontal top left
set output 'medias_gerais.png'
set xlabel 'Sessões' font ',20' offset 0,-1
set ylabel 'Média das distâncias' font ',20' offset 2.5,0
set style data histogram
set style histogram cluster gap 1
set style fill solid border -1
#set boxwidth 0.9
set style data histogram
plot "medias_gerais" using 2:xtic(1) ti col lc rgb 'green',\
    '' using 0:2:3 ti col(3) lw 3 lc rgb 'red' with yerrorbars
    #'' using 3 ti col lw 2 lc rgb 'red'
