#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pokemon.h"

#define MAX_POKEMONS 5

int capacidade = 0;
int quantidade = 0;
Pokemon pokemon = NULL;

bool InicializarPokemons()
{
    pokemon = (Pokemon *)malloc(MAX_POKEMONS * sizeof(Pokemon));

    if (pokemon == NULL)
    {
        return false;
    }
    else
    {
        capacidade = MAX_POKEMONS;
        quantidade = 0;
        return true;
    }
}

bool EncerraPokemons()
{
    if (pokemon != NULL)
    {
        free(pokemon);
        pokemon = NULL;
        capacidade = 0;
        quantidade = 0;
        return true;
    }
    return false;
}

bool SalvarPokemon(Pokemon p)
{
    if (quantidade >= capacidade)
    {
        int novaCapacidade = capacidade * 2;
        Pokemon *novoArray = (Pokemon *)realloc(pokemon, novaCapacidade * sizeof(Pokemon));
        if (novoArray == NULL)
        {
            return false;
        }
        pokemon = novoArray;
        capacidade = novaCapacidade;
    }
    pokemon[quantidade++] = p;
    return true;
}

int QuantidadePokemon()
{
    return quantidade;
}

Pokemon *ObterPokemonPeloIndice(int indice)
{
    if (indice < 0 || indice >= quantidade)
    {
        return NULL;
    }
    return &pokemon[indice];
}

Pokemon *ObterPokemonPeloCodigo(int codigo)
{
    for (int i = 0; i < quantidade; i++)
    {
        if (pokemon[i].codigo == codigo)
        {
            return pokemon[i];
        }
    }
    return NULL;
}

bool AtualizarPokemon(Pokemon p)
{
    Pokemon *pokemon = ObterPokemonPeloCodigo(p.codigo);
    if (pokemon != NULL)
    {
        *pokemon = p;
        return true;
    }
    return false;
}

bool ApagarPokemonPeloCodigo(int codigo)
{
    for (int i = 0; i < quantidade; i++)
    {
        if (pokemon[i].codigo == codigo)
        {
            pokemon[i] = pokemon[quantidade - 1];
            quantidade--;

            if (quantidade < capacidade / 2 && capacidade > MAX_POKEMONS)
            {
                int novaCapacidade = capacidade / 2;
                Pokemon *novoArray = (Pokemon *)realloc(pokemon, novaCapacidade * sizeof(Pokemon));
                if (novoArray != NULL)
                {
                    pokemon = novoArray;
                    capacidade = novaCapacidade;
                }
            }
            return true;
        }
    }
    return false;
}

bool ApagarPokemonPeloNome(char *nome)
{
    bool encontrado = false;

    for (int i = 0; i < quantidade; i++)
    {
        if (strcmp(pokemon[i].nome, nome) == 0)
        {
            pokemon[i] = pokemon[quantidade - 1];
            quantidade--;
            encontrado = true;
            i--;
        }
    }

    if (encontrado && quantidade < capacidade / 2 && capacidade > MAX_POKEMONS)
    {
        int novaCapacidade = capacidade / 2;
        Pokemon *novoArray = (Pokemon *)realloc(pokemon, novaCapacidade * sizeof(pokemon));
        if (novoArray != NULL)
        {
            pokemon = novoArray;
            capacidade = novaCapacidade;
        }
    }

    return encontrado;
}

int ListarPokemons()
{
    if (quantidade == 0)
    {
        printf("Nenhum pokemon cadastrado.\n");
        return;
    }

    printf("Listar Pokemons:\n");
    for (int i = 0; i < quantidade; i++)
    {
        printf("Código: %d, Nome: %s, Ataque: %d, Defesa: %d\n",
               pokemon[i].codigo, pokemon[i].nome, pokemon[i].Defesa, pokemon[i].Ataque);
    }
}

void CadastrarPokemon()
{
    Pokemon p;
    printf("Digite o codigo do pokemon: ");
    scanf("%d", &p.codigo);
    // Usado para limpar o buffer
    getchar();

    printf("Digite o nome do Pokemon: ");
    // fgets() serve para ler uma cadeia de caracteres e armazenar em uma string
    fgets(p.nome, sizeof(p.nome), stdin);
    // stdin vai ser utilizado para ler operações de E/S
    p.nome[strcspn(p.nome, "\n")] = '\0';

    printf("Digite o bônus de ataque: ");
    scanf("%d", &p.BonusAtaque);

    printf("Digite o bônus de defesa: ");
    scanf("%d", &p.BonusDefesa);

    if (SalvarPokemon(p))
    {
        printf("Pokemon cadastrado com sucesso!\n");
    }
    else
    {
        printf("Erro ao cadastrar pokemon.\n");
    }
}

void ExcluirPokemon()
{
    int codigo;

    printf("Digite o codigo do pokemon a ser excluido: ") /
        scanf("%d", &codigo);

    if (ApagarPokemonPeloCodigo(codigo))
    {
        printf("Pokemon excluido com sucesso!\n");
    }
    else
    {
        printf("Pokemon com o codigo %d não encontrado.\n", codigo);
    }
}