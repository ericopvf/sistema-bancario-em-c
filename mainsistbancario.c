
//Sistema banc�rio

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

float dinheirototal = 0;
int numdedepositos = 0;
int numdesaques = 0;
int quantdeacoes = 0;
int acaodatoyo = 0, acaodapetro = 0, acaodamicro = 0;

void depositar()
{
    float quantdedeposito = 0;
    printf("==============================\n");
    printf("Digite o quanto voc� deseja depositar:\n");
    scanf("%f", &quantdedeposito);
    dinheirototal += quantdedeposito;
    numdedepositos++;
    printf("Voc� depositou %.2f reais.\n", quantdedeposito);
    printf("==============================\n");
}

void saque()
{
    float quantdosaque = 0;
    printf("==============================\n");
    printf("Digite o quanto voc� deseja sacar:\n");
    scanf("%f", &quantdosaque);
    if (quantdosaque <= dinheirototal)
    {
        dinheirototal -= quantdosaque;
        numdesaques++;
        printf("Voc� resgatou %.2f reais.\n", quantdosaque);
        printf("==============================\n");
    }
    else
    {
        printf("Saldo insuficiente para o saque.\n");
        printf("==============================\n");
    }
}

void extrato()
{
    printf("==============================\n");
    printf("Extrato da sua conta:\n");
    printf("Saldo total: %.2f reais.\n", dinheirototal);
    printf("N�mero de dep�sitos realizados: %d.\n", numdedepositos);
    printf("N�mero de saques realizados: %d.\n", numdesaques);
    printf("A��es da Toyota: %d.\n", acaodatoyo);
    printf("A��es da Petrobras: %d.\n", acaodapetro);
    printf("A��es da Microsoft: %d.\n", acaodamicro);
    printf("==============================\n");
}

void investimentos()
{
    int escolha, quantdeacoes;
    float subtrair;
    printf("==============================\n");
    printf("A��es mais negociadas hoje:\n");
    printf(" [1] TOYOTA: R$ 28.897,00\n");
    printf(" [2] PETROBRAS: R$ 6.321,00\n");
    printf(" [3] MICROSOFT: R$ 973,00\n");
    scanf("%d", &escolha);
    if (escolha < 1 || escolha > 3)
    {
        printf("Digite uma op��o v�lida.\n");
        printf("==============================\n");
        return;
    }
    printf("Quantas a��es voc� deseja comprar?\n");
    printf("==============================\n");
    scanf("%d", &quantdeacoes);
    switch (escolha)
    {
        case 1:
            subtrair = quantdeacoes * 28897.0;
            acaodatoyo+= quantdeacoes;
            break;
        case 2:
            subtrair = quantdeacoes * 6321.0;
            acaodapetro+= quantdeacoes;
            break;
        case 3:
            subtrair = quantdeacoes * 973.0;
            acaodamicro+= quantdeacoes;
            break;
    }
    if (dinheirototal >= subtrair)
    {
        dinheirototal -= subtrair;
        printf("Voc� comprou %d a��es.\n", quantdeacoes);
        printf("==============================\n");
    }
    else
    {
        printf("O saldo da conta n�o � suficiente para fazer esse investimento.\n");
        printf("==============================\n");
    }
}

int interface()
{
    setlocale(LC_ALL, "Portuguese");
    int opcaoescolhida = 0;
    char repetir[10];
    do
    {
        printf("==============================\n Bem-vindo ao sistema banc�rio.\n Escolha uma op��o:\n [1] Depositar.\n [2] Sacar.\n [3] Extrato.\n [4] Investir.\n==============================\n");
        printf("Observa��o: Sua conta banc�ria come�a com 0 reais.\n");
        scanf("%d", &opcaoescolhida);
        switch (opcaoescolhida)
        {
        case 1:
            depositar();
            break;
        case 2:
            saque();
            break;
        case 3:
            extrato();
            break;
        case 4:
            investimentos();
            break;
        default:
            printf("Digite uma op��o v�lida.\n");
        }

        printf("Deseja algo mais? (sim/nao)\n");
        scanf("%9s", repetir);
    }
    while (strncmp(repetir, "sim", 6) == 0);
    printf("Fim do programa.\n");
    printf("==============================\n");
    return 0;
}

int main()
{
    return interface();
}
