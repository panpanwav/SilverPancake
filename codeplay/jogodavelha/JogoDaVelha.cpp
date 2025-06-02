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
        void displayTabuleiro(){
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
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
            else{
                return false;
            }
        }
        bool verificarFim(char read){
            bool holder = false;
            for (int i = 0; i < 2; i++){
                if (read == tabuleiro[i][1] == tabuleiro[i][2] == tabuleiro[i][3]){
                    holder = true;
                }
                    
                if (read == tabuleiro[1][i] == tabuleiro[2][i] == tabuleiro[3][i]){
                    holder = true;
                }
            }
            if (read == tabuleiro[1][1] == tabuleiro[2][2] == tabuleiro[3][3]){
                holder = true;
            }
            if (read == tabuleiro[3][1] == tabuleiro[2][2] == tabuleiro[1][3]){
                holder = true;
            }
            return holder;
        }
};
