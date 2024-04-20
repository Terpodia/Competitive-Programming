#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define fore(i,x,n) for(auto i=(x); i<(n); i++)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " " 
#define raya cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;
typedef long double ld;

typedef vector<ll> vll;

const ll MOD = 1e9+7;

ll N;
int M;

vector<vll> mult(vector<vll> a, vector<vll> b){
  vector<vll> ret(SZ(a), vll(SZ(b[0]), 0));

  int r = SZ(a), c = SZ(b[0]);

  fore(i,0,r) fore(j,0,c) {
    fore(k, 0, SZ(b)) 
      ret[i][j] += (a[i][k] * b[k][j]) % MOD, ret[i][j] %= MOD;
  }
  return ret;
}
vector<vll> binpow(vector<vll> a, ll b){
  int r = SZ(a);
  vector<vll> ret(r, vll(r, 0));
  fore(i,0,r) ret[i][i] = 1;
  while(b){
    if(b & 1LL) ret = mult(ret, a);
    a = mult(a, a);
    b >>= 1LL;
  }
  return ret;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin >> N >> M;

  vector<vll> a(M, vll(M,0)), b(M, vll(1, 1));

  a[M-1][0] = a[M-1][M-1] = 1;
  fore(i,0,M-1) a[i][i+1] = 1;

  a = binpow(a, N);
  b = mult(a, b);
  cout << b[0][0] << "\n";

  return 0;
}

