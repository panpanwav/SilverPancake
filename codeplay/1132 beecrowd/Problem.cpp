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
};
