#include <cstdio>
using ll = long long;

int main() {
    int N; scanf("%d",&N);
    ll A[N];
    for(int i=0; i<N; i++) scanf("%lld",A+i);

    ll s=A[N-1], s_square=A[N-1]*A[N-1], cnt=1, ans=0;

    for(int i=N-2; i>=0; i--) {
        ans += s_square - 2 * A[i] * s + cnt * A[i] * A[i];
        
        s += A[i];
        s_square += A[i]*A[i];
        cnt++;
    }

    printf("%lld\n", ans);

    return 0;
}
