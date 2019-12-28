#include "funcoes.h"
#include <ncurses.h>
#define B 9

void imprimirCampo(char **campoReal, char **campo, int l, int c, int lh, int ch){
  int i, j, ip, jp, itc;
  WINDOW * gamewin = newwin((l*2)+1, (c*2)+2, 0, 0);
  box(gamewin, 0, 0);
  start_color();
  init_pair(10, COLOR_WHITE, COLOR_BLACK);
  init_pair(9, COLOR_YELLOW, COLOR_BLACK);
  init_pair(0, COLOR_WHITE, COLOR_BLACK);
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  for(i=0, ip=-1; i < l+2; i++, ip+=2){
	  for(j=0, jp=0; j < c+2; j++, jp+=2){
		 if(i == lh && j == ch)
			 wattron(stdscr, A_REVERSE);

		 itc = campo[i][j] - '0';
		 if(campo[i][j] == '*') itc = 10;
		 if(campo[i][j] == 'B') itc = 9;
		 wattron(stdscr, COLOR_PAIR(itc));
		 mvwprintw(stdscr, ip, jp, "%c", campo[i][j]);
		 wattroff(stdscr, A_REVERSE);
		 wattroff(stdscr, COLOR_PAIR(itc));
	  }
  }
  //mvprintw((l*2)+2, 1, "y: %d", lh);
  //mvprintw((l*2)+3, 1, "x: %d", ch);
  wrefresh(gamewin);
  refresh();

//Caso queira uma colinha, tá aqui o campo de verdade ;p
/*move(1, (c*2)+4);
printw("Campo REAL\n");
  for(i=0; i < l+2; i++){
    for(j=0; j < c+2; j++)
     mvprintw(i+1, j+(c*2)+5, "%c ", campoReal[i][j]);

  }*/
}

