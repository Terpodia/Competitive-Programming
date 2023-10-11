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
  int key, pr, sz;
  ll val, sum, lazy, cnt, lazy2;
  pitem l, r;
  item(int k, ll v)
      : key(k),
        pr(rand()),
        sz(1),
        val(v),
        sum(v),
        lazy(0),
        cnt(0),
        lazy2(0),
        l(0),
        r(0) {}
};
void push(pitem t);
int size(pitem t) { return t ? t->sz : 0; }
ll sum(pitem t) { return t ? push(t), t->sum : 0; }
void eval(pitem t) {
  if (t) {
    t->sz = size(t->l) + size(t->r) + 1;
    t->sum = sum(t->l) + sum(t->r) + t->val;
  }
}
void push(pitem t) {
  if (!t || !t->cnt) return;
  t->sum +=
      size(t) * t->lazy + t->cnt * ((ll)(size(t) * (ll)(size(t) - 1LL)) / 2);
  t->val += t->key * t->cnt + t->lazy2;
  if (t->l) t->l->cnt += t->cnt, t->l->lazy += t->lazy, t->l->lazy2 += t->lazy2;
  if (t->r) {
    ll s = t->key - size(t->l);
    t->r->cnt += t->cnt, t->r->lazy += t->lazy + (t->key - s + 1LL) * t->cnt,
        t->r->lazy2 += t->lazy2;
  }
  t->lazy = t->cnt = t->lazy2 = 0;
}
pair<pitem, pitem> split(pitem t, int key) {
  if (!t) return {NULL, NULL};
  push(t);
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
void upd(pitem& t, int a, int b) {
  pitem l, r, mid;
  tie(l, r) = split(t, a - 1);
  tie(mid, r) = split(r, b);
  mid->lazy++, mid->cnt++, mid->lazy2 += -1LL * a + 1;
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
    ll x;
    cin >> x;
    insert(treap, i, x);
  }
  while (q--) {
    int t, l, r;
    cin >> t >> l >> r;
    l--, r--;
    if (t == 1) {
      upd(treap, l, r);
    } else {
      cout << query(treap, l, r) << "\n";
    }
  }
  return 0;
}
