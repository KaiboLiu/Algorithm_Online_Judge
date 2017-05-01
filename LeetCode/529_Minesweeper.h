//529_Minesweeper.h
//6ms	100.00%

/*
Total Accepted: 5131
Total Submissions: 9907
Instruction: LeetCode 529 - Minesweeper - [M]
Developer: lrushx
Process Time: Apr 30, 2017
*/


/*
Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

If a mine ('M') is revealed, then the game is over - change it to 'X'.
If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.
Example 1:
Input: 

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]
*/


//模拟扫雷，如果点出的位置周边8格没有雷，则往这8格扩展自动点击，否则显示数字/显示炸雷
//没太巧妙的地方，按matrix判断，若为空则recursive做周边格
//注意小细节即可，两种方案，地图作为参数传递更新后返回，或者设个全局变量作为答案直接该，后者快一些。  



//////////////solution 1, answer as global variable, update directly
//////////////6ms	100.00%

    vector<vector<char>> ans;
    void updateBoard2(vector<int>& click,int h,int w) {
        int i = click[0], j = click[1],count = 0,k;
        if (ans[i][j] == 'M'){
            ans[i][j] = 'X';
            return;
        }
        
        if (ans[i][j] < '9') return;
        int move[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
        if (ans[i][j] == 'E'){
            for (k=0;k<8;k++)
                if (i+move[k][0] >= 0 && i+move[k][0] < h && j+move[k][1] >= 0 && j+move[k][1] < w && ans[i+move[k][0]][j+move[k][1]] == 'M')
                    count++;
            // assign number to this position
            if (count) {    
                ans[i][j] = '0' + count;
                return;
            }
        }
        // recursively reveal adjacent square
        ans[i][j] = 'B';
        for (k=0;k<8;k++)
            if (i+move[k][0] >= 0 && i+move[k][0] < h && j+move[k][1] >= 0 && j+move[k][1] < w && ans[i+move[k][0]][j+move[k][1]] == 'E'){
                vector<int> newclick;
                newclick.push_back(i+move[k][0]);
                newclick.push_back(j+move[k][1]);
                updateBoard2(newclick,h,w);
            }
        return;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        ans = board;
        int h = board.size();
        int w = board[0].size();
        updateBoard2(click,h,w);
        return ans;
    }
    


//////////////solution 2, board as parameter in function, need to return as final answer, influence some runtime
//////////////16ms  28.2%

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int h = board.size();
        int w = board[0].size();
        int i = click[0], j = click[1],count = 0,k;
        if (board[i][j] == 'M'){
            board[i][j] = 'X';
            return board;
        }
        
        if (board[i][j] < '9') return board;
        int move[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
        if (board[i][j] == 'E'){
            for (k=0;k<8;k++)
                if (i+move[k][0] >= 0 && i+move[k][0] < h && j+move[k][1] >= 0 && j+move[k][1] < w && board[i+move[k][0]][j+move[k][1]] == 'M')
                    count++;
            // assign number to this position
            if (count) {    
                board[i][j] = '0' + count;
                return board;
            }
        }
        // recursively reveal adjacent square
        board[i][j] = 'B';
        for (k=0;k<8;k++)
            if (i+move[k][0] >= 0 && i+move[k][0] < h && j+move[k][1] >= 0 && j+move[k][1] < w && board[i+move[k][0]][j+move[k][1]] == 'E'){
                vector<int> newclick;
                newclick.push_back(i+move[k][0]);
                newclick.push_back(j+move[k][1]);
                board = updateBoard(board,newclick);
            }
        return board;
    }