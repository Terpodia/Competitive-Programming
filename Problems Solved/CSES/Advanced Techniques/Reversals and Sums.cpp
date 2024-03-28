#include <bits/stdc++.h>
using namespace std;

#define SZ(x) (int)x.size()
#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
typedef long long ll;

typedef struct item *pitem;

struct item {
  int pr, sz;
  ll val, sum;
  bool rev;
  pitem l, r;
  item(ll v) : pr(rand()), sz(1), val(v), sum(v), rev(0), l(0), r(0) {}
};
void push(pitem t) {
  if (!t) return;
  if (t->rev) {
    swap(t->l, t->r);
    if (t->l) t->l->rev ^= t->rev;
    if (t->r) t->r->rev ^= t->rev;
    t->rev = false;
  }
}
ll sum(pitem t) { return t ? t->sum : 0; }
int size(pitem t) { return t ? t->sz : 0; }
void eval(pitem t) {
  if (t) {
    t->sz = size(t->l) + size(t->r) + 1;
    t->sum = sum(t->l) + sum(t->r) + t->val;
  }
}
pair<pitem, pitem> split(pitem t, int key) {
  if (!t) return {NULL, NULL};
  push(t);
  int cur_key = size(t->l);
  if (cur_key <= key) {
    pitem r;
    tie(t->r, r) = split(t->r, key - cur_key - 1);
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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  pitem treap = NULL;
  fore(i, 0, n) {
    ll x;
    cin >> x;
    auto [l, r] = split(treap, i);
    treap = merge(merge(l, new item(x)), r);
  }
  while (m--) {
    int t, a, b;
    cin >> t >> a >> b;
    a--, b--;
    pitem l, r, mid;
    tie(l, r) = split(treap, b);
    tie(l, mid) = split(l, a - 1);
    if (t == 1)
      mid->rev ^= true;
    else
      cout << sum(mid) << "\n";
    treap = merge(merge(l, mid), r);
  }
  return 0;
}
