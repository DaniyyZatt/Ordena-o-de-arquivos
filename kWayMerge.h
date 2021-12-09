#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>


/*Inicializa um vetor de buffers e seus elementos: Recebe como parametro
a quantidade de buffers que ira comportar, a capacidade de cada um deles,
o tamanho dos arquivos que serão manipulados, o tamanho do ultimo arquivo
e uma flag resto para o caso de haver sobra no arquivo final*/

void kWayMerge(bufferEntrada** entrada, bufferSaida* saida, uint32_t bufferQuantidade);
void kWayMergeSort(const char* entradaNome, uint32_t maxMemB, uint32_t tamanhoBufferSaida, const char* saidaNome, uint32_t tamanhoArquivoEntrada);