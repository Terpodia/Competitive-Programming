#include <iostream>
#include <cstring>
using namespace std;
int aux;

const int MAXN = 2e5;

int n, p[MAXN], a[MAXN];

void solve() {
  int root=-1; 
  for (int i=0; i<n; i++) if (p[i] == i)
    root = i;

  if (a[0] != root) { puts("-1"); return; }
  
  int ans[n];
  int dist[n];
  int ls = 0;

  memset(dist, -1, sizeof(dist));
  dist[root] = 0;
  ans[root] = 0;

  for (int i=1; i<n; i++) {
    int v = a[i];
    if (dist[p[v]] == -1) { puts("-1"); return; }
    ans[v] = ls + 1 - dist[p[v]];
    dist[v] = dist[p[v]] + ans[v];
    ls = dist[v];
  }

  for (int i=0; i<n; i++) 
    printf("%d%c", ans[i], " \n"[i==n-1]);
}

int main() {
  int t; aux=scanf("%d",&t);
  while (t--) {
    aux=scanf("%d",&n); 
    for (int i=0; i<n; i++) {
      aux=scanf("%d",p+i); 
      p[i]--;
    }
    for (int i=0; i<n; i++) {
      scanf("%d",a+i);
      a[i]--;
    }

    solve();
  }

  return 0;
}

