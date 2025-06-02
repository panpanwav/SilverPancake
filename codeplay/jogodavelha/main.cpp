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
    bool liberar;
    bool finalFase;
    bool finalJogo = false;
    int rodada;
    int partidaAtual = 0;
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
    
    while(finalJogo == false){
        game.zerarTabuleiro();
        partidaAtual++;
        cout << "Partida " << partidaAtual << "\n";
        finalFase = false;
        rodada = -1;
        while (finalFase == 0){
            rodada++;
            if(rodada%2 == 0){
                jogadorDaRodada = 0;
            }
            else{
                jogadorDaRodada = 1;
            }
            liberar = false;
            while (liberar == false){
                cout << player[jogadorDaRodada].getNomeJogador() << ", insira o valor da linha e da coluna (de 1 a 3)\n";
                game.displayTabuleiro();
                cin >> val1 >> val2;
                val1--;
                val2--;
                liberar = game.verificarVazio(val1,val2);
                if (liberar == true){
                    game.setTabuleiro(val1,val2,player[jogadorDaRodada].getInsert());
                }
                else {
                    cout << "O bloco está ocupado com o valor " << game.getCellTabuleiro(val1,val2) << "\n";
                }
            }
            finalFase = game.verificarFim(player[jogadorDaRodada].getInsert());
            if (finalFase == true && rodada !=9){
                game.displayTabuleiro();
                player[jogadorDaRodada].setVitorias(player[jogadorDaRodada].getVitorias()+1);
                cout << "O vencedor é " << player[jogadorDaRodada].getNomeJogador() << "\n";
                cout << "Placar de " << player[0].getVitorias() << " a " << player[1].getVitorias() << "\n";
                game.displayTabuleiro();
                cout << "Deseja continuar? Insira: \n 1 - sim \n 2 - não\n";
            }
            else if (rodada == 8){
                finalFase = true;
                cout << "Empate!\n";
                cout << "Placar de " << player[0].getVitorias() << " a " << player[1].getVitorias() << "\n";
                game.displayTabuleiro();
                cout << "Deseja continuar? Insira: \n 1 - sim \n 2 - não\n";
            }
            
        }
        cin >> jogadorDaRodada;
        while (jogadorDaRodada != 1 && jogadorDaRodada != 2){
            cout << "valor inválido, tente novamente!\n";
            cin >> jogadorDaRodada;
        }
        if (jogadorDaRodada == 1){
            finalJogo = false;
        }
        else {
            finalJogo = true;
        }
    }
    
    return 0;
}
