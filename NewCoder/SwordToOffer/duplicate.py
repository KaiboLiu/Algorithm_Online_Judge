# -*- coding:utf-8 -*-
'''
Challenge: duplicate
Total Acceptence: 27.35%
Developer: lrushx
Process Time: Apr 08, 2018
https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&tPage=3&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
'''


class Solution:
    # 这里要特别注意~找到任意重复的一个值并赋值到duplication[0]
    # 函数返回True/False
    def duplicate(self, numbers, duplication):
        if len(numbers) == 0:
            return False
        '''
        s = set()
        for x in numbers:
            if x in s: 
                duplication[0] = x
                return True
            s.add(x)
        return False
        
        '''
        n = len(numbers)
        for i in range(n):
            while numbers[numbers[i]]!=numbers[i]:
                j = numbers[i]
                numbers[i], numbers[j] = numbers[j], numbers[i]
        for i,x in enumerate(numbers):
            if i != x:
                duplication[0] = x
                return True
        return False


#l = [2,3,1,0,2,5,3]
l = [2,1,3,1,4]
s = Solution()
du = [-10]
if s.duplicate(l,du): print(du[0])

