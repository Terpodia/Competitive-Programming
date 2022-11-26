#include <fstream>
#include <vector>
using namespace std;
using vi = vector<int>;

#define sz(x) (int)x.size()

vi buildPsum(vi &v) {
  vi res(sz(v) + 1);
  res[0] = 0;
  for (int i = 1; i < sz(res); i++) res[i] = v[i - 1] + res[i - 1];

  return res;
}

int psum(int &l, int &r, vi &s) { return s[r] - s[l - 1]; }

int main() {
  ifstream fin;
  ofstream fout;
  fin.open("bcount.in");
  fout.open("bcount.out");

  int Q, N;
  fin >> N >> Q;
  vi c1(N, 0), c2(N, 0), c3(N, 0);

  for (int i = 0; i < N; i++) {
    int x;
    fin >> x;
    if (x == 1)
      c1[i] = 1;
    else if (x == 2)
      c2[i] = 1;
    else
      c3[i] = 1;
  }

  vi psum1 = buildPsum(c1), psum2 = buildPsum(c2), psum3 = buildPsum(c3);

  while (Q--) {
    int l, r;
    fin >> l >> r;
    fout << psum(l, r, psum1) << " " << psum(l, r, psum2) << " "
         << psum(l, r, psum3) << "\n";
  }

  fin.close();
  fout.close();
  return 0;
}
