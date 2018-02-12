## 779_K-th_Symbol_in_Grammar.py
## 62ms   ?%

'''
Total Accepted:2.7K
Total Submissions:8.1K
Instruction: LeetCode 779 - K-th Symbol in Grammar - [M]
Developer: lrushx
Process Time: Feb 11, 2018
'''

'''
On the first row, we write a 0. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.
Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001
'''


class Solution:
    def kthGrammar(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: int
        """
        if N == 1: return 0
        if (K & 1) == 1:
            return self.kthGrammar(N-1, (K+1)//2)
        else:
            return 1-self.kthGrammar(N-1, (K+1)//2)
        

if __name__ == "__main__":
    c = Solution()
    
    print(c.kthGrammar(4,5))
    print(c.kthGrammar(1,1))
    print(c.kthGrammar(2,1))
    print(c.kthGrammar(2,2))