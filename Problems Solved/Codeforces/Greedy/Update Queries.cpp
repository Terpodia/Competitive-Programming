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

bool cmp(char x, char y) { return x > y; }

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  int ind[m];
  forn(i, m) {
    cin >> ind[i];
    ind[i]--;
  }
  string c;
  cin >> c;

  sort(all(c), cmp);

  vector<int> cnt(n, 0);
  forn(i, m) cnt[ind[i]]++;

  map<int, set<int>> d;

  forn(i, n) { d[cnt[i]].insert(i); }

  forn(i, m) {
    auto it1 = d.end();
    it1--;
    auto it2 = it1->snd.end();
    it2--;

    s[*it2] = c[i];
    d[it1->fst - 1].insert(*it2);

    it1->snd.erase(it2);
    if (it1->snd.empty()) d.erase(it1);
  }

  cout << s << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
