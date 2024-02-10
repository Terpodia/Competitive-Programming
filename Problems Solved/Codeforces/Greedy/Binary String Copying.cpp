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

const int MAXN = 2e5 + 10;

int pref[MAXN];

int last0(int lx, int rx) {
  int l = lx, r = rx;
  int s = pref[r + 1] - pref[l];
  while (r > l) {
    int mid = l + (r - l) / 2;
    if (pref[mid + 1] - pref[lx] == s)
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}
int fst1(int lx, int rx) {
  int l = lx, r = rx;
  while (r > l) {
    int mid = l + (r - l) / 2;
    if (mid - lx + 1 - pref[mid + 1] + pref[lx] > 0)
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    fore(i, 0, SZ(s)) pref[i + 1] = pref[i] + (s[i] == '0');

    int l[m], r[m];
    fore(i, 0, m) {
      cin >> l[i] >> r[i];
      l[i]--, r[i]--;
    }

    bool flag = false;

    set<pair<int, int>> p;

    fore(i, 0, m) {
      if (pref[r[i] + 1] - pref[l[i]] == r[i] - l[i] + 1) {
        flag = true;
        continue;
      }
      if (pref[r[i] + 1] - pref[l[i]] == 0) {
        flag = true;
        continue;
      }
      int j = last0(l[i], r[i]);
      int k = fst1(l[i], r[i]);
      if (j < k) {
        flag = true;
        continue;
      }
      p.insert(mp(k, j));
    }
    int ans = SZ(p) + flag;
    cout << ans << "\n";
  }
  return 0;
}
