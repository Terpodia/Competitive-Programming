#include <iostream>
#include <vector>
using namespace std;

#define SZ(x) (int)x.size()
#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)

int N;
vector<string> S, T;
bool can = false;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

vector<string> rotate90(vector<string>& v) {
  int n = SZ(v), m = SZ(v[0]);
  vector<string> ret = v;
  FOR(i, 0, n) FOR(j, 0, m) ret[j][m - i - 1] = v[i][j];
  return ret;
}

pair<int, int> find_leftmost(vector<string>& v) {
  FOR(i, 0, SZ(v))
  FOR(j, 0, SZ(v[0])) if (v[i][j] == '#') return make_pair(i, j);

  return make_pair(0, 0);
}

vector<string> mv(int dr, int dc, bool& flag) {
  vector<string> ret = S;
  FOR(i, 0, N) FOR(j, 0, N) ret[i][j] = '.';

  FOR(i, 0, N) FOR(j, 0, N) {
    if (!flag) break;

    if (S[i][j] == '#') {
      if (i + dr < 0 || i + dr >= N || j + dc < 0 || j + dc >= N) flag = false;
      if (!flag) break;
    }

    if (i + dr < 0 || i + dr >= N || j + dc < 0 || j + dc >= N) continue;

    ret[i + dr][j + dc] = S[i][j];
  }

  return ret;
}

bool check() {
  pair<int, int> p1, p2;
  p1 = find_leftmost(S), p2 = find_leftmost(T);

  int dr = p2.first - p1.first, dc = p2.second - p1.second;
  bool flag = true;

  vector<string> s = mv(dr, dc, flag);

  if (!flag) return false;

  FOR(i, 0, N) FOR(j, 0, N) if (s[i][j] != T[i][j]) return false;

  return true;
}

int main() {
  fastIO();

  cin >> N;
  S.resize(N);
  T.resize(N);
  FOR(i, 0, N) cin >> S[i];
  FOR(i, 0, N) cin >> T[i];

  FOR(i, 0, 4) {
    can |= check();
    S = rotate90(S);
  }

  (can) ? cout << "Yes\n" : cout << "No\n";

  return 0;
}
