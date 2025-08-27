#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// --- Definição das Estruturas ---

typedef struct Pino {
    int cor; 
} Pino;

typedef struct No {
    Pino pino;
    struct No* proximo;
} No;


typedef struct Pilha {
    No* topo;
    int tamanho;
    int capacidade; 
} Pilha;

// --- Funções Auxiliares e da Pilha ---

// Função para criar uma nova pilha
Pilha* criarPilha(int capacidade) {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro de alocacao de memoria para a pilha!\n");
        exit(1);
    }
    p->topo = NULL;
    p->tamanho = 0;
    p->capacidade = capacidade;
    return p;
}


int estaVazia(Pilha* p) {
    return p->topo == NULL;
}


int estaCheia(Pilha* p) {
    return p->tamanho == p->capacidade;
}


void push(Pilha* p, Pino pino) {
    if (estaCheia(p)) {
        printf("Movimento invalido: A pilha de destino esta cheia!\n");
        return;
    }
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria para o no!\n");
        exit(1);
    }
    novoNo->pino = pino;
    novoNo->proximo = p->topo;
    p->topo = novoNo;
    p->tamanho++;
}


Pino pop(Pilha* p) {
    if (estaVazia(p)) {
        printf("Movimento invalido: A pilha de origem esta vazia!\n");
        Pino pinoVazio = {-1}; // pino vazio com cor -1 para indicar erro
        return pinoVazio;
    }
    No* temp = p->topo;
    Pino pinoDesempilhado = temp->pino;
    p->topo = p->topo->proximo;
    free(temp);
    p->tamanho--;
    return pinoDesempilhado;
}

// --- Funções do Jogo ---

// retornar a representação em string da cor
const char* getCor(int cor) {
    switch (cor) {
        case 1: return "VML"; // Vermelho
        case 2: return "VRD"; // Verde
        case 3: return "AZL"; // Azul
        case 4: return "AMR"; // Amarelo
        default: return "   ";
    }
}

// exibir o estado atual do jogo no terminal
void exibirJogo(Pilha* p1, Pilha* p2, Pilha* p3, Pilha* p4, Pilha* temp1, Pilha* temp2, int nivel) {
    system("clear || cls");
    printf("=====================================================\n");
    printf("               JOGO TORRE DE HANOI                   \n");
    printf("=====================================================\n\n");

    if (nivel == 1) {
        // Nível Fácil: Mostra ambos os temporários
        printf(" Temp 1: [%s]                      Temp 2: [%s]\n",
               estaVazia(temp1) ? "   " : getCor(temp1->topo->pino.cor),
               estaVazia(temp2) ? "   " : getCor(temp2->topo->pino.cor));
    } else if (nivel == 2) {
        // Nível Médio: Mostra apenas o Temp1
        printf(" Temp 1: [%s]\n",
               estaVazia(temp1) ? "   " : getCor(temp1->topo->pino.cor));
    } else {
        // Nível Difícil: Não mostra nenhum temporário
        printf("\n");
    }
    printf("\n   P1        P2        P3        P4    \n");
    printf(" ------    ------    ------    ------ \n");
        
        // exibe as pilhas de pinos
    int displayP1[4] = {0}, displayP2[4] = {0}, displayP3[4] = {0}, displayP4[4] = {0};
    No *atual1 = p1->topo, *atual2 = p2->topo, *atual3 = p3->topo, *atual4 = p4->topo;
    int i;
    // preenche os arrays de exibição com os nós das pilhas, começando do topo
    for (i = p1->tamanho - 1; i >= 0; i--) { displayP1[i] = atual1->pino.cor; atual1 = atual1->proximo; }
    for (i = p2->tamanho - 1; i >= 0; i--) { displayP2[i] = atual2->pino.cor; atual2 = atual2->proximo; }
    for (i = p3->tamanho - 1; i >= 0; i--) { displayP3[i] = atual3->pino.cor; atual3 = atual3->proximo; }
    for (i = p4->tamanho - 1; i >= 0; i--) { displayP4[i] = atual4->pino.cor; atual4 = atual4->proximo; }

    // exibe os pinos de cada pilha
    for (i = 3; i >= 0; i--) {
        printf("| [%s] |  | [%s] |  | [%s] |  | [%s] |\n",
               getCor(displayP1[i]), getCor(displayP2[i]),
               getCor(displayP3[i]), getCor(displayP4[i]));
    }
    printf(" ------    ------    ------    ------ \n");
    
}


// inicializar o jogo com pinos aleatórios
void inicializarJogo(Pilha* p1, Pilha* p2, Pilha* p3, Pilha* p4) {
    Pino pinos[12];
    int i;
    // Cria 3 pinos de cada uma das 4 cores
    for (i = 0; i < 12; i++) {
        pinos[i].cor = (i % 4) + 1;
    }

    // embaralha os pinos
    srand(time(NULL));
    for (i = 0; i < 12; i++) {
        int j = rand() % 12;
        Pino temp = pinos[i];
        pinos[i] = pinos[j];
        pinos[j] = temp;
    }

    // Distribui os pinos nas 4 pilhas
    for (i = 0; i < 3; i++) push(p1, pinos[i]);
    for (i = 3; i < 6; i++) push(p2, pinos[i]);
    for (i = 6; i < 9; i++) push(p3, pinos[i]);
    for (i = 9; i < 12; i++) push(p4, pinos[i]);
}

