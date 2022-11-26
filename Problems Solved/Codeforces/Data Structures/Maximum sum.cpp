#include <iostream>
#include <vector>
using namespace std;

#define forr(i, x, n) for (int i = (x); i < (int)(n); i++)
typedef long long ll;

struct node {
  ll sum;
  ll pre;
  ll su;
  ll seg;
};

struct seg_tree {
  vector<node> nodes;

  void init(int n) { nodes.resize(n * 4); }

  node merge(node a, node b) {
    return {a.sum + b.sum, max(a.pre, a.sum + b.pre), max(b.su, b.sum + a.su),
            max(a.seg, max(b.seg, a.su + b.pre))};
  }

  void build(ll array[], int l, int r, int x) {
    if (l == r) {
      if (array[l] > 0)
        nodes[x] = {array[l], array[l], array[l], array[l]};
      else
        nodes[x] = {array[l], 0, 0, 0};
      return;
    }
    int m = (l + r) / 2;
    build(array, l, m, x * 2);
    build(array, m + 1, r, x * 2 + 1);
    nodes[x] = merge(nodes[x * 2], nodes[x * 2 + 1]);
  }

  void update(int u, int v, int l, int r, int x) {
    if (l == r) {
      if (v > 0)
        nodes[x] = {v, v, v, v};
      else
        nodes[x] = {v, 0, 0, 0};
      return;
    }

    int m = (l + r) / 2;
    if (u <= m)
      update(u, v, l, m, x * 2);
    else
      update(u, v, m + 1, r, x * 2 + 1);

    nodes[x] = merge(nodes[x * 2], nodes[x * 2 + 1]);
  }

  node calc(int u, int v, int l, int r, int x) {
    if (r < u || l > v) return {0, 0, 0, 0};
    if (l >= u && r <= v) return nodes[x];

    int m = (l + r) / 2;
    node a = calc(u, v, l, m, x * 2);
    node b = calc(u, v, m + 1, r, x * 2 + 1);

    return merge(a, b);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  seg_tree st;
  cin >> n >> m;
  ll array[n];
  st.init(n);

  forr(i, 0, n) cin >> array[i];
  st.build(array, 0, n - 1, 1);
  cout << st.calc(0, n - 1, 0, n - 1, 1).seg << "\n";

  forr(i, 0, m) {
    int u, v;
    cin >> u >> v;
    st.update(u, v, 0, n - 1, 1);
    cout << st.calc(0, n - 1, 0, n - 1, 1).seg << "\n";
  }
  return 0;
}
