#include <stdio.h>

// Variaveis //
int menu, options;
char aparencia;

// Funcoes //
void UI();
void menu_principal();
void definicoes();


int main(void)
{
	do{
		menu_principal();
		
	switch(menu)
		{
			case 1:
				printf("Jogo foda");
			break;
			
			case 2:
				definicoes();
			break;
			
			case 3:
				printf("Placar\n");
			break;
			
			case 4:
				printf("Sair\n");
			break;
			
			default:
				printf("Opcao invalida. Tente novamente.\n");
			break;
		}
	}while(menu != 4);
	
	return 0;
}

void definicoes()
{
do{
	printf("\n\n[1] <- Mudar a cor do Mapa\n[2] <- Mudar Aparencia\n[3] <- Voltar");
	scanf("%d", &options);
				
	switch(options)
	{
		case 1:
			printf("Mudar cor do mapa\n");
		break;
		
		case 2:
			printf("Muda aparencia\n");
		break;
		
		case 3:
			printf("Voltando ao menu principal...\n");
		break;	
		
		default:
			printf("Opcao invalida. tente novamente.\n");
		break;
	}
	}while(options != 3);
	
}

void menu_principal()
{

void UI();	

	UI();
	printf(" \n\tDungeon Masters - O Roguelite RPG em ASCII\n");
	UI();

	printf("\n[1] <- Comecar Jogo\n[2] <- Definicoes\n[3] <- Placar\n[4] <- Sair\n>/");
	scanf("%d", &menu);
	
	UI();
}

void UI()
{
	printf("+");
	for(int i=0; i<56; i++)
		{
			printf("-");
		}
	printf("+");
}
