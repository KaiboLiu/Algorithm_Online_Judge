//514_Freedom_Trail.py
//292ms  49.64%


/*
Total Accepted: 2219
Total Submissions: 6433
Instruction: LeetCode 514 - Freedom Trail - [H]
Developer: lrushx
Process Time: Apr 22, 2017
*/

/*
In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring", and use the dial to spell a specific keyword in order to open the door.

Given a string ring, which represents the code engraved on the outer ring and another string key, which represents the keyword needs to be spelled. You need to find the minimum number of steps in order to spell all the characters in the keyword.
Initially, the first character of the ring is aligned at 12:00 direction. You need to spell all the characters in the string key one by one by rotating the ring clockwise or anticlockwise to make each character of the string key aligned at 12:00 direction and then by pressing the center button. 
At the stage of rotating the ring to spell the key character key[i]:
You can rotate the ring clockwise or anticlockwise one place, which counts as 1 step. The final purpose of the rotation is to align one of the string ring's characters at the 12:00 direction, where this character must equal to the character key[i].
If the character key[i] has been aligned at the 12:00 direction, you need to press the center button to spell, which also counts as 1 step. After the pressing, you could begin to spell the next character in the key (next stage), otherwise, you've finished all the spelling.
*/

//给一个圆形拨盘带一个固定指针，圆盘每次转一格，盘上每格有字母，给一个字符串key，求拨盘逐个拨到key相应位置需要最少步数。
//"可等效为2个字符串key和ring，在逐个遍历key时找其在ring上的对应位置，要求每次到新位置走过的距离最小（此处ring的位置是首尾相连的）。

//dp，遍历key[i]，记录key[i]在dial上所有对应位置pos[i][1..k]，dp[i][j]表示key[i]指向dial[j]需要的最少步数，dp[i][j]=min{dp[i-1][pos[i-1][k]]+dist(pos[i-1][k],j)}
//注意避免python数组的shallow copy：mat=[list for i in range(10)],则这10行其实都是由list地址生成，改任意一个元素都会改变整列元素。


def dist(i,j,n):
    return min((n+i-j)%n,(n+j-i)%n)
        
        
class Solution(object):
    def findRotateSteps(self, ring, key):
        """
        :type ring: str
        :type key: str
        :rtype: int
        """
        len_r = len(ring)
        len_k = len(key)

        pos = [[] for i in range(26)]
        for i in range(len_r):
            pos[ord(ring[i])-ord('a')].append(i)
            
        dp = []
        dp = [[10000 for i in range(len_r)] for j in range(len_k)]

        tmp = ord(key[0])-ord('a')
        for p in pos[tmp]:
            dp[0][p] = dist(0,p,len_r)

        for i in range(1,len_k):
            tmp0 = ord(key[i])-ord('a')
            for j in pos[tmp0]:
                if (key[i] == ring[j]):
                    tmp = ord(key[i-1])-ord('a')
                    for p in pos[tmp]:
                        tmp2 = dp[i-1][p]+dist(p,j,len_r)
                        if tmp2 < dp[i][j]:
                            dp[i][j] = tmp2
                            
        tmp = ord(key[len_k-1])-ord('a')
        ans = 10000
        for p in pos[tmp]:
            if dp[len_k-1][p] < ans:
                ans = dp[len_k-1][p]
        ans = ans + len_k

        return ans
