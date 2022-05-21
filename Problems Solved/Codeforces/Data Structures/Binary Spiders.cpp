#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

const int MAXN = 3e5 + 7;

int sequence[MAXN];

struct vertex {
  vertex *l, *r;
  int bit, val, pos;
  vertex(int b) : bit(b) {
    l = r = NULL;
    val = pos = -1;
  }
};

class Trie {
 private:
  vertex* root;

 public:
  Trie() { root = new vertex(239); }

  void insert(int x, int pos, int v) {
    vertex* cur = root;
    for (int i = 29; i >= 0; i--) {
      if (x & (1 << i)) {
        if (cur->r == NULL) cur->r = new vertex(1);
        cur = cur->r;
      } else {
        if (cur->l == NULL) cur->l = new vertex(0);
        cur = cur->l;
      }
      if (cur->val < v) {
        cur->val = v;
        cur->pos = pos;
      }
    }
  }

  int calc(int x, int pos, int k) {
    vertex* cur = root;
    int ret = 0;
    for (int i = 29; i >= 0; i--) {
      int b1 = (x & (1 << i)) ? 1 : 0;
      int b2 = (k & (1 << i)) ? 1 : 0;
      if (b2 == 0) {
        if (b1 == 0 && cur->r != NULL) {
          if (ret < cur->r->val) {
            sequence[pos] = cur->r->pos;
            ret = cur->r->val;
          }
        } else if (b1 == 1 && cur->l != NULL) {
          if (ret < cur->l->val) {
            sequence[pos] = cur->l->pos;
            ret = cur->l->val;
          }
        }
      }
      vertex* newVertex = NULL;
      if (b2 == 0) {
        if (b1 == 0)
          newVertex = cur->l;
        else if (b1 == 1)
          newVertex = cur->r;
      } else {
        if (b1 == 0)
          newVertex = cur->r;
        else if (b1 == 1)
          newVertex = cur->l;
      }
      cur = newVertex;
      if (cur == NULL) break;
    }
    if (cur != NULL) {
      if (ret < cur->val) {
        ret = cur->val;
        sequence[pos] = cur->pos;
      }
    }
    return ret;
  }
};

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  set<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int b;
    scanf("%d", &b);
    a.insert({b, i});
  }

  if (k == 0) {
    printf("%d\n", n);
    for (int i = 0; i < n; i++) printf("%d%c", i + 1, " \n"[i == n - 1]);
  }

  else {
    int ans = 0, pos = 0;
    memset(sequence, -1, sizeof(sequence));
    Trie trie;

    for (auto [b, i] : a) {
      int v = trie.calc(b, i, k) + 1;
      if (ans < v) ans = v, pos = i;
      trie.insert(b, i, v);
    }

    if (ans < 2)
      printf("-1\n");
    else {
      printf("%d\n", ans);
      while (pos != -1) {
        printf("%d ", pos + 1);
        pos = sequence[pos];
      }
      printf("\n");
    }
  }

  return 0;
}

