#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void jogo_perguntas();
void jogo_cobra();
void jogo_gousmas();

int main() {
    int opcao;

    srand(time(NULL));

    do {
        printf("=============================\n");
        printf("     central de minijogos    \n");
        printf("=============================\n");
        printf("1) pergunta e resposta\n");
        printf("2) cobra na caixa\n");
        printf("3) gousmas war\n");
        printf("4) sair\n");
        printf("=============================\n");
        printf("escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            jogo_perguntas();
        } else if (opcao == 2) {
            jogo_cobra();
        } else if (opcao == 3) {
            jogo_gousmas();
        } else if (opcao == 4) {
            printf("obrigado por jogar! ate logo!\n");
        } else {
            printf("opcao invalida. tente novamente.\n\n");
        }

    } while (opcao != 4);

    return 0;
}

void jogo_perguntas() {
    int resposta, jogar, pontos;

    printf("\n--- pergunta e resposta ---\n");
    printf("responda as 5 perguntas escolhendo o numero da alternativa correta.\n\n");

    do {
        pontos = 0;

        printf("pergunta 1: qual a capital do brasil?\n");
        printf("1) rio de janeiro\n2) sao paulo\n3) brasilia\n4) salvador\n");
        printf("resposta: ");
        scanf("%d", &resposta);
        if (resposta == 3) {
            printf("resposta correta!\n\n");
            pontos++;
        } else {
            printf("resposta incorreta! a correta era: 3) brasilia\n\n");
        }

        printf("pergunta 2: qual e o maior planeta do sistema solar?\n");
        printf("1) jupiter\n2) saturno\n3) marte\n4) venus\n");
        printf("resposta: ");
        scanf("%d", &resposta);
        if (resposta == 1) {
            printf("resposta correta!\n\n");
            pontos++;
        } else {
            printf("resposta incorreta! a correta era: 1) jupiter\n\n");
        }

        printf("pergunta 3: em que ano o cesupa foi criado?\n");
        printf("1) 1986\n2) 1990\n3) 1992\n4) 1995\n");
        printf("resposta: ");
        scanf("%d", &resposta);
        if (resposta == 1) {
            printf("resposta correta!\n\n");
            pontos++;
        } else {
            printf("resposta incorreta! a correta era: 1) 1986\n\n");
        }

        printf("pergunta 4: quais sao as linguagens mais usadas no mundo?\n");
        printf("1) java\n2) python\n3) c\n4) javascript\n");
        printf("(digite 2 para python ou 4 para javascript): ");
        scanf("%d", &resposta);
        if (resposta == 2 || resposta == 4) {
            printf("resposta correta!\n\n");
            pontos++;
        } else {
            printf("resposta incorreta! as corretas eram: 2) python ou 4) javascript\n\n");
        }

        printf("pergunta 5: quem e a coordenadora do curso de ciencia da computacao do cesupa?\n");
        printf("1) prof. pedro girotto\n2) prof. alessandra baganha\n3) prof. claudio coutinho\n4) prof. ricardo casseb\n");
        printf("resposta: ");
        scanf("%d", &resposta);
        if (resposta == 2) {
            printf("resposta correta!\n\n");
            pontos++;
        } else {
            printf("resposta incorreta! a correta era: 2) prof. alessandra baganha\n\n");
        }

        printf("=============================\n");
        printf("voce acertou %d de 5 perguntas!\n", pontos);
        printf("=============================\n\n");

        printf("deseja jogar novamente? (1 - sim / 0 - nao): ");
        scanf("%d", &jogar);

    } while (jogar == 1);

    printf("voltando ao menu principal...\n\n");
}

