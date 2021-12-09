#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>
#include "big_file.h"

typedef struct bufferSaida{
    ITEM_VENDA* vetBuffer; //VETOR QUE ARMAZENA OS REGISTROS DO BUFFER;
    uint32_t tamanho; //VARIAVEL QUE GUARDA O TAMANHO DO BUFFER;
    uint32_t contador; //VARIAVEL QUE GUARDA A QUANTIDADE DE REGISTROS NO BUFFER
    uint32_t arqTam; //VARIAVEL QUE GUARDA QUANTOS REGISTROS FORAM INSERIDOS NO ARQUIVO DE SAIDA
    FILE* saida; //ARQUIVO DE SAIDA;
}bufferSaida;

/*aloca espaço para N registros e abre o arquivo de saída. Recebe por parâmetro 
o nome do arquivo de saida e seu tamanho*/
bufferSaida* bufferSaidaCriar(const char* arquivo_saida, uint32_t tamanho);
/*Insere um registro no buffer de saída. Caso o buffer tenha N registros inseridos, despeje o
conteúdo do buffer no arquivo de saída*/
void bufferSaidaInserir(bufferSaida* b, ITEM_VENDA* i);
/*Escreve o conteúdo do buffer de saída no arquivo de saída. Caso apenas M < N elementos estejam
inseridos no buffer, escreve apenas os M elementos no arquivo de saída. (Essa operação é comumente
chamada de dump). Recebe por paraetrô um buffer e um registro*/
void bufferSaidaDespejar(bufferSaida* b);
/*Fecha o arquivo de saída e liberar quaisquer variáveis alocadas dinamicamente.*/
void bufferSaidaDestruir(bufferSaida** b);
