# -*- coding: utf-8 -*-

#1_1.py
#CodeM Qualifying

'''
Instruction: CodeM - 1_1 音乐研究
Developer: lrushx
Process Time: June 11, 2017
'''

#音乐研究
'''
在第二段音频中找到一个长度和第一段音频相等且是连续的子序列，使得它们的 difference 最小。两段等长音频的 difference 定义为：
difference = SUM(a[i] - b[i])2 (1 ≤ i ≤ n),其中SUM()表示求和
其中 n 表示序列长度，a[i], b[i]分别表示两段音频的音高。现在袋鼠先生想要知道，difference的最小值是多少？数据保证第一段音频的长度小于等于第二段音频的长度。
'''
import sys

def dist(a,b,d):
    dis = 0
    for i in range(len(a)):
        dis += (a[i]-b[i])**2
        if dis > d:
            return d
    return dis

if __name__ == "__main__":

    # 读取第一行的n
    n = int(sys.stdin.readline().strip())
    line = sys.stdin.readline().strip()
    # 把每一行的数字分隔后转化成int列表
    s = map(int, line.split())
    m = int(sys.stdin.readline().strip())
    line = sys.stdin.readline().strip()
    # 把每一行的数字分隔后转化成int列表
    t = map(int, line.split())


    ans = 2e9
    for p in range(0,m-n):
        t1 = t[p:p+n]
        #print len(s),len(t1)
        ans = min(ans,dist(s,t1,ans))
        if (ans == 0):
            break
    print ans
