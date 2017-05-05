//498_Diagonal_Traverse.h
//

/*
Total Accepted: 6240
Total Submissions: 13506
Instruction: LeetCode 498 - Diagonal Traverse - [M]
Developer: lrushx
Process Time: May 04, 2017
*/


/*
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:
*/

//给一个矩阵，要求按照对角线顺序输出元素
//对角线有个特性是同一条对角线上元素的i,j相加都相等，找规律发现i+j为奇时向右上遍历，偶时向左下遍历，只要外循环遍历sum即可
//先开辟空间再赋值比一直push_back快多了


    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> a;
        int h = matrix.size();
        if (h == 0) return a;
        int w = matrix[0].size();
        if (w == 0) return a;
        vector<int> ans(h*w,0);
        int i,idsum,imin,imax,n=0;
        for (idsum=0;idsum<=(h+w-2);idsum++)
            if (idsum & 1) {
                imin = max(idsum-w+1,0);
                imax = min(h-1,idsum);
                for (i=imin;i<=imax;i++) ans[n++] = matrix[i][idsum-i];
                //for (i=imin;i<=imax;i++) ans.push_back(matrix[i][idsum-i]);
            }else{
                imin = max(idsum-h+1,0);
                imax = min(w-1,idsum);
                for (i=imin;i<=imax;i++) ans[n++] = matrix[idsum-i][i];                
                //for (i=imin;i<=imax;i++) ans.push_back(matrix[idsum-i][i]);                
            }
        return ans;
    }