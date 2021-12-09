#include "big_file.h"

void troca(ITEM_VENDA* v, int i, int j){
    ITEM_VENDA temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

uint32_t partition(ITEM_VENDA* v, int p, int r){
    ITEM_VENDA x;
    long int i, j;
    x = v[r];
    i = p-1;
    for(j=p; j<r; j++){
        if(v[j].id <= x.id){
            i++;
            troca(v, i, j);
        }
    }
    troca(v, i+1, r);
    return i+1;
}

void quickSort(ITEM_VENDA* v, int e, int d){
    uint32_t q;
    if(e<d){
        q = partition(v, e, d);
        quickSort(v, e, q-1);
        quickSort(v, q+1, d);
    }
}

static inline void trocar(ITEM_VENDA* x, ITEM_VENDA* y){
    ITEM_VENDA aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

unsigned int random_32bits(){
    unsigned int x;
    x = rand() & 0xff;
    x |= (rand() & 0xff) << 8;
    x |= (rand() & 0xff) << 16;
    x |= (rand() & 0xff) << 24;
    return x;
}

static void embaralhar(ITEM_VENDA* v, int ini, int fim){
    int i, j;
    for(i = fim-1; i > ini; i--){
        j = (random_32bits() % (i + 1));
        j = j <= ini? ini+1 : j;
        trocar(&v[i], &v[j]);
    }
}

void gerar_array_iv(const char* arquivo_saida, unsigned int n_registros, int seed){
    ITEM_VENDA* iv;
    FILE* saida;
    uint32_t i;
    time_t t = time(NULL);
    srand(seed);
    iv = malloc(sizeof(ITEM_VENDA) * n_registros);
    for(i = 0; i < n_registros; i++){
        iv[i].id = i;
        iv[i].id_venda = i + (rand() % 2);
        iv[i].desconto = (rand() % 10) / (float)100;
        iv[i].data = t + (( -1 * (rand() % 30)) * 86400) ;
        iv[i].obs[0] = '\0';
    }
    embaralhar(iv, 0, n_registros);
    saida = fopen(arquivo_saida, "wb");
    if(saida == NULL){
        perror("Erro");
        exit(1);
    }
    fwrite(iv, sizeof(ITEM_VENDA), n_registros, saida);
    fclose(saida);
    free(iv);
    return;
}

void printArquivo(const char* arquivo, unsigned int tam){
    unsigned int i;
    FILE* temp = fopen(arquivo, "rb");
    ITEM_VENDA* iv = malloc(sizeof(ITEM_VENDA) * tam);
    fread(&iv[0], sizeof(ITEM_VENDA), tam, temp);
    for(i = 0; i < tam; i++){
        printf("%d ", iv[i].id);
    }
    printf("\n\n");
    fclose(temp);
    free(iv);
    return;
}

uint32_t dividirArquivo(const char* entrada, uint32_t tamanhoPedaco, int k, uint32_t tamanhoArquivo){
    int i;
    long int cont = tamanhoArquivo/1024;
    uint32_t tamanhoSaida = tamanhoPedaco;
    FILE* f1 = fopen(entrada, "rb");
    for(i=0; i<k; i++){
        if(tamanhoSaida > cont)tamanhoSaida = cont;
        ITEM_VENDA* vet = malloc(sizeof(ITEM_VENDA)*tamanhoSaida);
        char nome[100];
        sprintf(nome, "arquivos/temp/pedaco%d", i);
        FILE* temp = fopen(nome, "wb");
        fread(&vet[0], sizeof(ITEM_VENDA), tamanhoSaida, f1);
        quickSort(vet, 0, tamanhoSaida-1);
        fwrite(vet, sizeof(ITEM_VENDA), tamanhoSaida, temp);
        // printArquivo(nome, tamanhoSaida);
        fclose(temp);
        cont -= tamanhoSaida;
        free(vet); 
        vet = NULL;
    } 
    fclose(f1);
    return tamanhoSaida;
}

uint32_t tamanhoArquivoBytes(const char* nomeArquivo){
    FILE* arq = fopen(nomeArquivo, "rb");
    fseek (arq, 0, SEEK_END);
    uint32_t size = ftell(arq);
    fclose(arq);
    return size;
}