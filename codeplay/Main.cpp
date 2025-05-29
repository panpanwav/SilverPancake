class Main {
    private:
        int val1;
        int val2;
        int result;
}

int main(){
    Main meuProblema;
    meuProblema.result = 0;
    cin >> meuProblema.val1 >> meuProblema.val2;
    for (int i = meuProblema.val1; i < meuProblema.val2; i++){
        if(i/13 == 0){
            meuProblema.result += i;
        }
    }
}
