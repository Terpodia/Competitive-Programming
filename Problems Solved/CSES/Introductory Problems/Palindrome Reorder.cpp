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
#define erof(i, x, n) for (auto i = (x); i > (n); i--)
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << "=" << x << " "
#define line \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int cnt[26];
  memset(cnt, 0, sizeof(cnt));
  for (char c : s) cnt[c - 'A']++;

  string ans = s;

  if (SZ(s) % 2 == 1) {
    int j = 0;
    fore(i, 0, 26) if (cnt[i] > 0) j = i;
    fore(i, 0, 26) if (cnt[i] % 2 == 1) j = i;
    ans[SZ(s) / 2] = 'A' + j;
    cnt[j]--;
  }
  bool can = true;
  fore(i, 0, 26) can &= cnt[i] % 2 == 0;
  if (!can) {
    cout << "NO SOLUTION\n";
    return 0;
  }
  int i = 0, j = SZ(s) - 1, cur = 0;

  while (i < j) {
    while (cnt[cur] == 0) cur++;
    ans[i] = ans[j] = 'A' + cur;
    cnt[cur] -= 2;
    i++, j--;
  }
  cout << ans << "\n";
  return 0;
}
