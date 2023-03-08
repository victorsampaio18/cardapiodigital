struct cardapio{
    char nome[25];
    char descricao[50];
    float preco;
    int codigo;
    int tipo;
    int qtde;
    int removido;
    int alcoolica;
};
typedef struct cardapio Cardapio;
struct lista{
	Cardapio info;
	struct lista *prox;
};
typedef struct lista Lista;
