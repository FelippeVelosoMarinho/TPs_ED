set term png
set output "../tmp/out/huffmanLog-acesso-1.png"
set title "Grafico de acesso - ID 1"
set xlabel "Acesso"
set ylabel "Endereco"
plot "../tmp/out/huffmanLog-acesso-0-1.gpdat" u 2:4 w points t "L", "../tmp/out/huffmanLog-acesso-1-1.gpdat" u 2:4 w points t "E"
