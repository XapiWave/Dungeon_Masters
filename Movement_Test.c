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
int player_inputM();	//	Player input for movement
//-------------------------movement--------------------------------------------

//---------------------enemy-encounter--------------------------------------------
typedef struct	{
	int hp;
	int dmg;
	int Ec;		//	Encounter value (chance)
	int movesT;	//	Move threshold (n of moves for enemy to attack)
	int movesR;	//	N of moves to attack - default value
}enemy;
enemy basic;

int victories=0;
int moves=0;		//	Number of moves in combat
int Ev;			//	Encounter value
char ActL[3];		//	Battle action list - Attack - Block - Skip
int Act=1;

int Php = 25;		//	Player hp
int Pdmg = 3;		//	Player dmg

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
	while(Php > 0)
	{
	display();
	int moved = player_inputM();

    if (moved){
	if(PI == 'q') break;
	
	Ev = rand()%10+1;
	
	if (Ev <= basic.Ec)	{
		if(PI == 'q') break;
		encounter ();
		if(PI == 'q') break;
		}
	
	    }
	}
	
	
	if(Php <= 0) {
	    clear();
	    printw("You died\n\nThank you for playing!\n\n\n\n/> Press any key to finish");
	    refresh();
	    getch(); 
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
printw("\t\t\t\t\t\t\tPlayer hp -> %d\n", Php);
printw("\t\t\t\t\t\t\tPlayer dmg -> %d\n\n\n", Pdmg);
printw("\t\t\t\t\t\t\tMovement -> Arrow Keys\n\n");
refresh();
}

int player_inputM(){
int moved = 0;
switch(PI = getch())
	{
	case KEY_UP:
	    Pv--;
	    if(map[Ph][Pv] == '!')
		Pv++;
	    else
		moved = 1;
	    break;
	
	case KEY_DOWN:
	    Pv++;
	    if(map[Ph][Pv] == '!')
		Pv--;
	    else
		moved = 1;
	    break;
	
	case KEY_LEFT:
	    Ph--;
	    if(map[Ph][Pv] == '!')
		Ph++;
	    else
		moved = 1;
	    break;
	
	case KEY_RIGHT:
	    Ph++;
	    if(map[Ph][Pv] == '!')
		Ph--;
	    else
		moved = 1;
	    break;
	
	default:
	    break;
	}
return moved;
}

//---------------------enemy-encounter--------------------------------------------

void encounter(){
	do{
	if (Php <= 0)	break;
	if (PI == 'q') break;
	
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
	printw("\n\tEnemy attacks in -> %d\t\t\t\t\t\t\tmoves -> %d\n",basic.movesT ,moves);
	printw("\n\n\t\t\t\t\t\t\t\thp -> %d", Php);
	printw("\n\t\t\t\t\t\t\t\tdmg -> %d\n\n", Pdmg);
	refresh();
	
	battle_act();
	
	if(basic.hp<=0)
		break;
	
	}while(Php > 0);
victories++;
moves = 0;
reset_Enmy();

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
		basic.hp -= Pdmg;
		moves++;	
		basic.movesT--;	}
		if (Act == 2)	{
		printw("\tBlock - succes");
		moves++;	
		basic.movesT--;	}
		if (Act == 3)	{
		printw("\tSkip - succes");
		moves++;	
		basic.movesT--;}
		
		if (basic.movesT <= 0){
		    printw("\n\nEnemy Attacked!");
		    Php -= basic.dmg;
		    basic.movesT = basic.movesR;
			if (Act == 2)		{
			    printw("\t\tAttck blocked!");
			    Php += basic.dmg;	}
		}
		
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
	basic.hp = rand()%4+4;
	basic.dmg = rand()%5+1;
	basic.Ec = 5;
	basic.movesR = rand()%3+2;
	basic.movesT == basic.movesR;
    if(basic.movesR >= 4)
	basic.dmg++;
}

