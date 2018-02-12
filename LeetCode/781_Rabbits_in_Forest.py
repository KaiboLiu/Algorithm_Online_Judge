## 781_Rabbits_in_Forest.py
## 62ms   ?%

'''
Total Accepted:1.6K
Total Submissions:3.4K
Instruction: LeetCode 781 - Rabbits in Forest - [M]
Developer: lrushx
Process Time: Feb 11, 2018
'''

'''
In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell you how many other rabbits have the same color as them. Those answers are placed in an array.
Return the minimum number of rabbits that could be in the forest.

Examples:
Input: answers = [1, 1, 2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit than answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.

Input: answers = [10, 10, 10]
Output: 11

Input: answers = []
Output: 0
'''

# if answer[i] =10 then this kind definitely has 11 members. If more than 11 answers is 10, there must be another color with 11 members.

class Solution:
    def numRabbits(self, answers):
        """
        :type answers: List[int]
        :rtype: int
        """
        s = {}
        for x in answers: 
            if x not in s: s[x] = 1
            else: s[x] += 1
        res = 0
        for x in s:
            while s[x] >0:
                res += (x+1)
                s[x] -= (x+1)
                
        return res

if __name__ == "__main__":
    c = Solution()
    
    print(c.numRabbits([1, 1, 2]))
    print(c.numRabbits([10, 10, 10]))
    print(c.numRabbits([]))
