# https://code.google.com/codejam/contest/3264486/dashboard#s=p1

'''




def calc(n,f={1:2}):
    if n in f: return f[n]
    f[n] = f[n-1]*9+10**(n-1)
    return f[n]
'''

def A_no_nine0(f,l):
    res = 0
    for i in range(f,l+1):
        if not check(i):
            res += 1
    return res

def check(n):
    if n%9 == 0 or '9' in str(n): return True
    else: return False

def A_nines_2(l):
    if l == 0: return 0
    s = str(l)
    n, first = len(s), int(s[0])
    if n == 1: return 2
    left = pre[n] if first == 9 else first*pre[n-1]
    right = A_nines_2(l - first * 10**(n-1))
    return left + right

def A_nines_1(l):
    if l < 9: return 0
    if l < 10: return 1
    tail = l % 10
    Nines = 0
    for i in range(l - tail, l): 
        if check(i): Nines += 1
    Nines += A_nines_2(l-tail)     
    return Nines

def A_no_nine(f,l):
    res_f = A_nines_1(f)
    res_l = A_nines_1(l)
    if res_f == 0: res_f = 1
    #print(f, l, res_f, res_l)
    return l - f + 1 - res_l + res_f
    #return l - f + 1 - A_nines_1(l) + A_nines_1(f)

    
pre = [0,2, 28, 352, 4168, 47512, 527608, 5748472, 61736248, 655626232, 
        6900636088, 72105724792, 748951523128, 7740563708152, 79665073373368, 
        816985660360312, 8352870943242808, 85175838489185272, 866582546402667448]
t = int(input())  # read a line with a single integer
for ii in range(1, t + 1):
    #s = input()
    #a, b = map(int,s.split(" "))
    #s = [st for st in input().split(" ")]  # read a list of integers, 2 in this case
    f, l = map(int,input().strip().split(" "))
    res = A_no_nine(f,l)
    #print(f,l)
    print("Case #{}: {}".format(ii, res))

    # check out .format's specification for more formatting options

