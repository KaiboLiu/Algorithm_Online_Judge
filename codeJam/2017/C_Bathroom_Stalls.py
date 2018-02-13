# https://code.google.com/codejam/contest/3264486/dashboard#s=p2

# BFS (x)

t = int(input())  # read a line with a single integer
for ii in range(1, t + 1):
    n, k = [int(s) for s in input().split(" ")]  # read a list of integers, 2 in this case
    ''' 
    import math
    i = int(math.log(k,2))      # wrong due to precision
    m = 2**i
    '''
    k1, m = k, 1
    while k1 > 1:
        k1 >>= 1
        m <<= 1
    
    j = k - m   # k = 2^i+j = m+j
    level_sum = n-m+1
    v = level_sum // m
    n_big   = level_sum - v*m
    if j < n_big: v += 1
    l = (v-1)//2
    r = v-1-l
    l, r = max(l,r),min(l,r)
    
    print("Case #{}: {} {}".format(ii, l, r))
    # check out .format's specification for more formatting options