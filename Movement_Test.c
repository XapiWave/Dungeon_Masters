#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

char map[7][7];

int Pv=3;		//	Player Vertical
int Ph=3;		//	Player Horizontal
int PI;			//	Player Input
//		Top left = [1] [1]		 Bottom right =  [5] [5]		Middle = [3] [3]

void reset();
void display();
void player_input();

int main(void)
{
initscr();		//	Initializes the screen (aka the ncurses library)
raw();			//	Disables line buffering, sends all key inputs to the programm using ncurses
keypad(stdscr, TRUE);	//	Enable special keys to be captured
noecho();		//	Makes it so the pressed keys are not displayed in the terminal
	
	
	
	while(1)
	{
	display();
	player_input();
	
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
			printw("[*]  ");
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


