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

struct UnionFind {
	int n,comp;
	vector<int> uf,si,c;
	UnionFind(int n=0):n(n),comp(n),uf(n),si(n,1){
		fore(i,0,n)uf[i]=i;}
	int find(int x){return x==uf[x]?x:find(uf[x]);}
	bool join(int x, int y){
		if((x=find(x))==(y=find(y)))return false;
		if(si[x]<si[y])swap(x,y);
		si[x]+=si[y];uf[y]=x;comp--;c.pb(y);
		return true;
	}
	int snap(){return c.size();}
	void rollback(int snap){
		while(c.size()>snap){
			int x=c.back();c.pop_back();
			si[uf[x]]-=si[x];uf[x]=x;comp++;
		}
	}
};
enum {ADD,DEL,QUERY};
struct Query {int type,x,y;};
struct DynCon {
	vector<Query> q;
	UnionFind dsu;
	vector<int> mt;
	map<pair<int,int>,int> last;
	DynCon(int n):dsu(n){}
	void add(int x, int y){
		if(x>y)swap(x,y);
		q.pb((Query){ADD,x,y});mt.pb(-1);last[{x,y}]=q.size()-1;
	}
	void remove(int x, int y){
		if(x>y)swap(x,y);
		q.pb((Query){DEL,x,y});
		int pr=last[{x,y}];mt[pr]=q.size()-1;mt.pb(pr);
	}
	void query(){q.pb((Query){QUERY,-1,-1});mt.pb(-1);}
	void process(){ // answers all queries in order
		if(!q.size())return;
		fore(i,0,q.size())if(q[i].type==ADD&&mt[i]<0)mt[i]=q.size();
		go(0,q.size());
	}
	void go(int s, int e){
		if(s+1==e){
			if(q[s].type==QUERY) // answer query using DSU
				cout << dsu.comp << " ";
			return;
		}
		int k=dsu.snap(),m=(s+e)/2;
		for(int i=e-1;i>=m;--i)if(mt[i]>=0&&mt[i]<s)dsu.join(q[i].x,q[i].y);
		go(s,m);dsu.rollback(k);
		for(int i=m-1;i>=s;--i)if(mt[i]>=e)dsu.join(q[i].x,q[i].y);
		go(m,e);dsu.rollback(k);
	}
};

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    DynCon d(n);
    forn(i,m){
        int u,v;
        cin>>u>>v;
        u--,v--;
        d.add(u, v);
    }
    d.query();
    forn(i,k){
        int t,u,v;
        cin>>t>>u>>v;
        u--,v--;
        if(t==1) d.add(u,v);
        else d.remove(u,v);
        d.query();
    }
    d.process();
    cout<<"\n";
	return 0;
}
