void ordenacao(Lista *l){
	FILE *fp;
	Cardapio c;
	Lista *p;
	int i=0, j;
	int a,ex=1, b=0;
	int vet[100];
	
	if((fp=fopen("Cardapio.bin","rb"))!=NULL){
		while(fread(&c, sizeof(Cardapio), 1, fp)==1){
			i++;
		}
	}
	
	for(a = 0; a < i; a++){
		if(p->info.codigo>b){
			b=p->info.codigo;	
		}	
	}
	while((b/ex)>0){
		int ord[10]={0};
		for(a=0; a<i; a++){
			ord[(p->info.codigo/ex)%10]++;				
		}
		for(a=1; a<10; a++){
			ord[a]+=ord[a-1];	
		}
		for(a=(i-1); a>=0; a--){	
			vet[--ord[(p->info.codigo/ex)%10]]=p->info.codigo;		
		}
		for(a=0; a<i; a++){	
			p->info.codigo=vet[a];	
		}
		ex*=10;
	}
	
	for(p=l;p!=NULL;p=p->prox){
		if(p->info.removido==0){
			printf("CÓDIGO: %i\n", p->info.codigo);
			printf("PRODUTO: %s\n", p->info.nome);
			printf("DESCRIÇÃO: %s\n", p->info.descricao);
			printf("PREÇO: R$%.2f\n", p->info.preco);
			printf("------------------------\n");
        }
    }
    system("pause");
}
