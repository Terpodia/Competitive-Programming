#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

#define FOR(i, x, n) for (int i = (x); i < (int)(n); i++)
#define SZ(x) (int)x.size()

struct letter {
  ll n, p, cnt;
};

string s;
ll nb, ns, nc, pb, ps, pc, r, cntb, cnts, cntc;

void fastIO() { cin.tie(0)->sync_with_stdio(0); }

ll solve() {
  vector<letter> vec;
  if (cntb > 0) vec.push_back({nb, pb, cntb});
  if (cnts > 0) vec.push_back({ns, ps, cnts});
  if (cntc > 0) vec.push_back({nc, pc, cntc});

  ll m = 0;
  FOR(i, 0, SZ(vec))
  m = max(m, vec[i].n / vec[i].cnt);

  ll ret = 0;

  FOR(i, 0, m) {
    bool can = true;
    FOR(j, 0, SZ(vec)) {
      if (vec[j].n >= vec[j].cnt)
        vec[j].n -= vec[j].cnt;
      else {
        if (r < vec[j].p * (vec[j].cnt - vec[j].n)) {
          can = false;
          break;
        }
        r -= vec[j].p * (vec[j].cnt - vec[j].n);
        vec[j].n = 0;
      }
    }

    if (!can) break;
    ret++;
  }

  ll acc = 0;

  FOR(i, 0, SZ(vec))
  acc += vec[i].p * (vec[i].cnt - (vec[i].n % vec[i].cnt));

  if (r >= acc) {
    r -= acc;
    ret++;

    acc = 0;
    FOR(i, 0, SZ(vec)) acc += vec[i].cnt * vec[i].p;
    ret += r / acc;
  }

  return ret;
}

int main() {
  fastIO();
  cin >> s;
  cin >> nb >> ns >> nc;
  cin >> pb >> ps >> pc;
  cin >> r;

  for (char c : s) {
    if (c == 'B')
      cntb++;
    else if (c == 'S')
      cnts++;
    else
      cntc++;
  }

  cout << solve() << "\n";

  return 0;
}
