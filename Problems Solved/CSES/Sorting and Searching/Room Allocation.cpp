/*
*************************************************************
"Si puedes imaginarlo, puedes programarlo" Alejandro Taboada.
*************************************************************
*/

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

#define foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define rforsn(i, x, n, a) for (int i = (x); i >= (int)(n); i -= a)
#define forsn(i, x, n, a) for (int i = (x); i < (int)(n); i += a)
#define rforn(i, x, n) for (int i = (x); i >= (int)(n); i--)
#define forn(i, x, n) for (int i = (x); i < (int)(n); i++)
#define deb(x) cout << #x << " " << x << endl;
#define all(cont) cont.begin(), cont.end()
#define sz(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define endl "\n"
#define s second
#define f first

void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

struct customer {
  int l, r, pos, num;

  bool operator<(const customer& c) const {
    if (l != c.l) return l < c.l;
    return r < c.r;
  }

  bool operator>(const customer& c) const {
    if (l != c.l) return l > c.l;
    return r > c.r;
  }
};

const int MAXN = 2e5;
int n;
customer customers[MAXN];

void solve() {
  sort(customers, customers + n);
  priority_queue<customer, vector<customer>, greater<customer>> pq;

  int k = 1;
  vector<int> ans(n);

  customers[0].num = k;
  pq.push({customers[0].r, customers[0].l, customers[0].pos, customers[0].num});
  ans[customers[0].pos] = k;

  forn(i, 1, n) {
    customer c = pq.top();
    swap(c.l, c.r);

    if (c.r < customers[i].l) {
      ans[customers[i].pos] = customers[i].num = c.num;
      pq.pop();
    }

    else {
      k++;
      ans[customers[i].pos] = customers[i].num = k;
    }

    pq.push(
        {customers[i].r, customers[i].l, customers[i].pos, customers[i].num});
  }

  cout << k << endl;
  forn(i, 0, n) cout << ans[i] << " ";
  cout << endl;
}

int main() {
  setIO();
  cin >> n;

  forn(i, 0, n) {
    cin >> customers[i].l >> customers[i].r;
    customers[i].pos = i;
  }

  solve();
  return 0;
}
