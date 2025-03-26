#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

// Dimensao do mapa
const int largura = 40, altura = 20;
int x, y, comidaX, comidaY, pontuacao;
int caudaX[100], caudaY[100];
int ncauda;

enum Direcao
{
    STOP = 0,
    ESQUERDA,
    DIREITA,
    BAIXO,
    CIMA
};
Direcao dir;

bool gameOver;

void setUp()
{
    gameOver = false;
    dir = STOP;

    x = largura / 2;
    y = altura / 2;
    comidaX = rand() % largura;
    comidaY = rand() % altura;
    pontuacao = 0;
}

void desenhar()
{
    system("cls"); // limpa a tela windows

    // Desenhar mapa
    for (int i = 0; i < largura + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            if (j == 0)
                cout << "#"; // Borda esquerda

            if (i == y && j == x)
                cout << "O"; // Cabeca da cobra

            else if (i == comidaY && comidaX)
                cout << "O"; // Comida

            else
            {
                bool impresso = false;
                for (int k = 0; k < ncauda; k++)
                {
                    if (caudaX[k] == j && caudaY[k] == i)
                    {
                        cout << "o"; // corpo da cobra
                        impresso = true;
                    }
                }
                if (!impresso)
                    cout << " ";
            }
            if (j == largura - 1)
                cout << "#"; // Borda direita
        }
        cout << endl;
    }

    for (int i = 0; i < largura + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Ponttucao: " << pontuacao << endl;
}

void entrada()
{
    if (_kbhit())
    { // Verfica se uma tecla foi pressionada
        switch (_getch())
        {
        case 'a':
            dir = ESQUERDA;
            break;
        case 'd':
            dir = DIREITA;
            break;
        case 's':
            dir = BAIXO;
            break;
        case 'w':
            dir = CIMA;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void logica()
{
    int prevX = caudaX[0];
    int prevY = caudaY[0];
    int prev2X, prev2Y;

    caudaX[0] = x;
    caudaY[0] = y;

    for (int i = 1; i < ncauda; i++)
    {
        prev2X = caudaX[i];
        prev2Y = caudaY[i];
        caudaX[i] = prevX;
        caudaY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case ESQUERDA:
        x--;
        break;
    case DIREITA:
        x++;
        break;
    case CIMA:
        y--;
        break;
    case BAIXO:
        y++;
        break;
    }

    // Se bater na parede perde  o jogo
    if (x >= largura || x <= 0 || y >= altura || y <= 0)
    {
        gameOver = true;
    }

    // Se bater no proprio corpo perde o jogo
    for (int i = 0; i < ncauda; i++)
    {
        if (caudaX[i] == x && caudaY[i] == y)
        {
            gameOver = true;
        }
    }

    // Se comer comida
    if (x == comidaX && y == comidaY)
    {
        pontuacao += 10;
        comidaX = rand() % largura;
        comidaY = rand() % altura;
        ncauda++;
    }
    Sleep(100); // Controla a velocidade do jogo
}

int main(){
    setUp();
    while(!gameOver){
        desenhar();
        entrada();
        logica();
    }

    cout <<"GAME OVER! Sua pontuacao foi: "<<pontuacao<<endl;

    return 0;
}

