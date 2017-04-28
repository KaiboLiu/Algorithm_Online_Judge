//419_Battleships_in_a_Board.h
//3ms   100%

/*
Total Accepted: 20845
Total Submissions: 34051
Instruction: LeetCode 419 - Battleships in a Board - [M]
Developer: lrushx
Process Time: Apr 27, 2017
*/


/*
Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
*/

//给一个X和.组成的矩阵，相连的X表示一个ship，问一共有多少ship，ship之间不会相连，要求只用O(1)空间并且不改变原数组(不用染色)
//从坐上到右下遍历，若该位置为X并且←和↑都不是X，那么ans++，这样每个ship只被计数一次
//没啥要注意的，只是第一排第一列单独处理，免得处理边界条件


    int countBattleships(vector<vector<char>>& board) {
        int h = board.size();
        if (h == 0) return 0;
        int w = board[0].size();
        if (w == 0) return 0;
        int i,j,ans=0;
        if (board[0][0] == 'X') ans = 1;
        for (j=1;j<w;j++) 
            if (board[0][j] == 'X' && board[0][j-1] == '.') ans++;
        for (i=1;i<h;i++) 
            if (board[i][0] == 'X' && board[i-1][0] == '.') ans++;
        for (i=1;i<h;i++)
            for (j=1;j<w;j++)
                if (board[i][j] == 'X' && board[i-1][j] == '.' && board[i][j-1] == '.') ans++;
        return ans;
        
    }