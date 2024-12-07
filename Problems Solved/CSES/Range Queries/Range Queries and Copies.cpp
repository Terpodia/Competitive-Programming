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
  ll val;
  Node(ll _val = 0) {
    l = r = NULL;
    val = _val;
  }
  Node(Node *_l, Node *_r) {
    l = _l, r = _r, val = 0;
    if (l) val += l->val;
    if (r) val += r->val;
  }
};
struct PSTree {
  Node *root;
  int n;
  PSTree(int _n) {
    n = _n;
    root = new Node();
  }
  PSTree(PSTree *st) { n = st->n, root = st->root; }
  PSTree *copy() { return new PSTree(this); }
  Node *upd(Node *u, int l, int r, int pos, ll val) {
    if (l + 1 == r)
      return new Node(val);
    else {
      int m = (l + r) / 2;
      if (pos < m) {
        if (!u->l) u->l = new Node();
        return new Node(upd(u->l, l, m, pos, val), u->r);
      } else {
        if (!u->r) u->r = new Node();
        return new Node(u->l, upd(u->r, m, r, pos, val));
      }
    }
  }
  ll query(Node *u, int l, int r, int s, int e) {
    if (!u) return 0;
    if (l >= e || r <= s) return 0;
    if (l >= s && r <= e) return u->val;
    int m = (l + r) / 2;
    return query(u->l, l, m, s, e) + query(u->r, m, r, s, e);
  }
  void upd(int pos, ll val) { root = upd(root, 0, n, pos, val); }
  ll query(int s, int e) { return query(root, 0, n, s, e); }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  ll v[n];
  forn(i, n) cin >> v[i];

  vector<PSTree *> d;
  PSTree *init = new PSTree(n);

  forn(i, n) init->upd(i, v[i]);
  d.pb(init);

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int k, a, x;
      cin >> k >> a >> x;
      d[k - 1]->upd(a - 1, x);
    } else if (t == 2) {
      int k, a, b;
      cin >> k >> a >> b;
      cout << d[k - 1]->query(a - 1, b) << "\n";
    } else {
      int k;
      cin >> k;
      d.pb(d[k - 1]->copy());
    }
  }
  return 0;
}
