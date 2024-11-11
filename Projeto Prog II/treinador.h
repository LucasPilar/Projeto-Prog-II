#include <stdbool.h>

typedef struct{
		int codigo;
		char nome[50];
		int BonusAtaque;
		int BonusDefesa;
}Treinador;


bool InicializarTreinadores();
bool EncerraTreinadores();
bool SalvarTreinador(Treinador t);
int QuantidadeTreinadores();
Treinador* ObterTreinadorPeloIndice(int indice);
Treinador* ObterTreinadorPeloCodigo(int codigo);
bool AtualizarTreinador(Treinador t);
bool ApagarTreinadorPeloCodigo(int codigo);
bool ApagarTreinadorPeloNome(char* nome); 