// verificar se o jogo terminou (condição de vitória)
int verificarVitoria(Pilha* p1, Pilha* p2, Pilha* p3, Pilha* p4) {
    Pilha* pilhas[] = {p1, p2, p3, p4};
    int i;
    int coresVerificadas[5] = {0}; 

    for (i = 0; i < 4; i++) {
        Pilha* p_atual = pilhas[i];

        if (p_atual->tamanho != 3) {
            return 0; // Se qualquer pilha não tiver 3 pinos, o jogo ainda não acabou.
        }

        // Condição 2: Todos os pinos na pilha devem ser da mesma cor.
        int corBase = p_atual->topo->pino.cor;
        No* no_atual = p_atual->topo->proximo;

        while (no_atual != NULL) {
            if (no_atual->pino.cor != corBase) {
                return 0; // Encontrou uma cor diferente, jogo não acabou.
            }
            no_atual = no_atual->proximo;
        }

    
        coresVerificadas[corBase] = 1;
    }

    // Se o loop terminou, significa que todas as 4 pilhas passaram em todas as verificações.
    return 1; 
}




int main() {
    Pilha *p1, *p2, *p3, *p4, *temp1, *temp2;

   
    p1 = criarPilha(4);
    p2 = criarPilha(4);
    p3 = criarPilha(4);
    p4 = criarPilha(4);

    
    temp1 = criarPilha(1);
    temp2 = criarPilha(1);

    int nivel;
    printf("Escolha o nivel de dificuldade:\n");
    printf("1. Facil (4 pilhas, 2 temporarios)\n");
    printf("2. Medio (4 pilhas, 1 temporario)\n");
    printf("3. Dificil (4 pilhas, 0 temporarios)\n");
    printf("Opcao: ");
    scanf("%d", &nivel);

    while (nivel < 1 || nivel > 3) {
        printf("Opcao invalida! Escolha 1, 2 ou 3: ");
        scanf("%d", &nivel);
    }

    inicializarJogo(p1, p2, p3, p4);

    time_t inicio = time(NULL);
    int jogadas = 0;

    while (!verificarVitoria(p1, p2, p3, p4)) {
        exibirJogo(p1, p2, p3, p4, temp1, temp2, nivel);

        printf("\nTempo: %ld segundos | Jogadas: %d\n\n", time(NULL) - inicio, jogadas);
        printf("Faca seu movimento (ex: '1 2' para mover de P1 para P2).\n");
        if (nivel==1)  printf("Use 5 para Temp1 e 6 para Temp2.\n");
        if (nivel==2)  printf("Use 5 para Temp1.\n");
        printf("Origem e Destino: ");

        int origem, destino;
        scanf("%d %d", &origem, &destino);

        Pilha* pOrigem = NULL;
        Pilha* pDestino = NULL;

        
        switch(origem) {
            case 1: pOrigem = p1; break;
            case 2: pOrigem = p2; break;
            case 3: pOrigem = p3; break;
            case 4: pOrigem = p4; break;
            case 5: pOrigem = temp1; break;
            case 6: pOrigem = temp2; break;
            default: printf("Origem invalida!\n"); continue;
        }

        switch(destino) {
            case 1: pDestino = p1; break;
            case 2: pDestino = p2; break;
            case 3: pDestino = p3; break;
            case 4: pDestino = p4; break;
            case 5: pDestino = temp1; break;
            case 6: pDestino = temp2; break;
            default: printf("Destino invalido!\n"); continue;
        }

        // validação de niveis 
        if ((origem == 6 || destino == 6) && nivel != 1) {
            printf("Temp2 so esta disponivel no nivel Facil!\n");
            sleep(2);
            continue;
        }
        if ((origem == 5 || destino == 5) && nivel == 3) {
            printf("Temporarios nao estao disponiveis no nivel Dificil!\n");
            sleep(2);
            continue;
        }

        if (pOrigem && pDestino && !estaVazia(pOrigem) && !estaCheia(pDestino)) {
            push(pDestino, pop(pOrigem));
            jogadas++;
        } else {
            printf("\n--- MOVIMENTO INVALIDO! Tente novamente. ---\n");
            sleep(2); 
        }
    }

    // Fim de jogo
    time_t fim = time(NULL);
    exibirJogo(p1, p2, p3, p4, temp1, temp2, nivel);
    printf("\n\n=====================================================\n");
    printf("                  PARABENS, VOCE VENCEU!               \n");
    printf("=====================================================\n");
    printf("Tempo total: %ld segundos\n", fim - inicio);
    printf("Total de jogadas: %d\n", jogadas);

    free(p1);
    free(p2);
    free(p3);
    free(p4);
    free(temp1);
    free(temp2);

    return 0;
}