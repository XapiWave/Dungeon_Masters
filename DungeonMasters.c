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
char map[5][5];	//	mapa do jogo
int Pv=3;		//	Player Vertical
int Ph=3;		//	Player Horizontal
int PI;			//	Player Input
//	Top left = [1] [1]		 Bottom right =  [5] [5]		Middle = [3] [3]
//---------------------------------

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
//---------------------------------
//------------jogo-----------------
void reset();
void display();
void player_input();
//---------------------------------



int main(void)
{
	system("clear");
	do{
		menu_principal();
		
	switch(menu)
		{
			case 1:

/*==========================================================================*
 |									JOGO									|
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
 |								   FIM JOGO									|
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
	
	system("clear");
	
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
			
			system("clear");
			
			printf("Cor da interface alterada.\n");
		break;
		
		
		case 2:
			printf("\n\nMude sua aparencia. No mapa central do jogo, a aparencia e um caractere a sua escolha. Podendo ser uma das aparencias a baixo.\n\n");
			
			UI();
			
			printf("\n\nEscolha sua aparencia:\n[1] <- @\n[2] <- *\n[3] <- $\n[4] <- &\n >/ ");
			scanf("%d", &aparencia_escolha);
			
			aparencias();

			system("clear");
			printf("\n\nNova aparencia: %c\n\n", aparencia);
			
			UI();
		break;
		
		
		case 3:
			system("clear");
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

/*==========================================================================*
 |								FUNÇÕES JOGO								|
 *==========================================================================*/

void reset(){
	for (int h=1;h<=5;h++){
		for (int v=1;v<=5;v++){
			map[h][v] = ' ';
		}
	}
}


void display() {
	clear();
	reset();
	map[Pv][Ph] = '!';
	printw("\n\n\n");
	for (int h=1;h<=5;h++)
	{
		printw("\t\t");
		for(int v=1;v<=5;v++)
		{
			if (map[h][v] != map[Pv][Ph])
			printw("[%c]  ", map[h][v]);
			
			if (map[h][v] == map[Pv][Ph])
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
	    break;
	
	case KEY_DOWN:
	    Pv++;
	    break;
	
	case KEY_LEFT:
	    Ph--;
	    break;
	
	case KEY_RIGHT:
	    Ph++;
	    break;
	
	default:
	    break;
	}
}

