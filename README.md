# Complexidade_EDBII

# Análise Empírica de Complexidade de Algoritmos

Este repositório contém o código-fonte do trabalho prático da disciplina de **Estruturas de Dados Básicos II**. O objetivo do projeto é avaliar empiricamente o tempo de execução de diferentes algoritmos de ordenação e busca, comparando o comportamento observado com a complexidade teórica esperada. 

## 🚀 Algoritmos Analisados

O programa implementa e analisa os seguintes algoritmos:

* **Algoritmos de Ordenação:**
    * Selection Sort - Complexidade Teórica: $O(n^2)$
    * Quicksort - Complexidade Teórica (caso médio): $O(n \log n)$

* **Algoritmos de Busca:**
    * Busca Sequencial - Complexidade Teórica: $O(n)$
    * Busca Binária - Complexidade Teórica: $O(\log n)$

## ✨ Funcionalidades

* **Implementação Modular:** Os algoritmos são separados da lógica principal do experimento, permitindo fácil extensibilidade. 
* **Análise Empírica Precisa:** O tempo de execução é medido utilizando a biblioteca `<chrono>` do C++ para alta precisão.
* **Dados Confiáveis:** O programa executa cada algoritmo múltiplas vezes para cada tamanho de entrada `n`, calculando o tempo médio para minimizar flutuações externas.
* **Testes Abrangentes:** A análise é feita para entradas de tamanhos crescentes, permitindo a observação da curva de crescimento do tempo de execução. 
* **Configuração Inteligente:** Utiliza diferentes vetores de tamanho de entrada para algoritmos de classes de complexidade distintas ($O(n^2)$ vs $O(n \log n)$), permitindo testes mais amplos para os algoritmos rápidos sem que o tempo de execução total se torne proibitivo.

## 🛠️ Como Compilar e Executar

Siga os passos abaixo para compilar e executar o programa de análise.

### Pré-requisitos

* Um compilador C++ moderno (ex: g++)
* Git instalado

### Passos

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/leandrovitordev/Complexidade_EDBII.git](https://github.com/leandrovitordev/Complexidade_EDBII.git)
    ```

2.  **Navegue até a pasta do projeto:**
    ```bash
    cd Complexidade_EDBII
    ```

3.  **Compile o programa:**
    O comando abaixo compila todos os arquivos fonte e gera um executável chamado `analise_experimento`.
    ```bash
    g++ main.cpp funcoes.cpp -o analise_experimento -std=c++17
    ```

4.  **Execute o programa:**
    ```bash
    ./analise_experimento
    ```
    O programa imprimirá no terminal os resultados do tempo de execução para cada algoritmo e cada tamanho de `n`.

## 📂 Estrutura do Projeto

O código está organizado de forma modular em três arquivos principais:

* `main.cpp`: Contém a lógica principal que orquestra os experimentos, definindo os tamanhos de `n`, chamando os algoritmos e medindo o tempo.
* `algoritmos.hpp`: Arquivo de cabeçalho que declara as assinaturas de todas as funções de algoritmos, servindo como uma interface.
* `algoritmos.cpp`: Contém a implementação detalhada de cada um dos algoritmos de ordenação e busca.

## 👨‍💻 Autor

* **[Leandro Vitor Silva Santos]** - [leandro.silva.016@ufrn.edu.br]

---

