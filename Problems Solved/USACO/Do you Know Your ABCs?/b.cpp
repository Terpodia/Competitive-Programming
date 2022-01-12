#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>
using namespace std;

typedef long double ld;
typedef vector<ld> vd;
typedef vector<vd> vvd;
#define sz(x) (int)x.size()
#define FOR(i, x, n) for (int i = (x); i < (int)n; i++)
#define ROF(i, x, n) for (int i = (x); i > (int)n; i--)

int N, x[7], p[7];
set<tuple<int, int, int>> s;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

int forwardElim(vvd &m) {
  FOR(k, 0, 3) {
    int i_max = k;
    ld v_max = m[k][k];
    FOR(i, k + 1, 3) {
      if (v_max < abs(m[i][k]))
        v_max = abs(m[i][k]), i_max = i;
    }
    swap(m[i_max], m[k]);
    if (!m[k][k])
      return k;
    FOR(i, k + 1, 3) {
      ld f = m[i][k] / m[k][k];
      FOR(j, k + 1, 4) m[i][j] -= f * m[k][j];
      m[i][k] = 0;
    }
  }
  return -1;
}

tuple<int, int, int> gaussElimination(vvd &m) {
  if (forwardElim(m) != -1)
    return make_tuple(-1, -1, -1);
  ld xs[3];
  ROF(i, 2, -1) {
    xs[i] = m[i][3];
    FOR(j, i + 1, 3) xs[i] -= xs[j] * m[i][j];
    xs[i] /= m[i][i];
  }
  return make_tuple((int)xs[0], (int)xs[1], (int)xs[2]);
}

void solve() {
  vvd k(7, vd(4));
  k[0] = {1, 0, 0, -1}, k[1] = {0, 1, 0, -1}, k[2] = {0, 0, 1, -1},
  k[3] = {1, 1, 0, -1}, k[4] = {1, 0, 1, -1}, k[5] = {0, 1, 1, -1},
  k[6] = {1, 1, 1, -1};
  FOR(i, 0, N) k[p[i]][3] = (ld)x[i];

  vvd m(3, vd(4, -1));
  vector<int> v;

  FOR(i, 0, 3) FOR(j, 0, 3) {
    if ((int)m[j][0] == -1 && (int)k[i][3] != -1) {
      m[j] = k[i];
      v.push_back(i);
      break;
    }
  }
  FOR(i, 3, 7) FOR(j, 0, 3) {
    if ((int)m[j][0] == -1 && (int)k[i][3] != -1) {
      if (sz(v) != 2) {
        m[j] = k[i];
        break;
      } else if (i == 6) {
        m[j] = k[i];
        break;
      } else if (!k[i][v[0]] || !k[i][v[1]]) {
        m[j] = k[i];
        break;
      }
    }
  }

  auto [A, B, C] = gaussElimination(m);

  if (A < 1 || B < 1 || C < 1 || A > B || A > C || B > C)
    return;

  if ((int)k[0][3] != -1 && (int)k[0][3] != A)
    return;
  if ((int)k[1][3] != -1 && (int)k[1][3] != B)
    return;
  if ((int)k[2][3] != -1 && (int)k[2][3] != C)
    return;
  if ((int)k[3][3] != -1 && (int)k[3][3] != A + B)
    return;
  if ((int)k[4][3] != -1 && (int)k[4][3] != A + C)
    return;
  if ((int)k[5][3] != -1 && (int)k[5][3] != B + C)
    return;
  if ((int)k[6][3] != -1 && (int)k[6][3] != A + B + C)
    return;

  s.insert(make_tuple(A, B, C));
}

int main() {
  fastIO();
  int TC;
  cin >> TC;
  while (TC--) {
    cin >> N;
    FOR(i, 0, N) cin >> x[i];
    FOR(i, 0, 7) p[i] = i;
    do {
      solve();
    } while (next_permutation(p, p + 7));
    cout << sz(s) << "\n";
    s.clear();
  }
  return 0;
}

