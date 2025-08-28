# Jogo de Lógica com Pilhas (Estilo Torre de Hanói) em C

Este projeto é uma implementação em C de um jogo de raciocínio lógico inspirado na Torre de Hanói, desenvolvido como uma atividade acadêmica para a disciplina de Estrutura de Dados. O objetivo principal é aplicar os conceitos de **Pilhas (Stacks)** e **alocação dinâmica de memória** (`malloc` e `free`) para criar um jogo funcional via terminal.

## 🎯 Sobre o Jogo

O jogo desafia o jogador a organizar 12 pinos de 4 cores diferentes em 4 colunas (pilhas). O objetivo final é ter cada coluna preenchida com os 3 pinos de uma única cor. O jogador pode mover apenas um pino por vez, utilizando as colunas principais e, dependendo do nível de dificuldade, posições auxiliares temporárias.

## ✨ Funcionalidades

- **Interface de Terminal:** Jogo totalmente jogável em qualquer ambiente de terminal padrão.
- **Níveis de Dificuldade:** Três modos que alteram a disponibilidade de espaços auxiliares.
- **Inicialização Aleatória:** A disposição inicial dos pinos é gerada aleatoriamente a cada nova partida.
- **Contador de Tempo e Jogadas:** O jogo monitora o desempenho do jogador.
- **Compilação Automatizada:** Utiliza um `Makefile` para gerenciar a compilação de múltiplos arquivos de forma eficiente.
- **Gerenciamento de Memória:** Utiliza `malloc` e `free` para alocação dinâmica.

## 🛠️ Estruturas e Conceitos Aplicados

- **Estrutura de Dados Pilha (Stack):** O núcleo do jogo. Cada coluna e cada espaço temporário é implementado como uma pilha (LIFO - Last-In, First-Out).
- **Listas Ligadas (Linked Lists):** A pilha foi implementada utilizando uma lista ligada de nós.
- **Alocação Dinâmica de Memória:** `malloc` e `free` são usados para gerenciar a memória dos nós da pilha.
- **Ponteiros:** Conceito fundamental em C, usado extensivamente em todo o projeto.
- **Modularização:** O código é dividido em múltiplos arquivos (`.c` e `.h`), com a compilação gerenciada por um `Makefile`.

## 🚀 Como Compilar e Executar

É necessário ter o `gcc` (ou outro compilador C) e a ferramenta `make` instalados em seu sistema.

1.  **Clone ou baixe o projeto:**
    Garanta que todos os arquivos (`.c`, `.h` e o `Makefile`) estejam no mesmo diretório.

2.  **Abra o terminal:**
    Navegue até o diretório raiz do projeto.

3.  **Compile o projeto com `make`:**
    Execute o comando abaixo. Ele irá ler o `Makefile`, compilar todos os arquivos fonte necessários e gerar o executável final chamado `programa_placas`.
    ```bash
    make
    ```

4.  **Execute o programa:**
    Após a compilação bem-sucedida, inicie o jogo com o seguinte comando:
    ```bash
    ./programa_placas
    ```

5.  **(Opcional) Limpar os arquivos gerados:**
    Para remover o executável e os arquivos objeto (`.o`) criados durante a compilação, utilize o comando:
    ```bash
    make clean
    ```

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
