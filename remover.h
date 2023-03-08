void remover(){
	FILE *fp;
	int cod;
	Cardapio c;
	
	if((fp=fopen("Cardapio.bin", "r+b"))!=NULL){
		puts("Digite o codigo do produto a ser removido:");
		scanf("%i", &cod);
		while(fread(&c, sizeof(Cardapio), 1, fp)==1){
			if(cod == c.codigo && c.removido == 0){
				printf("CÓDIGO: %i\n", c.codigo);
				printf("PRODUTO: %s\n", c.nome);
				printf("DESCRIÇÃO: %s\n", c.descricao);
				printf("PREÇO: R$%.2f\n", c.preco);
				fseek(fp, sizeof(Cardapio)*-1, SEEK_CUR);
				c.removido = 1;
				fwrite(&c, sizeof(Cardapio), 1, fp);
				fseek(fp, sizeof(Cardapio)*0, SEEK_END);
				puts("Dado removido com sucesso");
				system("pause");
			}
		}
		fclose(fp);
	}
}
