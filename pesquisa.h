void pesquisar(){
	FILE *fp;
	int cod;
	Cardapio c;
	
	if((fp=fopen("Cardapio.bin", "rb"))!=NULL){
		printf("Digite o codigo do produto a ser pesquisado:\n");
		scanf("%i", &cod);
		while(fread(&c, sizeof(Cardapio), 1, fp)==1){
			if(cod == c.codigo && c.removido == 0){
				if(c.tipo==1){
					system("cls");
					system(" color 06 ");
					printf("\n------------------------\n");
					printf("RESULTADO DA PESQUISA\n");
					printf("------------------------\n");
					printf("CÓDIGO: %i\n", c.codigo);
					printf("PRODUTO: %s\n", c.nome);
					printf("DESCRIÇÃO: %s\n", c.descricao);
					printf("PREÇO: R$%.2f\n", c.preco);
					printf("------------------------\n");
				}else
					if(c.tipo==2){
						system("cls");
						system(" color 02 ");
						printf("\n------------------------\n");
						printf("RESULTADO DA PESQUISA\n");
						printf("------------------------\n");
						printf("CÓDIGO: %i\n", c.codigo);
						printf("PRODUTO: %s\n", c.nome);
						printf("DESCRIÇÃO: %s\n", c.descricao);
						printf("PREÇO: R$%.2f\n", c.preco);
						printf("------------------------\n");
					}else
						if(c.tipo==3){
							system("cls");
							system(" color 04 ");
							printf("\n------------------------\n");
							printf("RESULTADO DA PESQUISA\n");
							printf("------------------------\n");
							printf("CÓDIGO: %i\n", c.codigo);
							printf("PRODUTO: %s\n", c.nome);
							printf("DESCRIÇÃO: %s\n", c.descricao);
							printf("PREÇO: R$%.2f\n", c.preco);
							printf("------------------------\n");
						}
			}
			}
		}
		system("pause");
	}
