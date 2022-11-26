#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

#define sz(x) (int)x.size()

const int MAXLOG = 26;
const int INF = 1e9;

struct sparse_table {
  vector<vi> st;

  sparse_table(vi& a) {
    st = vector<vi>(sz(a), vi(MAXLOG, INF));
    for (int i = 0; i < sz(a); i++) st[i][0] = a[i];

    for (int j = 1; j <= MAXLOG; j++) {
      for (int i = 0; i + (1 << j) - 1 < sz(a); i++) {
        st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  int rmq(int l, int r) {
    int ans = INF;

    for (int j = MAXLOG; j >= 0; j--) {
      if ((1 << j) <= r - l + 1) {
        ans = min(ans, st[l][j]);
        l += (1 << j);
      }
    }

    return ans;
  }
};

void test() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    sparse_table st(a);

    int q;
    scanf("%d", &q);
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", st.rmq(l, r));
    }
  }
}

int main() {
  test();

  return 0;
}
