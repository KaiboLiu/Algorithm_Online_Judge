//463_Island_Perimeter.h
//95ms	97.85%

/*
Total Accepted: 36039
Total Submissions: 63427
Instruction: LeetCode 463 - Island Perimeter - [E]
Developer: lrushx
Process Time: Apr 27, 2017
*/


/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
Answer: 16
*/

//给一个由0,1组成的矩阵，1表示岛，0表示水，所有岛都连在一起并且没有湖，求岛周长
//从坐上到右下遍历，计算1的个数n(岛的数量)和相邻对数c(若该位置为1并且←和↑都是1，那么c++)，周长为4n-2c(2c为岛中间非边长的边数)
//没啥要注意的，只是第一排第一列单独处理，免得处理边界条件


    int islandPerimeter(vector<vector<int>>& grid) {
        int h = grid.size();
        if (h == 0) return 0;
        int w = grid[0].size();
        if (w == 0) return 0;
        int i,j,count=grid[0][0],connect=0;
        for (i=1;i<h;i++) 
            if (grid[i][0]){
                count++;
                connect += grid[i-1][0];
            }
        for (j=1;j<w;j++)
            if (grid[0][j]) {
                count++;
                connect += grid[0][j-1];
            }
            
        for (i=1;i<h;i++)
            for (j=1;j<w;j++)
                if (grid[i][j]) {
                    count++;
                    connect += grid[i-1][j]+grid[i][j-1];
                }
        return count*4-connect-connect;
        
    }