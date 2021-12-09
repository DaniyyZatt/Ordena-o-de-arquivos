#pragma once

#include <stdint.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ITEM_VENDA{
    uint32_t id;
    uint32_t id_venda;
    uint32_t data;
    float desconto;
    char obs[1008];
}ITEM_VENDA;

/*Gera um arquivo com n registros aleatorios*/
void gerar_array_iv(const char* arquivo_saida, unsigned int n_registros, int seed);
/*Escreve o conteudo de um arquivo recebido por parametro*/
void printArquivo(const char* arquivo, unsigned int tam);
/*Divide um arquivo de entrada em n pedaços: Recebe como parâmetro o aquivo
que será dividido, o tamanho de cada pedaço e o tamanho inicial do arquivo*/
uint32_t dividirArquivo(const char* entrada, uint32_t tamanhoPedaco, int k, uint32_t tamanhoArquivo);
/*Retorna o valor em bytes de um arquivo. Recebe como parâmetro um arquivo de entrada*/
uint32_t tamanhoArquivoBytes(const char* nomeArquivo);