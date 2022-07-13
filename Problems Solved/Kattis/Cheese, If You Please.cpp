// -Si puedes imaginarlo, puedes programarlo- Alejandro Taboada
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define fst first
#define snd second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i, x, n) \
	for (__typeof(n) i = (x); i != (n); i += 1 - 2 * ((x) > (n)))
#define dbg(x) cout << #x << "=" << x << " ";
#define line cout << "\n............................................\n";

const double EPS = 1e-9;

namespace Simplex {
vector<int> X, Y;
vector<vector<double>> A;
vector<double> b, c;
double z;
int n, m;
void pivot(int x, int y) {
	swap(X[y], Y[x]);
	b[x] /= A[x][y];
	rep(i, 0, m) if (i != y) A[x][i] /= A[x][y];
	A[x][y] = 1 / A[x][y];
	rep(i, 0, n) if (i != x && abs(A[i][y]) > EPS) {
		b[i] -= A[i][y] * b[x];
		rep(j, 0, m) if (j != y) A[i][j] -= A[i][y] * A[x][j];
		A[i][y] = -A[i][y] * A[x][y];
	}
	z += c[y] * b[x];
	rep(i, 0, m) if (i != y) c[i] -= c[y] * A[x][i];
	c[y] = -c[y] * A[x][y];
}
pair<double, vector<double>> simplex(  // maximize c^T x s.t. Ax<=b, x>=0
    vector<vector<double>> _A, vector<double> _b, vector<double> _c) {
	// returns pair (maximum value, solution vector)
	A = _A;
	b = _b;
	c = _c;
	n = (int)b.size();
	m = (int)c.size();
	z = 0.;
	X = vector<int>(m);
	Y = vector<int>(n);
	rep(i, 0, m) X[i] = i;
	rep(i, 0, n) Y[i] = i + m;
	while (1) {
		int x = -1, y = -1;
		double mn = -EPS;
		rep(i, 0, n) if (b[i] < mn) mn = b[i], x = i;
		if (x < 0) break;
		rep(i, 0, m) if (A[x][i] < -EPS) {
			y = i;
			break;
		}
		assert(y >= 0);	 // no solution to Ax<=b
		pivot(x, y);
	}
	while (1) {
		double mx = EPS;
		int x = -1, y = -1;
		rep(i, 0, m) if (c[i] > mx) mx = c[i], y = i;
		if (y < 0) break;
		double mn = 1e200;
		rep(i, 0, n) if (A[i][y] > EPS && b[i] / A[i][y] < mn) mn =
		    b[i] / A[i][y],
								       x = i;
		assert(x >= 0);	 // c^T x is unbounded
		pivot(x, y);
	}
	vector<double> r(m);
	rep(i, 0, n) if (Y[i] < m) r[Y[i]] = b[i];
	return {z, r};
}
}  // namespace Simplex

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	double w[n], p[m][n], t[m];
	rep(i, 0, n) scanf("%lf", &w[i]);
	rep(i, 0, m) {
		rep(j, 0, n) scanf("%lf", &p[i][j]);
		scanf("%lf", &t[i]);
	}
	vector<vector<double>> A(n, vector<double>(m));
	vector<double> b, c;

	rep(i, 0, m) c.pb(t[i]);
	rep(i, 0, n) b.pb(w[i]);
	rep(i, 0, n) { rep(j, 0, m) A[i][j] = p[j][i] / 100.0; }
	double ans = Simplex::simplex(A, b, c).fst;
	printf("%.2lf\n", ans);
	return 0;
}

