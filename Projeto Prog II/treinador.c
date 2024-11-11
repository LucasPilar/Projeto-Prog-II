#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "treinador.h"

#define MAX_TREINADORES 5

int capacidade = 0;
int quantidade = 0;
Treinador treinador = NULL;

bool InicializarTreinadores()
{
    treinador = (Treinador *)malloc(MAX_TREINADORES * sizeof(Treinador));

    if (treinador == NULL)
    {
        return false;
    }
    else
    {
        capacidade = MAX_TREINADORES;
        quantidade = 0;
        return true;
    }
}

bool EncerraTreinadores()
{
    if (treinador != NULL)
    {
        free(treinador);
        treinador = NULL;
        capacidade = 0;
        quantidade = 0;
        return true;
    }
    return false;
}

bool SalvarTreinador(Treinador t)
{
    if (quantidade >= capacidade)
    {
        int novaCapacidade = capacidade * 2;
        Treinador *novoArray = (Treinador *)realloc(treinador, novaCapacidade * sizeof(Treinador));
        if (novoArray == NULL)
        {
            return false;
        }
        treinador = novoArray;
        capacidade = novaCapacidade;
    }
    treinador[quantidade++] = t;
    return true;
}

int QuantidadeTreinadores()
{
    return quantidade;
}

Treinador *ObterTreinadorPeloIndice(int indice)
{
    if (indice < 0 || indice >= quantidade)
    {
        return NULL;
    }
    return &treinador[indice];
}

Treinador *ObterTreinadorPeloCodigo(int codigo)
{
    for (int i = 0; i < quantidade; i++)
    {
        if (treinador[i].codigo == codigo)
        {
            return treinador[i];
        }
    }
    return NULL;
}

bool AtualizarTreinador(Treinador t)
{
    Treinador *treinador = ObeterTreinadorPeloCodigo(t.codigo);
    if (treinador != NULL)
    {
        *treinador = t;
        return true;
    }
    return false;
}

bool ApagarTreinadorPeloCodigo(int codigo)
{
    for (int i = 0; i < quantidade; i++)
    {
        if (treinador[i].codigo == codigo)
        {
            treinador[i] = treinador[quantidade - 1];
            quantidade--;

            if (quantidade < capacidade / 2 && capacidade > MAX_TREINADORES)
            {
                int novaCapacidade = capacidade / 2;
                Treinador *novoArray = (Treinador *)realloc(treinador, novaCapacidade * sizeof(Treinador));
                if (novoArray != NULL)
                {
                    treinador = novoArray;
                    capacidade = novaCapacidade;
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

    for (int i = 0; i < quantidade; i++)
    {
        if (strcmp(treinador[i].nome, nome) == 0)
        {
            treinador[i] = treinador[quantidade - 1];
            quantidade--;
            encontrado = true;
            i--;
        }
    }

    if (encontrado && quantidade < capacidade / 2 && capacidade > MAX_TREINADORES)
    {
        int novaCapacidade = capacidade / 2;
        Treinador *novoArray = (Treinador *)realloc(treinador, novaCapacidade * sizeof(treinador));
        if (novoArray != NULL)
        {
            treinador = novoArray;
            capacidade = novaCapacidade;
        }
    }

    return encontrado;
}

void ListarTreinadores()
{
    if (quantidade == 0)
    {
        printf("Nenhum treinador cadastrado.\n");
        
    }

    printf("Listar Treinadores:\n");
    for (int i = 0; i < quantidade; i++)
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
    // stdin vai ser utilizado para ler operações de E/S
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
