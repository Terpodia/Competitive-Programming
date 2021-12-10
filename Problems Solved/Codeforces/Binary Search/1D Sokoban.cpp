#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define sz(x) (int)x.size()

int n, m;
vector<int> a, b;

int calc(vector<int>& x, vector<int>& y) {
    int i=0, j=0, ret=0, cnt=0;

    while(j < sz(y)) {
        if(i<sz(x) && x[i] < y[j]) cnt++, i++;
        else {
            if(i<sz(x) && y[j] == x[i]) ret++, cnt++, i++, j++;
            else j++;

            if(cnt == 0) continue;

            int d = j - distance(y.begin(), lower_bound(y.begin(), y.end(), y[j-1]-cnt+1));

            ret = max(ret, d);
        }
    }

    return ret;
}

int solve() {
    vector<int> x1, y1, x2, y2;

    for(int i=0; i<n; i++)
        (a[i] > 0)? x1.push_back(a[i]) : x2.push_back(abs(a[i]));

    for(int i=0; i<m; i++)
        (b[i] > 0)? y1.push_back(b[i]) : y2.push_back(abs(b[i]));

    sort(x2.begin(), x2.end());
    sort(y2.begin(), y2.end());

    return calc(x1, y1) + calc(x2, y2);
}

int main() {
    int t; scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        a = vector<int>(n), b = vector<int>(m);

        for(int i=0; i<n; i++) scanf("%d",&a[i]);
        for(int i=0; i<m; i++) scanf("%d",&b[i]);

        printf("%d\n", solve());
    }

    return 0;
}

