#include <iostream>
#include <stdio.h>
#include <string>
#include "Jogador.cpp"
#include "JogoDaVelha.cpp"
using namespace std;

int main()
{
    Jogador player1;
    Jogador player2;
    JogoDaVelha game;
    string lerString;
    
    cout << "Jogador 1: Insira seu nome:\n";
    cin >> lerString;
    player1.setNomeJogador(lerString);
    cout << "Jogador 2: Insira seu nome:\n";
    cin >> lerString;
    player2.setNomeJogador(lerString);
    player1.setInsert = x;
    player2.setInsert = o;
    JogoDaVelha.zerarTabuleiro();

    return 0;
}
