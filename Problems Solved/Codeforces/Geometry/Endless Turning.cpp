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
typedef long double ld;

const ld EPS = 1e-9;
const ld INF = 1e18;

struct pt {
  ld x, y;
  pt() {}
  pt(ld _x, ld _y) : x(_x), y(_y) {}
  ld norm2() { return *this * *this; }
  ld norm() { return sqrtl(norm2()); }
  pt operator+(pt p) { return pt(x + p.x, y + p.y); }
  pt operator-(pt p) { return pt(x - p.x, y - p.y); }
  pt operator*(ld k) { return pt(x * k, y * k); }
  pt operator/(ld k) { return pt(x / k, y / k); }
  ld operator*(pt p) { return x * p.x + y * p.y; }
  ld operator%(pt p) { return x * p.y - y * p.x; }
};
struct ln {
  pt p, d;
  ln() {}
  ln(pt a, pt b) { p = a, d = b - a; }
  bool has(pt q) { return dist(q) < EPS; }
  bool operator/(ln l) { return abs(d % l.d) < EPS; }
  pt operator^(ln l) {
    if (*this / l) return pt(INF, INF);
    return p + d * ((l.p - p) % l.d / (d % l.d));
  }
  pt proj(pt q) { return p + d * (d * (q - p) / d.norm2()); }
  ld dist(pt q) { return (q - proj(q)).norm(); }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int r;
  ll N;
  pt h;
  cin >> r >> N;
  cin >> h.x >> h.y;
  string s[r];
  ln l[r];

  int cur = 0;
  fore(i, 0, r) {
    cin >> s[i];
    pt a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    if (a.x < b.x)
      swap(a, b);
    else if (abs(a.x - b.x) < EPS && a.y < b.y)
      swap(a, b);
    l[i] = ln(b, a);
    if (l[i].has(h)) cur = i;
  }

  ll n = N;
  int flag = 1;
  ln l_cur;
  l_cur.p = h, l_cur.d = l[cur].d;
  vector<string> v;
  map<pair<pair<int, int>, int>, int> vis;
  int k = 0;

  while (n >= 0) {
    if (n == 0) {
      cout << s[cur] << "\n";
      return 0;
    }
    int j = -1;
    ld res = INF;
    fore(i, 0, r) {
      if (i == cur) continue;
      if (l_cur / l[i]) continue;
      ld alpha = ((l[i].p - l_cur.p) % l[i].d / (l_cur.d % l[i].d));
      alpha *= (ld)flag;
      if (alpha > EPS && res > alpha) res = alpha, j = i;
    }
    if (j == -1) {
      cout << s[cur] << "\n";
      return 0;
    }

    if (vis.find(mp(mp(cur, j), flag)) != vis.end()) {
      k = vis[mp(mp(cur, j), flag)];
      break;
    }
    v.push_back(s[j]);
    vis[mp(mp(cur, j), flag)] = SZ(v) - 1;

    flag *= (l_cur.d % l[j].d) > 0.0 ? -1 : 1;
    l_cur.p = l_cur ^ l[j];
    l_cur.d = l[j].d;
    cur = j;
    n--;
  }
  cout << v[k + (SZ(v) - 1 - k + n) % (SZ(v) - k)] << "\n";
  return 0;
}
