#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class JogoDaVelha{
    private:
        char tabuleiro[3][3];
    public:
        void setTabuleiro(int arr1, int arr2, char read){
            tabuleiro[arr1][arr2] = read;
        }
        char getCellTabuleiro(int arr1, int arr2){
            return tabuleiro[arr1][arr2];
        }
        void zerarTabuleiro(){
            for(int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    tabuleiro[i][j] = '+';
                }        
            }
        }
        void displayTabuleiro(){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    cout << tabuleiro[i][j];
                    if (j == 2){
                        cout << "\n";
                    }
                }
            }
        }
        bool verificarVazio(int arr1, int arr2){
            if (tabuleiro[arr1][arr2] == '+'){
                return true;
            }
            else {
                return false;
            }
        }
        bool verificarFim(char read){
            bool holder = false;
            for (int i = 0; i < 3; i++){
                if (read == tabuleiro[i][0] && read == tabuleiro[i][1] && read == tabuleiro[i][2]){
                    holder = true;
                }
                if (read == tabuleiro[0][i] && read == tabuleiro[1][i] && read == tabuleiro[2][i]){
                    holder = true;
                }
            }
            if (read == tabuleiro[0][0] && read == tabuleiro[1][1] && read == tabuleiro[2][2]){
                holder = true;
            }
            if (read == tabuleiro[2][0] && read == tabuleiro[1][1] && read == tabuleiro[0][2]){
                holder = true;
            }
            return holder;
        }
};
