# -*- coding: utf-8 -*-

#1_4.py
#CodeM Qualifying

'''
Instruction: CodeM - 1_4 送外卖
Developer: lrushx
Process Time: June 11, 2017
'''

'''
n 个小区排成一列，编号为从 0 到 n-1 。一开始，美团外卖员在第0号小区，目标为位于第 n-1 个小区的配送站。
给定两个整数数列 a[0]~a[n-1] 和 b[0]~b[n-1] ，在每个小区 i 里你有两种选择：
1) 选择a：向前 a[i] 个小区。
2) 选择b：向前 b[i] 个小区。

把每步的选择写成一个关于字符 ‘a’ 和 ‘b’ 的字符串。求到达小区n-1的方案中，字典序最小的字符串。如果做出某个选择时，你跳出了这n个小区的范围，则这个选择不合法。
• 当没有合法的选择序列时，输出 “No solution!”。
• 当字典序最小的字符串无限长时，输出 “Infinity!”。
• 否则，输出这个选择字符串。
'''

'''
算法：
1.先把输入数据a[i]和b[i]处理成i通过a、b路径能到的坐标
2.用b1[i]和b2[i]表示能通过a、b路径到达i的坐标，此处两个列表元素均为列表，因为可以有多个坐标通过a/b到i
3.从n-1坐标开始，利用b1和b2进行BFS，反向判断能否从0到达n-1，并且在此过程中用D数组确定是通过a路径还是b路径
BFS中，由当前位置找到的前一步坐标为pre，若D[pre]为0，则生成新的BFS状态；若由b1衍生出的前一步坐标pre，则D[pre]+=1；若由b2衍生出的前一步坐标pre，则D[pre]+=2；
4.完成BFS后从0开始根据D数组的指示生成最终路径
5.若D[0]==0则"No solution!"
6.若当前坐标为index，D[index]==1或者3，说明可以走a路径，则必走a路径，答案+"a"。但是在此过程中若遇到环(走到已经走过的点)，则说明这个环上肯定有通过b路径离开的位置，不需要找，答案直接是"Infinity!"
7.若当前坐标为index，D[index]==2，说明只能走b路径，则必走b路径，答案+"b"。
'''

import sys

if __name__ == "__main__":

    # 读取第一行的n
    n = int(sys.stdin.readline().strip())
    line = sys.stdin.readline().strip()
    # 把每一行的数字分隔后转化成int列表
    a = map(int, line.split())
    line = sys.stdin.readline().strip()
    # 把每一行的数字分隔后转化成int列表
    b = map(int, line.split())
    if n == 1:
        print ""
    else:
        for i in xrange(0,n):
            a[i] += i
            b[i] += i
            if a[i] >= n:
                a[i] = -1
            if b[i] >= n:
                b[i] = -1

        b1 = [[] for i in xrange(0,n)]
        b2 = [[] for i in xrange(0,n)]
        for i in xrange(0,n-1):
            if a[i] >= 0:
                b1[a[i]].append(i)
            if b[i] >= 0:
                b2[b[i]].append(i)
        #print b1
        #print b2

        BFS = [0] * n;
        D = [0] * n
        BFS[0] = n-1
        D[n-1] = 3          # D[i] is the direction for i to n-1, 1=a,2=b,3=a||b
        found = False
        l, r = -1 , 0;
        while (l < r):
            l += 1
            cur = BFS[l]
            for pre in b1[cur]:
                if (D[pre] == 0):
                    r += 1
                    BFS[r] = pre
                    D[pre] = 1
                elif (D[pre] == 2):    # pre to cur via path a
                    D[pre] += 1
            for pre in b2[cur]:
                if D[pre] == 0:
                    r += 1
                    BFS[r] = pre
                    D[pre] = 2
                elif D[pre] == 1:         # pre to cur via path b
                    D[pre] += 2

        if (D[0] == 0):
            print "No solution!"
        else:
            #print D
            res = ""
            count = [0] * n
            index = 0
            count[0] = 1
            while (index != n-1):
                if (D[index]%2 == 1):
                    res += "a"
                    index = a[index]
                    if count[index] > 0:
                        res = "Infinity!"
                        break
                    count[index] += 1
                elif (D[index] == 2):
                    res += "b"
                    index = b[index]
                    count[index] += 1
            print res

        #print range(0,n)
        #print a
        #print b
