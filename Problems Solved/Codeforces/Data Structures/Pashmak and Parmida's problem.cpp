#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

typedef long long ll;

const int MAXA = 1e6 + 1;

struct Vertex {
  ll sum;
  void merge(Vertex l, Vertex r) { sum = l.sum + r.sum; }
};

class SegmentTree {
 private:
  int n;
  vector<Vertex> st;
  vector<ll> a;

  int l(int v) { return 2 * v; }
  int r(int v) { return 2 * v + 1; }

  void build(int L, int R, int v) {
    if (R - L == 1)
      st[v].sum = a[L];
    else {
      int m = (L + R) / 2;
      build(L, m, l(v));
      build(m, R, r(v));
      st[v].merge(st[l(v)], st[r(v)]);
    }
  }

  Vertex rsq(int L, int R, int v, int i, int j) {
    if (L >= i && R <= j) return st[v];
    if (L >= j || R <= i) return {0};
    int m = (L + R) / 2;
    Vertex ret;
    ret.merge(rsq(L, m, l(v), i, j), rsq(m, R, r(v), i, j));
    return ret;
  }

  void add(int L, int R, int v, int p, ll s) {
    if (R - L == 1)
      st[v].sum += s;
    else {
      int m = (L + R) / 2;
      if (p < m)
        add(L, m, l(v), p, s);
      else
        add(m, R, r(v), p, s);
      st[v].merge(st[l(v)], st[r(v)]);
    }
  }

 public:
  SegmentTree() {}
  SegmentTree(int m) : n(m), st(4 * m) {}
  SegmentTree(vector<ll>& v) : SegmentTree(sz(v)) {
    a = v;
    build(0, n, 1);
  }
  Vertex rsq(int i, int j) { return rsq(0, n, 1, i, j); }
  void add(int p, ll s) { add(0, n, 1, p, s); }
};

void compress(vector<int>& a) {
  vector<int> b = a;
  sort(all(b));
  b.resize(distance(b.begin(), unique(all(b))));
  for (int i = 0; i < sz(a); i++)
    a[i] = (int)distance(b.begin(), lower_bound(all(b), a[i]));
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  compress(a);

  vector<ll> cnt(MAXA, 0), pref(n, 0), suff(n, 0);
  for (int i = 0; i < n; i++) cnt[a[i]]++, pref[i] = cnt[a[i]];
  cnt = vector<ll>(MAXA, 0);
  for (int i = n - 1; i > -1; i--) cnt[a[i]]++, suff[i] = cnt[a[i]];

  cnt = vector<ll>(n + 1, 0);
  cnt[suff[n - 1]]++;
  SegmentTree st(cnt);

  ll ans = 0;

  for (int i = n - 2; i > -1; i--) {
    ans += st.rsq(0, (int)pref[i]).sum;
    cnt[suff[i]]++;
    st.add((int)suff[i], 1);
  }

  cout << ans << "\n";

  return 0;
}
