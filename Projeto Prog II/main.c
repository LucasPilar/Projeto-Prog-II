#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"
#include "treinador.h"

void MenuTreinador(int codigo)
{
	int opcao;
	do
	{
		printf("\n Menu Treinador:\n");
		printf("1 - Listar Treinadores\n");
		printf("2 - Cadastrar Treinador\n");
		printf("3 - Excluir Treinador pelo Codigo\n");
		printf("4 - Excluir Treinador pelo nome\n");
		printf("0 - Sair\n");
		printf("Escolha uma Opcao:");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			ListarTreinadores();
			break;

		case 2:
		{
			Treinador novoTreinador;
			printf("Digite o codigo do treinador: ");
			scanf("%d", &novoTreinador.codigo);
			getchar();
			printf("Digite o nome do treinador: ");
			fgets(novoTreinador.nome, sizeof(novoTreinador.nome), stdin);
			novoTreinador.nome[strcspn(novoTreinador.nome, "\n")] = '\0';
			printf("Digite o bonus de ataque: \n");
			scanf("%d", &novoTreinador.BonusAtaque);
			printf("Digite o bonus de defesa: \n");
			scanf("%d", &novoTreinador.BonusDefesa);

			if (SalvarTreinador(novoTreinador))
			{
				printf("Treinador cadastrado com sucesso!\n");
			}
			else
			{
				printf("Erro ao cadastrar treinador.\n");
			}
		}

		break;

		case 3:
		{
			int codigo;
			printf("Digite o codigo do Treinador a ser excluido: ");
			scanf("%d", &codigo);

			if (ApagarTreinadorPeloCodigo(codigo))
			{
				printf("Treinador excluido com sucesso!\n");
			}
			else
			{
				printf("Treinador nao encontrado.\n");
			}
		}
		break;

		case 4:
		{
			char nome[50];
			printf("Digite o nome do treinador a ser excluido");
			getchar();
			fgets(nome, sizeof(nome), stdin);
			nome[strcspn(nome, "\n")] = '\0';

			if (ApagarTreinadorPeloNome(nome))
			{
				printf("Treinador Excluido com sucesso!\n");
			}
			else
			{
				printf("Treinador nao encontrado.\n");
			}
		}
		break;

		case 5:
		{
			Treinador treinadorAtualizado;
			printf("Digite o codigo do treinador para atualizar: ");
			scanf("%d", &treinadorAtualizado.codigo);
			getchar();
			printf("Digite o novo nome do Treinador: ");
			fgets(treinadorAtualizado.nome, sizeof(treinadorAtualizado.nome), stdin);
			treinadorAtualizado.nome[strspn(treinadorAtualizado.nome, "\n")] = '\0';
			printf("Digite o novo bonus de ataque: ");
			scanf("%d", &treinadorAtualizado.BonusAtaque);
			printf("Digite o novo bonus de defesa: ");
			scanf("%d", &treinadorAtualizado.BonusDefesa);

			if (AtualizarTreinador(treinadorAtualizado))
			{
				printf("Treinador atualizado com sucesso!\n");
			}
			else
			{
				printf("Treinador nao encontrado.\n");
			}
		}
		break;

		case 0:
			printf("Saindo do Submenu Treinador");
			break;

		default:
			printf("Opcao invalida. Tente novamente.\n");
			break;
		}

	} while (opcao != 0);
}

void MenuPokemon(int codigo)
{
	int opcao;
	do
	{
		printf("\n Menu Pokemon:\n");
		printf("1 - Listar Pokemon\n");
		printf("2 - Cadastrar Pokemon\n");
		printf("3 - Excluir Pokemon pelo Codigo\n");
		printf("4 - Excluir Pokemon pelo nome\n");
		printf("0 - Sair\n");
		printf("Escolha uma Opcao:");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			ListarPokemons();
			break;

		case 2:
		{
			Treinador novoPokemon;
			printf("Digite o codigo do Pokemon: ");
			scanf("%d", &novoPokemon.codigo);
			getchar();
			printf("Digite o nome do Pokemon: ");
			fgets(novoPokemon.nome, sizeof(novoPokemon.nome), stdin);
			novoPokemon.nome[strcspn(novoPokemon.nome, "\n")] = '\0';
			printf("Digite o bonus de ataque: \n");
			scanf("%d", &novoPokemon.BonusAtaque);
			printf("Digite o bonus de defesa: \n");
			scanf("%d", &novoPokemon.BonusDefesa);

			if (SalvarTreinador(novoPokemon))
			{
				printf("Pokemon cadastrado com sucesso!\n");
			}
			else
			{
				printf("Erro ao cadastrar Pokemon.\n");
			}
		}

		break;

		case 3:
		{
			int codigo;
			printf("Digite o codigo do Pokemon a ser excluido: ");
			scanf("%d", &codigo);

			if (ApagarPokemonPeloCodigo(codigo))
			{
				printf("Pokemon excluido com sucesso!\n");
			}
			else
			{
				printf("Pokemon nao encontrado.\n");
			}
		}
		break;

		case 4:
		{
			char nome[50];
			printf("Digite o nome do Pokemon a ser excluido");
			getchar();
			fgets(nome, sizeof(nome), stdin);
			nome[strcspn(nome, "\n")] = '\0';

			if (ApagarPokemonPeloNome(nome))
			{
				printf("Pokemon Excluido com sucesso!\n");
			}
			else
			{
				printf("Pokemon nao encontrado.\n");
			}
		}
		break;

		case 5:
		{
			Pokemon pokemonAtualizado;
			printf("Digite o codigo do Pokemon para atualizar: ");
			scanf("%d", &pokemonAtualizado.codigo);
			getchar();
			printf("Digite o novo nome do Pokemon: ");
			fgets(pokemonAtualizado.nome, sizeof(pokemonAtualizado.nome), stdin);
			pokemonAtualizado.nome[strspn(pokemonAtualizado.nome, "\n")] = '\0';
			printf("Digite o novo bonus de ataque: ");
			scanf("%d", &pokemonAtualizado.Ataque);
			printf("Digite o novo bonus de defesa: ");
			scanf("%d", &pokemonAtualizado.Defesa);

			if (AtualizarPokemon(pokemonAtualizado))
			{
				printf("Pokemon atualizado com sucesso!\n");
			}
			else
			{
				printf("Pokemon nao encontrado.\n");
			}
		}
		break;

		case 0:
			printf("Saindo do Submenu Pokemon");
			break;

		default:
			printf("Opcao invalida. Tente novamente.\n");
			break;
		}

	} while (opcao != 0);
}

void MenuPrincipal(opcao)
{

//	int opcao;
	do
	{
		printf("0 - Sair");
		printf("1 - Treinador");
		printf("2 - Pokemon");
		printf("3 - Ginasio");
		printf("4 - Batalha");
		printf("");
		scanf("%d", opcao);

		switch (opcao)
		{
		case 1:

			break;
		case 2:

		default:
			break;
		}
	} while (opcao != 0);
}

int main(int argc, char *argv[])
{
	if (!InicializarTreinadores())
	{
		printf("Erro ao inicializar o sistema de treinadores.\n");
		return 1;
	}

	if (!InicializarPokemons())
	{
		printf("Erro ao inicializar o sistema de Pokemons.\n");
		return 1;
	}

	MenuPrincipal();

	EncerraTreinadores();
	EncerraPokemons();
	return 0;
}
