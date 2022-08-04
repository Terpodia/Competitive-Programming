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

const int MAXN = 1e5;

typedef long long ll;

const ll INF = 1e9;

int n;
pair<ll, int> a[MAXN];
ll pref[MAXN + 1];
ll A, cf, cm, m;
vector<ll> b;

bool can(ll lo, ll k) {
  auto it = lower_bound(all(b), lo);
  if (it == b.begin()) return true;

  ll d = (ll)distance(b.begin(), it);
  return k >= (lo * d) - pref[d];
}
ll bs(ll k) {
  ll l = b[0], r = A;
  while (r > l) {
    ll mid = l + (r - l + 1) / 2;
    if (can(mid, k))
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}

int main() {
  scanf("%d%lld%lld%lld%lld", &n, &A, &cf, &cm, &m);
  rep(i, 0, n) {
    scanf("%lld", &a[i].fst);
    a[i].snd = i;
  }
  sort(a, a + n);
  b = vector<ll>(n);
  rep(i, 0, n) b[i] = a[i].fst;
  rep(i, 1, n + 1) pref[i] = pref[i - 1] + b[i - 1];

  ll k = m, ans = bs(k) * cm, lo = bs(k);
  int pos = n;

  rep(i, n - 1, -1) {
    if (A - a[i].fst <= k) {
      k -= A - a[i].fst;
      b[i] = A;
      ll res = bs(k) * cm + (ll)(n - i) * cf;
      if (res > ans) ans = res, pos = i, lo = bs(k);
    } else
      break;
  }
  rep(i, 0, n) b[i] = a[i].fst;

  printf("%lld\n", ans);

  rep(i, pos, n) a[a[i].snd].fst = A;
  rep(i, 0, pos) {
    if (b[i] < lo)
      a[a[i].snd].fst = lo;
    else
      a[a[i].snd].fst = b[i];
  }
  rep(i, 0, n) printf("%lld%c", a[i].fst, " \n"[i == n - 1]);
  return 0;
}

