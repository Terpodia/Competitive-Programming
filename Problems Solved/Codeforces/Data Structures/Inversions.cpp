#include <iostream>
#include <vector>
using namespace std;

#define forr(i, x, n) for (int i = (x); i < (int)(n); i++)
typedef long long ll;

struct segTree {
  vector<ll> nodes;
  void init(int n) { nodes.resize(n * 4); }
  ll sum(int l, int lx, int rx, int x) {
    if (rx < l) return 0;
    if (lx >= l) return nodes[x];

    int m = (lx + rx) / 2;
    ll u = sum(l, lx, m, x * 2);
    ll v = sum(l, m + 1, rx, x * 2 + 1);
    return u + v;
  }
  void update(ll val, int pos, int lx, int rx, int x) {
    if (lx == rx)
      nodes[x] = val;
    else {
      int m = (lx + rx) / 2;
      if (pos <= m)
        update(val, pos, lx, m, x * 2);
      else
        update(val, pos, m + 1, rx, x * 2 + 1);

      nodes[x] = nodes[x * 2] + nodes[x * 2 + 1];
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  segTree st;
  cin >> n;
  st.init(n);
  ll p[n], answer = 0;

  forr(i, 0, n) cin >> p[i];

  forr(i, 0, n) {
    answer = st.sum(p[i] - 1, 0, n - 1, 1);
    cout << answer << " ";
    st.update(1, p[i] - 1, 0, n - 1, 1);
  }
  cout << "\n";
  return 0;
}
