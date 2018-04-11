# -*- coding:utf-8 -*-
'''
Challenge: hasPath.py
Total Acceptence: 22.44%
Developer: lrushx
Process Time: Apr 10, 2018
https://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc?tpId=13&tqId=11218&tPage=4&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
'''


# -*- coding:utf-8 -*-
class Solution:
    def hasPath(self, matrix, rows, cols, path):
        def doit(x,y,i):
            if i == l_path:
                return True
            for d in go:
                x1, y1 = x+d[0], y+d[1]
                if 0<=x1<rows and 0<=y1<cols and not visit[x1][y1] and matrix[x1*cols+y1] == path[i]:
                    visit[x1][y1] = True
                    if doit(x1,y1,i+1): return True
                    visit[x1][y1] = False
            return False
        
        l_path = len(path)
        if l_path == 0: return True
        if rows*cols < l_path: return False
        go = [(-1,0),(1,0),(0,1),(0,-1)]
        visit = [[False]* cols for i in range(rows)]
        res = []   
        for i in range(rows):
            for j in range(cols):
                if matrix[i*cols+j] == path[0]:
                    visit[i][j] = True
                    if doit(i,j,1): return True
                    visit[i][j] = False
        return False


matrix, rows,cols,path = "ABCESFCSADEE",3,4,"ABCCED"
s=Solution()
print(s.hasPath(matrix,rows,cols,path))
