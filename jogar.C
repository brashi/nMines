#include "funcoes.h"
#include <ncurses.h>
#define SET_ANY_EVENT_MOUSE 1003

void jogar(char *acao, int l, int c, int *yPos, int *xPos, char **campoReal, char **campoVisual){
        int input;
	(*yPos) = 1;
        (*xPos) = 1;
	int diff, sub;
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	for(;;){
		imprimirCampo(campoReal, campoVisual, l, c, *yPos, *xPos);
	        //printf("\033[?1003h\n");
	        //MEVENT mause;
		input = wgetch(stdscr);
		/*if(input == KEY_MOUSE){
			if(getmouse(&mause) == OK){
				if(mause.y/2 >= (*yPos) && (*yPos) < l)
				       	(*yPos)++;
				else if((*yPos) > l) (*yPos) = l;

				if(mause.y/2 < (*yPos) && (*yPos) > 1)
					(*yPos)--;
				else if((*yPos) < 1) (*yPos) = 1;
                                
				if(mause.x/2 >= (*xPos) && (*xPos) < c)
				       	(*xPos)++;
				else if((*xPos) > c) (*yPos) = c;

				if(mause.x/2 < (*xPos) && (*xPos) > 1)
					(*xPos)--;
				else if((*xPos) < 1) (*xPos) = 1;
			}	
		}*/
 		//printf("\033[?1003l\n");
		switch(input){
			case KEY_UP:
				(*yPos)--;
				if((*yPos) < 1)
					(*yPos) = 1;
				break;
			case KEY_DOWN:
				(*yPos)++;
				if((*yPos) > l)
					(*yPos) = l;
				break;
			case KEY_LEFT:
				(*xPos)--;
				if((*xPos) < 1)
					(*xPos) = 1;
				break;
			case KEY_RIGHT:
				(*xPos)++;
				if((*xPos) > c)
					(*xPos) = c;
				break;
			default:
				break;
		}
		//printw("%d %d", yPos, xPos);
	        //imprimirCampo(campoReal, campoVisual, l, c, *yPos, *xPos);
		if(input == 'z'){
			(*acao) = 'A';
			break;
		}
		if(input == 'x'){
			(*acao) = 'B';
			break;
		}
	}
              
}
