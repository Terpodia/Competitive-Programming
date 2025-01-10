#include "bits/stdc++.h"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

typedef vector<int> vi;

const int INF = 1e9;

void Hungarian(int n, int m, vector<vi> &A){
    vi u(n+1), v(m+1), p(m+1), way(m+1);
    fore(i,1,n+1){
        p[0] = i;
        int j0 = 0;
        vi minv(m+1, INF);
        vector<bool> used(m+1, false);
        do {
            used[j0] = true;
            int i0 = p[j0],  delta = INF,  j1;
            fore(j,1,m+1) if(!used[j]) {
                int cur = A[i0][j]-u[i0]-v[j];
                if(cur < minv[j]) minv[j] = cur,  way[j] = j0;
                if(minv[j] < delta) delta = minv[j],  j1 = j;
            }
            fore(j,0,m+1){
                if(used[j]) u[p[j]] += delta,  v[j] -= delta;
                else minv[j] -= delta;
            }
            j0 = j1;
        } while(p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while(j0);
    }
    cout << -v[0] << "\n";
    fore(j,1,m+1){
        cout << p[j] << " " << j << "\n";
    }
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    vector<vi> A(n+1, vi(n+1));
    fore(i,1,n+1) fore(j,1,n+1) cin>>A[i][j];
    Hungarian(n,n,A);
	return 0;
}
