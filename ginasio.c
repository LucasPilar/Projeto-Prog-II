#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ginasio.h"

#define MAX_GINASIO 5

int capacidadeGinasio = 0;
int quantidadeGinasio = 0;
Ginasio* ginasio = NULL;

bool InicializarGinasio()
{
    struct Ginasio *ginasio = malloc(MAX_GINASIO * sizeof(Ginasio));

    if (ginasio == NULL)
    {
        return false;
    }
    else
    {
        capacidadeGinasio = MAX_GINASIO;
        quantidadeGinasio = 0;
        return true;
    }
}

bool EncerraGinasio()
{
    if (ginasio != NULL)
    {
        free(ginasio);
        ginasio = NULL;
        capacidadeGinasio = 0;
        quantidadeGinasio = 0;
        return true;
    }
    return false;
}

bool SalvarGinasio(Ginasio g)
{
    if (quantidadeGinasio >= capacidadeGinasio)
    {
        int novaCapacidadeGinasio = capacidadeGinasio * 2;
        Ginasio *novoArray = (Ginasio *)realloc(ginasio, novaCapacidadeGinasio * sizeof(Ginasio));
        if (novoArray == NULL)
        {
            return false;
        }
        ginasio = novoArray;
        capacidadeGinasio = novaCapacidadeGinasio;
    }
    ginasio[quantidadeGinasio++] = g;
    return true;
}

int QuantidadeGinasio()
{
    return quantidadeGinasio;
}

Ginasio *ObterGinasioPeloIndice(int indice)
{
    if (indice < 0 || indice >= quantidadeGinasio)
    {
        return NULL;
    }
    return &ginasio[indice];
}

Ginasio* ObterGinasioPeloCodigo(int codigo)
{
	int i = 0;
    for (i; i < quantidadeGinasio; i++)
    {
        if (ginasio[i].codigo == codigo)
        {
            return &ginasio[i];
        }
    }
    return NULL;
}

bool AtualizarGinasio(Ginasio g)
{
    Ginasio *ginasio = ObterGinasioPeloCodigo(g.codigo);
    if (ginasio != NULL)
    {
        *ginasio = g;
        return true;
    }
    return false;
}

bool ApagarGinasioPeloCodigo(int codigo)
{
	int i = 0;
    for (i; i < quantidadeGinasio; i++)
    {
        if (ginasio[i].codigo == codigo)
        {
            ginasio[i] = ginasio[quantidadeGinasio - 1];
            quantidadeGinasio--;

            if (quantidadeGinasio < capacidadeGinasio / 2 && capacidadeGinasio > MAX_GINASIO)
            {
                int novaCapacidadeGinasio = capacidadeGinasio / 2;
                Ginasio *novoArray = (Ginasio *)realloc(ginasio, novaCapacidadeGinasio * sizeof(Ginasio));
                if (novoArray != NULL)
                {
                    ginasio = novoArray;
                    capacidadeGinasio = novaCapacidadeGinasio;
                }
            }
            return true;
        }
    }
    return false;
}

bool ApagarGinasioPeloNome(char *nome)
{
    bool encontrado = false;
	int i = 0;
    for (i; i < quantidadeGinasio; i++)
    {
        if (strcmp(ginasio[i].nome, nome) == 0)
        {
            ginasio[i] = ginasio[quantidadeGinasio - 1];
            quantidadeGinasio--;
            encontrado = true;
            i--;
        }
    }

    if (encontrado && quantidadeGinasio < capacidadeGinasio / 2 && capacidadeGinasio > MAX_GINASIO)
    {
        int novaCapacidadeGinasio = capacidadeGinasio / 2;
        Ginasio *novoArray = (Ginasio *)realloc(ginasio, novaCapacidadeGinasio * sizeof(ginasio));
        if (novoArray != NULL)
        {
            ginasio = novoArray;
            capacidadeGinasio = novaCapacidadeGinasio;
        }
    }

    return encontrado;
}

void ListarGinasios()
{
	int i = 0;
    if (quantidadeGinasio == 0)
    {
        printf("Nenhum Ginasio cadastrado.\n");
        
    }

    printf("Listar Ginasios:\n");
    for (i; i < quantidadeGinasio; i++)
    {
        printf("Codigo: %d, Nome: %s, Capacidade: %d, Bairro:%d\n",
               ginasio[i].codigo, ginasio[i].nome, ginasio[i].Capacidade, ginasio[i].Bairro);
    }
}

void CadastrarGinasio()
{
    Ginasio g;
    printf("Digite o codigo do Ginasio: ");
    scanf("%d", &g.codigo);
    // Usado para limpar o buffer
    getchar();

    printf("Digite o nome do Ginasio: ");
    // fgets() serve para ler uma cadeia de caracteres e armazenar em uma string
    fgets(g.nome, sizeof(g.nome), stdin);
    // stdin vai ser utilizado para ler operacoes de E/S
    g.nome[strcspn(g.nome, "\n")] = '\0';

    printf("Digite a capacidade: ");
    scanf("%d", &g.Capacidade);

    printf("Digite o Bairro: ");
    scanf("%d", &g.Bairro);

    if (SalvarGinasio(g))
    {
        printf("Ginasio cadastrado com sucesso!\n");
    }
    else
    {
        printf("Erro ao cadastrar Ginasio.\n");
    }
}

void ExcluirGinasio()
{
    int codigo;

    printf("Digite o codigo do ginasio a ser excluido: ") /
        scanf("%d", &codigo);

    if (ApagarGinasioPeloCodigo(codigo))
    {
        printf("Ginasio excluido com sucesso!\n");
    }
    else
    {
        printf("Ginasio com o codigo %d nao encontrado.\n", codigo);
    }
}
