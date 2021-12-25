#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int aux;

typedef long long ll;

#define FOR(i,x,n) for(int i=(x); i<(int)(n); i++)
#define sz(x) (int)x.size()

struct event {
  int pos, id;
  ll val;

  bool operator<(const event& e) {
    if (pos != e.pos) return pos < e.pos;
    return id > e.id;
  }
};

const int MAX = 2e5+7, INF = 2e9;

int K, M, N;

pair<int,ll> p[MAX];
int f[MAX];

ll sweep_line(vector<event>& e) {
  sort(e.begin(), e.end());
  ll ret=0, acc=0;

  for (event ev : e) {
    if (ev.id == 0) acc += ev.val;
    else acc -= ev.val;

    ret = max(ret, acc);
  }

  return ret;
}

void calc(vector<ll>& a) {
  ll acc=0;
  int i=0, j=0;

  while (i < K && p[i].first < f[j]) acc += p[i++].second;
  
  if (acc > 0) a.push_back(acc);
  acc = 0;
  j++;

  while (i < K) {
    vector<event> e;

    while (i < K && p[i].first < f[j]) {
      int d = min(f[j] - p[i].first, p[i].first - f[j-1]);
      e.push_back({p[i].first - d, 0, p[i].second});
      e.push_back({p[i].first + d, 1, p[i].second});
      acc += p[i].second;
      i++;
    }

    if (!e.empty()) {
      ll v = sweep_line(e);
      a.push_back(v);
      a.push_back(acc - v);
    }

    acc=0;
    j++;
  }
}

void solve() {
  vector<ll> a;
  ll ans=0;

  calc(a);

  sort(a.begin(), a.end(), greater<ll>());
  for (int i=0; i<sz(a) && i<N; i++) {
    ans += a[i]; 
  }

  printf("%lld\n", ans);
}

int main() {
  aux=scanf("%d%d%d",&K,&M,&N);
  FOR(i,0,K) aux=scanf("%d%lld",&p[i].first, &p[i].second); 
  FOR(i,0,M) aux=scanf("%d",f+i);

  f[M] = INF;

  sort(p, p+K);
  sort(f, f+(M+1));

  solve();

  return 0;
}

