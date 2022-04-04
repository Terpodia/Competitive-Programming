#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int aux;

const int MAXN = 300;

#define LSOne(x) (x) & (-x)

bool cmp(pair<int,int> a, pair<int,int> b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second < b.second;
}

int ft[MAXN+7][MAXN+7];

int psum(int index, int j) {
  int ret=0;
  for (int i=j; i>0; i-=LSOne(i)) {
    ret += ft[index][i];
  }
  return ret;
}

void update(int index, int j, int v) {
  for (int i=j; i<=MAXN; i+=LSOne(i)) 
    ft[index][i] += v;
}

int main() {
  int t; aux=scanf("%d",&t);
  while (t--) {
    int n, m; aux=scanf("%d%d",&n,&m);
    pair<int,int> a[n*m];
    for (int i=0; i<n*m; i++) {
      aux=scanf("%d", &a[i].first);
      a[i].second = i;
    }
    
    sort(a, a+(n*m), cmp);
    int p[n*m];

    int r = 0, c = 0, i = 0;
    
    while (i < n*m) {
      int j = i;
      while (i+1 < n*m && a[i+1].first == a[j].first && c + 1 < m) i++, c++;

      int z = i, w = j;
      while (z >= j) {
        p[a[z].second] = w;
        z--, w++;
      }
       
      i++, c++;
      if (c == m) r++, c=0;
    }

    memset(ft, 0, sizeof(ft));

    int ans=0;

    for (i=0; i<n*m; i++) {
      ans += psum((p[i] / m) + 1, (p[i] % m) + 1); 
      update((p[i] / m) + 1, (p[i] % m) + 1, 1);
    }

    printf("%d\n", ans);
  }


  return 0;
}

