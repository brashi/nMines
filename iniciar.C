#include "funcoes.h"
#include <ncurses.h>

void iniciarJogo(char **campo, int l, int c, int minas){
  int i, j, tete;
  int status = 0;
  int yPos = 1, xPos = 1;
  int jogadas = (l * c) - minas;
  char acao;
  //Este campo é o que vai ser visto pelo usuário.
  char **campoVisual = (char**)calloc(l+2, sizeof(char*));
  for(i=0; i < l+2; i++){
    campoVisual[i] = (char*)calloc(c+2, sizeof(char));
  }
  for(i=1; i < l+1; i++)
    for(j=1; j < c+1; j++)
      campoVisual[i][j] = '*';
  
  while(status == 0){
    //imprimirCampo(campo, campoVisual, l, c, yPos, xPos);
    jogar(&acao, l, c, &yPos, &xPos, campo, campoVisual);
    printf("\033[?1003l\n");
   if(acao == 'B'){
      if(campoVisual[yPos][xPos] == 'B') campoVisual[yPos][xPos] = '*';
      else
        campoVisual[yPos][xPos] = 'B';
    }
    if(acao == 'A') status = abrirCampo(campo, campoVisual, &jogadas, yPos, xPos, acao);

    if(status == 0 && jogadas == 0){
	for(i=0; i < l+2; i++){
		for(j=0; j < c+2; j++){
			if(campo[i][j] == 'B') campoVisual[i][j] = 'B';
		}
	}
      mvprintw((l*2)+3, 1, "Parabéns!!!\nVocê ganhou!!");
      refresh();
      status = 1;
    }
  }

  if(status == 1 && jogadas > 0){
      for(i=0; i < l+2; i++){
          for(j=0; j < c+2; j++){
              if(campo[i][j] == 'B') campoVisual[i][j] = 'B';
          }
      }
      //yPos = 0, xPos = 0;
      imprimirCampo(campo, campoVisual, l, c, yPos, xPos);
      mvprintw((l*2)+3, 1, "Você perdeu!");
      refresh();
    }
}
