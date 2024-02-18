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

const int MAXN = 1e5 + 3, INF = 1e9;

int n;
pair<char, int> s[MAXN];
char c[5];

#define op max
#define NEUT 0

struct STree {
  vector<int> st;
  int n;
  STree(int _n) : st(_n * 2, NEUT), n(_n) {}
  STree(int _n, int* a) : st(_n * 2, NEUT), n(_n) {
    fore(i, 0, n) st[n + i] = a[i];
    build();
  }
  void build() {
    for (int i = n - 1; i > 0; i--) st[i] = op(st[i << 1], st[(i << 1) | 1]);
  }
  void upd(int p, int v) {
    for (st[p += n] = v; p >>= 1;) st[p] = op(st[p << 1], st[(p << 1) | 1]);
  }
  int query(int l, int r) {
    int resl = NEUT, resr = NEUT;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = op(resl, st[l++]);
      if (r & 1) resr = op(st[--r], resr);
    }
    return op(resl, resr);
  }
};

int lis(vector<ll>& a) {
  vector<int> dp(n + 1, 0);
  STree seg(n + 10);
  fore(i, 1, n + 1) {
    dp[i] = seg.query(0, a[i - 1]) + 1;
    seg.upd(a[i - 1], dp[i]);
  }
  return *max_element(all(dp));
}

int getNumber(string a) {
  string b;
  fore(i, 1, SZ(a)) b.pb(a[i]);
  return stoi(b);
}

int solve(vector<int> p) {
  ll acc = 0;
  vector<ll> a(n, 0);
  p.pb(4);
  fore(i, 0, 5) {
    fore(j, 0, n) if (s[j].fst == c[p[i]]) { a[j] = acc + (ll)s[j].snd; }
    acc += (ll)n;
  }

  vector<ll> v = a;
  sort(all(v));
  v.erase(unique(all(v)), v.end());
  fore(i, 0, n) a[i] = (int)distance(v.begin(), lower_bound(all(v), a[i]));
  return n - lis(a);
}

int main() {
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  c[0] = 'S', c[1] = 'W', c[2] = 'E', c[3] = 'R', c[4] = 'C';

  cin >> n;
  fore(i, 0, n) {
    string w;
    cin >> w;
    s[i].fst = w[0];
    s[i].snd = getNumber(w);
  }
  int ans = INF;

  vector<int> p(4, 0);
  fore(i, 0, 4) p[i] = i;

  do {
    ans = min(ans, solve(p));
  } while (next_permutation(all(p)));

  cout << ans << "\n";
  return 0;
}
