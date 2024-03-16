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

const int MAXN = 3e5+10;
const ll MOD = 998244353;

vector<int> g[MAXN];
ll a[MAXN], b[MAXN];

ll dfs(int u, int p=-1){
  a[u]=1;
  for(int v : g[u]) if(v != p) {
    dfs(v,u);
    a[u] *= a[v];
    a[u] %= MOD;
  }
  ++a[u];
  for(int v : g[u]) if(v != p) {
    b[u] += a[v] + b[v] - 1LL;
    b[u] %= MOD, b[u] += MOD, b[u] %= MOD;
  }
  return (a[u]+b[u]) % MOD;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int tt;
  cin>>tt;
  while(tt--){
    int n;
    cin>>n;
    fore(i,0,n-1){
      int u,v;
      cin>>u>>v;
      u--, v--;
      g[u].pb(v);
      g[v].pb(u);
    }
    cout << dfs(0) << "\n";
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    fore(i,0,n) g[i].clear();
  }
  return 0;
}

