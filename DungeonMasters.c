#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#ifdef _WIN32
    #include <windows.h>
    void change_color(int color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        switch(color) {
            case 1:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                break;
            case 2:
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                break;
            case 3:
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
                break;
            case 4:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                break;
            case 5:
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                break;
            case 6:
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                break;
            case 7:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                break;
            default:
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;
        }
    }
#else
    void change_color(int color) {
        switch(color) {
            case 1:
                printf("\033[0;31m"); // Vermelho
                break;
            case 2:
                printf("\033[0;32m"); // Verde
                break;
            case 3:
                printf("\033[0;35m"); // Roxo
                break;
            case 4:
                printf("\033[0;33m"); // Amarelo
                break;
            case 5:
                printf("\033[0;34m"); // Azul
                break;
            case 6:
                printf("\033[0;36m"); // Ciano
                break;
            case 7:
                printf("\033[0;37m"); // Branco
                break;
            default:
                printf("\033[0m"); // Reseta para a cor padrão
                break;
        }
    }
#endif

// Variaveis //
//------------menu-----------------
int menu, options;
int aparencia_escolha;
char aparencia = '*';
int color;
int placar_option;
//---------------------------------
//------------jogo-----------------
char map[7][7];	//	mapa do jogo
int Pv=3;		//	Player Vertical
int Ph=3;		//	Player Horizontal
int PI;			//	Player Input
//	Top left = [1] [1]		 Bottom right =  [5] [5]		Middle = [3] [3]
//---------------------------------
//------------Character Selection-----------------
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
//------------Character Selection-----------------

FILE *f;

// PROTOTIPOS //
//------------menu-----------------
void UI();
void menu_principal();
void definicoes();
void aparencias();
void mudar_cor();
void leaderboard();
void mostrar_leaderboard();
void clear_screen();
//---------------------------------
//------------jogo-----------------
void reset();
void display();
void player_input();
//---------------------------------
//------------Character Selection-----------------
void character_selection();
//------------Character Selection-----------------
//---------------------------------


int main(void)
{
	clear_screen();
	do{
		menu_principal();
		
	switch(menu)
		{
			case 1:
				
				
				character_selection();
				
				
/*==========================================================================*
 |				    JOGO				    |
 *==========================================================================*/

initscr();		//	Initializes the screen (aka the ncurses library)
raw();			//	Disables line buffering, sends all key inputs to the programm using ncurses
keypad(stdscr, TRUE);	//	Enable special keys to be captured
noecho();		//	Makes it so the pressed keys are not displayed in the terminal
	
	while(1)				{
	display();
	player_input();
	
	if(PI == 'q') break;	}	// press q to exit
	
endwin();		//closes the window (aka the ncurses library)

			break;

/*==========================================================================*
 |				  FIM JOGO				    |
 *==========================================================================*/
			
			case 2:
				definicoes();
			break;
			
			
			case 3:
				leaderboard();
			break;
			
			
			case 4:
				exit(0);
			break;
			
			
			default:
				printf("Opcao invalida. Tente novamente.\n");
			break;
		}
	}while(menu != 4);
	
	return 0;
}

// FUNÇÕES //

void mostrar_leaderboard()
{
	char linha[100];
	
	f = fopen("placar.txt", "r");
	
	if(f == NULL) {
		printf("Erro ao abrir o arquivo do placar.\n");
		return;
	}
	
	clear_screen();
	
	printf("\nPlacar:\n");
	while(fgets(linha, sizeof(linha), f) != NULL ) {
		printf("%s", linha);
	} 
	
	printf("\n\n");
}

