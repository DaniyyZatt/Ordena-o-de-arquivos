#include "tad_bufferEntrada.h"
#include "tad_bufferSaida.h"
#include "big_file.h"
#include "kWayMerge.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>


void teste1(uint32_t b, uint32_t s){
    uint32_t tamEntrada = 256000;// Tamanho do arquivo de entrada (E);
    printf("TESTE PARA %d registros \n", tamEntrada);
    int seed = 42;
    char entrada[100] = "arquivos/entrada.dat";// Nome do arquivo de saída;
    gerar_array_iv(entrada, tamEntrada, seed);
    char saida[100] = "arquivos/saida.dat";// Nome do arquivo de saída;
    uint32_t maxBytes = b;// Número máximo de bytes que podem ser usados para armazenar registros durante toda a operação (B);
    uint32_t tamBufferSaida = s;// Tamanho do buffer de saída em bytes (S);
    kWayMergeSort(entrada, maxBytes, tamBufferSaida, saida, tamanhoArquivoBytes("arquivos/entrada.dat"));
    // printArquivo(saida, tamEntrada);
}

void teste2(uint32_t b, uint32_t s){
    uint32_t tamEntrada = 512000;// Tamanho do arquivo de entrada (E);
    printf("TESTE PARA %d registros \n", tamEntrada);
    int seed = 42;
    char entrada[100] = "arquivos/entrada.dat";// Nome do arquivo de saída;
    gerar_array_iv(entrada, tamEntrada, seed);
    char saida[100] = "arquivos/saida.dat";// Nome do arquivo de saída;
    uint32_t maxBytes = b;// Número máximo de bytes que podem ser usados para armazenar registros durante toda a operação (B);
    uint32_t tamBufferSaida = s;// Tamanho do buffer de saída em bytes (S);
    kWayMergeSort(entrada, maxBytes, tamBufferSaida, saida, tamanhoArquivoBytes("arquivos/entrada.dat"));
}

void teste3(uint32_t b, uint32_t s){
    uint32_t tamEntrada = 921600;// Tamanho do arquivo de entrada (E);
    printf("TESTE PARA %d registros \n", tamEntrada);
    int seed = 42;
    char entrada[100] = "arquivos/entrada.dat";// Nome do arquivo de saída;
    gerar_array_iv(entrada, tamEntrada, seed);
    char saida[100] = "arquivos/saida.dat";// Nome do arquivo de saída;
    uint32_t maxBytes = b;// Número máximo de bytes que podem ser usados para armazenar registros durante toda a operação (B);
    uint32_t tamBufferSaida = s;// Tamanho do buffer de saída em bytes (S);
    kWayMergeSort(entrada, maxBytes, tamBufferSaida, saida, tamanhoArquivoBytes("arquivos/entrada.dat"));
}

void teste4(uint32_t b, uint32_t s){
    uint32_t tamEntrada = 1572864;// Tamanho do arquivo de entrada (E);
    printf("TESTE PARA %d registros \n", tamEntrada);
    int seed = 42;
    char entrada[100] = "arquivos/entrada.dat";// Nome do arquivo de saída;
    gerar_array_iv(entrada, tamEntrada, seed);
    char saida[100] = "arquivos/saida.dat";// Nome do arquivo de saída;
    uint32_t maxBytes = b;// Número máximo de bytes que podem ser usados para armazenar registros durante toda a operação (B);
    uint32_t tamBufferSaida = s;// Tamanho do buffer de saída em bytes (S);
    kWayMergeSort(entrada, maxBytes, tamBufferSaida, saida, tamanhoArquivoBytes("arquivos/entrada.dat"));
}

int main(){
    uint32_t b;
    clock_t t;

    b = 8388608;
        t = clock();
        teste1(b, b/8);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste1(b, b/4);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste1(b, b/2);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));
    
    b = 16777216;
        t = clock();
        teste1(b, b/8);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste1(b, b/4);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste1(b, b/2);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

    b = 33554432;
        t = clock();
        teste1(b, b/8);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste1(b, b/4);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste1(b, b/2);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

    b = 16777216;
        t = clock();
        teste2(b, b/8);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste2(b, b/4);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste2(b, b/2);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

    b = 33554432;
        t = clock();
        teste2(b, b/8);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste2(b, b/4);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste2(b, b/2);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

    b = 67108864;
        t = clock();
        teste2(b, b/8);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste2(b, b/4);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste2(b, b/2);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

b = 67108864;
        t = clock();
        teste3(b, b/8);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste3(b, b/4);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste3(b, b/2);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

b = 134217728;
        t = clock();
        teste3(b, b/8);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste3(b, b/4);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste3(b, b/2);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

b = 268435456;
        t = clock();
        teste3(b, b/8);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste3(b, b/4);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste3(b, b/2);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

b = 67108864;
        t = clock();
        teste4(b, b/8);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste4(b, b/4);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste4(b, b/2);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

b = 134217728;
        t = clock();
        teste4(b, b/8);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste4(b, b/4);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste4(b, b/2);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

b = 268435456;
        t = clock();
        teste4(b, b/8);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste4(b, b/4);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

        t = clock();
        teste4(b, b/2);
        t = clock() - t;
        printf("Tempo de execucao: %lf \n", ((double)t)/((CLOCKS_PER_SEC)));

    return 0;
}