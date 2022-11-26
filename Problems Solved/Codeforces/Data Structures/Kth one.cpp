#include <iostream>
#include <vector>
using namespace std;

#define forr(i, x, n) for (int i = (x); i < (int)(n); i++)
typedef long long ll;

struct seg_tree {
  vector<ll> nodes;

  void init(int n) { nodes.resize(n * 4); }

  void build(ll array[], int l, int r, int x) {
    if (l == r)
      nodes[x] = array[l];
    else {
      int m = (l + r) / 2;
      build(array, l, m, x * 2);
      build(array, m + 1, r, x * 2 + 1);
      nodes[x] = nodes[x * 2] + nodes[x * 2 + 1];
    }
  }

  void update(int u, int v, int l, int r, int x) {
    if (l == r) {
      nodes[x] = v;
      return;
    }
    int m = (l + r) / 2;
    if (u <= m)
      update(u, v, l, m, x * 2);
    else
      update(u, v, m + 1, r, x * 2 + 1);

    nodes[x] = nodes[x * 2] + nodes[x * 2 + 1];
  }

  int calc(int k, int l, int r, int x) {
    if (l == r) return l;
    int m = (l + r) / 2;
    int sl = nodes[x * 2];

    if (k < sl)
      calc(k, l, m, x * 2);
    else
      calc(k - sl, m + 1, r, x * 2 + 1);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, u, q;
  seg_tree st;

  cin >> n >> m;
  st.init(n);
  ll array[n];
  forr(i, 0, n) cin >> array[i];
  st.build(array, 0, n - 1, 1);

  forr(i, 0, m) {
    cin >> q >> u;
    if (q == 1) {
      array[u] = 1 - array[u];
      st.update(u, array[u], 0, n - 1, 1);
    } else
      cout << st.calc(u, 0, n - 1, 1) << "\n";
  }

  return 0;
}
