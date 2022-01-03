#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <bitset>
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
void _scan(long double &x) { aux=scanf("%Lf",&x); }
void _scan(char &x) { aux=scanf(" %c",&x); }
void _scan(char *x) { aux=scanf("%s",x); }
template<typename T>
void _scan(vector<T> &v) {
	for(int i=0; i<(int)v.size(); i++) _scan(v[i]);
}
void scan() {}
template<typename T, typename... U>
void scan(T& head, U&... tail) { _scan(head); scan(tail...); }
/* ================================================= */

#define sz(x) (int)x.size()
#define FOR(i,x,n) for (int i=(x); i<(int)(n); i++)

int main() {
  fastIO();
  int tc; cin >> tc;

  while (tc--) {
    int n, k; cin >> n >> k; 
    if (k > (n+1)/2) cout << "-1\n";
    else {
      char ans[n][n];
      FOR(i,0,n) FOR(j,0,n) ans[i][j] = '.'; 
      for (int i=0; i<n && k > 0; i+=2) {
        ans[i][i] = 'R';
        k--;
      }

      FOR(i,0,n) {
        FOR(j,0,n) cout << ans[i][j];
        cout << "\n";
      }
    }
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
