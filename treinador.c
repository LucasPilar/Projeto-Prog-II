#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "treinador.h"

#define MAX_TREINADORES 5

int capacidadeTreinador = 0;
int quantidadeTreinador = 0;
Treinador* treinador = NULL;

bool InicializarTreinadores()
{
    struct Treinador *treinador = malloc(MAX_TREINADORES * sizeof(Treinador));

    if (treinador == NULL)
    {
        return false;
    }
    else
    {
        capacidadeTreinador = MAX_TREINADORES;
        quantidadeTreinador = 0;
        return true;
    }
}

bool EncerraTreinadores()
{
    if (treinador != NULL)
    {
        free(treinador);
        treinador = NULL;
        capacidadeTreinador = 0;
        quantidadeTreinador = 0;
        return true;
    }
    return false;
}

bool SalvarTreinador(Treinador t)
{
    if (quantidadeTreinador >= capacidadeTreinador)
    {
        int novaCapacidadeTreinador = capacidadeTreinador * 2;
        Treinador *novoArray = (Treinador *)realloc(treinador, novaCapacidadeTreinador * sizeof(Treinador));
        if (novoArray == NULL)
        {
            return false;
        }
        treinador = novoArray;
        capacidadeTreinador = novaCapacidadeTreinador;
    }
    treinador[quantidadeTreinador++] = t;
    return true;
}

int QuantidadeTreinadores()
{
    return quantidadeTreinador;
}

Treinador *ObterTreinadorPeloIndice(int indice)
{
    if (indice < 0 || indice >= quantidadeTreinador)
    {
        return NULL;
    }
    return &treinador[indice];
}

Treinador* ObterTreinadorPeloCodigo(int codigo)
{
	int i = 0;
    for (i; i < quantidadeTreinador; i++)
    {
        if (treinador[i].codigo == codigo)
        {
            return &treinador[i];
        }
    }
    return NULL;
}

bool AtualizarTreinador(Treinador t)
{
    Treinador *treinador = ObterTreinadorPeloCodigo(t.codigo);
    if (treinador != NULL)
    {
        *treinador = t;
        return true;
    }
    return false;
}

bool ApagarTreinadorPeloCodigo(int codigo)
{
	int i = 0;
    for (i; i < quantidadeTreinador; i++)
    {
        if (treinador[i].codigo == codigo)
        {
            treinador[i] = treinador[quantidadeTreinador - 1];
            quantidadeTreinador--;

            if (quantidadeTreinador < capacidadeTreinador / 2 && capacidadeTreinador > MAX_TREINADORES)
            {
                int novaCapacidadeTreinador = capacidadeTreinador / 2;
                Treinador *novoArray = (Treinador *)realloc(treinador, novaCapacidadeTreinador * sizeof(Treinador));
                if (novoArray != NULL)
                {
                    treinador = novoArray;
                    capacidadeTreinador = novaCapacidadeTreinador;
                }
            }
            return true;
        }
    }
    return false;
}

bool ApagarTreinadorPeloNome(char *nome)
{
    bool encontrado = false;
	int i = 0;
    for (i; i < quantidadeTreinador; i++)
    {
        if (strcmp(treinador[i].nome, nome) == 0)
        {
            treinador[i] = treinador[quantidadeTreinador - 1];
            quantidadeTreinador--;
            encontrado = true;
            i--;
        }
    }

    if (encontrado && quantidadeTreinador < capacidadeTreinador / 2 && capacidadeTreinador > MAX_TREINADORES)
    {
        int novaCapacidadeTreinador = capacidadeTreinador / 2;
        Treinador *novoArray = (Treinador *)realloc(treinador, novaCapacidadeTreinador * sizeof(treinador));
        if (novoArray != NULL)
        {
            treinador = novoArray;
            capacidadeTreinador = novaCapacidadeTreinador;
        }
    }

    return encontrado;
}

void ListarTreinadores()
{
	int i = 0;
    if (quantidadeTreinador == 0)
    {
        printf("Nenhum treinador cadastrado.\n");
        
    }

    printf("Listar Treinadores:\n");
    for (i; i < quantidadeTreinador; i++)
    {
        printf("Codigo: %d, Nome: %s, Bonus de Ataque: %d, Bonus de Defesa:%d\n",
               treinador[i].codigo, treinador[i].nome, treinador[i].BonusAtaque, treinador[i].BonusDefesa);
    }
}

void CadastrarTreinador()
{
    Treinador t;
    printf("Digite o codigo do treinador: ");
    scanf("%d", &t.codigo);
    // Usado para limpar o buffer
    getchar();

    printf("Digite o nome do treinador: ");
    // fgets() serve para ler uma cadeia de caracteres e armazenar em uma string
    fgets(t.nome, sizeof(t.nome), stdin);
    // stdin vai ser utilizado para ler operacoes de E/S
    t.nome[strcspn(t.nome, "\n")] = '\0';

    printf("Digite o bonus de ataque: ");
    scanf("%d", &t.BonusAtaque);

    printf("Digite o bonus de defesa: ");
    scanf("%d", &t.BonusDefesa);

    if (SalvarTreinador(t))
    {
        printf("Treinador cadastrado com sucesso!\n");
    }
    else
    {
        printf("Erro ao cadastrar treinador.\n");
    }
}

void ExcluirTreinador()
{
    int codigo;

    printf("Digite o codigo do treinador a ser excluido: ") /
        scanf("%d", &codigo);

    if (ApagarTreinadorPeloCodigo(codigo))
    {
        printf("Treinador excluido com sucesso!\n");
    }
    else
    {
        printf("Treinador com o codigo %d não encontrado.\n", codigo);
    }
}
