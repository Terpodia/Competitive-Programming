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

const int MAXN = 3e5;

struct state {
	int sz, link;
	ll cnt;
	map<char,int> nxt;
};

state st[MAXN];
ll dp[MAXN];
int last, N;
void sa_extend(char c){
	int cur = ++N;
	st[cur].sz = st[last].sz+1;
	st[cur].cnt = 1;
	int p = last;
	while(p != -1 && st[p].nxt.count(c) == 0){
		st[p].nxt[c] = cur;
		p = st[p].link;
	}
	if(p == -1) st[cur].link = 0;
	else{
		int q = st[p].nxt[c];
		if(st[q].sz == st[p].sz+1){
			st[cur].link = q;
		}
		else{
			int clone = ++N;
			st[clone].sz = st[p].sz+1;
			st[clone].cnt = 0;
			st[clone].nxt = st[q].nxt;
			st[clone].link = st[q].link;

			st[cur].link = clone;
			st[q].link = clone;

			while(p != -1 && st[p].nxt[c] == q){
				st[p].nxt[c] = clone;
				p = st[p].link;
			}
		}
	}
	last = cur;
}

ll compute_dp(int u){
	ll& ret=dp[u];
	if(ret != -1) return ret;
	ret = st[u].cnt;
	for(auto [c,v] : st[u].nxt){
		ret += compute_dp(v);
	}
	return ret;
}
void calc(){
	vector<int> states;
	forn(i,N+1) states.pb(i);
	sort(all(states), [](const int &i, const int &j){
		return st[i].sz > st[j].sz;
	});
	for(int i : states) if(st[i].link != -1){
		//dbg(st[i].cnt);
		st[st[i].link].cnt += st[i].cnt;
	}
	st[0].cnt = 0;

	memset(dp,-1,sizeof(dp));
	compute_dp(0);
}

void solve(int u, ll k, string& cur){
	k -= st[u].cnt;

	if(k <= 0) return;

	for(auto [c,v] : st[u].nxt){
		if(dp[v] >= k){
			cur += c;
			solve(v, k, cur);
			return;
		}
		k -= dp[v];
	}
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	ll k;
	cin>>s>>k;
	st[0].sz = st[0].cnt = 0;
	st[0].link = -1;
	for(char c : s){
		sa_extend(c);
	}
	calc();
	string ans="";
	solve(0,k,ans);
	cout << ans << "\n";
	return 0;
}

