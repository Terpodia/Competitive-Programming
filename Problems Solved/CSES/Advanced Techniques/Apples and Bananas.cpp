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

typedef complex<double> C;
typedef vector<double> vd;
typedef vector<int> vi;
void fft(vector<C>& a) {
	int n = len(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		fore(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	fore(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	fore(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) fore(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(len(a) + len(b) - 1);
	int L = 32 - __builtin_clz(len(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	fore(i,0,len(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	fore(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	fore(i,0,len(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int k,n,m;
	cin>>k>>n>>m;
	vd a(k+1,0), b(k+1,0);
	forn(i,n){
		int w;
		cin>>w;
		a[w]++;
	}
	forn(i,m){
		int w;
		cin>>w;
		b[w]++;
	}
	vd res = conv(a,b);
	fore(i,2,2*k+1){
		ll cnt = roundl(res[i]);
		cout << cnt << " ";
	}
	cout<<"\n";
	return 0;
}
