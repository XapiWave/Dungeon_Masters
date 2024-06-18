#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>

//-------------------------movement--------------------------------------------
char map[7][7];
int Pv=3;		//	Player Vertical
int Ph=3;		//	Player Horizontal
int PI;			//	Player Input
//		Top left = [1] [1]		 Bottom right =  [5] [5]		Middle = [3] [3]

void reset();
void display();
void player_inputM();	//	Player input for movement
//-------------------------movement--------------------------------------------

//---------------------enemy-encounter--------------------------------------------
typedef struct	{
	int hp;
	int dmg;
	int Ec;		//	Encounter value (chance)
}enemy;
enemy basic;

int victories=0;
int moves=0;
int Ev;			//	Encounter value
char ActL[3];		//	Battle action list
int Act=1;

void encounter();
void battle_act();
void reset_Act();	//reset Act list
void reset_Enmy();
//---------------------enemy-encounter--------------------------------------------


int main(void)
{
initscr();		//	Initializes the screen (aka the ncurses library)
raw();			//	Disables line buffering, sends all key inputs to the programm using ncurses
keypad(stdscr, TRUE);	//	Enable special keys to be captured
noecho();		//	Makes it so the pressed keys are not displayed in the terminal
srand(time(NULL));
	
	reset_Enmy();
	while(1)
	{
	display();
	player_inputM();

	Ev = rand()%3+1;
	
	if (Ev == basic.Ec)
	do{
		if(PI == 'q') break;
		encounter ();
		if(PI == 'q') break;
	
	}while(basic.hp >0);
	if(basic.hp<=0)		{
		victories++;
		moves = 0;
		reset_Enmy();	}
	if(PI == 'q') break;
	
	}
	
endwin();		//closes the window (aka the ncurses library)
	return 0;
}


void reset(){
	for (int v=0;v<=6;v++){
		for (int h=0;h<=6;h++){
			if (h==0 || h==6)
			map[h][v] = '!';
			if (v==0 || v==6)
			map[h][v] = '!';
			if (h!=0 && h!=6 && v!=0 && v!=6)
			map[h][v] = ' ';
		}
	}
}

void display(){
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
			printw("[*]  ");
		}
		printw("\n\n");
	}
printw("\t\t\t\t\t\t\tEnemys defeated -> %d\n\n", victories);
refresh();
}

void player_inputM(){
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

//---------------------enemy-encounter--------------------------------------------

void encounter(){
	
	
	clear();
	reset_Act();
	ActL[Act] = '*';
	printw("Battle Window\n\n\t\tEnemy Encountered!\t\t\texit-> q\n\n\tEnemy hp -> %d\n\tEnemy dmg -> %d", basic.hp, basic.dmg);
	printw("\n\n\n\t\t        ATTACK     BLOCK      SKIP\n\t\t\t");
	for(int i=1;i<=3;i++)
	{
		if (ActL[i] != Act)
		printw("[%c]        ", ActL[i]);
		if (ActL[i] == Act)
		printw("[*]        ");
	}
	printw("\n\t\t\t\t\t\t\t\tmoves-> %d\n", moves);
	refresh();
	
	battle_act();
}

void battle_act(){
	switch(PI = getch())
	{
	case KEY_LEFT:
	    Act--;
	    if (Act<1)
	    Act++;
	    break;
	
	case KEY_RIGHT:
		Act++;
		if (Act>3)
		Act--;
	    break;
	
	case 10:		// Enter key represented by 10
		if (Act == 1)	{
		printw("\tAttack - succes");
		basic.hp = basic.hp - 2;
		moves++;	}
		if (Act == 2)	{
		printw("\tBlock - succes");
		moves++;	}
		if (Act == 3)	{
		printw("\tSkip - succes");
		moves++;	}
		
		printw("\n\n/>Press any key to continue");
		refresh();
		getch();	//	awaits user input
		break;
	
	default:
	    break;
	}
	
	
	
}

void reset_Act(){
	for(int i=1;i<=3;i++)
		ActL[i] = ' ';
}

void reset_Enmy(){
	basic.hp = 5;
	basic.dmg = 2;
	basic.Ec = 3;
}

