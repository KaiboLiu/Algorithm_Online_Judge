//289_Game_of_Life.h
//0ms	100.00%

/*
Total Accepted: 44007
Total Submissions: 120446
Instruction: LeetCode 289 - Game of Life - [M]
Developer: lrushx
Process Time: May 05, 2017
*/


/*
Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
*/


//给一个矩阵，0/1表示是否存活，像扫雷一样满足一些和周边相关的条件就可以更新矩阵每个位置的值，但要求同时更新，输出下一时刻的矩阵
//因为元素为0/1并且给的是int矩阵，可以把周边统计结果加到元素的十位数上，根据十位数来更新个位数。
//注意角落位置即可

    void gameOfLife(vector<vector<int>>& board) {
        int h = board.size();
        if (h == 0) return;
        int w = board[0].size();
        if (w == 0) return;
        int i,j,m,count;
        int move[8][2]={{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{1,1},{1,-1},{-1,1}};
        for (i=0;i<h;i++)
            for (j=0;j<w;j+= (w==1?1:(w-1))){
                count = 0;
                for (m=0;m<8;m++)
                    if (i+move[m][0] >= 0 && i+move[m][0] < h && j+move[m][1] >= 0 && j+move[m][1] < w)
                    count += board[i+move[m][0]][j+move[m][1]] % 10;
                board[i][j] += count * 10;
            }
        for (j=1;j<w-1;j++)
            for (i=0;i<h;i+=(h==1?1:(h-1))){
                count = 0;
                for (m=0;m<8;m++)
                    if (i+move[m][0] >= 0 && i+move[m][0] < h && j+move[m][1] >= 0 && j+move[m][1] < w)
                    count += board[i+move[m][0]][j+move[m][1]] % 10;
                board[i][j] += count * 10;
            }
        for (i=1;i<h-1;i++)
            for (j=1;j<w-1;j++){
                count = 0;
                for (m=0;m<8;m++)
                    count += board[i+move[m][0]][j+move[m][1]] % 10;
                board[i][j] += count * 10;
            }
            //cout<<"kkk";
        for (i=0;i<h;i++)
            for (j=0;j<w;j++){
                count = board[i][j] / 10;
                if (count < 2 || count > 3) board[i][j] = 0;
                else if (count == 3) board[i][j] = 1;
                else board[i][j] = board[i][j] % 10;
            }
        return;
                
    }



