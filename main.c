#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *V, int N) {
    int i, j, aux;
    for (i = 1; i < N; i++) {
        aux = V[i];
        for (j = i; (j > 0) && (aux < V[j - 1]); j--) {
            V[j] = V[j - 1];
        }
        V[j] = aux;
    }
}

void imprimirVetor(int *v, int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int* gerarVetorAleatorio(int N) {
    int *vetor = (int *)malloc(N * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    
    for (int i = 0; i < N; i++) {
        vetor[i] = rand() % 100; // Números entre 0 e 99
    }
    return vetor;
}

int main() {
    int tamanho;
    srand(time(NULL)); // Inicializa a semente para números aleatórios
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    int *vetor = gerarVetorAleatorio(tamanho);
    
    printf("\nVetor antes da ordenacao:\n");
    imprimirVetor(vetor, tamanho);
    
    insertionSort(vetor, tamanho);
    
    printf("\nVetor depois da ordenacao:\n");
    imprimirVetor(vetor, tamanho);
    
    free(vetor);
    
    return 0;
}
