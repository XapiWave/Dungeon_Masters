#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

char map[5][5];

int PX=3;		//	Player Vertical
int PY=3;		//	Player Horizontal
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
	
	
	
	for(int i=0;i<10;i++)
	{
	display();
	player_input();
	
	}
	
	
endwin();		//closes the window (aka the ncurses library)
	return 0;
}


void reset(){
	for (int h=1;h<=5;h++){
		for (int v=1;v<=5;v++){
			map[h][v] = ' ';
		}
	}
}


void display() {
	//system("clear");
	reset();
	map[PX][PY] = '*';
	
	for (int h=1;h<=5;h++)
	{
		printw("\t\t");
		for(int v=1;v<=5;v++)
		{
			if (map[h][v] != map[PX][PY])
			printw("[%c]  ", map[h][v]);
			
			if (map[h][v] == map[PX][PY])
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
	    PX--;
	    break;
	
	case KEY_DOWN:
	    PX++;
	    break;
	
	case KEY_LEFT:
	    PY--;
	    break;
	
	case KEY_RIGHT:
	    PY++;
	    break;
	}
}











/*

int main() {
    int ch;

    // Initialize the curses mode
    initscr();
    raw();              // Line buffering disabled, Pass all keystrokes to the program
    keypad(stdscr, TRUE); // Enable special keys to be captured
    noecho();           // Don't echo keystrokes to the screen

    printw("Press arrow keys to move the cursor. Press 'q' to exit.\n");
    refresh();

    while ((ch = getch()) != 'q') {
        switch (ch) {
            case KEY_UP:
                printf("Up arrow key pressed\n");
                break;
            case KEY_DOWN:
                printf("Down arrow key pressed\n");
                break;
            case KEY_LEFT:
                printf("Left arrow key pressed\n");
                break;
            case KEY_RIGHT:
                printf("Right arrow key pressed\n");
                break;
            default:
                printf("Pressed key is: %c\n", ch);
                break;
        }
        refresh(); // Refresh the screen to show the printed text
    }

    // End the curses mode
    endwin();
    return 0;
}
*/
// Chat-GPT example, - try to understand
