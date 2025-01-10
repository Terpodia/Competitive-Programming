#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define fst first
#define snd second
#define pb push_back
#define len(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fore(i,a,b) for(auto i=a;i<b;i++)
#define forn(i, n) fore(i, 0, n)
#define dfor(i, n) for(auto i=n;i-->0;)
#define dbg(x) cerr << "LINE" $ __LINE__ <<":" $ #x << "=" << x << endl;
#define raya cerr << "\n-----------------------------------------------------------\n"
#define $ <<" "<<

template<typename T, typename U>
ostream &operator<<(ostream &os, const pair<T,U> &p){
  os << '(' << p.first $ p.second << ')';
  return os;
}
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &v){
  os << "[";
  forn(i, len(v)){
    if(i) os << ", ";
    os << v[i];
  }
  os << "]";
  return os;
}

typedef long long ll;

int rm[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int cm[] = { 1, -1, 1, -1, 2, -2, 2, -2 };
int cnt;
bool stop;
const int n=8;
bool vis[n][n];
int ans[n][n];

int val(int r, int c){
    int ret=0;
    forn(_,8){
	int i = rm[_]+r, j = cm[_]+c;
	if(i<0 || j<0 || i>=n || j>=n) continue;
	if(vis[i][j]);
	ret++;
    }
    return ret;
}

void solve(int r, int c){
    vis[r][c] = true;
    ans[r][c] = ++cnt;
    if(cnt == n*n){
	stop=true;
	return;
    }
    if(stop) return;
    vector<pair<int,int>> pos;
    forn(_,8){
	if(stop) return;
	int i = rm[_]+r, j = cm[_]+c;
	if(i<0 || j<0 || i>=n || j>=n) continue;
	if(vis[i][j]) continue;
	pos.pb(make_pair(val(i,j), _));
    }
    sort(all(pos));
    for(auto [__, _] : pos){
	if(stop) return;
	int i = rm[_]+r, j = cm[_]+c;
	solve(i,j);
    }
    if(stop) return;
    
    --cnt;
    ans[r][c]=-1;
    vis[r][c] = false;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int x, y;
  cin>>x>>y;
  x--, y--;
  memset(ans,-1,sizeof(ans));
  solve(y,x);
  forn(i,n){
    forn(j,n) cout<<ans[i][j]<<" ";
    cout<<"\n";
  }
  cout<<"\n";
  return 0;
}
