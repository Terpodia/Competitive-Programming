#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " "
#define line cout << "\n==================================\n"

typedef long long ll;

class SegmentTree {
 private:
  int n;
  vector<ll> st, a;
  int l(int v) { return v * 2; }
  int r(int v) { return v * 2 + 1; }

  void build(int v, int L, int R) {
    if (L == R)
      st[v] = a[L];
    else {
      int m = (L + R) / 2;
      build(l(v), L, m);
      build(r(v), m + 1, R);
      st[v] = max(st[l(v)], st[r(v)]);
    }
  }

  ll rmq(int v, int L, int R, int lx, int rx) {
    if (L >= lx && R <= rx) return st[v];
    if (L > rx || R < lx) return -1;
    int m = (L + R) / 2;
    return max(rmq(l(v), L, m, lx, rx), rmq(r(v), m + 1, R, lx, rx));
  }

 public:
  SegmentTree() {}
  SegmentTree(vector<ll>& a_init) {
    n = sz(a_init);
    st = vector<ll>(n * 4, -1);
    a = a_init;
    build(1, 0, n - 1);
  }
  ll rmq(int lx, int rx) {
    if (rx < lx) return -1;
    return rmq(1, 0, n - 1, lx, rx);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<ll> h(n);
  rep(i, 0, n) cin >> h[i];

  set<int> s;
  map<ll, int> mp;
  vector<pair<int, int>> q;

  rep(i, 0, n) q.push_back({h[i], i});
  rep(i, 0, n) mp[h[i]] = i;
  sort(q.begin(), q.end());

  SegmentTree st(h);
  ll ans = 0;

  rep(i, sz(q) - 1, -1) {
    auto it = s.lower_bound(q[i].second);
    int l = q[i].second, r = (it == s.end()) ? n - 1 : *it;
    while (r > l) {
      ll hi;
      hi = st.rmq(l + 1, r);
      if (h[r] == hi)
        ans += r - l + 1, r--;
      else
        r = mp[hi];
    }
    s.insert(q[i].second);
  }

  cout << ans << "\n";

  return 0;
}
