#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include <conio.h>	

// ----------------------------------------------- VARIAVEIS -----------------------------------------------//
int menu;
// ----------------------------------------------- VARIAVEIS -----------------------------------------------//

// ----------------------------------------------- FUNÇÕES -----------------------------------------------//
void UI();
// ----------------------------------------------- FUNÇÕES -----------------------------------------------//

int main(void)
{
	system("color XY");
	
	UI();
	printf("\t\t Bem vindo ao Jogo da Cobrinha!\n\n");
	printf("Jogar -> [ 1 ] .:::::. Definições -> [ 2 ] .:::::. Sair -> [ 3 ]\n>/ ");
	scanf("%d", &menu);
	printf("\n");
	system("clear");
	
	switch(menu)
		{
			case 1:
				printf("Jogo foda");
			break;
			
			case 2:
				UI();
				printf("\t\t\t     Opções");
			break;
		
		}
	
	return 0;
}

void UI()
{
printf("+");
for(int i = 0; i<62; i++)
	{
		printf("-");
	}
printf("+\n");
}
