#include <bits/stdc++.h>
using namespace std;

#define fore(i, x, n) for (auto i = (x); i < (n); i++)
#define dbg(x) cerr << #x << "=" << x << " "
#define raya \
  cerr << "\n-----------------------------------------------------------\n"
typedef long long ll;

typedef struct item* pitem;
struct item {
  int key, pr;
  ll val, lazy_sum;
  pitem l, r;
  item(int k, ll v) : key(k), pr(rand()), val(v), lazy_sum(v), l(0), r(0) {}
};
ll sum(pitem t) { return (t) ? t->lazy_sum : 0; }
void eval(pitem t) {
  if (t) t->lazy_sum = sum(t->l) + sum(t->r) + t->val;
}
pair<pitem, pitem> split(pitem t, int key) {
  if (!t) return {NULL, NULL};
  pitem l, r;
  if (t->key <= key) {
    tie(t->r, r) = split(t->r, key);
    eval(t);
    return {t, r};
  }
  tie(l, t->l) = split(t->l, key);
  eval(t);
  return {l, t};
}
pitem merge(pitem l, pitem r) {
  if (!l || !r) return l ? l : r;
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
void erase(pitem& t, int key) {
  pitem l, r, mid;
  tie(l, r) = split(t, key);
  tie(l, mid) = split(l, key - 1);
  t = merge(l, r);
  delete mid;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pitem treap = NULL;
  int n, q;
  cin >> n >> q;
  fore(i, 0, n) {
    ll x;
    cin >> x;
    insert(treap, i, x);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int k;
      ll u;
      cin >> k >> u;
      k--;
      erase(treap, k);
      insert(treap, k, u);
    } else {
      int a, b;
      cin >> a >> b;
      a--, b--;
      pitem l, r, mid;
      tie(l, r) = split(treap, a - 1);
      tie(mid, r) = split(r, b);
      cout << sum(mid) << "\n";
      treap = merge(merge(l, mid), r);
    }
  }
  return 0;
}
