#include <iostream>
#include <stdio.h>
#include <string>
#include "Jogador.cpp"
#include "JogoDaVelha.cpp"
using namespace std;

int main()
{
    Jogador player[2];
    JogoDaVelha game;
    string lerString;
    bool finalFase = false;
    bool finalJogo = false;
    int rodada;
    int jogadorDaRodada;
    int val1, val2;
    
    cout << "Jogador 1: Insira seu nome:\n";
    cin >> lerString;
    player[0].setNomeJogador(lerString);
    cout << "Jogador 2: Insira seu nome:\n";
    cin >> lerString;
    player[1].setNomeJogador(lerString);
    player[0].setInsert('x');
    player[1].setInsert('o');
    game.zerarTabuleiro();
    while(finalJogo == false){
        rodada = 0;
        while (finalFase == false){
            if(rodada%2 == 0){
                jogadorDaRodada = 0;
            }
            else{
                jogadorDaRodada = 1;
            }
        game.displayTabuleiro();
            cout << player[jogadorDaRodada].getNomeJogador() << " , insira o valor da linha e da coluna (de 1 a 3)\n";
            cin >> val1 >> val2;
            
            rodada++;
        }
    }
    return 0;
}
