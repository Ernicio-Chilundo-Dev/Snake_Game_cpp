#include <iostream>
#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//Definicao do tabuleiro
const int largura = 30;
const int altura = 15;

struct Ponto{
    int x,y;
};

vevtor<Ponto> cobra;
Ponto comida;

int direcao = KEY_RIGHT;
bool jogoRodando = true;
int pontuacao = 0;

// Funcao para gerar nova comida
void gerarComida(){
    comida.x = rand()  %  (largura -2)+1;
    comida.y = rand() % (altura - 2)+1;
}

//Funcao para inicializar o jogo
void iniciarJogo(){
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(100)

    srand(time(0));
    cobra = {{largura/2, altura/2}};
    gerarComida()
}

