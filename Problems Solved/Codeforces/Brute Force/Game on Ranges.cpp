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

#define sz(x) (int)x.size()

const int MAXN = 1000;

int n;
pair<int,int> p[MAXN];

void solve() {
  for (int i=0; i<n; i++) {
    if (p[i].first == p[i].second) { 
      printf("%d %d %d\n", p[i].first, p[i].second, p[i].first);
      continue;
    }
    pair<int,int> a = {0,-1}, b = {0,-1};
    for (int j=0; j<n; j++) if (j != i) {
      if (p[j].first == p[i].first && p[j].second < p[i].second) {
        if (a.second - a.first + 1 < p[j].second - p[j].first + 1) {
          a = p[j];
        }
      }
      else if (p[j].second == p[i].second && p[j].first > p[i].first) {
        if (b.second - b.first + 1 < p[j].second - p[j].first + 1) {
          b = p[j];
        }
      }
    }
    if (a != make_pair(0,-1)) printf("%d %d %d\n", p[i].first, p[i].second, a.second+1);
    else if (b != make_pair(0,-1)) printf("%d %d %d\n", p[i].first, p[i].second, b.first-1);
  }
}

int main() {
  int tc; scan(tc);

  while (tc--) {
    scan(n);
    for (int i=0; i<n; i++) scan(p[i].first, p[i].second);
    solve();
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
