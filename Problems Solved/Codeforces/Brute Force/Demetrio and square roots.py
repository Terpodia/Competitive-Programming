from decimal import *
import math

x, k = [int(x) for x in input().split()]

getcontext().prec = 520
y = str(Decimal.sqrt(Decimal(x)))

ans="" 
cnt=0 
flag=False
sqr=True

for x in y:
    if flag: cnt=cnt+1
    if x == '.': 
        flag=True 
        sqr=False

    if flag and k==0: break

    ans = ans + str(x)
    if cnt==k and flag: break

if sqr and k > 0:
    ans = ans + str('.')
    while cnt < k:
        ans = ans + str('0')
        cnt = cnt+1

print(ans)
