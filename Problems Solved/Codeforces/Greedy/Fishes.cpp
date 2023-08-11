#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pll;

struct pos {
  ll val, row, col;
  bool operator<(const pos& p) const { return val < p.val; }
};

const ll rd[] = {0, 0, 1, -1}, cd[] = {1, -1, 0, 0};

ll n, m, r;
int k;

ll cost(ll i, ll j) {
  return (min(n + 1, i + 1 + r) - max(i + 1, r)) *
         (min(m + 1, j + 1 + r) - max(j + 1, r));
}

ll solve() {
  priority_queue<pos> pq;
  set<pll> vis;
  ll ans = 0;

  pq.push({cost(n / 2, m / 2), n / 2, m / 2});
  vis.insert({n / 2, m / 2});

  while (!pq.empty() && k > 0) {
    pos p = pq.top();
    pq.pop();
    k--;
    ans += p.val;
    for (int _ = 0; _ < 4; _++) {
      ll i = p.row + rd[_], j = p.col + cd[_];
      if (i >= 0 && i < n && j >= 0 && j < m && vis.find({i, j}) == vis.end()) {
        vis.insert({i, j});
        pq.push({cost(i, j), i, j});
      }
    }
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout << fixed << setprecision(13);
  cin >> n >> m >> r >> k;
  cout << (ld)solve() / (ld)((n - r + 1) * (m - r + 1)) << "\n";
  return 0;
}
