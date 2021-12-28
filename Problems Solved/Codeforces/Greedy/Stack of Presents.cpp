#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
/* ================================================= */
void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int aux;
void _scan(int &x) { aux=scanf("%d",&x); }
void _scan(long long &x) { aux=scanf("%lld",&x); }
void _scan(double &x) { aux=scanf("%lf",&x); }
void _scan(char &x) { aux=scanf(" %c",&x); }
void _scan( char *x) { aux=scanf("%s",x); }
template<typename T>
void _scan(vector<T> &v){
	for(int i=0; i<(int)v.size(); i++) _scan(v[i]);
}
void scan() {}
template<typename T, typename... U>
void scan( T& head, U&... tail ) { _scan(head); scan(tail...);}
/* ================================================= */

typedef long long ll;

#define sz(x) (int)x.size()

int n, m;
vector<int> a, b;

void solve() {
  int p[n+1];
  for (int i=0; i<n; i++) p[a[i]] = i+1;

  ll ans = 2*(p[b[0]] - 1)+1;
  int pos = p[b[0]], cnt = 1;
  
  for (int i=1; i<m; i++) {
    if (p[b[i]] < pos) ans++;
    else ans += 2*(p[b[i]] - 1 - cnt) + 1, pos = p[b[i]];

    cnt++;
  } 

  printf("%lld\n", ans);
}

int main() {
  int tc; scan(tc);
  while (tc--) {
    scan(n, m); 
    a = vector<int>(n);
    b = vector<int>(m);
    scan(a, b);

    solve();
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
