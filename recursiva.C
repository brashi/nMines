#include "funcoes.h"

int procurarMinas(char **campoReal, int l, int c){
  int i, j;
  int bombas = 0;
  //Checando envolta de uma célula por bombas!
  if(campoReal[l-1][c-1] == 'B') bombas++; //Canto superior esquerdo
  if(campoReal[l-1][c] == 'B') bombas++; //Encima
  if(campoReal[l-1][c+1] == 'B') bombas++; //Canto superior direito
  if(campoReal[l][c-1] == 'B') bombas++; //Esquerda
  if(campoReal[l][c+1] == 'B') bombas++; //Direita
  if(campoReal[l+1][c-1] == 'B') bombas++; //Canto inferior esquerdo
  if(campoReal[l+1][c] == 'B') bombas++; //Abaixo
  if(campoReal[l+1][c+1] == 'B') bombas++; //Canto inferior direito

  return bombas;
}

//Função recursiva para abrir o campo.
int abrirCampo(char **campoReal, char **campo, int *jogadas, int l, int c, char acao){
  int bombas = 0;
  if(campo[l][c] != '*')
    return 0;

  if(campoReal[l][c] == 'B'){
    return 1;
  } else{
    (*jogadas)--;
    bombas = procurarMinas(campoReal, l, c);
    if(acao == 'A') campo[l][c] = bombas + '0';
    if(bombas == 0){
      //Canto superior esquerdo
      if(campoReal[l-1][c-1] == '*') abrirCampo(campoReal, campo, jogadas, l-1, c-1, acao);
      //Encima
      if(campoReal[l-1][c] == '*') abrirCampo(campoReal, campo, jogadas, l-1, c, acao);
      //Canto superior direito
      if(campoReal[l-1][c+1] == '*') abrirCampo(campoReal, campo, jogadas, l-1, c+1, acao);
      //Esquerda
      if(campoReal[l][c-1] == '*') abrirCampo(campoReal, campo, jogadas, l, c-1, acao);
      //Direita
      if(campoReal[l][c+1] == '*') abrirCampo(campoReal, campo, jogadas, l, c+1, acao);
      //Canto inferior esquerdo
      if(campoReal[l+1][c-1] == '*') abrirCampo(campoReal, campo, jogadas, l+1, c-1, acao);
      //Embaixo
      if(campoReal[l+1][c] == '*') abrirCampo(campoReal, campo, jogadas, l+1, c, acao);
      //Canto inferior direito
      if(campoReal[l+1][c+1] == '*') abrirCampo(campoReal, campo, jogadas, l+1, c+1, acao);

    }
    return 0;
  }

}
