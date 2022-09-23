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

const int MAXM = 2e5;

int n, m, r[MAXM][3], dir[MAXM], vis[MAXM];
vector<int> g[MAXM], dag[MAXM];

map<pair<int,int>,int> mp;

void is_bipartite(int u, int d, bool& can){
  dir[u] = d;
  for(int v : g[u]){
    if(dir[u] == dir[v]) can=false;
    if(dir[v] == -1) is_bipartite(v, 1 - d, can);
  }
}
void construct_dag(int u){
  vis[u] = 1;
  for(int v : g[u]) if(!vis[v]){
    int type = mp[{min(u,v), max(u,v)}];
    if(type == 1){
      (dir[u] == 0) ? dag[u].pb(v) : dag[v].pb(u);
    }
    else{
      (dir[u] == 0) ? dag[v].pb(u) : dag[u].pb(v);
    }
  }
}
void is_dag(int u, bool& can){
  vis[u] = 1;
  for (int v : dag[u]){
    if(vis[v] == 1) can = false;
    if(!vis[v]) is_dag(v, can);
  }
  vis[u] = 2;
}

void toposort(int u, vector<int>& t){
  vis[u] = 1;
  for(int v : dag[u]) if(!vis[v]) 
    toposort(v, t);
  t.pb(u);
}

int main() {
  scan(n, m);
  bool can = true;
  
  rep(k, 0, m){
    int type, i, j;
    scan(type, i, j);
    r[k][0] = type, r[k][1] = i-1, r[k][2] = j-1;
    mp[{min(i-1,j-1), max(i-1,j-1)}] = type;
  }
  rep(i, 0, m){
    int u = r[i][1], v = r[i][2];
    g[u].pb(v);
    g[v].pb(u);
  }
  memset(dir, -1, sizeof(dir));
  rep(i, 0, n){
    if(dir[i] == -1){
      is_bipartite(i, 0, can);
    }
  }
  if(!can){
    puts("NO");
    return 0;
  }
  rep(i, 0, n) if(!vis[i]) construct_dag(i);
  memset(vis, 0, sizeof(vis));
  rep(i, 0, n) if(!vis[i]) is_dag(i, can);

  if(!can){
    puts("NO");
    return 0;
  }

  vector<int> t;
  memset(vis, 0, sizeof(vis));
  rep(i, 0, n) if(!vis[i]) toposort(i, t);
  reverse(all(t));

  int pos[n];
  rep(i, 0, n) pos[t[i]] = i;
  
  puts("YES");
  rep(i, 0, n){
    printf("%c %d\n", (dir[i]==0)?'L':'R', pos[i]);
  }

  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
