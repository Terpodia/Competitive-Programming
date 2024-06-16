#pragma GCC optimize("O3,unroll-loops")

#include <iostream>
#include <map>
#include <set>
#include <vector>
// #include<algorithm>
// #include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
#define dbg(x) cerr << "LINE" $ __LINE__ << ":" $ #x << "=" << x << endl;
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first $ p.second << ')';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  forn(i, len(v)) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

typedef long long ll;

const int MAXN = 2e5 + 10;
const int INF = 1e9;

int n, a[MAXN];

void solve() {
  int j = -1;
  forn(i, n) {
    if (a[i] != -1) {
      j = i;
      break;
    }
  }
  if (j == -1) {
    forn(i, n) {
      if (i % 2 == 0)
        cout << "2 ";
      else
        cout << "1 ";
    }
    cout << "\n";
    return;
  }

  for (int i = j - 1; i >= 0; i--) {
    if ((j - i) % 2 == 1)
      a[i] = a[i + 1] * 2;
    else
      a[i] = a[i + 1] / 2;
  }

  vector<int> cnt;
  bool can = true;
  int cur = 0;

  fore(i, j + 1, n) {
    if (a[i] == -1)
      cur++;
    else {
      if (cur > 0) cnt.pb(cur);
      cur = 0;
    }
  }
  if (cur > 0) cnt.pb(cur);

  int i = j;
  cur = 0;
  while (i < n - 1) {
    if (i + 1 < n && a[i + 1] != -1) {
      i++;
      continue;
    }
    if (i + cnt[cur] == n - 1) {
      for (int j = i + 1; j < n; j++) {
        if ((j - i) % 2 == 1)
          a[j] = a[j - 1] * 2;
        else
          a[j] = a[j - 1] / 2;
      }
      break;
    }
    int l = a[i], r = a[i + cnt[cur] + 1];
    int lx = i + 1, rx = i + cnt[cur];

    while (l != r) {
      if (l > r) {
        l /= 2;
        if (lx <= i + cnt[cur]) a[lx++] = l;
      } else {
        r /= 2;
        if (rx > i) a[rx--] = r;
      }
    }
    fore(j, lx, rx + 1) {
      if ((j - lx) % 2 == 0)
        a[j] = l * 2;
      else
        a[j] = l;
    }
    i += cnt[cur] + 1;
    cur++;
  }

  for (int i = 0; i < n - 1; i++) {
    can &= (a[i] == a[i + 1] / 2 || a[i + 1] == a[i] / 2);
  }

  if (!can) {
    cout << "-1\n";
    return;
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    forn(i, n) cin >> a[i];
    solve();
  }
  return 0;
}
