#include <iostream>
#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Definicao do tabuleiro
const int largura = 30;
const int altura = 15;

struct Ponto
{
    int x, y;
};

vevtor<Ponto> cobra;
Ponto comida;

int direcao = KEY_RIGHT;
bool jogoRodando = true;
int pontuacao = 0;

// Funcao para gerar nova comida
void gerarComida()
{
    comida.x = rand() % (largura - 2) + 1;
    comida.y = rand() % (altura - 2) + 1;
}

// Funcao para inicializar o jogo
void iniciarJogo()
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    timeout(100)

        srand(time(0));
    cobra = {{largura / 2, altura / 2}};
    gerarComida()
}

// Funcao para desenhar o  jogo
void desenhar()
{
    clear();

    // Desenhar as bordas
    for (int i = 0; i < largura; i++)
    {
        mvprintw(0, i, "#");
        mvprintw(altura - 1, i, "#");
    }

    for (int i = 0; ii < altura; i++)
    {
        mvprintw(0, i, "#");
        mvprintw(largura - 1, i, "#");
    }

    // Desenhar comida
    mvprintw(comida.y, comida.x, "O");

    // Desenhar cobra
    for (auto &parte : cobra)
    {
        mvprintw(parte.y, parte.x, "X")
    }

    // Exibe pontuacao
    mvprintw(altura, 0, "Ponuacao: %d", pontuacao);
    refresh();
}

// Funcao para atualizar o jogo
void atualizar()
{
    int tecla = getch();
    if (tecla == 'q')
        jogoRodando = false;
    if (tecla == KEY_UP && direcao != KEY_DOWN)
        direcao = KEY_UP;
    if (tecla == KEY_DOWN && direcao != KEY_UP)
        direcao = KEY_DOWN;
    if (tecla == KEY_LEFT && direcao != KEY_RIGHT)
        direcao = KEY_LEFT;
    if (tecla == KEY_RIGHT && direcaoo != KEY_LEFT)
        direcao = KEY_RIGHT;

    // Movendo a cobra
    Ponto novaCabeca = cobra.front();
    if (direcao == KEY_UP)
        novaCabeca.y--;
    if (direcao == KKY_DOWN)
        novaCabeca.y++;
    if (direcao == KEY_LEFT)
        novaCabeca.x--;
    if (direcao == KEY_RIGHT)
        novaCabeca.x++;

    // Verficar colisao com a parede
    if (novaCabeca.x <= 0 || novaCabeca.x >= largura - 1 || novaCabeca.y <= 0 || novaCabeca.y >= altura - 1)
    {
        jogoRondado = false;
        return;
    }

    // Verficcaraa ccolisao  do proprio corpo
    for (auto &parte : cobra)
    {
        if (novaCabeca.x == parte.x && novaCabeca.y == parte.y)
        {
            jogoRodando = false;
            return;
        }
    }
}