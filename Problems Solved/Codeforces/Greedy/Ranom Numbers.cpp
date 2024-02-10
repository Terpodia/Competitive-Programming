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
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// shuffle(.begin(),.end(),rng); uniform_int_distribution<int>(a,b)(rng) [a,b]
typedef long long ll;
typedef long double ld;

const int INF = 1e9;

int solve(string& s) {
  vector<int> last(5, -1);
  fore(i, 0, SZ(s)) last[s[i] - 'A'] = i;

  int ret = 0;
  fore(i, 0, SZ(s)) {
    bool flag = false;
    fore(j, s[i] - 'A' + 1, 5) {
      if (last[j] > i) flag = true;
    }
    int val = 1;
    fore(j, 0, s[i] - 'A') val *= 10;
    if (flag)
      ret -= val;
    else
      ret += val;
  }
  return ret;
}

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    pair<int, int> p[5];
    fore(i, 0, 5) p[i] = {-1, -1};
    fore(i, 0, SZ(s)) {
      int j = s[i] - 'A';
      if (p[j].fst == -1) p[j].fst = i;
      p[j].snd = i;
    }
    int ans = -INF;
    fore(i, 0, 5) if (p[i].fst != -1) {
      fore(j, 0, 5) {
        char c = s[p[i].fst];
        s[p[i].fst] = 'A' + j;
        ans = max(ans, solve(s));
        s[p[i].fst] = c;

        c = s[p[i].snd];
        s[p[i].snd] = 'A' + j;
        ans = max(ans, solve(s));
        s[p[i].snd] = c;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
