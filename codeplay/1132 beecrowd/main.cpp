#include "Problema.cpp"
#include <iostream>
using namespace std;

int main(){
    Problema meuProblema;
    
    meuProblema.leitura();
    cout << meuProblema.calculo() << "\n";
    
    return 1;
}
