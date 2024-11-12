#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pokemon.h"

#define MAX_POKEMONS 5

int capacidadePokemon = 0;
int quantidadePokemon = 0;
Pokemon* pokemon = NULL;

bool InicializarPokemons()
{
    pokemon = (Pokemon *)malloc(MAX_POKEMONS * sizeof(Pokemon));

    if (pokemon == NULL)
    {
        return false;
    }
    else
    {
        capacidadePokemon = MAX_POKEMONS;
        quantidadePokemon = 0;
        return true;
    }
}

bool EncerraPokemons()
{
    if (pokemon != NULL)
    {
        free(pokemon);
        pokemon = NULL;
        capacidadePokemon = 0;
        quantidadePokemon = 0;
        return true;
    }
    return false;
}

bool SalvarPokemon(Pokemon p)
{
    if (quantidadePokemon >= capacidadePokemon)
    {
        int novaCapacidadePokemon = capacidadePokemon * 2;
        Pokemon *novoArray = (Pokemon *)realloc(pokemon, novaCapacidadePokemon * sizeof(Pokemon));
        if (novoArray == NULL)
        {
            return false;
        }
        pokemon = novoArray;
        capacidadePokemon = novaCapacidadePokemon;
    }
    pokemon[quantidadePokemon++] = p;
    return true;
}

int QuantidadePokemon()
{
    return quantidadePokemon;
}

Pokemon *ObterPokemonPeloIndice(int indice)
{
    if (indice < 0 || indice >= quantidadePokemon)
    {
        return NULL;
    }
    return &pokemon[indice];
}

Pokemon *ObterPokemonPeloCodigo(int codigo)
{	
	int i = 0;
    for (i; i < quantidadePokemon; i++)
    {
        if (pokemon[i].codigo == codigo)
        {
            return &pokemon[i];
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
	int i = 0;
    for (i; i < quantidadePokemon; i++)
    {
        if (pokemon[i].codigo == codigo)
        {
            pokemon[i] = pokemon[quantidadePokemon - 1];
            quantidadePokemon--;

            if (quantidadePokemon < capacidadePokemon / 2 && capacidadePokemon > MAX_POKEMONS)
            {
                int novaCapacidadePokemon = capacidadePokemon / 2;
                Pokemon *novoArray = (Pokemon *)realloc(pokemon, novaCapacidadePokemon * sizeof(Pokemon));
                if (novoArray != NULL)
                {
                    pokemon = novoArray;
                    capacidadePokemon = novaCapacidadePokemon;
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
	
	int i = 0;
	
    for (i; i < quantidadePokemon; i++)
    {
        if (strcmp(pokemon[i].nome, nome) == 0)
        {
            pokemon[i] = pokemon[quantidadePokemon - 1];
            quantidadePokemon--;
            encontrado = true;
            i--;
        }
    }

    if (encontrado && quantidadePokemon < capacidadePokemon / 2 && capacidadePokemon > MAX_POKEMONS)
    {
        int novaCapacidadePokemon = capacidadePokemon / 2;
        Pokemon *novoArray = (Pokemon *)realloc(pokemon, novaCapacidadePokemon * sizeof(pokemon));
        if (novoArray != NULL)
        {
            pokemon = novoArray;
            capacidadePokemon = novaCapacidadePokemon;
        }
    }

    return encontrado;
}

void ListarPokemons()
{
	int i = 0;
    if (quantidadePokemon == 0)
    {
        printf("Nenhum pokemon cadastrado.\n");
        return;
    }

    printf("Listar Pokemons:\n");
    for (i; i < quantidadePokemon; i++)
    {
        printf("Codigo: %d, Nome: %s, Ataque: %d, Defesa: %d\n",
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
    // stdin vai ser utilizado para ler operacoess de E/S
    p.nome[strcspn(p.nome, "\n")] = '\0';

    printf("Digite o bonus de ataque: ");
    scanf("%d", &p.Ataque);

    printf("Digite o bonus de defesa: ");
    scanf("%d", &p.Defesa);

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
