#include <iostream>
#include <cstdlib>
using namespace std;

const int maxVertices = 100;
struct Grafo{
    int numVertices;
    int arestas[maxVertices][maxVertices];
};

int main (){
    Grafo g;
    cout << "num vertices\n";
    cin >> g.numVertices;
    for(int i = 0; i < g.numVertices; i++){
        for(int j = 0; j <= i; j++){
            cout << "vertex " << i+1 << " com vertex " << j+1 << "\n";
            //a linha abaixo permite escolher o valor do vértice
            //cin >> g.arestas;
            //a linha abaixo gera valores randômicos
            g.arestas[i][j] = rand() % 2;

            g.arestas[j][i] = g.arestas[i][j];
        }
        g.arestas[i][i] = 0;
    }
    for(int i = 0; i < g.numVertices; i++){
        for(int j = 0; j < g.numVertices; j++){
            cout << g.arestas[i][j] << " ";
            if (j == g.numVertices-1){
                cout << "\n";
            }
        }
    }
}