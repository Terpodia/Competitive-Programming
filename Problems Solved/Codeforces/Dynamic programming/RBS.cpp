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

const int MAXN = 4e5 + 100;

int n;
string s[21];
int sum[21];
bool f[21][MAXN];
int cnt[21][MAXN];

int dp[1 << 20][2];

int solve(int msk, int flag) {
  int &ret = dp[msk][flag];
  if (ret != -1) return ret;
  if (flag == 1) return ret = 0;
  ret = 0;

  int cur = 0;
  forn(i, n) if (msk & (1 << i)) { cur += sum[i]; }
  forn(i, n) if (!(msk & (1 << i))) {
    int nmsk = (msk | (1 << i));
    int nflag = 1 - (int)f[i][cur];
    ret = max(ret, cnt[i][cur] + solve(nmsk, nflag));
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  forn(i, n) cin >> s[i];
  forn(i, n) {
    for (char c : s[i]) sum[i] += (c == '(') ? 1 : -1;

    int cur = 0, hi = 0;
    for (char c : s[i]) {
      cur += (c == '(') ? 1 : -1;
      if (cur <= 0 && hi <= -cur) cnt[i][-cur]++;
      hi = max(hi, -cur);
    }
    fore(j, hi, MAXN) f[i][j] = true;
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0) << "\n";
  return 0;
}
