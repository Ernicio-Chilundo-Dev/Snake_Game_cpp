#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

//Dimensao do mapa
const int largura=40, altura=20;
int x,y,comidaX,comidaY,pontuacao;
int caudaX[100],caudaY[100];
int ncauda;

enum Direcao{STOP=0, ESQUERDA,DIREITA,BAIXO,CIMA};
Direcao dir;

bool gameOver;

void setUp(){
    gameOver = false;
    dir = STOP;

    x=largura/2;
    y=altura/2;
    comidaX= rand() % largura;
    comidaY = rand() % altura;
    pontuacao = 0;

}