Lista *carregarB(){
	FILE *fp;
	Lista *l;
	Cardapio c;
	l=NULL;
	if((fp=fopen("Cardapio.bin","rb"))!=NULL){
		while(fread(&c, sizeof(Cardapio), 1, fp)==1){
			l = inserir(l, c);
		}
		fclose(fp);
		return l;
	}else{
		printf("Arquivo não encontrado.\n");
		return NULL;
	}
}

void bebidas(Lista *l){
	Lista *p;
    Cardapio c;
    FILE *fp;
    for(p=l;p!=NULL;p=p->prox){
		if(p->info.removido==0 && p->info.tipo==1){
			system(" color 06 ");
			printf("CÓDIGO: %i\n", p->info.codigo);
			printf("PRODUTO: %s\n", p->info.nome);
			printf("DESCRIÇÃO: %s\n", p->info.descricao);
			printf("PREÇO: R$%.2f\n", p->info.preco);
			if(p->info.alcoolica==1){
				printf("BEBIDA ALCOÓLICA: SIM\n");
			}else
				if(p->info.alcoolica==2){
					printf("BEBIDA ALCOÓLICA: NÃO\n");
				}
			printf("------------------------\n");
        }
    }
    system("pause");
}

