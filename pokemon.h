#include <stdbool.h>

typedef struct{
	int codigo;
	char nome[50];
	int Ataque;
	int Defesa;
}  Pokemon;

bool InicializarPokemons();
bool EncerraPokemons();
bool SalvarPokemon(Pokemon p);
int QuantidadePokemon();
Pokemon *ObterPokemonPeloIndice(int indice);
Pokemon *ObterPokemonPeloCodigo(int codigo);
bool AtualizarPokemon(Pokemon p);
bool ApagarPokemonPeloCodigo(int codigo);
bool ApagarPokemonPeloNome(char *nome);
void ListarPokemons();
void CadastrarPokemon();
void ExcluirPokemon();
