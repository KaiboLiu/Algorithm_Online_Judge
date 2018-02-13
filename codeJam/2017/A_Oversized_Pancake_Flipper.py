# https://code.google.com/codejam/contest/3264486/dashboard#s=p0

# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Code Jam problems.
t = int(input())  # read a line with a single integer
for ii in range(1, t + 1):
    s, k = input().split(" ")
    #s = [st for st in input().split(" ")]  # read a list of integers, 2 in this case
    k, l, i, res = int(k), len(s), 0, 0

    a = [1 if x=='+' else 0 for x in s ]
    #print(k,l,s,a)
    while i <= l-k:
        while i <= l-k and a[i]&1: i += 1
        if i <= l-k:
            res += 1
            for j in range(k): a[i+j] += 1
    for i in range(l-k+1,l):
        if a[i]&1==0: 
            res = 'IMPOSSIBLE'
            break

    print("Case #{}: {}".format(ii, res))
    # check out .format's specification for more formatting options