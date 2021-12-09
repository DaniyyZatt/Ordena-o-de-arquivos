all:
	gcc -g big_file.c -c
	gcc -g tad_bufferEntrada.c -c 
	gcc -g tad_bufferSaida.c -c
	gcc -g kWayMerge.c -c
	gcc -g main.c tad_bufferEntrada.o tad_bufferSaida.o big_file.o kWayMerge.o -o main