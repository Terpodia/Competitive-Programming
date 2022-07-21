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

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  int n;
  cin >> n;
  string t[n];
  rep(i, 0, n) cin >> t[i];
  bool can = false;

  rep(i, 0, n) rep(j, 0, n) {
    string k = t[i];
    for (char c : t[j]) k.pb(c);
    rep(w, 0, sz(k) - 1) {
      if (s[0] == k[w] && s[1] == k[w + 1]) can = true;
    }
  }
  if (!can)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}

