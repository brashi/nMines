#include <stdio.h>
#include <stdlib.h>

char **gerarCampo(int l, int c, int m);

void imprimirCampo(char **campoReal, char **campo, int l, int c, int lh, int ch);

void jogar(char *acao, int l, int c, int *yPos, int *xPos, char **campoReal, char **campoVisual);

int procurarMinas(char **campoReal, int l, int c);

int abrirCampo(char **campoReal, char **campo, int *jogadas, int l, int c, char acao);

void iniciarJogo(char **campo, int l, int c, int minas);
