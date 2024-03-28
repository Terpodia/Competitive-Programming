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
  int pr, sz;
  char val;
  pitem l, r;
  item(char v) : pr(rand()), sz(1), val(v), l(0), r(0) {}
};
int size(pitem t) { return t ? t->sz : 0; }
void eval(pitem t) {
  if (t) {
    t->sz = size(t->l) + size(t->r) + 1;
  }
}
pair<pitem, pitem> split(pitem t, int key) {
  if (!t) return {NULL, NULL};
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
  if (l->pr > r->pr) {
    l->r = merge(l->r, r);
    eval(l);
    return l;
  }
  r->l = merge(l, r->l);
  eval(r);
  return r;
}
void insert(pitem& t, int key, char val) {
  auto [l, r] = split(t, key);
  t = merge(merge(l, new item(val)), r);
}
void print(pitem t) {
  if (!t) return;
  print(t->l);
  cout << t->val;
  print(t->r);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  pitem treap = NULL;
  fore(i, 0, n) { insert(treap, i, s[i]); }
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pitem l, r, mid;
    tie(l, r) = split(treap, a - 1);
    tie(mid, r) = split(r, b - a);
    treap = merge(merge(l, r), mid);
  }
  print(treap);
  cout << "\n";
  return 0;
}
