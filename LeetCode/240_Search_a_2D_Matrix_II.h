//240_Search_a_2D_Matrix_II.h
//62ms	88.74%

/*
Total Accepted: 73172
Total Submissions: 191840
Instruction: LeetCode 240 - Search a 2D Matrix II - [M]
Developer: lrushx
Process Time: Sep 07, 2015
*/

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/



//给一个矩阵，从左到右升序并且从上到下升序，求其中是否有元素==target
//根据第一行最后一行来二分，确定可能有答案的列的范围[c1,c2]；再从第一列最后一列来二分，确定行的范围[r1,r2]，然后在这个范围能按行或者按列二分查找，每次缩短c2或者r2
//另一种方法特别巧妙，从右上角开始，若这个值偏大，则更小的数一定在左侧，j--；若偏小，则更大的一定在下方，i++，复杂度O(m+n)
//第二种方法是借鉴的，特别巧妙！



////solution1, several bisearch!
//92ms  28.15%

    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row = matrix.size();
        if (row == 0) return false;
        int column = matrix[0].size();
        if (column == 0) return false;
        int l=0,r=column-1,mid,c1,c2,r1,r2;

        //先在第一行找到比target小的最大值的列号
        while (l <= r){
            mid = l + (r - l) / 2;
            if (matrix[0][mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        if (r < 0) r = 0;
        if (matrix[0][r] == target) return true;
        c2 = r;
        
        l=0;r=column-1;
        //再在最后一行找到比target小的最大值的列号
        while (l <= r){
            mid = l + (r - l) / 2;
            if (matrix[row-1][mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        if (r < 0) {r = 0; c1 = 0; } else c1 = r+1;
        if (matrix[row-1][r] == target) return true;
        
        l=0;r=row-1;
        //再在第一列行找到比target小的最大值的列号
        while (l <= r){
            mid = l + (r - l) / 2;
            if (matrix[mid][0] > target) r = mid - 1;
            else l = mid + 1;
        }
        if (r < 0) r = 0;
        if (matrix[r][0] == target) return true;
        r2 = r;
        
        l=0;r=row-1;
        //再在最后一列找到比target小的最大值的列号
        while (l <= r){
            mid = l + (r - l) / 2;
            if (matrix[mid][column-1] > target) r = mid - 1;
            else l = mid + 1;
        }
        if (r < 0) {r = 0; r1 = 0; } else r1 = r+1;
        if (matrix[r][column-1] == target) return true;
        
        if (r2 - r1 > c2 - c1){
        for (int i=c1;i<=c2;i++){//从第c1列到第c2列依次二分查找
            //l=1;r=row-2;
            l=r1;r=r2;
            while (l <= r){
                mid = l + (r - l) / 2;
                if (matrix[mid][i] > target) r = mid - 1;
                else l = mid + 1;
            }
            if (r < 0) r = 0;
            if (matrix[r][i] == target) return true;
            r2 = r;
        }
        }else{
        for (int i=r1;i<=r2;i++){//从第c1列到第c2列依次二分查找
            //l=1;r=row-2;
            l=c1;r=c2;
            while (l <= r){
                mid = l + (r - l) / 2;
                if (matrix[i][mid] > target) r = mid - 1;
                else l = mid + 1;
            }
            if (r < 0) r = 0;
            if (matrix[i][r] == target) return true;
            c2 = r;
        }
        }
        return false;
        
    }
    
    
//solution2, good one!
//62ms	88.74%
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m=matrix.size(),n=m?matrix[0].size():0;
        if (m*n == 0) return false;
        int i=0,j=n-1;  //从右上角开始，若这个值偏大，则更小的数一定在左侧，j--；若偏小，则更大的一定在下方，i++
        while (i < m && j >= 0){
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) i++;
            else j--;
        }
        return false;
        
    }
