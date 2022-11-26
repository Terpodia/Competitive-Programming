#include <iostream>
#include <vector>
using namespace std;

#define forr(i, x, n) for (int i = (x); i < (int)(n); i++)

struct seg_tree {
  vector<int> nodes;
  void init(int n) { nodes.resize(n * 4); }

  void build(int array[], int l, int r, int x) {
    if (l == r)
      nodes[x] = array[l];
    else {
      int m = (l + r) / 2;
      build(array, l, m, x * 2);
      build(array, m + 1, r, x * 2 + 1);
      nodes[x] = max(nodes[x * 2], nodes[x * 2 + 1]);
    }
  }

  void update(int u, int v, int l, int r, int x) {
    if (l == r)
      nodes[x] = v;
    else {
      int m = (l + r) / 2;
      if (u <= m)
        update(u, v, l, m, x * 2);
      else
        update(u, v, m + 1, r, x * 2 + 1);

      nodes[x] = max(nodes[x * 2], nodes[x * 2 + 1]);
    }
  }

  int find(int u, int v, int l, int r, int x) {
    if (nodes[x] < v || r < u) return -1;
    if (l == r) return l;

    int m = (l + r) / 2;
    int a = find(u, v, l, m, x * 2);
    if (a == -1) a = find(u, v, m + 1, r, x * 2 + 1);
    return a;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, u, v, q;
  seg_tree st;
  cin >> n >> m;
  st.init(n);
  int array[n];

  forr(i, 0, n) cin >> array[i];
  st.build(array, 0, n - 1, 1);

  forr(i, 0, m) {
    cin >> q >> u >> v;
    if (q == 1)
      st.update(u, v, 0, n - 1, 1);
    else
      cout << st.find(v, u, 0, n - 1, 1) << "\n";
  }

  return 0;
}
