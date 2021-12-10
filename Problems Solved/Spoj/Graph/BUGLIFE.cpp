#include <stdio.h>
#include <vector>
 
using namespace std;
 
bool suspicious_bug = false;
 
void DFS(long nodo, vector<bool> &visited, vector<vector<long> > &adjacent_list,
         long previus_gender, vector<long> &genders) {
 
  if (genders[nodo - 1] == -1) {
 
    if (previus_gender == 1) {
 
      genders[nodo - 1] = 0;
    }
 
    else {
 
      genders[nodo - 1] = 1;
    }
  }
 
  else if (genders[nodo - 1] == previus_gender) {
 
    suspicious_bug = true;
  }
 
  if (visited[nodo - 1]) {
 
    return;
  }
 
  visited[nodo - 1] = true;
 
  for (int i = 0; i < adjacent_list[nodo - 1].size(); i++) {
 
    DFS(adjacent_list[nodo - 1][i], visited, adjacent_list, genders[nodo - 1],
        genders);
  }
}
 
int main() {
 
  long number_scenarios;
 
  scanf("%li", &number_scenarios);
 
  for (int i = 1; i <= number_scenarios; i++) {
 
    long number_bugs, number_interactions, x, y;
 
    scanf("%li %li", &number_bugs, &number_interactions);
 
    vector<vector<long> > adjacent_list(number_bugs);
 
    vector<bool> visited(number_bugs, false);
 
    vector<long> genders(number_bugs, -1);
 
    for (int j = 0; j < number_interactions; j++) {
 
      scanf("%li %li", &x, &y);
 
      adjacent_list[x - 1].push_back(y);
      adjacent_list[y - 1].push_back(x);
    }
 
    printf("Scenario #%i:\n", i);
 
    for (int j = 0; j < number_bugs; j++) {
 
      if (!visited[j]) {
 
        DFS(j + 1, visited, adjacent_list, 0, genders);
      }
 
      if (suspicious_bug) {
 
        printf("Suspicious bugs found!\n");
        break;
      }
    }
 
    if (!suspicious_bug) {
 
      printf("No suspicious bugs found!\n");
    }
 
    suspicious_bug = false;
  }
 
  return 0;
} 

