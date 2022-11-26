#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<double> vd;
typedef vector<vd> vvd;
#define sz(x) (int)x.size()

int forwardElim(vvd &m) {
  for (int k = 0; k < sz(m); k++) {
    int i_max = k;
    double v_max = m[i_max][k];
    for (int i = k + 1; i < sz(m); i++) {
      if (v_max < abs(m[i][k])) i_max = i, v_max = abs(m[i][k]);
    }
    swap(m[k], m[i_max]);
    if (!m[k][k]) return k;
    for (int i = k + 1; i < sz(m); i++) {
      double f = m[i][k] / m[k][k];
      for (int j = k + 1; j <= sz(m); j++) m[i][j] -= m[k][j] * f;
      m[i][k] = 0;
    }
  }
  return -1;
}

void solve(vvd &m) {
  int singular_flag = forwardElim(m);
  if (singular_flag != -1) {
    printf("Singular Matrix\n");
    if (m[singular_flag][sz(m)])
      printf("Inconsistent System.\n");
    else
      printf("May have infinitely many solutions.\n");
    return;
  }
  double x[sz(m)];
  for (int i = sz(m) - 1; i > -1; i--) {
    x[i] = m[i][sz(m)];
    for (int j = i + 1; j < sz(m); j++) x[i] -= x[j] * m[i][j];
    x[i] /= m[i][i];
  }
  printf("Solution for the system:\n");
  for (int i = 0; i < sz(m); i++) printf("%lf\n", x[i]);
}

int main() {
  int n;
  scanf("%d", &n);
  vvd m(n, vd(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n + 1; j++) {
      double c;
      scanf("%lf", &c);
      m[i][j] = c;
    }
  }
  solve(m);
  return 0;
}
