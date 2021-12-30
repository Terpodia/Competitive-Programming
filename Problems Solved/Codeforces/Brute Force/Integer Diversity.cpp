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

int main() {
  int tc; scan(tc);

  while (tc--) {
    int n; scan(n);
    vector<int> a(n);
    scan(a);
    sort(a.begin(), a.end());

    for (int i=0; i<n-1; i++) {
      if (a[i] == a[i+1]) a[i] *= -1;
    }

    set<int> s;
    for (int i=0; i<n; i++) s.insert(a[i]);
    printf("%d\n", sz(s));
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
