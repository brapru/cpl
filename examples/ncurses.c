#include "vec.h"
#include <curses.h>
#include <time.h>

struct timespec req;

void init_terminal_ncurses(void){
	initscr();
	cbreak();
	noecho();
	start_color();
	use_default_colors();
	clear();
}

void swap(cpl_vector *v){
	int tmp;
	tmp = v->data[0];
	v->data[0] = v->data[2];
	v->data[2] = tmp;
}

void print_ncurses(cpl_vector *vec){
	int row = 0;
	int col = 0;

	int max_x = 100;
	int max_y = 100;

	for (int i = 0; i < vec->size; i++){
		for (int j = 0; j < vec->data[i]; j++){
			mvaddch(row, col++, '#');
		}
		
		for (int x = col; x < max_x; x++){
			mvaddch(row, col++, ' ');
		}
		
		col = 0;
		row++;
	}
}

int main(void){
	cpl_vector *vec = vector(5);
	
	vector_push_back(vec, 74)
	vector_push_back(vec, 23);
	vector_push_back(vec, 3);
	vector_push_back(vec, 12);
	vector_push_back(vec, 74);

	init_terminal_ncurses();

	while(1){
		print_ncurses(vec);
		refresh();
		swap(vec);	
		napms(10);
	};

	getch();
	endwin();
}
