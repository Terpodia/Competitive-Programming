from decimal import *

def calc_dp():
    C = [[0 for x in range(501)] for x in range(501)]

    for i in range(501):
        for j in range(min(i, 500)+1):
            if i == j or j == 0: C[i][j] = 1
            else: C[i][j] = C[i-1][j-1] + C[i-1][j]

    return C

n, m, k = [int(x) for x in input().split()]

dp = calc_dp()

num=0
for i in range(m, n-k+1):
    num = num + dp[n][i]

den=2**n

getcontext().prec = 50

print(Decimal(num) / Decimal(den))
