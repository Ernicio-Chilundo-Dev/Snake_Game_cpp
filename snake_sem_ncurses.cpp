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

void  desenhar(){
    system("cls");//limpa a tela windows

    //Desenhar mapa
    for(int i=0;i<largura+2;i++)cout <<"#";
    cout <<endl;

    for(int i =0; i <altura;i++){
        for(int j=0;j<largura;j++){
            if(j==0)cout << "#"; // Borda esquerda

            if(i==y && j==x)
                    cout << "O"; //Cabeca da cobra

            else if(i==comidaY && comidaX)
                cout << "O";//Comida

            else{
                bool impresso = false;
                for(int k =0; k<ncauda;k++){
                    if(caudaX[k]==j && caudaY[k] == i){
                        cout <<"o";//corpo da cobra
                        impresso=true;
                    }


                }
                if(!impresso)cout << " ";
            }
            if(j==largura-1)cout << "#";//Borda direita
        }
        cout << endl;
    }

    for(int i= 0;i<largura+2;i++)cout <<"#";
    cout <<endl;

    cout << "Ponttucao: "<<pontuacao<<endl;
}