#include <iostream>
using namespace std;

#define sz(x) (int)x.size()
#define forn(i,x,n) for(int i=(x); i<(int)n; i++)

int main() {
    int t; scanf("%d",&t);

    while(t--) {
        int c,d; scanf("%d%d",&c,&d);
        if(c == d) 
            (c == 0)? puts("0") : puts("1");
        
        else if(abs(c - d) % 2 == 0) puts("2");
        
        else puts("-1");
    }

    return 0;
}

