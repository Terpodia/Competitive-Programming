#include <cstdio>
#include <vector>
using namespace std;

#define LSOne(x) x&(-x)

typedef long long ll;

class FenwickTree {
 private:
  int m;
  vector<ll> ft;

 public:
  FenwickTree() {}
  FenwickTree(int n) : m(n + 1) { ft = vector<ll>(n + 1, 0); }
  void update(int p, int v) {
    for (int i = p; i < m; i += LSOne(i)) ft[i] += v;
  }
  ll rsq(int p) {
    ll ret = 0;
    for (int i = p; i > 0; i -= LSOne(i)) ret += ft[i];
    return ret;
  }
};

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    FenwickTree ft(n);
    ft.update(a[0], 1);
    ll ans = 0;
    for (int i = 1; i < n; i++) {
      ans += i - ft.rsq(a[i] - 1);
      ft.update(a[i], 1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}

