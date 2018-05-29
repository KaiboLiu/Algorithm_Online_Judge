# https://code.google.com/codejam/contest/3264486/dashboard#s=p1



def B_bit_small(n,k,p,A):
    # ai == bi
    res = ['*']*n
    A.sort()
    for a,b,c in A:
        res[a-1] = '1' if c == 1 else '0'
    unknow = res.count('*')
    if unknow == 0: return ''.join(res)
    s = bin(p-1)[2:]
    #print(res, s, n, len(s), unknow)
    pos = n-1
    for c in s[::-1]:
        #while pos > 0 and res[pos] != '*': pos -= 1
        while res[pos] != '*': pos -= 1
        res[pos] = c
    res = ''.join(res)
    return res.replace('*','0')


t = int(input())  # read a line with a single integer
for ii in range(1, t + 1):
    #s = input()
    #a, b = map(int,s.split(" "))
    #s = [st for st in input().split(" ")]  # read a list of integers, 2 in this case
    n,k,p = map(int,input().strip().split(" "))
    A = []
    for i in range(k):
        A.append(tuple(map(int,input().strip().split(" "))))
    #print(n,k,p,A)
    res = B_bit_small(n,k,p,A)
    #print(f,l)

    print("Case #{}: {}".format(ii, res))

    # check out .format's specification for more formatting options

