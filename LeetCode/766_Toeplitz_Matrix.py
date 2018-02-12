## 766_Toeplitz_Matrix.py
## 3ms   100.00%

'''
Total Accepted:8.2K
Total Submissions:13.9K
Instruction: LeetCode 766 - Toeplitz Matrix - [E]
Developer: lrushx
Process Time: Feb 11, 2018
'''

'''
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.
Now given an M x N matrix, return True if and only if the matrix is Toeplitz.
'''


class Solution:
    def isToeplitzMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: bool
        """
        return all(matrix[i][j] == matrix[i+1][j+1] for i in range(len(matrix)-1) for j in range(len(matrix[0])-1))
        '''
        M, N = len(matrix), len(matrix[0])

        for i in range(M-1):
            j_max = min(M-i,N)
            for d in range(1,j_max):
                if matrix[i][0] != matrix[i+d][d]: return False
        for j in range(1,N-1):
            i_max = min(M,N-j)
            for d in range(1,i_max):
                if matrix[0][j] != matrix[d][j+d]: return False
        return True
        '''


if __name__ == "__main__":
    c = Solution()
    
    s = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
    print(c.isToeplitzMatrix(s))
    s = [[1,2],[2,2]]
    print(c.isToeplitzMatrix(s))
    s = [[1]]
    print(c.isToeplitzMatrix(s))