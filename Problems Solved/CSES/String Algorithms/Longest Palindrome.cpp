// Si puedes imaginarlo puedes programarlo
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// ordered_set<int> x; x.find_by_order(y); x.order_of_key(y)

#define fst first
#define snd second
#define pb push_back
#define mp make_pair
#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define line \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;

vector<int> marray(string s) {
  s = "^" + s + "$";
  vector<int> m(SZ(s), 0);
  int l = 1, r = 1;
  fore(i, 1, SZ(s) - 1) {
    if (i < r) m[i] = min(r - i, m[l + r - i]);
    while (s[i - m[i]] == s[i + m[i]]) m[i]++;
    if (i + m[i] > r) l = i - m[i], r = i + m[i];
  }
  return vector<int>(m.begin() + 1, m.end() - 1);
}
void manacher(string& s, vector<int>& d1, vector<int>& d2) {
  string t = "";
  for (auto c : s) t += "#", t.pb(c);
  vector<int> m = marray(t + "#");
  fore(i, 0, SZ(s)) d1[i] = m[i * 2 + 1] / 2, d2[i] = m[i * 2] / 2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  vector<int> d1(SZ(s)), d2(SZ(s));
  manacher(s, d1, d2);

  int hi = 1;
  fore(i, 0, SZ(s)) hi = max(hi, max(d1[i] * 2 - 1, d2[i] * 2));

  fore(i, 0, SZ(s)) {
    if (hi == d1[i] * 2 - 1) {
      fore(j, i - d1[i] + 1, i + d1[i]) cout << s[j];
      cout << "\n";
      break;
    }
    if (hi == d2[i] * 2) {
      fore(j, i - d2[i], i + d2[i]) cout << s[j];
      cout << "\n";
      break;
    }
  }
  return 0;
}
