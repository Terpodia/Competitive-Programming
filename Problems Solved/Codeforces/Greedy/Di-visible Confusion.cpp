#include <iostream>
#include <queue>
#include <set>
using namespace std;

int aux;

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    int n;
    aux = scanf("%d", &n);
    int a[n], d[n];
    for (int i = 0; i < n; i++) aux = scanf("%d", a + i);
    for (int i = 0; i < n; i++) d[i] = i + 2;

    int cnt = n;

    priority_queue<int> pq;
    set<int> s;

    for (int i = 0; i < n; i++) s.insert(i);

    for (int i = 0; i < n; i++) {
      if (a[i] % d[i] != 0) {
        pq.push(i);
        s.erase(i);
        cnt--;
      }
    }

    while (!pq.empty() && !s.empty()) {
      int j = pq.top();
      pq.pop();
      queue<int> q;
      for (auto it = s.rbegin(); it != s.rend(); it++) {
        if (*it < j) break;
        d[*it]--;
        if (a[*it] % d[*it] != 0) {
          pq.push(*it);
          q.push(*it);
        }
      }

      while (!q.empty()) {
        s.erase(q.front());
        cnt--;
        q.pop();
      }
    }

    (cnt == 0) ? puts("YES") : puts("NO");
  }

  return 0;
}
