#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treinador.h"
#include "pokemon.h"
#include "ginasio.h"

//MENU TREINADOR

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

//MENU POKEMON
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
			Pokemon novoPokemon;
			printf("Digite o codigo do Pokemon: ");
			scanf("%d", &novoPokemon.codigo);
			getchar();
			printf("Digite o nome do Pokemon: ");
			fgets(novoPokemon.nome, sizeof(novoPokemon.nome), stdin);
			novoPokemon.nome[strcspn(novoPokemon.nome, "\n")] = '\0';
			printf("Digite o ataque: \n");
			scanf("%d", &novoPokemon.Ataque);
			printf("Digite a defesa: \n");
			scanf("%d", &novoPokemon.Defesa);

			if (SalvarPokemon(novoPokemon))
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
			printf("Digite o codigo do pokemon para atualizar: ");
			scanf("%d", &pokemonAtualizado.codigo);
			getchar();
			printf("Digite o novo nome do pokemon: ");
			fgets(pokemonAtualizado.nome, sizeof(pokemonAtualizado.nome), stdin);
			pokemonAtualizado.nome[strspn(pokemonAtualizado.nome, "\n")] = '\0';
			printf("Digite o novo ataque: ");
			scanf("%d", &pokemonAtualizado.Ataque);
			printf("Digite a defesa: ");
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



//MENU GINASIO
void MenuGinasio(int codigo)
{
	int opcao;
	do
	{
		printf("\n Menu Ginasio:\n");
		printf("1 - Listar Ginasio\n");
		printf("2 - Cadastrar Ginasio\n");
		printf("3 - Excluir Ginasio pelo Codigo\n");
		printf("4 - Excluir Ginasio pelo nome\n");
		printf("0 - Sair\n");
		printf("Escolha uma Opcao:");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:
			ListarGinasios();
			break;

		case 2:
		{
			 Ginasio novoGinasio;
			printf("Digite o codigo do Ginasio: ");
			scanf("%d", &novoGinasio.codigo);
			getchar();
			printf("Digite o nome do Ginasio: ");
			fgets(novoGinasio.nome, sizeof(novoGinasio.nome), stdin);
			novoGinasio.nome[strcspn(novoGinasio.nome, "\n")] = '\0';
			printf("Digite a capacidade: \n");
			scanf("%d", &novoGinasio.Capacidade);
			printf("Digite o bairro: \n");
			scanf("%d", &novoGinasio.Bairro);

			if (SalvarGinasio(novoGinasio))
			{
				printf("Ginasio cadastrado com sucesso!\n");
			}
			else
			{
				printf("Erro ao cadastrar Ginasio.\n");
			}
		}

		break;

		case 3:
		{
			int codigo;
			printf("Digite o codigo do Ginasio a ser excluido: ");
			scanf("%d", &codigo);

			if (ApagarGinasioPeloCodigo(codigo))
			{
				printf("Ginasio excluido com sucesso!\n");
			}
			else
			{
				printf("Ginasio nao encontrado.\n");
			}
		}
		break;

		case 4:
		{
			char nome[50];
			printf("Digite o nome do Ginasio a ser excluido");
			getchar();
			fgets(nome, sizeof(nome), stdin);
			nome[strcspn(nome, "\n")] = '\0';

			if (ApagarGinasioPeloNome(nome))
			{
				printf("Ginasio Excluido com sucesso!\n");
			}
			else
			{
				printf("Ginasio nao encontrado.\n");
			}
		}
		break;

		case 5:
		{
			 Ginasio ginasioAtualizado;
			printf("Digite o codigo do Ginasio para atualizar: ");
			scanf("%d", &ginasioAtualizado.codigo);
			getchar();
			printf("Digite o novo nome do ginasio: ");
			fgets(ginasioAtualizado.nome, sizeof(ginasioAtualizado.nome), stdin);
			ginasioAtualizado.nome[strspn(ginasioAtualizado.nome, "\n")] = '\0';
			printf("Digite a nova Capacidadde: ");
			scanf("%d", &ginasioAtualizado.Capacidade);
			printf("Digite o novo bairro: ");
			scanf("%d", &ginasioAtualizado.Bairro);

			if (AtualizarGinasio(ginasioAtualizado))
			{
				printf("Ginasio atualizado com sucesso!\n");
			}
			else
			{
				printf("Ginasio nao encontrado.\n");
			}
		}
		break;

		case 0:
			printf("Saindo do Submenu Ginasio");
			break;

		default:
			printf("Opcao invalida. Tente novamente.\n");
			break;
		}

	} while (opcao != 0);
}


//BATALHA

void MenuPrincipal(opcao)
{

//	int opcao;
	do
	{
		printf("---- Menu Principal ----\n");
		printf("0 - Sair\n");
		printf("1 - Treinador\n");
		printf("2 - Pokemon\n");
		printf("3 - Ginasio\n");
		printf("4 - Batalha\n");
		printf("Digite a sua opcao: \n");
		scanf("%d", opcao);

		switch (opcao)
		{
		case 1:
			MenuTreinador(opcao);
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
