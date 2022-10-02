#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void _scan(int &x) { scanf("%d", &x); }
void _scan(long long &x) { scanf("%lld", &x); }
void _scan(double &x) { scanf("%lf", &x); }
void _scan(long double &x) { scanf("%Lf", &x); }
void _scan(char &x) { scanf(" %c", &x); }
void _scan(char *x) { scanf("%s", x); }
template <typename T>
void _scan(vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++) _scan(v[i]);
}
void scan() {}
template <typename T, typename... U>
void scan(T &head, U &... tail) {
  _scan(head);
  scan(tail...);
}
void set_IO() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(15);
}

void _dbg(istream_iterator<string> it) {}
template <typename T, typename... U>
void _dbg(istream_iterator<string> it, T &head, U &... tail) {
  cout << *it << "=" << head << " ";
  _dbg(++it, tail...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back
#define fst first
#define snd second
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define line cout << "\n-----------------------------\n";
#define dbg(args...)                         \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    _dbg(_it, args);                         \
  }

typedef __uint128_t u128;
typedef long long ll;

const ll MOD = 998244353;

ll comb[100][100];

int main(){
  rep(i,0,100) comb[i][0] = 1;
  rep(i,0,100) comb[i][i] = 1;
  rep(i,1,100) rep(j,i-1,-1){
    comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
  }
  int tt;
  scan(tt);
  while(tt--){
    int n;
    scan(n);
    ll alex=0;
    int curr = n-1, flag=0, m=n, k=n/2;
    
    rep(i,n,0){
      m--;
      if(k == 0) break;
      if(i == curr) curr -= (flag==0)?1:3, k--, flag=1-flag;
      else alex = (alex + comb[m][k-1]) % MOD;
    }
    printf("%lld %lld 1\n", alex, (comb[n][n/2]-alex-1+MOD)%MOD);
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada 
