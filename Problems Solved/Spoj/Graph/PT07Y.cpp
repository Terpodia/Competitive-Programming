#include <stdio.h>
#include <vector>
 
using namespace std;
 
void DFS(int nodo, vector<bool> &visitados,
         vector<vector<int> > &lista_adyacencia) {
 
  if (visitados[nodo - 1]) {
 
    return;
  }
 
  visitados[nodo - 1] = true;
 
  for (int i = 0; i < lista_adyacencia[nodo - 1].size(); i++) {
 
    DFS(lista_adyacencia[nodo - 1][i], visitados, lista_adyacencia);
  }
}
 
int main() {
 
  int num_vertices, num_aristas, x, y;
 
  scanf("%i %i", &num_vertices, &num_aristas);
 
  vector<vector<int> > lista_adyacencia(num_vertices);
 
  vector<bool> visitados(num_vertices, false);
 
  for (int i = 0; i < num_aristas; i++) {
 
    scanf("%i %i", &x, &y);
    lista_adyacencia[x - 1].push_back(y);
    lista_adyacencia[y - 1].push_back(x);
  }
 
  if (num_vertices == 0) {
 
    printf("NO\n");
    return 0;
  }
 
  if(num_aristas >= num_vertices){
      printf("NO\n");
      return 0;
  }  
 
  DFS(1, visitados, lista_adyacencia);
 
  for (int i = 0; i < num_vertices; i++) {
 
    if (!visitados[i]) {
      printf("NO\n");
      return 0;
    }
  }
 
  printf("YES\n");
 
  return 0;
} 