void jogo_cobra() {
    int jogador1, jogador2, quem_comeca, turno, caixa, pos_cobra, pos_botao, fim, jogar;
    int abertas[5];
    int i;

    printf("\n--- cobra na caixa! ---\n");
    printf("dois exploradores estao presos em uma tumba egipcia.\n");
    printf("ha 5 caixas: uma tem o botao da saida, outra esconde uma cobra mortal.\n\n");

    do {
        printf("escolha o nome do jogador 1:\n");
        printf("1) indiana jones\n2) lara croft\n3) howard carter\n");
        printf("4) evie carnahan\n5) rick o'connell\n6) nefertiti\n7) ramses\n");
        printf("jogador 1: ");
        scanf("%d", &jogador1);
        while (jogador1 < 1 || jogador1 > 7) {
            printf("opcao invalida. escolha entre 1 e 7: ");
            scanf("%d", &jogador1);
        }

        printf("escolha o nome do jogador 2:\n");
        printf("1) indiana jones\n2) lara croft\n3) howard carter\n");
        printf("4) evie carnahan\n5) rick o'connell\n6) nefertiti\n7) ramses\n");
        printf("jogador 2: ");
        scanf("%d", &jogador2);
        while (jogador2 < 1 || jogador2 > 7 || jogador2 == jogador1) {
            if (jogador2 == jogador1) {
                printf("nome ja escolhido! escolha outro: ");
            } else {
                printf("opcao invalida. escolha entre 1 e 7: ");
            }
            scanf("%d", &jogador2);
        }

        quem_comeca = rand() % 2;
        if (quem_comeca == 0) {
            printf("\nsorteio: jogador 1 comeca!\n\n");
        } else {
            printf("\nsorteio: jogador 2 comeca!\n\n");
        }

        pos_cobra = rand() % 5;
        do {
            pos_botao = rand() % 5;
        } while (pos_botao == pos_cobra);

        for (i = 0; i < 5; i++) {
            abertas[i] = 0;
        }

        fim = 0;
        turno = quem_comeca;

        while (fim == 0) {
            if (turno == 0) {
                printf("vez do jogador 1. ");
            } else {
                printf("vez do jogador 2. ");
            }

            printf("caixas disponiveis: ");
            for (i = 0; i < 5; i++) {
                if (abertas[i] == 0) {
                    printf("[%d] ", i + 1);
                }
            }

            printf("\nescolha uma caixa: ");
            scanf("%d", &caixa);
            caixa--;

            if (caixa < 0 || caixa > 4 || abertas[caixa] == 1) {
                printf("caixa invalida ou ja aberta. tente novamente.\n");
            } else {
                abertas[caixa] = 1;

                if (caixa == pos_cobra) {
                    printf("\n*** uma cobra! ");
                    if (turno == 0) {
                        printf("jogador 1 foi picado e perdeu!\n");
                        printf("jogador 2 venceu e escapou da tumba! ***\n\n");
                    } else {
                        printf("jogador 2 foi picado e perdeu!\n");
                        printf("jogador 1 venceu e escapou da tumba! ***\n\n");
                    }
                    fim = 1;
                } else if (caixa == pos_botao) {
                    printf("\n*** clique! ");
                    if (turno == 0) {
                        printf("jogador 1 encontrou o botao e venceu! ***\n\n");
                    } else {
                        printf("jogador 2 encontrou o botao e venceu! ***\n\n");
                    }
                    fim = 1;
                } else {
                    printf("caixa vazia. proximo!\n\n");
                    if (turno == 0) {
                        turno = 1;
                    } else {
                        turno = 0;
                    }
                }
            }
        }

        printf("deseja jogar novamente? (1 - sim / 0 - nao): ");
        scanf("%d", &jogar);

    } while (jogar == 1);

    printf("voltando ao menu principal...\n\n");
}

