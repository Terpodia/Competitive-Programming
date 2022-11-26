#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int aux;

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    vector<int> b(7);
    for (int i = 0; i < 7; i++) aux = scanf("%d", &b[i]);

    bool finish = false;

    for (int i = 0; i < 7; i++) {
      if (finish) break;
      for (int j = 0; j < 7; j++) {
        if (finish) break;
        for (int z = 0; z < 7; z++) {
          if (finish) break;
          vector<int> a;
          a.push_back(b[i]);
          a.push_back(b[j]);
          a.push_back(b[z]);
          a.push_back(b[i] + b[j]);
          a.push_back(b[i] + b[z]);
          a.push_back(b[i] + b[j] + b[z]);
          a.push_back(b[j] + b[z]);
          sort(a.begin(), a.end());
          if (a == b) {
            finish = true;
            printf("%d %d %d\n", b[i], b[j], b[z]);
          }
        }
      }
    }
  }

  return 0;
}
