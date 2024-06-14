#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// VARIAVEIS //
char nome_char[12];
int classe_char;
int nivel_char;
char classe_char_val[20];

struct stats {
	int forca, agi, intel, resist;
	
	int hp, mana, dodge;
	};
	
		/*
		 * Força (FOR)			- A força fisica de seu personagem.
		 * Agilidade (AGI)		- A velocidade e reflexos de seu personagem.
		 * Inteligencia (INT) 	- A força mental e magica de seu personagem.
		 * Resistencia (RES) 	- A resistencia fisica e mental de seu personagem.
		 */

// VARIAVEIS //

// FUNCOES //
void UI();

void validacao_atributos();
// FUNCOES //



int main(void)
{
	struct stats char1;
	
	UI();
	printf("\n\t\tBem vindo a Dungeon Masters\n\nUm jogo Roguelite RPG feito completamente em C com uma aparencia em ASCII!\n\n");
	UI();

	printf("\n\nAventureiro... Qual e o seu nome? (Max 12 Letras)\n>/ ");
	scanf("%s", nome_char);
	
	printf("%s... O Mundo precisa de sua ajuda! O Rei Caido voltou e ele esta armando um plano!\n\tSo voce consegue parar-lo!", nome_char);
	printf("\n\n Vamos %s, Escolha seu caminho!\n\n", nome_char);
	
	UI();
	
	printf("\n\n\t[1]<- Cavaleiro\n\t[2]<- Mago\n\t[3]<- Ninja\n>/ ");
	scanf("%d", &classe_char);
	
	system("cls");
	
		switch(classe_char)
			{
				case 1:
					printf("Vamos, levante-se Cavaleiro %s!\n\n", nome_char);
					strcpy(classe_char_val, "Cavaleiro");
				break;
				
				
				case 2:
					printf("Vamos, levante-se Mago %s!\n\n", nome_char);
					strcpy(classe_char_val, "Mago");
				break;
				
				
				case 3:
					printf("Vamos, levante-se Ninja %s!\n\n", nome_char);
					strcpy(classe_char_val, "Ninja");
				break;
				
				default:
					printf("Caminho invalido. Escolha outro caminho da proxima vez.");
				break;
				}
	
	UI();
	
	// Atributos //
	nivel_char = 1;
	
	char1.forca  = 0;
	char1.agi 	 = 0;
	char1.intel  = 0;
	char1.resist = 0;
	// Atributos //
	
	// Bonus da Classe //
	if(classe_char == 1) 
	{
		char1.forca++; }
		
	if(classe_char == 2) 
	{
		char1.intel++; }
		
	if(classe_char == 3) 
	{
		char1.agi++; }
	// Bonus da Classe //
	
	// Atributos Rigidos //
		char1.hp = char1.resist + 3;
		char1.mana = char1.intel + 5;
		char1.dodge = char1.agi + 2;
	// Atributos Rigidos //
	
	printf("Informacoes do Personagem: \n\n\t%s, %s Nivel %d\n", nome_char, classe_char_val, nivel_char);
	printf("\n\nSeus atributos sao: \n\tFOR %d\n\tAGI %d\n\tINT %d\n\tRES %d\n\n", char1.forca, char1.agi, char1.intel, char1.resist);
	printf("\tPontos de Vida: %d\n\tPontos de Magia: %d\n\tChance de Esquiva: %d\n\n", char1.hp, char1.mana, char1.dodge);
	
	UI();
	
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

// PROTOTIPOS //
