#include "tad_bufferEntrada.h"
#include "tad_bufferSaida.h"
#include "big_file.h"
#include "kWayMerge.h"

/*IMPLEMENTACAO PRINCIPAL*/
void kWayMerge(bufferEntrada** entrada, bufferSaida* saida, uint32_t bufferQuantidade){
    uint32_t i;
    uint32_t j;
    uint32_t all = 0;
    for(i=0; i<bufferQuantidade; i++) all += entrada[i]->n_registros;
    bufferEntrada* b;
    for(i=0; i<all; i++){
        uint32_t min = INT_MAX;
        uint32_t indice = -1;
        for(j=0; j<bufferQuantidade; j++){
            if(!bufferEntradaVazio(entrada[j])){
                b = entrada[j];
                ITEM_VENDA* temp = bufferEntradaProximo(b);
                if((temp->id < min)){
                    indice = j;
                    min = temp->id;  
                }
            }
        }
        if(indice != -1){
            b = entrada[indice];
            ITEM_VENDA* item;
            bufferEntradaConsumir(b, &item);
            bufferSaidaInserir(saida, item);
        }
    }
    if((saida->contador>0) && (saida->contador <= saida->tamanho)) bufferSaidaDespejar(saida);
}

void kWayMergeSort(const char* entradaNome, uint32_t maxMemB, uint32_t tamanhoBufferSaida, const char* saidaNome, uint32_t tamanhoArquivoEntrada){
    //VARIAVEIS DE APOIO;
    int i;
    //NOTACOES
    uint32_t maxBytes = maxMemB;// Número máximo de bytes que podem ser usados para armazenar registros durante toda a operação (B);
    uint32_t tamBufferSaida = tamanhoBufferSaida;// Tamanho do buffer de saída em bytes (S);
    uint32_t tamEntrada = tamanhoArquivoEntrada;// Tamanho do arquivo de entrada (E);
    int quantPedaco = tamEntrada/maxBytes;// Quantidade de pedacos (K); (E/B);
    if(tamEntrada%maxBytes != 0) quantPedaco = tamEntrada/maxBytes+1;// -> Arredondamento;
    int resto = tamEntrada%maxBytes;
    uint32_t tamPedaco = (tamEntrada/quantPedaco)/1024; // Tamanho de cada pedaco do arquivo de entrada (E/K);
    uint32_t tamBufferEntrada = ((maxBytes-tamBufferSaida)/quantPedaco)/1024;// Tamanho Buffer de Entrada ((B-S)/K)/1024;
    //Dividir arquivo de entrada
    uint32_t tamanhoUltimo = dividirArquivo(entradaNome, tamPedaco, quantPedaco, tamanhoArquivoEntrada);
    //Inicializar buffers 
    bufferEntrada** b = InicializaVetBuffer(quantPedaco, tamBufferEntrada, (tamanhoArquivoEntrada/1024)/quantPedaco, tamanhoUltimo, resto);
    bufferSaida* bs = bufferSaidaCriar(saidaNome, tamBufferSaida);
    //Intercalar no arquivo de saida
    kWayMerge(b, bs, quantPedaco);
    bufferSaidaDestruir(&bs);
    for(i=0; i<quantPedaco; i++) bufferEntradaDestruir(&b[i]);
    for(i=0; i<quantPedaco; i++){
        char nome[100];
        sprintf(nome, "arquivos/temp/pedaco%d", i);
        remove(nome);
    }
}