#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class Jogador{
    private:
        string nomeJogador;
        char insert;
        int vitorias = 0;
    
    public:
        string getNomeJogador(){
            return nomeJogador;
        }
        char getInsert(){
            return insert;
        }
        int getVitorias(){
            return vitorias;
        }
        void setNomeJogador(string read){
            nomeJogador = read;
        }
        void setInsert(char read){
            nomeJogador = read;
        }
        void setVitorias(int read){
            vitorias = read;
        }
};
