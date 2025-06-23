#include <iostream>
#include <cstdlib>
#include <limits>
#include <queue>
using namespace std;

const int maximoPositivo = numeric_limits<int>::max();
const int maxVertices = 100;
struct Grafo{
    int numVertices;
    int arestas[maxVertices][maxVertices];
    int pesos[maxVertices][maxVertices];
};
void dijkstra(Grafo &g, int inicio){
    inicio--;
    bool visitados[g.numVertices];
    int dist[g.numVertices];
    int predecessores[g.numVertices];
    queue<int> fila;

    //inicia os vertices com dist infinita menos o incial, que é declarado como visitado
    for(int i = 0; i < g.numVertices; i++){
        if (i != inicio){
            dist[i] = maximoPositivo;
        }
    }
    visitados[inicio] = 1;
    dist[inicio] = 0;
    predecessores[inicio] = inicio;
    fila.push(inicio);
    while (!fila.empty()){
        int atual = fila.front();
        fila.pop();
        for (int i = 0; i < g.numVertices; i++){
            //se houver aresta e não for um laço
            if (g.arestas[atual][i] == 1 && i != atual){
                //se não foi visitado, marca como tal
                if(visitados[i] == 0){
                    visitados[i] = 1;
                    fila.push(i);
                }
                // se a distância do próximo vértice for maior que distância do vértice atual + peso da aresta
                if(dist[i] > dist[atual] + g.pesos[atual][i]){
                    //substitui peso e o predecessor é o vértice atual
                    dist[i] = dist[atual] + g.pesos[atual][i];
                    predecessores[i] = atual;
                }
            }
        }
    }
    //exibe o resultado
    for (int i = 0; i < g.numVertices; i++){
        cout << i+1 << " - " << dist[i] << " - " << predecessores[i] + 1 << "\n";
    }
}
/* iniciar fila com vértices
vetor de distância dos vértices
vetor de predecessores
vetor de visitados
enquanto !fila.empty() {
	se houver adjascência{
		se distância atual vértice > distância do vértice atual + peso da aresta
		distância atual = distância do vértice atual + peso da aresta
	}
} */

int main (){
    cout << maximoPositivo << "\n";  
    Grafo g;
    cout << "num vertices\n";
    cin >> g.numVertices;
    srand(time(NULL));
    for(int i = 0; i < g.numVertices; i++){
        for(int j = 0; j <= i; j++){
            //cout << "vertex " << i+1 << " com vertex " << j+1 << "\n";
            //a linha abaixo permite escolher o valor do vértice
            //cin >> g.arestas;
            //a linha abaixo gera valores randomicos
            g.arestas[i][j] = rand()%2;
            //se tem arestas, gera valor entre 10 e 99 (pode ser alterado, mas dificultará a leitura da matriz no display)
            if (g.arestas[i][j] == 1){
                g.pesos[i][j] = rand() % 89+10;
            }
            else{
                //se não tem aresta, peso da "aresta" é infinito
                g.pesos[i][j] = maximoPositivo;
            }
            //faz com que o vertice não tenha direções
            g.arestas[j][i] = g.arestas[i][j];
            g.pesos[j][i] = g.pesos[i][j];
        }
        //impede laços(pode ser removido)
        g.arestas[i][i] = 0;
        g.pesos[i][i] = maximoPositivo;
    }
    //diplay arestas
    for(int i = 0; i < g.numVertices; i++){
        for(int j = 0; j < g.numVertices; j++){
            cout << g.arestas[i][j] << " ";
            if (j == g.numVertices-1){
                cout << "\n";
            }
        }
    }
    cout <<"\n";
    //display pesos
    for(int i = 0; i < g.numVertices; i++){
        cout << "^ ";
        for(int j = 0; j < g.numVertices; j++){
            if (g.pesos[i][j] == maximoPositivo){
                if (j == i) {
                    cout << "self ";
                }
                else {
                    cout << "NULL ";
                }
            }
            else {
                cout << g.pesos[i][j] << "   ";
            }
            if (j == g.numVertices-1){

                cout << " v\n";
            }
        }
    }
    cout << "\n";
    //inicia dikstra passando numVertices como valor inicial e g como o grafo a ser lido
    dijkstra(g, g.numVertices);
}