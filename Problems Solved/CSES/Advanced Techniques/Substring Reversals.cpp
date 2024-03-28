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
  char val;
  bool rev;
  pitem l, r;
  item(char v) : pr(rand()), sz(1), val(v), rev(0), l(0), r(0) {}
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
int size(pitem t) { return t ? t->sz : 0; }
void eval(pitem t) {
  if (t) {
    t->sz = size(t->l) + size(t->r) + 1;
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
void print(pitem t) {
  if (!t) return;
  push(t);
  print(t->l);
  cout << t->val;
  print(t->r);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  pitem treap = NULL;
  fore(i, 0, n) {
    char c;
    cin >> c;
    auto [l, r] = split(treap, i);
    treap = merge(merge(l, new item(c)), r);
  }
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pitem l, r, mid;
    tie(l, r) = split(treap, b);
    tie(l, mid) = split(l, a - 1);
    mid->rev ^= true;
    treap = merge(merge(l, mid), r);
  }
  print(treap);
  cout << "\n";
  return 0;
}
