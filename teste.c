#include "tad_bufferEntrada.h"
#include "tad_bufferSaida.h"
#include "big_file.h"

#include "kWayMerge.h"

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
            ITEM_VENDA item;
            bufferEntradaConsumir(b, &item);
            bufferSaidaInserir(saida, &item);
        }
    }
    if((saida->contador>0) && (saida->contador <= saida->tamanho)) bufferSaidaDespejar(saida);
}

void kWayMerge(bufferEntrada** entrada, bufferSaida* saida, uint32_t bufferQuantidade){
    uint32_t i;
    uint32_t j;
    uint32_t all = 0;
    for(i=0; i<bufferQuantidade; i++) all += entrada[i]->n_registros;
    bufferEntrada* b;
}