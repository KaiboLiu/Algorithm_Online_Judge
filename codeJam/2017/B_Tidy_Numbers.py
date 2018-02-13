# https://code.google.com/codejam/contest/3264486/dashboard#s=p1

def pre(ch):
    return str((int(ch)-1)%10)

def tidy(s):
    if (len(s) < 2): return s
    l = len(s)
    isTidy = True
    for i in range(l-1):
        if s[i]>s[i+1]:
            isTidy = False
            s[i] = pre(s[i])
            for j in range(i+1,l): s[j] = '9'
            break

    if isTidy: return s
    else: return tidy(s)

t = int(input())  # read a line with a single integer
for ii in range(1, t + 1):
    s = input()
    #s = [st for st in input().split(" ")]  # read a list of integers, 2 in this case
    s_list, i = tidy(list(s)), 0
    while i < len(s) and s_list[i] == '0': i += 1
    res = ''.join(s_list[i:])

    print("Case #{}: {}".format(ii, res))
    # check out .format's specification for more formatting options