from decimal import *

getcontext().prec = 100

n = int(input())
r = list(map(int, input().split(' ')))

ans = Decimal(0)

for i in range(1, n):
    for j in range(1, r[i]+1):
        for k in range(0, i):
            if r[k] <= j: continue
            p = Decimal(r[k] - j) / Decimal(r[k])
            ans += p / Decimal(r[i])


print('{:.6f}'.format(round(ans, 6)))
