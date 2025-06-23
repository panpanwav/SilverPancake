#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

const int maxVertices = 100;
struct Grafo{
    int numVertices;
    int arestas[maxVertices][maxVertices];
};

void BFS(const Grafo &g, int inicio){
    bool visitado[maxVertices] = {false};
    queue<int> fila;

    visitado[inicio] = true;
    fila.push(inicio);
    while(fila.empty() == 0){
        int atual = fila.front();
        fila.pop();
        cout << atual+1 << " ";
        for (int i = 0; i < g.numVertices; i++){
            if(g.arestas[atual][i] != 0 && visitado[i] == 0) {
                visitado[i] = true;
                fila.push(i);
            }
        }
    }

}

int main (){
    Grafo g;
    srand(time(NULL));
    cout << "num vertices\n";
    cin >> g.numVertices;
    cout << "\n";    
    srand(time(NULL));
    for(int i = 0; i < g.numVertices; i++){
        for(int j = 0; j <= i; j++){
            g.arestas[i][j] = rand() % 2;
            g.arestas[j][i] = g.arestas[i][j];
        }
        g.arestas[i][i] = 0;
    }
    cout << "    ";
    for (int i = 0; i < g.numVertices; i++){
        cout << i+1 << " ";
    }
    cout << "\n";
    cout << "    ";
    for (int i = 0; i < g.numVertices; i++){
        cout << "- ";
    }
    cout << "\n";
    
    for(int i = 0; i < g.numVertices; i++){
        cout << i+1 << " - ";
        for(int j = 0; j < g.numVertices; j++){
            cout << g.arestas[i][j] << " ";
            if (j == g.numVertices-1){
                cout << "\n";
            }
        }
    }
    cout << "\n";
    BFS(g, g.numVertices-1);

    return 0;
}