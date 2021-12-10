#include <cstdio>

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        scanf("%d",&n);
        int a[n];
        for(int i=0; i<n; i++) scanf("%d",a+i);

        long long odd, even; odd = even = 0;
        for(int i=0; i<n; i++)
            (i%2 == 0)? odd += (long long)a[i] : even += (long long)a[i];

        if(odd > even) {
            for(int i=0; i<n; i++)
                (i%2 == 0)? printf("%d%c",a[i]," \n"[i==n-1]) : printf("1%c", " \n"[i==n-1]);
        }

        else {
            for(int i=0; i<n; i++)
                (i%2 == 1)? printf("%d%c",a[i]," \n"[i==n-1]) : printf("1%c", " \n"[i==n-1]);
        }
    }

    return 0;
}

