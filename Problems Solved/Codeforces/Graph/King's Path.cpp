//-Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fst first
#define snd second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n........................................\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int R_CHANGE[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int C_CHANGE[] = {0, 0, 1, -1, 1, -1, 1, -1};

int n, r0, c0, r1, c1;

map<int, set<int>> mp;
map<pair<int, int>, int> dist;

void bfs() {
  queue<tuple<int, int, int>> Q;
  Q.push(make_tuple(r0, c0, 0));
  dist[{r0, c0}] = 0;

  while (!Q.empty()) {
    auto& [x, y, w] = Q.front();
    Q.pop();
    rep(k, 0, 8) {
      int r = x + R_CHANGE[k], c = y + C_CHANGE[k];
      if (mp.find(r) == mp.end()) continue;
      if (mp[r].find(c) == mp[r].end()) continue;
      if (dist.find({r, c}) != dist.end()) continue;
      dist[{r, c}] = w + 1;
      Q.push(make_tuple(r, c, w + 1));
    }
  }
}

int main() {
  scanf("%d%d%d%d", &r0, &c0, &r1, &c1);
  scanf("%d", &n);

  rep(i, 0, n) {
    int r, a, b;
    scanf("%d%d%d", &r, &a, &b);
    rep(x, a, b + 1) mp[r].insert(x);
  }

  bfs();

  if (dist.find({r1, c1}) != dist.end())
    printf("%d\n", dist[{r1, c1}]);
  else
    puts("-1");

  return 0;
}

