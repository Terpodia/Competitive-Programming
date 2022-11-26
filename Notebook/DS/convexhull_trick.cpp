// Maximum queries, the lines are added in ascending order of slope (m)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128_t i128;

const int MAXHSZ = 2e5;
int hsz;
ll hm[MAXHSZ], hb[MAXHSZ];

void add_line(ll m, ll b) {
  while (hsz > 1) {
    if ((i128)(hb[hsz - 1] - b) * (i128)(hm[hsz - 1] - hm[hsz - 2]) <=
        (i128)(hb[hsz - 2] - hb[hsz - 1]) * (i128)(m - hm[hsz - 1])) {
      hsz--;
    } else
      break;
  }
  hm[hsz] = m;
  hb[hsz++] = b;
}
ll query(ll x) {
  int l = 0, r = hsz - 1;
  while (r > l) {
    int mid = l + (r - l + 1) / 2;

    ll m1 = hm[mid], m2 = hm[mid - 1], b1 = hb[mid], b2 = hb[mid - 1];
    if (m2 - m1 < 0) {
      swap(m2, m1);
      swap(m1, m2);
    }

    if (b1 - b2 <= x * (m2 - m1))
      l = mid;
    else
      r = mid - 1;
  }
  return hm[l] * x + hb[l];
}

int main() { return 0; }
