#include <cstdio>

int main() {
    int b, k;
    scanf("%d%d",&b,&k);
    int d[k];
    for(int i=0; i<k; i++) scanf("%d",d+i);

    if(b%2 == 0)
        (d[k-1]%2==0)? puts("even") : puts("odd");

    else {
        int cnt=0;
        for(int i=0; i<k; i++)
            if(d[i]%2 != 0) cnt++;

        (cnt%2==0)? puts("even") : puts("odd");
    }

    return 0;
}