void leaderboard()
{
	UI();
	printf("\n\n[1] <- Ver Placar\n[2] <- Apagar Placar\n>/ ");
	scanf("%d", &placar_option);
	
	switch(placar_option)
	{
		case 1:
			mostrar_leaderboard();
			
		break;
		
		
		case 2:
			f = fopen("placar.txt", "w");
			
			if(f != NULL) {
				fclose(f);
				printf("Placar apagado com sucesso.\n");
			} else {
				printf("Erro ao apagar o placar.\n");
			}
			break;
			
			default:
				printf("Opcao invalida. Tente novamente.\n");
			break;
	}
	
	
}	

void definicoes()
{
	
void UI();
void aparencias();
	
do{
	printf("\n\n[1] <- Mudar a Cor da Interface\n[2] <- Mudar Aparencia\n[3] <- Voltar\n\n>/ ");
	scanf("%d", &options);
	
	UI();
				
	switch(options)
	{
		case 1:
			printf("Escolha uma cor:\n\n[1] <- Vermelho\n[2] <- Verde\n[3] <- Roxo\n[4] <- Amarelo\n[5] <- Azul\n[6] <- Ciano\n[7] <- Branco\n>/ ");
			scanf("%d", &color);
			change_color(color);
			
			clear_screen();
			
			printf("Cor da interface alterada.\n");
		break;
		
		
		case 2:
			printf("\n\nMude sua aparencia. No mapa central do jogo, a aparencia e um caractere a sua escolha. Podendo ser uma das aparencias a baixo.\n\n");
			
			UI();
			
			printf("\n\nEscolha sua aparencia:\n[1] <- @\n[2] <- *\n[3] <- $\n[4] <- &\n >/ ");
			scanf("%d", &aparencia_escolha);
			
			aparencias();

			clear_screen();
			printf("\n\nNova aparencia: %c\n\n", aparencia);
			
			UI();
		break;
		
		
		case 3:
			clear_screen();
			printf("\n\nVoltando ao menu principal...\n\n");
		break;	
		
		
		default:
			printf("Opcao invalida. tente novamente.\n");
		break;
	}
	}while(options != 3);
	
}

void aparencias()
{
	switch(aparencia_escolha)
	{
		case 1:
			aparencia = '@';
		break;
		
		
		case 2:
			aparencia = '*';
		break;
		
		
		case 3:
			aparencia = '$';
		break;
		
		
		case 4:
			aparencia = '&';
		break;
		
		
		default:
			printf("Escolha invalida, tente novamente.\n");
		break;
			
	}
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

void clear_screen() 
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void character_selection()
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
	
	clear_screen();
	
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
}

/*==========================================================================*
 |				FUNÇÕES JOGO				    |
 *==========================================================================*/

void reset(){
	for (int v=0;v<=6;v++){
		for (int h=0;h<=6;h++){
			if (h==0 || h==6 || v==0 || v==6)
			map[h][v] = '!';
			if (h!=0 && h!=6 && v!=0 && v!=6)
			map[h][v] = ' ';
		}
	}
}

void display() {
	clear();
	reset();
	map[Ph][Pv] = '*';
	printw("\n\n\n");
	for (int v=1;v<=5;v++)
	{
		printw("\t\t");
		for(int h=1;h<=5;h++)
		{
			if (map[h][v] != map[Ph][Pv])
			printw("[%c]  ", map[h][v]);
			
			if (map[h][v] == map[Ph][Pv])
			printw("[%c]  ", aparencia);
		}
		printw("\n\n");
	}
refresh();
}

void player_input(){
switch(PI = getch())
	{
	case KEY_UP:
	    Pv--;
	    if(map[Ph][Pv] == '!')
	    Pv++;
	    break;
	
	case KEY_DOWN:
	    Pv++;
	    if(map[Ph][Pv] == '!')
	    Pv--;
	    break;
	
	case KEY_LEFT:
	    Ph--;
	    if(map[Ph][Pv] == '!')
	    Ph++;
	    break;
	
	case KEY_RIGHT:
	    Ph++;
	    if(map[Ph][Pv] == '!')
	    Ph--;
	    break;
	
	default:
	    break;
	}
}
