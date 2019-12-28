#include "funcoes.h"
#include <time.h>

char **gerarCampo(int l, int c, int m){
  int i, j, bl, bc;
  //printf("Linhas: %d\nColunas: %d\n", l, c);
  char **field = (char**)calloc(l+2, sizeof(char*));
  for(i=0; i < l+2; i++){
    field[i] = (char*)calloc(c+2, sizeof(char));
  }

  for(i=1; i < l+1; i++)
    for(j=1; j < c+1; j++)
      field[i][j] = '*';

  srand(time(NULL));
  while(m > 0){
    bl = rand() % (l+1);
    bc = rand() % (c+1);
    //printf("\nbl = %d\nbc = %d\n", bl, bc);
    if(field[bl][bc] != 'B' && (bl != 0 && bc != 0)){
      field[bl][bc] = 'B';
      m--;
    }
  }

  return field;
}

