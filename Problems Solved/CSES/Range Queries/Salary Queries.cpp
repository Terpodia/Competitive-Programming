#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fore(i, a, b) for (auto i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for (auto i = n; i-- > 0;)
#define dbg(x) cerr << "LINE" $ __LINE__ << ":" $ #x << "=" << x << endl;
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
#define $ << " " <<

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << '(' << p.first $ p.second << ')';
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  forn(i, len(v)) {
    if (i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

typedef long long ll;

const int INF = 1e9 + 10;

struct Node {
  Node *l, *r;
  int val;
  Node() {
    l = r = NULL;
    val = 0;
  }
};
struct STree {
  Node *root;
  STree() { root = new Node(); }
  int op(Node *l, Node *r) {
    int ret = 0;
    if (l) ret += l->val;
    if (r) ret += r->val;
    return ret;
  }
  void upd(Node *u, int l, int r, int pos, int val) {
    if (l + 1 == r)
      u->val += val;
    else {
      int m = (l + r) / 2;
      if (pos < m) {
        if (!u->l) u->l = new Node();
        upd(u->l, l, m, pos, val);
      } else {
        if (!u->r) u->r = new Node();
        upd(u->r, m, r, pos, val);
      }
      u->val = op(u->l, u->r);
    }
  }
  int query(Node *u, int l, int r, int s, int e) {
    if (!u) return 0;
    if (l >= e || r <= s) return 0;
    if (l >= s && r <= e) return u->val;
    int m = (l + r) / 2;
    return query(u->l, l, m, s, e) + query(u->r, m, r, s, e);
  }
  void upd(int pos, int val) { upd(root, 1, INF, pos, val); }
  int query(int s, int e) { return query(root, 1, INF, s, e); }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  int p[n];
  STree st;
  forn(i, n) {
    cin >> p[i];
    st.upd(p[i], 1);
  }
  while (q--) {
    char t;
    cin >> t;
    if (t == '?') {
      int a, b;
      cin >> a >> b;
      cout << st.query(a, b + 1) << "\n";
    } else {
      int k, x;
      cin >> k >> x;
      k--;
      st.upd(p[k], -1);
      p[k] = x;
      st.upd(p[k], 1);
    }
  }
  return 0;
}
