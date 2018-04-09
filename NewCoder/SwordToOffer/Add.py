# -*- coding:utf-8 -*-
'''
Challenge: Add.py 
Total Acceptence: 45.09%
Developer: lrushx
Process Time: Apr 08, 2018
https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
'''


import sys
class Solution:
    def Add(self, num1, num2):
        while (num1 & num2) and num1 and num2:
            #a, b = num1, num2
            #num1, num2 = a^b, (a & b)<<1
            num1, num2 = num1^num2, (num1&num2)<<1
        return num1|num2

if __name__ == "__main__":
    if len(sys.argv) == 1:
        a,b = 10,12
    else: a,b = map(int,(sys.argv[1], sys.argv[2]))
    

    s = Solution()
    print(a,bin(a),b,bin(b),a^b,a&b)
    print(s.Add(a,b))

