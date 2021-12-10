#include <stdio.h>
#include <vector>
 
using namespace std;
 
void DFS(long nodo, vector<bool> &visited,
         vector<vector<long> > &lista_adyacencia) {
 
  if (visited[nodo]) {
    return;
  }
 
  visited[nodo] = true;
 
  for (int i = 0; i < lista_adyacencia[nodo].size(); i++) {
 
    DFS(lista_adyacencia[nodo][i], visited, lista_adyacencia);
  }
}
 
int main() {
 
  long numero_vertices, numero_aristas, x, y, caminos = -1;
 
  scanf("%li %li", &numero_vertices, &numero_aristas);
 
  vector<vector<long> > lista_adyacencia(numero_vertices);
  vector<bool> visited(numero_vertices, false);
 
  for (int i = 0; i < numero_aristas; i++) {
 
    scanf("%li %li", &x, &y);
    lista_adyacencia[x].push_back(y);
    lista_adyacencia[y].push_back(x);
  }
 
  for (long i = 0; i < numero_vertices; i++) {
 
    if (!visited[i]) {
      caminos++;
      DFS(i, visited, lista_adyacencia);
    }
  }
 
  if (numero_vertices == 0) {
    printf("0\n");
    return 0;
  }
 
  printf("%li\n", caminos);
 
  return 0;
} 

