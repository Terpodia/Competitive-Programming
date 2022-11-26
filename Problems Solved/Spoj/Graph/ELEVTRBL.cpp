#include <stdio.h>

#include <queue>
#include <vector>

using namespace std;

void BFS(long &f, long &s, long &g, long &u, long &d, long &answer,
         bool &impossible, vector<bool> &visited) {
  queue<long> Q;
  long counter = 0;

  Q.push(s);

  while (!Q.empty()) {
    long v = Q.front();
    Q.pop();

    if (v == g) {
      impossible = false;
      return;
    }

    if (!visited[v - 1]) {
      visited[v - 1] = true;

      if (v - d >= 1 && v + u <= f) {
        Q.push(v - d);
        Q.push(v + u);
      }

      else if (v - d >= 1) {
        Q.push(v - d);
      }

      else if (v + u <= f) {
        Q.push(v + u);
      }
    }

    if (counter == 0) {
      counter = Q.size();
      answer++;
    }

    counter--;
  }
}

int main() {
  long f, s, g, u, d, answer = 0;
  bool impossible = true;

  scanf("%li %li %li %li %li", &f, &s, &g, &u, &d);

  vector<bool> visited(f, false);

  BFS(f, s, g, u, d, answer, impossible, visited);

  if (impossible)
    printf("use the stairs\n");

  else
    printf("%li\n", answer);

  return 0;
}
