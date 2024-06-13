#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

char map[5][5];

int PX=3;		//	Player Vertical
int PY=3;		//	Player Horizontal
//		Top left = [1] [1]		 Bottom right =  [5] [5]		Middle = [3] [3]

void reset();
void display();
void player_input();

WINDOW *win(void);
int keypad(WINDOW *win, bool);
int noecho();
//int nodelay(WINDOW *win, bool)

int main(void)
{
	reset();
	while (true)
	{
	display();
	player_input();
	system("clear");
	}
	
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
	map[PX][PY] = '*';
	printf("\n\n\n");
	for (int h=1;h<=5;h++)
	{
		printf("\t\t");
		for(int v=1;v<=5;v++)
		{
			if (map[h][v] != map[PX][PY])
			printf("[%c]  ", map[h][v]);
			
			if (map[h][v] == map[PX][PY])
			printf("[*]  ");
		}
		printf("\n\n");
	}
}

void player_input(){
	int wgetch(WINDOW *win);
	
	


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
                printw("Up arrow key pressed\n");
                break;
            case KEY_DOWN:
                printw("Down arrow key pressed\n");
                break;
            case KEY_LEFT:
                printw("Left arrow key pressed\n");
                break;
            case KEY_RIGHT:
                printw("Right arrow key pressed\n");
                break;
            default:
                printw("Pressed key is: %c\n", ch);
                break;
        }
        refresh(); // Refresh the screen to show the printed text
    }

    // End the curses mode
    endwin();
    return 0;
}
* 
* // Chat-GPT example, - try to understand
