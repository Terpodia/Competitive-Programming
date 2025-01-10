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
typedef vector<int> vint;

vint sa, lcp; 
void build(string& s, int lim=256){ 
	int n = len(s) + 1, k = 0, a, b;
	vint x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
	sa = lcp = y, iota(all(sa), 0);
	for(int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
		p = j, iota(all(y), n - j);
		forn(i,n) if (sa[i] >= j) y[p++] = sa[i] - j;
		fill(all(ws), 0);
		forn(i,n) ws[x[i]]++;
		fore(i,1,lim) ws[i] += ws[i - 1];
		for(int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
		swap(x, y), p = 1, x[sa[0]] = 0;
		fore(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
			(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
	}
	fore(i,1,n) rank[sa[i]] = i;
	for(int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
		for(k && k--, j = sa[rank[i] - 1];
			s[i + k] == s[j + k]; k++);
}


int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	cin>>s;
	build(s);
	int idx=0, cnt=0;

	fore(i,1,len(s)+1){
		if(lcp[i] == 0) continue;
		if(lcp[i] > cnt) cnt = lcp[i], idx = i;
	}
	if(cnt == 0) cout << "-1\n";
	else{
		cout << s.substr(sa[idx], cnt) << "\n";
	}
	return 0;
}

