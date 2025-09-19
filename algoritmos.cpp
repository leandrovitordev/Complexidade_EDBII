#include "algoritmos.hpp"
#include <utility> // Para std::swap, usado no Quicksort

// 1. Selection Sort
void selectionSort(int vetor[], int tamanho) {
    int i, j, indice_menor;

    // Laço principal que percorre o vetor até a penúltima posição
    for (i = 0; i < tamanho - 1; i++) {
        
        // Assume que o menor elemento é o primeiro da parte não ordenada
        indice_menor = i;

        // Laço interno que busca pelo menor elemento no resto do vetor
        for (j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[indice_menor]) {
                indice_menor = j;
            }
        }

        // Se o menor elemento encontrado não for o que já estava na posição,
        // realiza a troca.
        if (indice_menor != i) {
            std::swap(vetor[i], vetor[indice_menor]);
        }
    }
}

// 2. Quicksort

// Função auxiliar para o Quicksort: particiona o vetor e retorna o índice do pivô
int particionar(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim]; // Escolhendo o último elemento como pivô
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        if (vetor[j] < pivo) {
            i++;
            std::swap(vetor[i], vetor[j]);
        }
    }
    std::swap(vetor[i + 1], vetor[fim]);
    return (i + 1);
}

// Função principal do Quicksort
void quickSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        // indicePivo é o índice de particionamento, vetor[indicePivo] está no lugar certo
        int indicePivo = particionar(vetor, inicio, fim);

        // Ordena os elementos separadamente antes e depois da partição
        quickSort(vetor, inicio, indicePivo - 1);
        quickSort(vetor, indicePivo + 1, fim);
    }
}


// 3. Busca Sequencial 
int buscaSequencial(int vetor[], int tamanho, int alvo) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == alvo) {
            return i; // Retorna o índice onde o elemento foi encontrado
        }
    }
    return -1; // Retorna -1 se o elemento não estiver no vetor
}

// 4. Busca Binária
int buscaBinaria(int vetor[], int tamanho, int alvo) {
    int esquerda = 0;
    int direita = tamanho - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        // Se o alvo estiver no meio
        if (vetor[meio] == alvo) {
            return meio;
        }

        // Se o alvo for menor, ignora a metade direita
        if (vetor[meio] > alvo) {
            direita = meio - 1;
        }
        // Se o alvo for maior, ignora a metade esquerda
        else {
            esquerda = meio + 1;
        }
    }
    return -1; // Retorna -1 se o elemento não estiver no vetor
}