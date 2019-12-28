#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "funcoes.h"
int main(void) {
  initscr();
  noecho();
  leaveok(stdscr, TRUE);
  cbreak();
  int h, w, sy, sx, yMax, xMax;
  //getmaxyx(stdscr, yMax, xMax);
  //WINDOW * win = newwin(yMax, xMax, 0, 0);
  //box(win, 0, 0);
  //refresh();

  int linhas, colunas, minas;
  char **campoReal = NULL;
  char opc = 'z';
  int valido = 0;

  keypad(stdscr, true);
  char opcoes[3][8] = {"Pequeno", "Medio", "Grande"};
  int escolha;
  int marca = 0;

  while(1){
    //delwin(win);
    //getmaxyx(stdscr, yMax, xMax);
    //wresize(win, yMax, xMax);
    //win = newwin(yMax, xMax, 0, 0);
    //box(win, 0, 0);

    mvprintw(1, 1, "Bem vindo ao N-Mines!");
    mvprintw(2, 1, "Selecione o tamanho de jogo desejado: ");
    mvprintw(2, 1, "Selecione o tamanho de jogo desejado: ");

    
    for(int i = 0; i < 3; i++)
    {
	    if(i == marca)
		    attron(A_REVERSE);
	    mvprintw(i+3, 1, opcoes[i]);
	    attroff(A_REVERSE);
    }
    refresh();
    escolha = getch();

    switch(escolha)
    {
	    case KEY_UP:
		    marca--;
		    if(marca == -1)
			    marca = 0;
		    break;
	    case KEY_DOWN:
		    marca++;
		    if(marca == 3)
			    marca = 2;
		    break;
	    default:
		    break;
    }

    if(escolha == 10)
	   break; 

  }

  switch(marca)
  {
	  case 0:
		  linhas = 9;
		  colunas = 9;
		  minas = 10;
		  break;
          case 1:
		  linhas = 16;
		  colunas = 16;
		  minas = 40;
		  break;
          case 2:
		  
		  linhas = 16;
		  colunas = 30;
		  minas = 99;
		  break;
	  default: 
		  break;
  }
  
  campoReal = gerarCampo(linhas, colunas, minas);
  clear();
  refresh();
  iniciarJogo(campoReal, linhas, colunas, minas);
  return 0;
}
