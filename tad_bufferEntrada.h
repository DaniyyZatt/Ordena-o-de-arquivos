#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "big_file.h"

typedef struct bufferEntrada{
    ITEM_VENDA* vetBuffer; //VETOR QUE ARMAZENA OS REGISTROS DO BUFFER;
    uint32_t tamanho; //VARIAVEL QUE GUARDA O TAMANHO DO BUFFER;
    uint32_t proximo; //VARIAVEL QUE GUARDA O ENDEREÇO DO PROXIMO ELEMENTO A SER CONSUMIDO;
    unsigned int n_registros; //VARIAVEL QUE GUARDA A QUANTIDADE DE REGISTROS NO ARQUIVO;
    FILE* entrada; // ARQUIVO DE ENTRADA
}bufferEntrada;

/*Aloca espaço para N registros, abre o arquivo de entrada, lê os primeiros N registros do arquivo
de entrada e inicializa quaisquer variáveis de controle necessárias: Recebe como parâmetro o nome
do arquivo de entrada, o tamanho do buffer e quantidade de registros do arquivo*/
bufferEntrada* bufferEntradaCriar(const char* arquivo_entrada, unsigned int tamanho, unsigned int n_registros);
/*Retorna o próximo registro do buffer, mas não o consome;*/
ITEM_VENDA* bufferEntradaProximo(bufferEntrada* b);

/*consome o próximo registro do buffer e o retorna. Neste caso “consumir” é apontar para o
próximo elemento do buffer. Caso o registro atual seja o último do buffer, ler os próximos 
N registros do arquivo de entrada: Recebe por parâmetro um buffer*/
void bufferEntradaConsumir(bufferEntrada* b, ITEM_VENDA** saida);
/*Retorna verdadeiro se todos os registros do arquivo já foram consumidos pela função “Consumir”.
Caso contrário, retorna falso*/
bool bufferEntradaVazio(bufferEntrada* b);
/*fechar o arquivo de entrada e liberar quaisquer variáveis alocadas dinâmicamente. Exlucui o 
arquivo o qual estava associado*/
void bufferEntradaDestruir(bufferEntrada** b);
//Escreve na tela o conteúdo de um buffer recebido por parâmetro
void BufferEntradaPrint(bufferEntrada* b);
/*Carrega um buffer de entrada com n registros de um arquivo. Recebe por parâmetro um buffer,
e uma quantidade de registros*/
void bufferEntradaCarrega(bufferEntrada* b, unsigned int tamanho);
bufferEntrada** InicializaVetBuffer(uint32_t bufferQuantidade, uint32_t bufferTamanho, uint32_t arquivoTamanho, uint32_t tamanhoUltimo, uint32_t resto);