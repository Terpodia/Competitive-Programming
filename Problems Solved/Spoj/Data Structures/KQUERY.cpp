#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int aux;
void _scan(int &x){ aux=scanf("%d",&x); }
void _scan(long long &x){ aux=scanf("%lld",&x); }
void _scan(double &x){ aux=scanf("%lf",&x); }
void _scan(long double &x){ aux=scanf("%Lf",&x); }
void _scan(char &x){ aux=scanf(" %c",&x); }
void _scan(char *x){ aux=scanf("%s",x); }
template<typename T>
void _scan(vector<T> &v){
	for(int i=0; i<(int)v.size(); i++) _scan(v[i]);
}
void scan(){}
template<typename T, typename... U>
void scan(T& head, U&... tail) { _scan(head); scan(tail...); }
void setIO(string name=""){
  cin.tie(0)->sync_with_stdio(0);
  if((int)name.size()){
    freopen((name+".in").c_str(), "r", stdin);
    freopen((name+".out").c_str(), "w", stdout);
  }
  cout << fixed << setprecision(15);
}

template<typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef __uint128_t u128;
#define sz(x) (int)x.size()
#define FOR(i,x,n) for (int i=(x); i<(int)(n); i++) 
#define ROF(i,x,n) for (int i=(x); i>(int)(n); i--)
#define LSOne(x) (x) & (-x)

class FenwickTree{
  private:
    vector<int> ft;

    int rsq(int j){
      int ret=0;
      for(int i=j; i>0; i-=LSOne(i)){
        ret += ft[i];
      }
      return ret;
    }

  public:
    FenwickTree(){}
    FenwickTree(int n){
      ft=vector<int>(n+1,0);
    }
    void update(int j, int v){
      for(int i=j; i<sz(ft); i+=LSOne(i)){
        ft[i]+=v;
      } 
    }
    int rsq(int l, int r){
      return rsq(r)-rsq(l-1);
    }
};

struct querie{
  int l, r, k, pos;
  bool operator<(const querie& q) const {
    return k < q.k;
  }
};

int main(){
  int n; scan(n);
  vector<int> a(n); scan(a);
  int q; scan(q);
  querie queries[q];
  FOR(i,0,q){
    scan(queries[i].l, queries[i].r, queries[i].k);
    queries[i].pos=i;
  }
  sort(queries,queries+q);
  vector<pair<int,int>> st;
  FOR(i,0,n){
    st.push_back({a[i],i});
  }
  sort(st.begin(), st.end()); 
  FenwickTree ft(n);
  int ans[q];
  ROF(i,q-1,-1){
    while(!st.empty() && st.back().first > queries[i].k){
      ft.update(st.back().second+1, 1);
      st.pop_back();
    }
    ans[queries[i].pos]=ft.rsq(queries[i].l, queries[i].r);
  }
  FOR(i,0,q){
    printf("%d\n",ans[i]);
  }
  return 0;
}
// "Si puedes imaginarlo puedes programarlo" Alejandro Taboada
