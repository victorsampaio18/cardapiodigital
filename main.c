
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "estrutura.h"
#include "criaLista.h"
#include "login.h"
#include "entrada.h"
#include "editar.h"
#include "remover.h"
#include "bebida.h"
#include "comida.h"
#include "vinho.h"
#include "ordenacao.h"
#include "pesquisa.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	Lista *l;
	int op, op2, op3, op4, ind, numProd, cont=1;
	l = criar();
	do{
		system("cls");
		printf(" _______________________\n");
		printf("| RESTAURANTE RODRIGUES |\n");
		printf("|-----------------------|\n");
		printf("|    1 - Funcionário    |\n");
		printf("|    2 - Cliente        |\n");
		printf("|    3 - Sair           |\n");
		printf("|_______________________|\n");
		printf("\nEscolha uma opção:\n");
		scanf("%i", &op);
		switch(op){
			case 1:
				system("cls");
				printf("LOGIN FUNCIONÁRIO\n");
				if(login()==1){
					do{
					system("cls");
					printf(" _________________\n");
					printf("|   FUNCIONÁRIO   |\n");
					printf("|-----------------|\n");
					printf("|  1 - Cadastrar  |\n");
					printf("|  2 - Editar     |\n");
					printf("|  3 - Excluir    |\n");
					printf("|  4 - Cardápio   |\n");
					printf("|  5 - Voltar     |\n");
					printf("|_________________|\n");
					printf("\nEscolha uma opção:\n");
					scanf("%i", &op2);
					switch(op2){
						case 1:
							system("cls");
							printf("Digite o numero de produtos que serão cadastrados:\n");
							scanf("%i", &numProd);
							system("cls");
							do{
								l = inserir(l, cadastrar(l));
								system("cls");
								cont++;
							}while(cont<=numProd);
							armazenar(l);
							free(l);
							printf("Se desejar cadastrar mais produtos,\nfeche o executavel e abra novamente!\n");
							system("pause");
							break;
						case 2:
							system("cls");
							printf("EDITAR CARDÁPIO\n");
							printf("ATENÇÃO: Só pode editar descrição e preço!\n");
							editar();
							break;
						case 3:
							system("cls");
							printf("EXCLUIR ITEM DO CARDÁPIO\n");
							remover();
							break;
						case 4:
							do{
								system("cls");
								system(" color 7");
								printf(" ____________________\n");
								printf("|      CARDÁPIO      |\n");
								printf("|--------------------|\n");
								printf("|     1 - Bebidas    |\n");
								printf("|     2 - Comidas    |\n");
								printf("|     3 - Vinhos     |\n");
								printf("|     4 - Voltar     |\n");
								printf("|____________________|\n");
								printf("\nEscolha uma opção:\n");
								scanf("%i", &op4);
								switch(op4){
									case 1:
										system("cls");
										printf("\nBEBIDAS\n");
										printf("------------------------\n");
										l=carregarB();
										bebidas(l);
										free(l);
										break;
									case 2:
										system("cls");
										printf("\nCOMIDAS\n");
										printf("------------------------\n");
										l=carregarC();
										comidas(l);
										free(l);
										break;
									case 3:
										system("cls");
										printf("\nVINHOS\n");
										printf("------------------------\n");
										l=carregarV();
										vinhos(l);
										free(l);
										break;
									case 4:
										break;
									default:
										puts("Opção invalida");
									}
								}while(op4!=4);
							break;
						case 5:
							break;
						default:
							puts("Opção invalida");	
						}
					}while(op2!=5);
				}
				break;
			case 2:
				do{
					system("cls");
					system(" color 7");
					printf(" ____________________\n");
					printf("|      CARDÁPIO      |\n");
					printf("|--------------------|\n");
					printf("|  1 - Cardápio      |\n");
					printf("|  2 - Cardápio Ord. |\n");
					printf("|  3 - Pesquisar     |\n");
					printf("|  4 - Voltar        |\n");
					printf("|____________________|\n");
					printf("\nEscolha uma opção:\n");
					scanf("%i", &op3);
					switch(op3){
						case 1:
							do{
								system("cls");
								system(" color 7");
								printf(" ____________________\n");
								printf("|      CARDÁPIO      |\n");
								printf("|--------------------|\n");
								printf("|     1 - Bebidas    |\n");
								printf("|     2 - Comidas    |\n");
								printf("|     3 - Vinhos     |\n");
								printf("|     4 - Voltar     |\n");
								printf("|____________________|\n");
								printf("\nEscolha uma opção:\n");
								scanf("%i", &op4);
								switch(op4){
									case 1:
										system("cls");
										printf("\nBEBIDAS\n");
										printf("------------------------\n");
										l=carregarB();
										bebidas(l);
										free(l);
										break;
									case 2:
										system("cls");
										printf("\nCOMIDAS\n");
										printf("------------------------\n");
										l=carregarC();
										comidas(l);
										free(l);
										break;
									case 3:
										system("cls");
										printf("\nVINHOS\n");
										printf("------------------------\n");
										l=carregarV();
										vinhos(l);
										free(l);
										break;
									case 4:
										break;
									default:
										puts("Opção invalida");
								}
							}while(op4!=4);
							break;
						case 2:
							system("cls");
							printf("CARDÁPIO\n");
							ordenacao(l);
							break;
						case 3:
							system("cls");
							printf("PESQUISA NO CARDÁPIO\n");
							pesquisar();
							break;
						case 4:
							break;
						default:
							puts("Opção invalida");
					}
				}while(op3!=4);
				break;
			case 3:
				exit(1);
				break;
			default:
				puts("Opção invalida");
		}
	}while(1);
	return 0;
}
