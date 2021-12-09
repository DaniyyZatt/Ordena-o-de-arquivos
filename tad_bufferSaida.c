#include "tad_bufferSaida.h"

bufferSaida* bufferSaidaCriar(const char* arquivo_saida, uint32_t tamanho){
    bufferSaida* b = (bufferSaida*) malloc(sizeof(bufferSaida));
    b->tamanho = tamanho/1024;
    b->vetBuffer = (ITEM_VENDA*) malloc(sizeof(ITEM_VENDA)*b->tamanho);
    b->contador = 0;
    b->saida = fopen(arquivo_saida, "wb");
    if(b->saida == NULL){
        perror("Erro");
        exit(1);
    }
    return b;
}

void bufferSaidaDespejar(bufferSaida* b){
    if(b->contador < b->tamanho) b->tamanho = b->contador; 
    fwrite(b->vetBuffer, sizeof(ITEM_VENDA), b->tamanho, b->saida);
    b->contador = 0;
}

void bufferSaidaInserir(bufferSaida* b, ITEM_VENDA* i){
    b->vetBuffer[b->contador] = *i;
    b->contador++;
    b->arqTam++;
    if(b->contador == b->tamanho)bufferSaidaDespejar(b);
}

void bufferSaidaDestruir(bufferSaida** b){
    bufferSaida* temp = *b;
    fclose(temp->saida);
    free(temp->vetBuffer);
    free(temp);
    temp = NULL;
}