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
		printf("Arquivo n�o encontrado.\n");
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
			printf("C�DIGO: %i\n", p->info.codigo);
			printf("PRODUTO: %s\n", p->info.nome);
			printf("DESCRI��O: %s\n", p->info.descricao);
			printf("PRE�O: R$%.2f\n", p->info.preco);
			if(p->info.alcoolica==1){
				printf("BEBIDA ALCO�LICA: SIM\n");
			}else
				if(p->info.alcoolica==2){
					printf("BEBIDA ALCO�LICA: N�O\n");
				}
			printf("------------------------\n");
        }
    }
    system("pause");
}

