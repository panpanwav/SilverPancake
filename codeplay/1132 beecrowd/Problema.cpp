#include <iostream>
using namespace std;

class Problema {
    private:
        int val1;
        int val2;
        int result;
    
    public:
        void setVal1(int s){
            val1 = s;
        };
        void setVal2(int s){
            val2 = s;
        };
        void setResult(int s){
            result = s;
        };
        int getVal1(){
            return val1;
        };
        int getVal2(){
            return val2;
        };
        int getResult(){
            return result;
        };
        void leitura(){
            int *placeholder;
            placeholder = new int;
            if (!placeholder) {
            cout << "allocation of memory failed";
            exit(0);
        }
            cin >> *placeholder;
            setVal1(*placeholder);
            cin >> *placeholder;
            setVal2(*placeholder);
            if (getVal2() < getVal1()){
                *placeholder = 0;
                int placeholder = getVal2();
                setVal2(getVal1());
                setVal1(placeholder);
        }
            
            delete placeholder;
        };
        int calculo(){
            int *resultado;
            resultado = new int;
            *resultado = 0;
            if (!resultado) {
                cout << "allocation of memory failed";
                exit(0);
            }
            for (int i = getVal1() ; i <= getVal2(); i++){
                if(i%13 != 0){
                   *resultado += i;
                }
            }
            setResult(*resultado);
            delete resultado;
            
            return getResult();
        };
};
