int leValidaCodigo();
Cardapio cadastrar(Lista *l){
	Lista *p;
	Cardapio c;
	int flag, qtde, ind=0;
	
	c.codigo = leValidaCodigo();
		
	do{
		printf("Digite o nome do produto:\n");
		fflush(stdin);
		gets(c.nome);
		if(strcmp(c.nome, "")==0){
			printf("Nome obrigatório!\n");
		}
	}while(strcmp(c.nome, "")==0);
		
	do{
		printf("Digite a descrição do produto:\n");
		fflush(stdin);
		gets(c.descricao);
		if(strcmp(c.descricao, "")==0){
			printf("Descrição obrigatória!\n");
		}
	}while(strcmp(c.descricao, "")==0);
		
	do{
		printf("Digite o preço do produto:\n");
		scanf("%f", &c.preco);
		if(c.preco<=0){
		printf("Preço obrigatório!\n");
		}
	}while(c.preco<=0);
		
	do{
		printf("Digite a categoria do produto:\n");
		printf("1 - Bebida\n");
		printf("2 - Comida\n");
		printf("3 - Vinho\n");
		scanf("%i", &c.tipo);
		if(c.tipo<=0 || c.tipo>3){
			printf("Opção inválida!\n");
		}
	}while(c.tipo<=0 || c.tipo>3);
	
	if(c.tipo==1){
		do{
			printf("Essa bebida é alcoólica?\n");
			printf("1 - SIM \n");
			printf("2 - NÃO \n");
			scanf("%i", &c.alcoolica);
			if(c.alcoolica != 1 && c.alcoolica != 2){
				printf("Opção inválida!\n");
			}
		}while(c.alcoolica != 1 && c.alcoolica != 2);
	}
		
	return c;
	c.removido = 0;
}

int leValidaCodigo(){
    FILE *fp;
    Cardapio c;
    int cod;
    int flag;
    do{
        flag=0;
        puts("Digite o código do produto:");
        scanf("%i", &cod);
        if(cod<1){
            flag=1;
        }else
            if((fp=fopen("Cardapio.bin","rb"))!=NULL){
                while(fread(&c, sizeof(Cardapio), 1, fp)==1){
                    if(cod==c.codigo){
                        puts("Código já cadastrado!");
                        flag=1;
                        fclose(fp);
                        break;
                    }
                }
                fclose(fp);
            }
        }while(flag==1);
    return cod;
}

Lista *inserir(Lista *l, Cardapio c){
	Lista *novo;
	novo = (Lista *)malloc(sizeof(Lista));
	novo->info = c;
	novo->prox = l;
	return novo;	
}

void armazenar(Lista *l){
	FILE *fp;
	Lista *p;
	p = l;
	if((fp=fopen("Cardapio.bin","ab"))!=NULL){
			while(p!=NULL){
				fwrite(&p->info,sizeof(Cardapio), 1, fp);
				p=p->prox;
			}
		fclose(fp);
	}	
}
