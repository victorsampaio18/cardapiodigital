void editar(){
	FILE *fp;
	int cod;
	Cardapio c;
	if((fp=fopen("Cardapio.bin", "r+b"))!=NULL){
		printf("Digite o codigo do produto a ser alterado:\n");
		scanf("%i", &cod);
		while(fread(&c, sizeof(Cardapio), 1, fp)==1){
			if(cod == c.codigo && c.removido == 0){
				printf("CÓDIGO: %i\n", c.codigo);
				printf("PRODUTO: %s\n", c.nome);
				printf("DESCRIÇÃO: %s\n", c.descricao);
				printf("PREÇO: R$%.2f\n", c.preco);
				fseek(fp, sizeof(Cardapio)*-1, SEEK_CUR);
				printf("Alterar os dados:\n");
				do{
					printf("Digite a nova descrição do produto:\n");
					fflush(stdin);
					gets(c.descricao);
					if(strcmp(c.descricao, "")==0){
						printf("Descrição obrigatória!\n");
					}
				}while(strcmp(c.descricao, "")==0);
				do{
					printf("Digite o novo preço do produto:\n");
					scanf("%f", &c.preco);
					if(c.preco<=0){
						printf("Preço obrigatório!\n");
					}
				}while(c.preco<=0);
				fwrite(&c, sizeof(Cardapio), 1, fp);
				fseek(fp, sizeof(Cardapio)*0, SEEK_END);
				puts("Dado alterado com sucesso");
				system("pause");
			}
		}
		fclose(fp);
	}
}
