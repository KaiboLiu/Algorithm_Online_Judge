//573_Squirrel_Simulation.h
//19ms	100.00%

/*
Instruction: LeetCode 573 - Squirrel Simulation - [M]
Developer: lrushx
Process Time: May 06, 2017
*/


/*
There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.

Example 1:
Input: 
Height : 5
Width : 7
Tree position : [2,2]
Squirrel : [4,4]
Nuts : [[3,0], [2,5]]
Output: 12

Note:
All given positions won't overlap.
The squirrel can take at most one nut at one time.
The given positions of nuts have no order.
Height and width are positive integers. 3 <= height * width <= 10,000.
The given positions contain at least one nut, only one tree and one squirrel.
*/


//LeetCode Contest 30
//地图中给一个树，一个松鼠和n个坚果，要求松鼠从起点出发每次拿一个坚果到树处，求一共多少步把坚果全部集齐
//先算每个坚果到树的距离，×2表示往返距离，然后比较松鼠到每个坚果的距离，找个最优的距离替换该坚果到树的一趟距离。最优指的是dist(松鼠,坚果[i])-dist(松树,坚果[i])最小。比较时要注意这个差可以为负数



    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int i,dist=0;
        int dist_nut,tmp,n_nut=nuts.size(),save=INT_MIN;
        for (i = 0;i<n_nut;i++)
        {
            dist_nut = abs(nuts[i][0]-tree[0]) + abs(nuts[i][1]-tree[1]);
            dist += 2*dist_nut;
            tmp = dist_nut - (abs(nuts[i][0]-squirrel[0]) + abs(nuts[i][1]-squirrel[1]));
            if (tmp > save) save = tmp;
        }
        return dist-save;
    }