//542_01_Matrix.h
//206ms	96.88%

/*
Total Accepted: 4605
Total Submissions: 14193
Instruction: LeetCode 542 - 01 Matrix - [M]
Developer: lrushx
Process Time: Apr 30, 2017
*/


/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Input:
0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
*/


//给一个01矩阵，求每个位置到最近0的距离（上下、左右单位距离为1，不能斜走），确保至少一个0
//BFS，答案dist初始化为-1，先遍历一遍把0位置(i,j)的dist赋值为0，并且把所有0位置(i,j)记录下来bfs[++end]=i*w+j,其中end为已记录中间态数量。
//start从-1开始循环，每次++，读取中间态bfs值，恢复成已经确定dist的(i,j)，再向4个方向扩展，
//如果邻位置dist<0，说明还未遍历过并且到了最小距离（由当前i,j可以加一步到达），则可以更新这个邻位的dist并加入到中间态bfs[++end]中，直到start=end
//时隔多年又自己想起来了BFS，runtime还不错


    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int h = matrix.size();
        if (h < 1) return matrix;
        int w = matrix[0].size();
        if (w < 1) return matrix;
        
        int i,j,address,start=-1,end=-1;
        vector<vector<int> > dist(h,vector<int> (w,-1));
        int bfs[h*w];
        memset(bfs,0,h*w*sizeof(int));
        
        for (i=0;i<h;i++)
            for (j=0;j<w;j++)
                if (matrix[i][j] == 0){
                    bfs[++end] = i*w + j;
                    dist[i][j] = 0;
                }
        while (start < end){
            address = bfs[++start];
            i = address / w;
            j = address % w;
            if (i-1 >= 0 && dist[i-1][j] < 0){
                dist[i-1][j] = dist[i][j] + 1;
                bfs[++end] = address - w;
            }
            if (i+1 < h && dist[i+1][j] < 0){
                dist[i+1][j] = dist[i][j] + 1;
                bfs[++end] = address + w;
            }
            if (j-1 >= 0 && dist[i][j-1] < 0){
                dist[i][j-1] = dist[i][j] + 1;
                bfs[++end] = address - 1;
            }
            if (j+1 < w && dist[i][j+1] < 0){
                dist[i][j+1] = dist[i][j] + 1;
                bfs[++end] = address + 1;
            }
        }
        return dist;
        
    }