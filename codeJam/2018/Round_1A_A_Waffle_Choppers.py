# https://codejam.withgoogle.com/2018/challenges/0000000000007883/dashboard


t = int(input())  # read a line with a single integer
for ii in range(1, t + 1):
    n, k = [int(s) for s in input().split(" ")]  # read a list of integers, 2 in this case
   
    print("Case #{}: {} {}".format(ii, l, r))
    # check out .format's specification for more formatting options
