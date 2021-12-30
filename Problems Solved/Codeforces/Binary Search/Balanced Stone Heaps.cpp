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

const int INF = 1e9;

int n;
vector<int> h;

bool can(int k) {
  vector<int> h2 = h;

  for (int i=n-1; i>=2; i--) {
    int d = max((h2[i] - k) / 3, 0);
    d = min(d, h[i]/3);

    h2[i] -= 3*d;
    h2[i-1] += d;
    h2[i-2] += 2*d;
  }

  for (int i=0; i<n; i++) if (h2[i] < k) return false;

  return true;
}

int bs() {
  int l=0, r = h[n-1]; 
  while (r>l) {
    int mid = l + (r-l+1)/2;
    if (can(mid)) l = mid;
    else r = mid-1;
  }

  return l;
}

int main() {
  int tc; scan(tc);
  while (tc--) {
    scan(n); 
    h = vector<int>(n);
    scan(h);

    printf("%d\n", bs());
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
