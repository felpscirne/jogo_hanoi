# Jogo de Lógica com Pilhas (Estilo Torre de Hanói) em C

Este projeto é uma implementação em C de um jogo de raciocínio lógico inspirado na Torre de Hanói, desenvolvido como uma atividade acadêmica para a disciplina de Estrutura de Dados. O objetivo principal é aplicar os conceitos de **Pilhas (Stacks)** e **alocação dinâmica de memória** (`malloc` e `free`) para criar um jogo funcional via terminal.

## 🎯 Sobre o Jogo

O jogo desafia o jogador a organizar 12 pinos de 4 cores diferentes em 4 colunas (pilhas). O objetivo final é ter cada coluna preenchida com os 3 pinos de uma única cor. O jogador pode mover apenas um pino por vez, utilizando as colunas principais e, dependendo do nível de dificuldade, posições auxiliares temporárias.

## ✨ Funcionalidades

- **Interface de Terminal:** Jogo totalmente jogável em qualquer ambiente de terminal padrão.
- **Níveis de Dificuldade:** Três modos que alteram a disponibilidade de espaços auxiliares:
    - **Fácil:** 4 pilhas e 2 espaços temporários.
    - **Médio:** 4 pilhas e 1 espaço temporário.
    - **Difícil:** 4 pilhas e nenhum espaço temporário.
- **Inicialização Aleatória:** A disposição inicial dos pinos é gerada aleatoriamente a cada nova partida, garantindo um desafio diferente sempre.
- **Contador de Tempo e Jogadas:** O jogo monitora o tempo decorrido e o número de movimentos, permitindo que o jogador avalie seu desempenho.
- **Gerenciamento de Memória:** Utiliza `malloc` e `free` para alocação dinâmica, seguindo as boas práticas de programação em C.

## 🛠️ Estruturas e Conceitos Aplicados

- **Estrutura de Dados Pilha (Stack):** O núcleo do jogo. Cada coluna e cada espaço temporário é implementado como uma pilha (LIFO - Last-In, First-Out), onde as operações principais são `push` (empilhar) e `pop` (desempilhar).
- **Listas Ligadas (Linked Lists):** A pilha foi implementada utilizando uma lista ligada de nós, onde cada nó armazena um pino e um ponteiro para o próximo nó.
- **Alocação Dinâmica de Memória:** `malloc` é usado para criar as pilhas e os nós conforme necessário, e `free` é usado para liberar a memória após o uso, evitando vazamentos de memória.
- **Ponteiros:** Conceito fundamental em C, usado extensivamente para gerenciar a estrutura da pilha e a passagem de dados entre funções.

## 🚀 Como Compilar e Executar

Você precisará de um compilador C, como o **GCC**, para executar este projeto.

1.  **Clone o repositório (ou salve o arquivo .c):**
    Se o projeto estiver no Git, clone-o. Caso contrário, apenas salve o arquivo `jogo_hanoi.c` em um diretório de sua preferência.

2.  **Abra o terminal:**
    Navegue até o diretório onde o arquivo foi salvo.

3.  **Compile o programa:**
    Execute o seguinte comando para compilar o código. Isso criará um arquivo executável chamado `jogo_hanoi`.
    ```bash
    gcc jogo_hanoi.c -o jogo_hanoi
    ```

4.  **Execute o jogo:**
    Agora, inicie o jogo com o comando:
    ```bash
    ./jogo_hanoi
    ```
    No Windows, o comando pode ser apenas `jogo_hanoi.exe`.

## 🎮 Como Jogar

1.  Ao iniciar, o jogo pedirá que você escolha um nível de dificuldade (1, 2 ou 3).
2.  O tabuleiro será exibido com a disposição aleatória dos pinos.
3.  Para mover um pino, digite o número da coluna de **origem**, seguido de um espaço, e o número da coluna de **destino**. Depois, pressione Enter.

    -   **Colunas Principais:** `1`, `2`, `3`, `4`
    -   **Temporário 1:** `5`
    -   **Temporário 2:** `6` (disponível apenas no modo Fácil)

4.  **Exemplo de jogada:** Para mover o pino do topo da Pilha 2 para a Pilha 4, digite:
    ```
    2 4
    ```

5.  O jogo termina quando todas as 4 colunas estiverem organizadas com 3 pinos da mesma cor em cada uma.

---

**Autor:** Felipe Cirne