void jogo_gousmas() {
    int furia1_a, furia1_b, furia2_a, furia2_b;
    int viva1_a, viva1_b, viva2_a, viva2_b;
    int turno, fim, jogar, acao;
    int atacante, alvo, transferir;
    int vivas1, vivas2;

    printf("\n--- gousmas war ---\n");
    printf("cada jogador tem 2 gousmas com furia 1.\n");
    printf("ataque para somar sua furia a uma gousma inimiga.\n");
    printf("se a furia passar de 5 a gousma se desintegra.\n");
    printf("divisao: divide uma gousma em duas (so quando tiver 1 gousma viva).\n\n");

    do {
        furia1_a = 1; viva1_a = 1;
        furia1_b = 1; viva1_b = 1;
        furia2_a = 1; viva2_a = 1;
        furia2_b = 1; viva2_b = 1;

        turno = 0;
        fim = 0;

        while (fim == 0) {
            printf("\n--- estado atual ---\n");
            printf("jogador 1: ");
            if (viva1_a == 1) printf("[ga: furia %d]  ", furia1_a);
            else              printf("[ga: morta]  ");
            if (viva1_b == 1) printf("[gb: furia %d]", furia1_b);
            else              printf("[gb: morta]");

            printf("\njogador 2: ");
            if (viva2_a == 1) printf("[ga: furia %d]  ", furia2_a);
            else              printf("[ga: morta]  ");
            if (viva2_b == 1) printf("[gb: furia %d]", furia2_b);
            else              printf("[gb: morta]");
            printf("\n\n");

            if (turno == 0) {
                printf("vez do jogador 1.\n");
            } else {
                printf("vez do jogador 2.\n");
            }

            printf("acao: 1) atacar  2) dividir\nescolha: ");
            scanf("%d", &acao);

            if (acao == 1) {
                printf("qual das suas gousmas vai atacar? (1 = ga / 2 = gb): ");
                scanf("%d", &atacante);

                if (turno == 0) {
                    if (atacante == 1 && viva1_a == 0) { printf("gousma morta!\n"); continue; }
                    if (atacante == 2 && viva1_b == 0) { printf("gousma morta!\n"); continue; }
                } else {
                    if (atacante == 1 && viva2_a == 0) { printf("gousma morta!\n"); continue; }
                    if (atacante == 2 && viva2_b == 0) { printf("gousma morta!\n"); continue; }
                }

                printf("qual gousma inimiga vai atacar? (1 = ga / 2 = gb): ");
                scanf("%d", &alvo);

                if (turno == 0) {
                    if (alvo == 1 && viva2_a == 0) { printf("gousma morta!\n"); continue; }
                    if (alvo == 2 && viva2_b == 0) { printf("gousma morta!\n"); continue; }
                } else {
                    if (alvo == 1 && viva1_a == 0) { printf("gousma morta!\n"); continue; }
                    if (alvo == 2 && viva1_b == 0) { printf("gousma morta!\n"); continue; }
                }

                if (turno == 0) {
                    if (alvo == 1) {
                        if (atacante == 1) furia2_a += furia1_a;
                        else               furia2_a += furia1_b;
                        printf("nova furia da ga do jogador 2: %d\n", furia2_a);
                        if (furia2_a > 5) { viva2_a = 0; furia2_a = 0; printf("ga do jogador 2 se desintegrou!\n"); }
                    } else {
                        if (atacante == 1) furia2_b += furia1_a;
                        else               furia2_b += furia1_b;
                        printf("nova furia da gb do jogador 2: %d\n", furia2_b);
                        if (furia2_b > 5) { viva2_b = 0; furia2_b = 0; printf("gb do jogador 2 se desintegrou!\n"); }
                    }
                } else {
                    if (alvo == 1) {
                        if (atacante == 1) furia1_a += furia2_a;
                        else               furia1_a += furia2_b;
                        printf("nova furia da ga do jogador 1: %d\n", furia1_a);
                        if (furia1_a > 5) { viva1_a = 0; furia1_a = 0; printf("ga do jogador 1 se desintegrou!\n"); }
                    } else {
                        if (atacante == 1) furia1_b += furia2_a;
                        else               furia1_b += furia2_b;
                        printf("nova furia da gb do jogador 1: %d\n", furia1_b);
                        if (furia1_b > 5) { viva1_b = 0; furia1_b = 0; printf("gb do jogador 1 se desintegrou!\n"); }
                    }
                }

            } else if (acao == 2) {
                if (turno == 0) {
                    vivas1 = viva1_a + viva1_b;
                    if (vivas1 >= 2) { printf("voce ja tem 2 gousmas!\n"); continue; }
                    if (viva1_a == 1) {
                        if (furia1_a < 2) { printf("furia insuficiente para dividir.\n"); continue; }
                        printf("dividir ga (furia %d). quanto transferir para gb? (1 a %d): ", furia1_a, furia1_a - 1);
                        scanf("%d", &transferir);
                        if (transferir < 1 || transferir >= furia1_a) { printf("valor invalido.\n"); continue; }
                        furia1_b = transferir;
                        furia1_a -= transferir;
                        viva1_b = 1;
                        printf("divisao feita! ga(furia %d) gb(furia %d)\n", furia1_a, furia1_b);
                    } else {
                        if (furia1_b < 2) { printf("furia insuficiente para dividir.\n"); continue; }
                        printf("dividir gb (furia %d). quanto transferir para ga? (1 a %d): ", furia1_b, furia1_b - 1);
                        scanf("%d", &transferir);
                        if (transferir < 1 || transferir >= furia1_b) { printf("valor invalido.\n"); continue; }
                        furia1_a = transferir;
                        furia1_b -= transferir;
                        viva1_a = 1;
                        printf("divisao feita! ga(furia %d) gb(furia %d)\n", furia1_a, furia1_b);
                    }
                } else {
                    vivas2 = viva2_a + viva2_b;
                    if (vivas2 >= 2) { printf("voce ja tem 2 gousmas!\n"); continue; }
                    if (viva2_a == 1) {
                        if (furia2_a < 2) { printf("furia insuficiente para dividir.\n"); continue; }
                        printf("dividir ga (furia %d). quanto transferir para gb? (1 a %d): ", furia2_a, furia2_a - 1);
                        scanf("%d", &transferir);
                        if (transferir < 1 || transferir >= furia2_a) { printf("valor invalido.\n"); continue; }
                        furia2_b = transferir;
                        furia2_a -= transferir;
                        viva2_b = 1;
                        printf("divisao feita! ga(furia %d) gb(furia %d)\n", furia2_a, furia2_b);
                    } else {
                        if (furia2_b < 2) { printf("furia insuficiente para dividir.\n"); continue; }
                        printf("dividir gb (furia %d). quanto transferir para ga? (1 a %d): ", furia2_b, furia2_b - 1);
                        scanf("%d", &transferir);
                        if (transferir < 1 || transferir >= furia2_b) { printf("valor invalido.\n"); continue; }
                        furia2_a = transferir;
                        furia2_b -= transferir;
                        viva2_a = 1;
                        printf("divisao feita! ga(furia %d) gb(furia %d)\n", furia2_a, furia2_b);
                    }
                }
            } else {
                printf("acao invalida.\n");
                continue;
            }

            vivas1 = viva1_a + viva1_b;
            vivas2 = viva2_a + viva2_b;

            if (vivas1 == 0) {
                printf("*** jogador 1 perdeu todas as gousmas! jogador 2 venceu! ***\n\n");
                fim = 1;
            } else if (vivas2 == 0) {
                printf("*** jogador 2 perdeu todas as gousmas! jogador 1 venceu! ***\n\n");
                fim = 1;
            }

            if (turno == 0) turno = 1;
            else            turno = 0;
        }

        printf("deseja jogar novamente? (1 - sim / 0 - nao): ");
        scanf("%d", &jogar);

    } while (jogar == 1);

    printf("voltando ao menu principal...\n\n");
}
