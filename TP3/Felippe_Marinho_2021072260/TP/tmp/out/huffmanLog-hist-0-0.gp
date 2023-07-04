set term png
set output "../tmp/out/huffmanLog-hist-0-0.png"
set style fill solid 1.0
set title "Distancia de Pilha (Total 16348339 # 4055830 Media 4.03) - Fase  0 - ID 0"
set xlabel "Distancia"
set ylabel "Frequencia"
plot [-1:25] "../tmp/out/huffmanLog-hist-0-0.gpdat" u 3:4 w boxes t ""
