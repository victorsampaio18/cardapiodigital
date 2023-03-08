void leValidaDado(char texto1[], char texto2[], char letra);
int login(){
	char usuario[25];
	char senha[25];
		
	do{
		leValidaDado(usuario, "usuário", 'o');
		leValidaDado(senha, "senha", 'a');
		if((strcmp(usuario, "admin")!=0)||(strcmp(senha, "123456")!=0)){
			puts("Usuário ou senha incorreto.");
		}
		system("pause");
	}while((strcmp(usuario, "admin")!=0)||(strcmp(senha, "123456")!=0));
	system("cls");
	printf("Usuário autorizado.\n");
	system("pause");
	system("cls");
	return 1;	
}
void leValidaDado(char texto1[], char texto2[], char letra){
	do{
		printf("Digite %c %s:\n", letra, texto2);
		fflush(stdin);
		gets(texto1);
		if(strcmp(texto1,"")==0){
			printf("%s obrigatóri%c\n", texto2, letra);
		}
	}while(strcmp(texto1,"")==0);
}
