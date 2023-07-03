set term png
set output "../tmp/out/huffmanLog-hist-0-1.png"
set style fill solid 1.0
set title "Distancia de Pilha (Total 91 # 104 Media 0.88) - Fase  0 - ID 1"
set xlabel "Distancia"
set ylabel "Frequencia"
plot [-1:2] "../tmp/out/huffmanLog-hist-0-1.gpdat" u 3:4 w boxes t ""
