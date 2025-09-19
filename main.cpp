#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include "algoritmos.hpp"

std::vector<int> gerarVetorAleatorio(int tamanho) {
    std::vector<int> vetor(tamanho);
    std::random_device dispositivo_aleatorio;
    std::mt19937 gerador(dispositivo_aleatorio());
    std::uniform_int_distribution<> distribuicao(0, tamanho * 10);

    for (int i = 0; i < tamanho; ++i) {
        vetor[i] = distribuicao(gerador);
    }
    return vetor;
}

int main() {
   
    // Ns para algoritmos LENTOS como o Selection Sort (O(n^2))
    std::vector<int> tamanhos_n_lento = {1000, 5000, 10000, 15000, 20000};

    // Ns para algoritmos RÁPIDOS como Quicksort e Buscas
    std::vector<int> tamanhos_n_rapido = {1000, 10000, 50000, 100000, 200000};

    int numero_repeticoes_ordenacao = 5;
    int numero_buscas_para_media = 10000;

    std::cout << "Iniciando análise empírica de complexidade...\n\n";

    // TESTE DOS ALGORITMOS DE ORDENAÇÃO 

    // Teste para o Selection Sort (usando o vetor LENTO)
    std::cout << "--- Selection Sort ---\n";

    for (int n : tamanhos_n_lento) {
        double tempo_total_ms = 0.0;
        for (int i = 0; i < numero_repeticoes_ordenacao; ++i) {
            std::vector<int> vetor_original = gerarVetorAleatorio(n);
            std::vector<int> vetor_para_ordenar = vetor_original;

            auto inicio = std::chrono::high_resolution_clock::now();

            // 👇👇 ADICIONE A CHAMADA DA FUNÇÃO AQUI 👇👇
            selectionSort(vetor_para_ordenar.data(), n);

            auto fim = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double, std::milli> duracao = fim - inicio;
            tempo_total_ms += duracao.count();
        }
        double tempo_medio_ms = tempo_total_ms / numero_repeticoes_ordenacao;
        std::cout << "N = " << n << ", Tempo Medio: " << tempo_medio_ms << " ms\n";
    }

    // Teste para o Quicksort (usando o vetor RÁPIDO)
    std::cout << "\n--- Quicksort ---\n";
    for (int n : tamanhos_n_rapido) {
        double tempo_total_ms = 0.0;
        for (int i = 0; i < numero_repeticoes_ordenacao; ++i) {
            std::vector<int> vetor_original = gerarVetorAleatorio(n);
            std::vector<int> vetor_para_ordenar = vetor_original;

            auto inicio = std::chrono::high_resolution_clock::now();
            quickSort(vetor_para_ordenar.data(), 0, n - 1);
            auto fim = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double, std::milli> duracao = fim - inicio;
            tempo_total_ms += duracao.count();
        }
        double tempo_medio_ms = tempo_total_ms / numero_repeticoes_ordenacao;
        std::cout << "N = " << n << ", Tempo Medio: " << tempo_medio_ms << " ms\n";
    }

// TESTE DOS ALGORITMOS DE BUSCA

    // Número de vezes que vamos repetir a busca para obter um tempo mensurável

    std::cout << "\n--- Busca Sequencial ---\n";
    // Usando o vetor de 'n' rápido para as buscas
    for (int n : tamanhos_n_rapido) {
        std::vector<int> vetor = gerarVetorAleatorio(n);
        int alvo = vetor[n / 2]; // Escolhe um elemento do meio para buscar

        auto inicio = std::chrono::high_resolution_clock::now();
        
        for(int i = 0; i < numero_buscas_para_media; ++i) {
            buscaSequencial(vetor.data(), n, alvo);
        }
        
        auto fim = std::chrono::high_resolution_clock::now();

        // Calcula a duração total para todas as buscas
        std::chrono::duration<double, std::micro> duracao_total = fim - inicio;
        double tempo_por_busca = duracao_total.count() / numero_buscas_para_media;

        std::cout << "N = " << n << ", Tempo por busca: " << tempo_por_busca << " microssegundos\n";
    }

    std::cout << "\n--- Busca Binaria ---\n";
    for (int n : tamanhos_n_rapido) {
        std::vector<int> vetor = gerarVetorAleatorio(n);
        int alvo = vetor[n / 2];
        std::sort(vetor.begin(), vetor.end());

        auto inicio = std::chrono::high_resolution_clock::now();

        for(int i = 0; i < numero_buscas_para_media; ++i) {
            buscaBinaria(vetor.data(), n, alvo);
        }
        
        auto fim = std::chrono::high_resolution_clock::now();
        
        std::chrono::duration<double, std::micro> duracao_total = fim - inicio;
        double tempo_por_busca = duracao_total.count() / numero_buscas_para_media;
        
        std::cout << "N = " << n << ", Tempo por busca: " << tempo_por_busca << " microssegundos\n";
    }

    std::cout << "\nAnalise concluida.\n";
    return 0;
}