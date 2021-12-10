#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
 
using namespace std;
 
void BFS(int &node, vector<vector<int> > &adjacent_list, vector<bool> &visited,
         int &path, int nodes_values[]) {
 
  queue<int> Q;
  int counter = 0;
 
  Q.push(node);
 
  while (!Q.empty()) {
 
    int v = Q.front();
    Q.pop();
 
    if (!visited[v]) {
 
      visited[v] = true;
 
      for (int i = 0; i < adjacent_list[v].size(); i++) {
 
        if (nodes_values[adjacent_list[v][i]] - nodes_values[v] == 1) {
          
          Q.push(adjacent_list[v][i]);
        }
      }
    }
 
    if (counter == 0) {
      path++;
 
      if (!Q.empty())
        counter = Q.size();
    }
 
    counter--;
  }
}
 
int main() {
 
  int H, W, number_case = 1;
 
  do {
 
    // Input
    cin >> H >> W;
 
    if (H == 0 && W == 0) {
 
      break;
    }
 
    char grid[H][W];
 
    // Aqui llevamos el conteo del nodo actual para rellenar
    // La lista de adyacencia
    int actual_node = 0;
 
    // Aqui guardamos los nodos que contengan 'A'
    vector<int> init_positions;
 
    // Lista de adyacencia
    vector<vector<int> > adjacent_list(H * W);
 
    // Aqui guardamos los valores de cada nodo
    int nodes_values[H * W];
 
    int aux = 0;
 
    int path = 0;
    int largest_path = 0;
 
    for (int i = 0; i < H; i++) {
 
      for (int j = 0; j < W; j++) {
 
        cin >> grid[i][j];
 
        nodes_values[aux] = grid[i][j] - '0';
 
        // Si la posicion actual es 'A', guardamos el valor
        // En init_positions
 
        if (grid[i][j] == 'A') {
 
          init_positions.push_back(aux);
        }
          
          aux++;
      }
    }
 
    // AÃ±adiendo valores en la lista de adyacencia
 
    for (int i = 0; i < H; i++) {
 
      for (int j = 0; j < W; j++) {
 
        if (j != W - 1) {
 
          // AÃ±adir el nodo a la derecha
          adjacent_list[actual_node].push_back(actual_node + 1);
        }
 
        if (j != 0) {
 
          // AÃ±adir el nodo a la izquierda
          adjacent_list[actual_node].push_back(actual_node - 1);
        }
 
        if (i != H - 1) {
 
          // AÃ±adir el nodo de abajo
          adjacent_list[actual_node].push_back(actual_node + W);
        }
 
        if (i != 0) {
 
          // AÃ±adir el nodo de arriba
          adjacent_list[actual_node].push_back(actual_node - W);
        }
 
        if (j != W - 1 && i != 0) {
 
          // AÃ±adir el nodo diagonal derecho de arriba
          adjacent_list[actual_node].push_back(actual_node - W + 1);
        }
 
        if (j != W - 1 && i != H - 1) {
 
          // AÃ±adir el nodo diagonal derecho de abajo
          adjacent_list[actual_node].push_back(actual_node + W + 1);
        }
 
        if (j != 0 && i != 0) {
 
          // Anadir el nodo diagonal izquierdo de arriba
          adjacent_list[actual_node].push_back(actual_node - W - 1);
        }
 
        if (j != 0 && i != H - 1) {
 
          // Anadir el nodo diagonal izquierdo de abajo
          adjacent_list[actual_node].push_back(actual_node + W - 1);
        }
 
        actual_node++;
      }
    }
 
    for (int i = 0; i < init_positions.size(); i++) {
 
      vector<bool> visited(H * W, false);
 
      BFS(init_positions[i], adjacent_list, visited, path, nodes_values);
 
      largest_path = max(path, largest_path);
      path = 0;
    }
 
    cout << "Case " << number_case << ": " << largest_path << "\n";
 
    number_case++;
 
  } while (H != 0 || W != 0);
 
  return 0;
} 

