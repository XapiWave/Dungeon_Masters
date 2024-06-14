#include <stdio.h>

// VARIAVEIS //
int nivel_char = 1;
int xp = 0;
int monstros_derrotados = 0;
int escolha_atributo;

struct stats {
	int forca, agi, intel, resist;
	
	int hp, mana, dodge;
	};
// VARIAVEIS //

// CONSTANTES //
#define XP_POR_MONSTRO 1
#define XP_POR_NIVEL 5
#define NIVEL_MAXIMO 5
// CONSTANTES //

// FUNCOES //
void UI();

void escolher_atributo(int *p_forca, int *p_agi, int *p_intel, int *p_resist);
// FUNCOES //

int main(void)
{
	struct stats char1;
	
	UI();
	
	do{
		printf("Voce derrotou um monstro! (+%d XP)\n", XP_POR_MONSTRO);
		xp += XP_POR_MONSTRO;
		monstros_derrotados++;
	
		if(xp >= nivel_char * XP_POR_NIVEL) 
			{
				xp -= nivel_char * XP_POR_NIVEL; // Subtrair o XP necessario para subir de nivel 
				nivel_char++;
				
				printf("Parabens! Voce subiu para o nivel %d!\n", nivel_char);
				
				escolher_atributo(&char1.forca, &char1.agi, &char1.intel, &char1.resist);
				
			}
		}while(nivel_char < NIVEL_MAXIMO);
		
		printf("Voce atingiu o nivel maximo!\n");
		
	return 0;
}

// PROTOTIPOS //
void UI()
{
	printf("+");
	for(int i=0; i<56; i++)
		{
			printf("-");
		}
	printf("+");
}

void escolher_atributo(int *p_forca, int *p_agi, int *p_intel, int *p_resist)
{
	int escolha;
	
	printf("Escolha um atributo para aumentar: \n");
	printf("[1]<- Forca\n[2]<- Agilidade\n[3]<- Inteligencia\n[4]<- Resistencia\n>/ ");
	scanf("%d", &escolha);
	
	switch(escolha)
		{
        case 1:
            (*p_forca)++;
            printf("Força aumentada para %d\n", *p_forca);
        break;
            
            
        case 2:
            (*p_agi)++;
            printf("Agilidade aumentada para %d\n", *p_agi);
        break;
            
            
        case 3:
            (*p_intel)++;
            printf("Inteligência aumentada para %d\n", *p_intel);
        break;
            
            
        case 4:
            (*p_resist)++;
            printf("Resistência aumentada para %d\n", *p_resist);
        break;
            
            
        default:
            printf("Escolha inválida, tente novamente.\n");
            escolher_atributo(p_forca, p_agi, p_intel, p_resist); // Chama a função novamente até que uma escolha válida seja feita
        break;
		}
}
// PROTOTIPOS //








