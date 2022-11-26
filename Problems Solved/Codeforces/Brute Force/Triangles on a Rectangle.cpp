#include <algorithm>
#include <iostream>
using namespace std;
int aux;

typedef long long ll;

struct pt {
  ll x, y;

  pt operator-(pt a) { return {x - a.x, y - a.y}; }

  ll operator^(pt a) { return x * a.y - y * a.x; }
};

const int MAXK = 2e5;

ll w, h;
pt p[4][MAXK + 7];
;

ll solve(pt a, pt b) {
  ll ret = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= p[i][0].x; j++) {
      ret = max(ret, abs((p[i][j] - a) ^ (p[i][j] - b)));
    }
  }
  return ret;
}

int main() {
  int t;
  aux = scanf("%d", &t);
  while (t--) {
    aux = scanf("%lld%lld", &w, &h);

    int k;
    aux = scanf("%d", &k);
    p[0][0].x = k;
    for (int i = 0; i < k; i++) {
      aux = scanf("%lld", &p[0][i + 1].x);
      p[0][i + 1].y = 0;
    }

    aux = scanf("%d", &k);
    p[1][0].x = k;
    for (int i = 0; i < k; i++) {
      aux = scanf("%lld", &p[1][i + 1].x);
      p[1][i + 1].y = h;
    }

    aux = scanf("%d", &k);
    p[2][0].x = k;
    for (int i = 0; i < k; i++) {
      aux = scanf("%lld", &p[2][i + 1].y);
      p[2][i + 1].x = 0;
    }

    aux = scanf("%d", &k);
    p[3][0].x = k;
    for (int i = 0; i < k; i++) {
      aux = scanf("%lld", &p[3][i + 1].y);
      p[3][i + 1].x = w;
    }

    ll ans = 0;

    for (int i = 0; i < 4; i++) {
      ans = max(ans, solve(p[i][1], p[i][p[i][0].x]));
    }

    printf("%lld\n", ans);
  }

  return 0;
}
