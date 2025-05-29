#include "Problema.cpp"
#include <iostream>
using namespace std;

int main(){
    double leitura;
    Problema meuProblema;
    meuProblema.setResult(0);
    cin>>leitura;
    meuProblema.setVal1(leitura);
    cin>>leitura;
    meuProblema.setVal2(leitura);
    if (meuProblema.getVal2() < meuProblema.getVal1()){
        int troca = meuProblema.getVal2();
        meuProblema.setVal2(meuProblema.getVal1());
        meuProblema.setVal1(troca);
    }
    int total = 0;
    for (int i = meuProblema.getVal1() ; i <= meuProblema.getVal2(); i++){
        if(i%13 != 0){
           total += i;
        }
    }
    meuProblema.setResult(total);
    cout << meuProblema.getResult() << "\n";
}
