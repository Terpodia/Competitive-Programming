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

string convert(string& p, int k) {
  string ret;

  rep(i, k - 1, sz(p)) ret.pb(p[i]);

  if ((sz(p) - k + 1) % 2 == 0) {
    rep(i, 0, k - 1) ret.pb(p[i]);
  } else {
    rep(i, k - 2, -1) ret.pb(p[i]);
  }

  return ret;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    string s;
    cin >> n >> s;
    vector<pair<string, int>> ans;

    rep(k, 1, n + 1) { ans.pb(make_pair(convert(s, k), k)); }
    sort(all(ans));

    cout << ans[0].fst << "\n" << ans[0].snd << "\n";
  }
  return 0;
}
