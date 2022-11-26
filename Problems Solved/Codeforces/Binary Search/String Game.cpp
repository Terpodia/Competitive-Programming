// -Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
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
#define line cout << "\n............................................\n";

const int MAXN = 2e5;

int a[MAXN];

bool can(int k, string t, string& p) {
  rep(i, 0, k) t[a[i]] = '$';
  string s;
  rep(i, 0, sz(t)) if (t[i] != '$') s.pb(t[i]);
  int j = 0;
  for (char c : s) {
    if (j == sz(p)) break;
    if (c == p[j]) j++;
  }
  return j == sz(p);
}

int solve(string& t, string& p) {
  int l = 0, r = sz(t);
  while (r > l) {
    int mid = l + (r - l + 1) / 2;
    if (can(mid, t, p))
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string t, p;
  cin >> t >> p;
  rep(i, 0, sz(t)) {
    cin >> a[i];
    a[i]--;
  }
  cout << solve(t, p) << "\n";
  return 0;
}
