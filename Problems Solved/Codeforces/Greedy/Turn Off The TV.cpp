// Si puedes imaginarlo puedes programarlo
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fst first
#define snd second
#define pb push_back
#define make_pair mp
#define dbg(x) cerr << #x << "=" << x << " "
#define line cerr << "\n========================================\n"
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(x) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef pair<int, int> ii;

const int MAXN = 2e5 + 3;
const int MAX = 1e6;

int n;
ii a[MAXN];

pair<int, vector<int>> l[MAX];

int solve() {
  set<int> s;
  int cnt = 0;

  rep(i, 0, MAX) l[i].fst = 0;

  rep(i, 0, n) {
    l[a[i].fst].fst++;
    l[a[i].fst].snd.pb(i + 1);
    l[a[i].snd + 1].fst--;
    l[a[i].snd + 1].snd.pb(-(i + 1));
  }
  rep(i, 0, MAX) {
    for (int j : l[i].snd) {
      if (j > 0)
        s.insert(j);
      else if (s.find(-j) != s.end())
        return -j;
    }
    cnt += l[i].fst;
    if (cnt == 1) s.clear();
  }
  return -1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  vector<int> v;
  rep(i, 0, n) {
    cin >> a[i].fst >> a[i].snd;
    v.pb(a[i].fst);
    v.pb(a[i].snd);
    v.pb(a[i].snd + 1);
  }
  sort(all(v));
  v.resize(distance(v.begin(), unique(all(v))));
  rep(i, 0, n) {
    a[i].fst = (int)distance(v.begin(), lower_bound(all(v), a[i].fst));
    a[i].snd = (int)distance(v.begin(), lower_bound(all(v), a[i].snd));
  }
  cout << solve() << "\n";
  return 0;
}
