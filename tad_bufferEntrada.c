#include "tad_bufferEntrada.h"

//FUNCOES AUXILIARES//
void BufferEntradaPrint(bufferEntrada* b){
    for(int i=0; i<b->tamanho; i++) printf("%d ", b->vetBuffer[i].id);
    printf("\n");
}

/*RETORNA VERDADEIRO SE O REGISTRO ATUAL FOR O ULTIMO DO BUFFER*/
static inline bool bufferEntradaUltimo(bufferEntrada* b){
    if(&b->vetBuffer[b->proximo+1] == &b->vetBuffer[b->tamanho]) return true;
    else return false;
}

/*CARREGA O BUFFER COM N REGISTROS*/
void bufferEntradaCarrega(bufferEntrada* b, unsigned int tamanho){
    if(b->n_registros < b->tamanho) b->tamanho = b->n_registros;
    fread(&b->vetBuffer[0], sizeof(ITEM_VENDA), tamanho, b->entrada); //Lê a quantidade máxima de registros que o buffer suporta
}

//IMPLEMENTACAO PRINCIPAL//
bufferEntrada* bufferEntradaCriar(const char* arquivo_entrada, unsigned int tamanho, unsigned int n_registros){
    bufferEntrada* b = (bufferEntrada*) malloc(sizeof(bufferEntrada));
    b->vetBuffer = (ITEM_VENDA*) malloc(sizeof(ITEM_VENDA)*tamanho);
    b->tamanho = tamanho;
    b->proximo = 0;
    b->n_registros = n_registros;
    b->entrada = fopen(arquivo_entrada, "rb");
    if(b->entrada == NULL){
        perror("Erro");
        exit(1);
    }
    bufferEntradaCarrega(b, tamanho);
    return b;
}

ITEM_VENDA* bufferEntradaProximo(bufferEntrada* b){
    if(b->proximo < b->tamanho) return &b->vetBuffer[b->proximo];
}

bool bufferEntradaVazio(bufferEntrada* b){
    if(b->n_registros == 0)return true;
    else return false;
}

void bufferEntradaConsumir(bufferEntrada* b, ITEM_VENDA** saida){
    *saida = bufferEntradaProximo(b);
    if(bufferEntradaUltimo(b) && !bufferEntradaVazio(b)){
        b->proximo = -1;
        bufferEntradaCarrega(b, b->tamanho);
    }
    b->proximo++;
    b->n_registros--;
}

void bufferEntradaDestruir(bufferEntrada** b){
    bufferEntrada* temp = *b;
    fclose(temp->entrada);
    free(temp->vetBuffer);
    free(temp);
    temp = NULL;
}

bufferEntrada** InicializaVetBuffer(uint32_t bufferQuantidade, uint32_t bufferTamanho, uint32_t arquivoTamanho, uint32_t tamanhoUltimo, uint32_t resto){
    uint32_t i;
	bufferEntrada** b = (bufferEntrada**) malloc(sizeof(bufferEntrada)*bufferQuantidade);
    for(i=0; i<bufferQuantidade; i++){
        char nome[100];
        sprintf(nome, "arquivos/temp/pedaco%d", i);
        if((i+1 == bufferQuantidade) && (resto != 0)){
            arquivoTamanho = tamanhoUltimo;
        }
        bufferEntrada* bTemp = bufferEntradaCriar(nome, bufferTamanho, arquivoTamanho);
        b[i] = bTemp;
    }
    return b;
}