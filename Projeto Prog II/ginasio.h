struct Ginasio{
		int codigo;
		char nome[50];
		int Capacidade;
		char Bairro[50];
};

typedef Ginasio;

bool InicializarGinasio();
bool EncerraGinasio();
bool SalvarGinasio(Ginasio g);
int QuantidadeGinasio();
Ginasio* ObterGinasioPeloIndice(int indice);
Ginasio* ObterGinasioPeloCodigo(int codigo);
bool AtualizarGinasio(Ginasio g);
bool ApagarGinasioPeloCodigo(int codigo);
bool ApagarGinasioPeloNome(char* nome); 