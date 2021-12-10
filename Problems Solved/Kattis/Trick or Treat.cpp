#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <complex>
using namespace std;

typedef long double ld;

const int MAXN = 5e4;
const ld INF = 1e8;

int n;
pair<ld,ld> p[MAXN];

ld f(ld x) {
    ld t=-INF;
    for (int i=0; i<n; i++) {
        t = max(t, sqrtl((x-(ld)p[i].first)*(x-(ld)p[i].first) + 
                   (p[i].second)*(p[i].second)));
    }
    return t;
}

ld calc() {
    ld l = -2e5-1, r = 2e5+1;
    for (int i=0; i<60; i++) {
        ld delta = (r-l)/3;
        ld m1 = l + delta, m2 = r - delta; 
        (f(m1) > f(m2)) ? l = m1 : r = m2;
    }

    return l;
}

int main() {
    do {
        aux=scanf("%d",&n);
        if(n == 0) continue;

        int aux;
        for (int i=0; i<n; i++) 
            aux=scanf("%Lf%Lf",&p[i].first,&p[i].second);  

        ld x = calc();
        printf("%Lf %Lf\n",x,f(x));

    } while (n != 0);

    return 0;
}

