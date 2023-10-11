#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
typedef long long ll;

typedef struct item* pitem;

struct item {
  int key, pr, cnt;
  ll val, sum, lazy;
  int lazy_type;
  pitem l, r;
  item(int k, ll v)
      : key(k),
        pr(rand()),
        cnt(1),
        val(v),
        sum(v),
        lazy(0),
        lazy_type(0),
        l(0),
        r(0) {}
};
void push(pitem& t);
int sz(pitem& t) { return t ? t->cnt : 0; }
ll sum(pitem& t) { return t ? push(t), t->sum : 0; }

void eval(pitem& t) {
  if (t) {
    t->cnt = sz(t->l) + sz(t->r) + 1;
    t->sum = sum(t->l) + sum(t->r) + t->val;
  }
}
void push(pitem& t) {
  if (!t || !t->lazy) return;
  if (t->lazy_type == 1) {
    t->sum += t->lazy * (ll)sz(t);
    t->val += t->lazy;
    ll val = t->lazy;
    if (t->l) t->l->lazy += val, t->l->lazy_type = max(t->l->lazy_type, 1);
    if (t->r) t->r->lazy += val, t->r->lazy_type = max(t->r->lazy_type, 1);
  } else {
    t->sum = t->lazy * (ll)sz(t);
    t->val = t->lazy;
    ll val = t->lazy;
    if (t->l) t->l->lazy = val, t->l->lazy_type = 2;
    if (t->r) t->r->lazy = val, t->r->lazy_type = 2;
  }
  t->lazy = t->lazy_type = 0;
}
pair<pitem, pitem> split(pitem t, int key) {
  if (!t) return {NULL, NULL};
  push(t);
  if (t->key <= key) {
    pitem r;
    tie(t->r, r) = split(t->r, key);
    eval(t);
    return {t, r};
  }
  pitem l;
  tie(l, t->l) = split(t->l, key);
  eval(t);
  return {l, t};
}
pitem merge(pitem l, pitem r) {
  if (!l || !r) return l ? l : r;
  push(l), push(r);
  if (l->pr > r->pr) {
    l->r = merge(l->r, r);
    eval(l);
    return l;
  }
  r->l = merge(l, r->l);
  eval(r);
  return r;
}
void insert(pitem& t, int key, ll val) {
  auto [l, r] = split(t, key);
  t = merge(merge(l, new item(key, val)), r);
}
void upd(pitem& t, int a, int b, ll val, int type) {
  pitem l, r, mid;
  tie(l, r) = split(t, a - 1);
  tie(mid, r) = split(r, b);
  if (type == 2)
    mid->lazy = val, mid->lazy_type = 2;
  else
    mid->lazy += val, mid->lazy_type = max(mid->lazy_type, 1);
  t = merge(merge(l, mid), r);
}
ll query(pitem& t, int a, int b) {
  pitem l, r, mid;
  tie(l, r) = split(t, a - 1);
  tie(mid, r) = split(r, b);
  ll ans = sum(mid);
  t = merge(merge(l, mid), r);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  pitem treap = NULL;
  fore(i, 0, n) {
    ll t;
    cin >> t;
    insert(treap, i, t);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b;
      ll x;
      cin >> a >> b >> x;
      a--, b--;
      upd(treap, a, b, x, t);
    } else if (t == 2) {
      int a, b;
      ll x;
      cin >> a >> b >> x;
      a--, b--;
      upd(treap, a, b, x, t);
    } else {
      int a, b;
      cin >> a >> b;
      a--, b--;
      cout << query(treap, a, b) << "\n";
    }
  }
  return 0;
}
