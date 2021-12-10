#include <iostream>
using namespace std;

const int MAXN = 1e6+7;
int x, n, c[MAXN];

void setupSieve()
{
    c[1] = 1;

    for(int i=2; i<=MAXN; i++){
        if(c[i] == 0)
            for(int j = i; j <= MAXN; j+=i) c[j] = i;
    }
}

int main(void)
{
    setupSieve();

    scanf("%d",&n);

    while(n--){
        scanf("%d",&x);
        int ans = 1;

        while(x != 1){
            int d = c[x], cnt = 0;
            while(x % d == 0){
                x /= d;
                cnt++;
            }
            ans *= cnt+1;
        }

        printf("%d\n",ans);
    }

    return 0;
}