#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"
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

const int INF = 1e9;

int n;
vector<int> s;

map<int, int> m;

vector<vector<int>> v;

void solve(vector<int> &ans) {
  assert(len(ans) <= n);

  if (len(ans) == n) {
    v.pb(ans);
    return;
  }
  if (len(m) == 1) {
    while (m.begin()->snd > 1) {
      ans.pb(0);
      m.begin()->snd /= 2;
    }
    if (len(ans) != n) return;
    v.pb(ans);
    return;
  }

  int x;

  if (prev(m.end())->snd > 1)
    x = 0;
  else
    x = prev(m.end())->fst - prev(prev(m.end()))->fst;

  if (m.find(x) != m.end()) {
    ans.pb(x);

    map<int, int> m2 = m;
    map<int, int> m3 = m;

    for (auto it = m.begin(); it != m.end(); it++) {
      int y = it->fst - x;
      while (m2[y] > 0 && it->snd > 0) {
        m2[y]--, it->snd--;
        m2[it->fst]--;
      }
    }

    queue<int> del;
    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->snd == 0) del.push(it->fst);
    }
    while (!del.empty()) {
      m.erase(del.front());
      del.pop();
    }

    solve(ans);

    m = m3;
    ans.pop_back();
  }

  if (x != 0 && m.find(-x) != m.end()) {
    ans.pb(-x);
    map<int, int> m2 = m;
    map<int, int> m3 = m;

    for (auto it = m.rbegin(); it != m.rend(); it++) {
      int y = it->fst + x;
      while (m2[y] > 0 && it->snd > 0) {
        m2[y]--, it->snd--;
        m2[it->fst]--;
      }
    }

    queue<int> del;
    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->snd == 0) del.push(it->fst);
    }
    while (!del.empty()) {
      m.erase(del.front());
      del.pop();
    }

    solve(ans);

    m = m3;
    ans.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  forn(i, (1 << n)) {
    int x;
    cin >> x;
    s.pb(x);
  }

  sort(all(s));

  forn(i, len(s)) m[s[i]]++;

  vector<int> ans;

  solve(ans);

  set<vector<int>> check;

  forn(i, len(v)) sort(all(v[i]));
  sort(all(v));

  forn(i, len(v)) {
    if (check.find(v[i]) != check.end()) continue;

    check.insert(v[i]);

    for (int j : v[i]) cout << j << " ";
    cout << "\n";
  }
  return 0;
}
