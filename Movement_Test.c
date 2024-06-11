#include <stdio.h>
#include <curses.h>

char map[5][5];

void reset();
void display();
void player_loc();

int main(void)
{
	reset();
	display();
	
	
	return 0;
}

void reset(){
	for (int h=0;h<5;h++){
		for (int v=0;v<5;v++){
			map[h][v] = ' ';
		}
	}
}

void display(){
	printf("\n\n");
	for (int h=0;h<5;h++){
		printf("\t\t");
		for(int v=0;v<5;v++){
			printf("[%c]  ", map[h][v]);
		}
		printf("\n\n");
	}
}

void player_loc(){
	
	
	
}


