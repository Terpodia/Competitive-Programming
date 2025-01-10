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

vector<int> z_function(string& s){
	int l=0,r=0;
	vector<int> z(len(s),0);
	fore(i,1,len(s)){
		if(i<r)z[i]=min(z[i-l],r-i);
		while(z[i]+i<len(s) && s[z[i]]==s[z[i]+i])z[i]++;
		if(i+z[i]>r)l=i, r=i+z[i];
	}
	return z;
}
vector<int> prefix_function(string& s){
	vector<int> b(len(s)+1,-1);
	int j=-1;
	fore(i,0,len(s)){
		while(j>-1 && s[i]!=s[j])j=b[j];
		b[i+1]=++j;
	}
	return b;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	cin>>s;
	vector<int> z = z_function(s);
	vector<int> p = prefix_function(s);

	for(int i : z) cout << i << " ";
	cout << "\n";
	fore(i,1,len(s)+1) cout << p[i] << " ";
	cout << "\n";
	return 0;
}

