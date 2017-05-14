//576_Out_of_Boundary_Paths.h
//9ms	100.00%
//LeetCode Contest 31

/*
Total Accepted: 554
Total Submissions: 1765
Instruction: LeetCode 576 - Out of Boundary Paths - [H]
Developer: lrushx
Process Time: May 06, 2017
*/


/*
There is an m by n grid with a ball. Given the start coordinate (i,j) of the ball, you can move the ball to adjacent cell or cross the grid boundary in four directions (up, down, left, right). However, you can at most move N times. Find out the number of paths to move the ball out of grid boundary. The answer may be very large, return it after mod 109 + 7.

Example 1:
Input:m = 2, n = 2, N = 2, i = 0, j = 0
Output: 6
*/



//无障碍地图中给一个坐标，求n步(包含)之内走出地图边界的所有方案数，答案可能很大
//因为步数<=50，可以按照步数遍历即可避免重复，但是每个位置可以到多次，所以每一步由上一步可能到的位置引申，4个位置的方案数相加即可。
//要注意初始状态，起点处方案


    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) return 0;
        int move[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> map1(m,vector<int>(n,0));
        int a=i,b=j,k,res=0,MOD=1000000007,mo;
        map1[i][j] = 1;

        for (mo=0;mo<N;mo++){
            vector<vector<int>> map2(m,vector<int>(n,0));
            for (i=0;i<m;i++)
                for (j=0;j<n;j++)
                    if (map1[i][j] > 0)
                        for (k=0;k<4;k++)   
                            if (i+move[k][0] < 0 || i+move[k][0] == m || j+move[k][1] < 0 || j+move[k][1] ==n) res = (res + map1[i][j])%MOD;
                            else map2[i+move[k][0]][j+move[k][1]] = (map2[i+move[k][0]][j+move[k][1]] + map1[i][j]) % MOD;
            map1 = map2;
        }
        return res;
    }
