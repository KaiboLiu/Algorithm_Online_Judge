# https://codejam.withgoogle.com/codejam/contest/4384486/dashboard#s=p2
# 乘法逆元

import sys
from collections import defaultdict
def POWER(N, K, x1, y1, C, D, E1, E2, F):
    a = (x1+y1) % F   # a[p]=(C+D)a[p-1]+E1+E2
    C += D
    E = E1 + E2
    coef = N
    s = K
    MOD = 1000000007
    res = (coef * a * s) % MOD
    list_a = [a]
    list_b = [res]
    def inv(a, p):
        a = a % p
        if a == 1: return 1
        return (p - p // a) * inv(p % a, p) % p

    def EXP(x, y):
        if y == 0:
            return 1
        elif y == 1:
            return x % MOD
        else:
            tmp = ((EXP(x, y//2) % MOD)**2) % MOD
            if y & 1:
                tmp = (tmp * x) % MOD
            return tmp

    for p in range(2, N+1):
        coef -= 1
        a = (C * a + E) % F
        #s = (s + (EXP(p,K+1)-p)//(p-1)) % MOD
        s = (s + (EXP(p,K+1)-p)*inv(p-1, MOD)) % MOD
        res = (res + coef * a * s) % MOD
        
    return res


t = int(input())  # read a line with a single integer
for ii in range(1, t + 1):
    N, K, x1, y1, C, D, E1, E2, F = map(int,input().strip().split(" "))
    res = POWER(N, K, x1, y1, C, D, E1, E2, F)
    print("Case #{}: {}".format(ii, res))