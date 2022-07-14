#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
  for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))

typedef complex<double> cd;

int reverseBit(int x, int m) {
  int ret = 0;
  rep(i, 0, m) {
    if (x & (1 << i)) ret |= 1 << (m - i - 1);
  }
  return ret;
}

void FFT(vector<cd>& A) {
  int m = 0;
  while ((1 << m) < sz(A)) m++;

  rep(i, 0, sz(A)) {
    int j = reverseBit(i, m);
    if (i < j) swap(A[i], A[j]);
  }
  for (int n = 2; n <= sz(A); n <<= 1) {
    for (int i = 0; i < sz(A); i += n) {
      for (int k = 0; k * 2 < n; k++) {
        cd x = cd(cos(2 * M_PI * k / n), sin(2 * M_PI * k / n));
        cd u = A[i + k], v = x * A[i + n / 2 + k];
        A[i + k] = u + v;
        A[i + n / 2 + k] = u - v;
      }
    }
  }
}

void IFFT(vector<cd>& A) {
  for (auto& p : A) p = conj(p);
  FFT(A);
  for (auto& p : A) p = conj(p);
  for (auto& p : A) p /= sz(A);
}

vector<int> multiplication(vector<int>& p1, vector<int>& p2) {
  int n = 1;
  while (n < sz(p1) + sz(p2) - 1) n <<= 1;

  vector<cd> A(all(p1));
  vector<cd> B(all(p2));
  A.resize(n);
  B.resize(n);

  FFT(A);
  FFT(B);
  vector<cd> C;
  rep(i, 0, n) C.pb(A[i] * B[i]);
  IFFT(C);
  vector<int> ret;
  for (auto& p : C) ret.pb(round(p.real()));
  ret.resize(sz(p1) + sz(p2) - 1);
  return ret;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n + 1), b(m + 1);
  rep(i, 0, n + 1) scanf("%d", &a[i]);
  rep(i, 0, m + 1) scanf("%d", &b[i]);
  vector<int> c = multiplication(a, b);
  rep(i, 0, n + m + 1) printf("%dx^%d%c", c[i], i, "+\n"[i == n + m]);
  return 0;
}

