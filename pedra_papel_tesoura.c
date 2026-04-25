#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para mostrar escolhas
void mostrarEscolha(int escolha)
{
    switch(escolha)
    {
        case 1:
            printf("Pedra");
            break;

        case 2:
            printf("Papel");
            break;

        case 3:
            printf("Tesoura");
            break;
    }
}

// Função para verificar vencedor
int verificarVencedor(int jogador, int computador)
{
    // empate
    if(jogador == computador)
    {
        return 0;
    }

    // jogador vence
    if(
        (jogador == 1 && computador == 3) ||
        (jogador == 2 && computador == 1) ||
        (jogador == 3 && computador == 2)
    )
    {
        return 1;
    }

    // computador vence
    return 2;
}

int main()
{
    int jogador, computador;
    int pontosJogador = 0;
    int pontosComputador = 0;

    // inicializa random
    srand(time(NULL));

    printf("=== PEDRA PAPEL TESOURA ===\n");

    while(pontosJogador < 2 && pontosComputador < 2)
    {
        printf("\nEscolha:\n");
        printf("1 - Pedra\n");
        printf("2 - Papel\n");
        printf("3 - Tesoura\n");

        printf("Digite sua escolha: ");
        scanf("%d", &jogador);

        // validação
        if(jogador < 1 || jogador > 3)
        {
            printf("Escolha invalida!\n");
            continue;
        }

        // computador escolhe aleatoriamente
        computador = (rand() % 3) + 1;

        printf("\nVoce escolheu: ");
        mostrarEscolha(jogador);

        printf("\nComputador escolheu: ");
        mostrarEscolha(computador);

        printf("\n");

        int resultado = verificarVencedor(jogador, computador);

        if(resultado == 0)
        {
            printf("Empate!\n");
        }
        else if(resultado == 1)
        {
            printf("Voce venceu a rodada!\n");
            pontosJogador++;
        }
        else
        {
            printf("Computador venceu a rodada!\n");
            pontosComputador++;
        }

        printf("\nPLACAR:\n");
        printf("Voce: %d\n", pontosJogador);
        printf("Computador: %d\n", pontosComputador);
    }

    printf("\n=== FIM DE JOGO ===\n");

    if(pontosJogador > pontosComputador)
    {
        printf("VOCE GANHOU!\n");
    }
    else
    {
        printf("COMPUTADOR GANHOU!\n");
    }

    return 0;
}
