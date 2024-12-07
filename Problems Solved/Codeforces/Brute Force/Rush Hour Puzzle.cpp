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
  cerr << "\n---------------------------------------------------------\n"
#define $ << " " <<

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.fst $ p.snd << ')';
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

const int INF = 11;

int a[6][6];
bool hor[11];
pair<int, int> head[11];
int sz[11];

int m;

int ans;

void solve(int k);

void move_right(int i, int k) {
  if (head[i].snd + 1 >= 6 || !hor[i] || a[head[i].fst][head[i].snd + 1] != 0)
    return;

  forn(j, sz[i]) a[head[i].fst][head[i].snd - j + 1] = i;
  a[head[i].fst][head[i].snd - sz[i] + 1] = 0;

  head[i].snd++;

  solve(k + 1);

  forn(j, sz[i]) a[head[i].fst][head[i].snd - j - 1] = i;
  a[head[i].fst][head[i].snd] = 0;

  head[i].snd--;
}

void move_left(int i, int k) {
  if (head[i].snd - sz[i] + 1 <= 0 || !hor[i] ||
      a[head[i].fst][head[i].snd - sz[i]] != 0)
    return;

  forn(j, sz[i]) a[head[i].fst][head[i].snd - j - 1] = i;
  a[head[i].fst][head[i].snd] = 0;

  head[i].snd--;

  solve(k + 1);

  forn(j, sz[i]) a[head[i].fst][head[i].snd - j + 1] = i;
  a[head[i].fst][head[i].snd - sz[i] + 1] = 0;

  head[i].snd++;
}

void move_down(int i, int k) {
  if (head[i].fst + 1 >= 6 || hor[i] || a[head[i].fst + 1][head[i].snd] != 0)
    return;

  forn(j, sz[i]) a[head[i].fst - j + 1][head[i].snd] = i;
  a[head[i].fst - sz[i] + 1][head[i].snd] = 0;

  head[i].fst++;

  solve(k + 1);

  forn(j, sz[i]) a[head[i].fst - j - 1][head[i].snd] = i;
  a[head[i].fst][head[i].snd] = 0;

  head[i].fst--;
}

void move_up(int i, int k) {
  if (head[i].fst - sz[i] + 1 <= 0 || hor[i] ||
      a[head[i].fst - sz[i]][head[i].snd] != 0)
    return;

  forn(j, sz[i]) a[head[i].fst - j - 1][head[i].snd] = i;
  a[head[i].fst][head[i].snd] = 0;

  head[i].fst--;

  solve(k + 1);

  forn(j, sz[i]) a[head[i].fst - j + 1][head[i].snd] = i;
  a[head[i].fst - sz[i] + 1][head[i].snd] = 0;

  head[i].fst++;
}

void solve(int k) {
  if (k + 6 - head[1].snd + sz[1] - 1 >= ans) return;
  if (head[1].snd == 5) {
    ans = k + 6 - head[1].snd + sz[1] - 1;
    return;
  }
  fore(i, 1, m + 1) {
    move_right(i, k);
    move_left(i, k);
    move_up(i, k);
    move_down(i, k);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  forn(i, 11) head[i] = make_pair(-1, -1);
  forn(i, 6) forn(j, 6) cin >> a[i][j];
  forn(i, 6) forn(j, 6) sz[a[i][j]]++;
  dfor(i, 6) dfor(j, 6) {
    if (head[a[i][j]] == make_pair(-1, -1)) {
      head[a[i][j]] = make_pair(i, j);
    }
  }
  forn(j, 6) fore(i, 1, 6) {
    if (a[i][j] == a[i - 1][j]) hor[a[i][j]] = false;
  }
  forn(i, 6) fore(j, 1, 6) {
    if (a[i][j] == a[i][j - 1]) hor[a[i][j]] = true;
  }
  fore(i, 1, 11) if (head[i] != make_pair(-1, -1)) m++;
  ans = INF;

  if (hor[1] && m > 0) solve(0);

  if (ans == INF)
    cout << "-1\n";
  else
    cout << ans << "\n";
  return 0;
}
