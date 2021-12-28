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
typedef long double ld;

#define sz(x) (int)x.size()

const ll INF = 1e18;

int n; ll k;
vector<ll> a;
vector<ll> pref;

bool check(ll x, ll y) {
  return (ld(x) * ld(y) <= (ld)-INF);
}

ll bs(int x) {
  ll l = (ll)-1e15 - 7, r = a[0];
  while (r > l) {
    ll mid = l + (r - l + 1) / 2;

    if (check(mid, n-x+1)) l = mid;
    else if ((pref[x-1] - pref[1] + mid + mid * (n - x + 1)) <= k) l = mid;
    else r = mid-1;
  }

  return l;
}

ll solve() {
  ll ret=INF;

  for (int i=n+1; i>1; i--) {
    ret = min(ret, a[0] - bs(i) + n - i + 1);
  }

  return ret;
}

int main() {
  int tc; scan(tc);
  while (tc--) {
    scan(n, k); 
    a = vector<ll>(n);
    scan(a);
    
    sort(a.begin(), a.end());

    pref = vector<ll>(n+1, 0); 
    for (int i=1; i<=n; i++) pref[i] += pref[i-1] + a[i-1];

    printf("%lld\n", solve());
  }

  return 0;
}

// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
