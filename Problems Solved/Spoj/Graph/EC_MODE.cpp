#include <bits/stdc++.h>
using namespace std;

#define forr(i, x, n) for (int i = (x); i < (int)(n); i++)
#define forR(i, x, n) for (int i = (x); i > (int)(n); i--)
typedef long double ld;
typedef pair<ld, ld> ii;

struct edge {
  int u;
  int v;
  ld w;
};

struct union_find {
  vector<int> p;
  vector<int> size;

  void init(int n) {
    p.resize(n);
    forr(i, 0, n) p[i] = i;
    size.resize(n, 1);
  }

  void unionSet(int u, int v) {
    int ru = findSet(u);
    int rv = findSet(v);

    if (size[ru] < size[rv]) {
      p[ru] = rv;
      size[rv] += size[ru];
    }

    else {
      p[rv] = ru;
      size[ru] += size[rv];
    }
  }

  int findSet(int i) {
    if (p[i] != i) p[i] = findSet(p[i]);
    return p[i];
  }
};

bool compare(edge a, edge b) { return (a.w < b.w); }

ld dist(ld x1, ld x2, ld y1, ld y2) {
  ld x = x1 - x2, y = y1 - y2;
  ld answer = (x * x) + (y * y);
  return sqrtl(answer);
}

void Kruskal(vector<edge> &edges, ld R, int W, ld U, ld V, int N) {
  sort(edges.begin(), edges.end(), compare);

  ld c1 = 0, c2 = 0;
  union_find uf;
  uf.init(N);
  forr(i, 0, edges.size()) {
    int u = edges[i].u, v = edges[i].v;
    ld w = edges[i].w;
    if (uf.findSet(u) != uf.findSet(v)) {
      uf.unionSet(u, v);
      if (w <= R)
        c1 += (w * U);
      else
        c2 += (w * V);
      N--;
    }
    if (N == W) break;
  }
  cout << fixed;
  cout << setprecision(3);
  cout << c1 << " " << c2 << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // N = number cities, T = number test cases, R = range of UTP,
  // W = number modems, U = unit price of UTP and
  // V = unit price of optical fiber
  int T, N, W;
  ld U, V, R;
  cin >> T;

  forr(k, 1, T + 1) {
    cin >> N >> R >> W >> U >> V;
    vector<ii> pos(N);
    vector<edge> edges;

    forr(i, 0, N) {
      ld x, y;
      cin >> x >> y;
      pos[i].first = x;
      pos[i].second = y;
    }

    forr(i, 0, N) {
      forr(j, i + 1, N) {
        ld w = dist(pos[i].first, pos[j].first, pos[i].second, pos[j].second);
        edges.push_back({i, j, w});
      }
    }
    cout << "Caso #" << k << ": ";
    Kruskal(edges, R, W, U, V, N);
  }

  return 0;
}
