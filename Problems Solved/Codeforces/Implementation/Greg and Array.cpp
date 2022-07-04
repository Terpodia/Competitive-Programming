#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 1e5;

struct operation {
  int l, r;
  ll d;
};

int n, m, k;
ll a[MAXN];
operation o[MAXN];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> o[i].l >> o[i].r >> o[i].d;

  int b[m + 1];
  ll c[n + 1];
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));

  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    b[x - 1]++;
    b[y]--;
  }

  ll acc = 0;

  for (int i = 0; i < m; i++) {
    acc += b[i];
    c[o[i].l - 1] += o[i].d * acc;
    c[o[i].r] -= o[i].d * acc;
  }

  acc = 0;
  for (int i = 0; i < n; i++) {
    acc += c[i];
    cout << a[i] + acc << " \n"[i == n - 1];
  }

  return 0;
}

