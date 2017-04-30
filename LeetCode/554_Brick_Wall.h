//554_Brick_Wall.h
//39ms	97.70%

/*
Total Accepted: 3815
Total Submissions: 9162
Instruction: LeetCode 554 - Brick Wall - [M]
Developer: lrushx
Process Time: Apr 30, 2017
*/


/*
There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The bricks have the same height but different width. You want to draw a vertical line from the top to the bottom and cross the least bricks.
The brick wall is represented by a list of rows. Each row is a list of integers representing the width of each brick in this row from left to right.
If your line go through the edge of a brick, then the brick is not considered as crossed. You need to find out how to draw the line to cross the least bricks and return the number of crossed bricks.
You cannot draw a line just along one of the two vertical edges of the wall, in which case the line will obviously cross no bricks.
Example:
Input: 
[[1,2,2,1],
 [3,1,2],
 [1,3,2],
 [2,4],
 [3,1,2],
 [1,3,1,1]]
Output: 2
*/


//给一个二维数组，列数不一定相同，wall[i][j]表示i层第j个砖的宽度，每层砖总宽度一样，求竖线往下割，最少穿过多少块砖？最左最右的竖线不算
//按行扫描，用递推算出从左到i的宽度和(除去最右)，加入到hash map<宽度,个数>中，若没有则新建为1，若有就++（本层不会影响，因为是宽度和递增不会重复）。
//至此统计出从左边开始的每种宽度的个数(层数)，在map中用iterator遍历，找到最大的

//宽度和加到hash map中要注意除去最右，因为每一层的左到最右块宽度和必相等，所以对应层数为h，切割这个位置等于切割最右边界，所以不应计入map中；
//有个corner data，就是层数为1时答案并不全为0，当块数为1时，这块砖必须切割，答案为1，所以不需要特殊考虑，我的算法也可以通用；




    int leastBricks(vector<vector<int>>& wall) {
        int h = wall.size();
        //if (h == 1) return 0;
        int w = wall[0].size();
        unordered_map <int,int> m;
        int i,j,wid;
        for (i=0;i<h;i++){
            wid = 0;
            for (j=0;j<wall[i].size()-1;j++){
                wid += wall[i][j];
                if (m.find(wid) == m.end()) m[wid] = 1;
                else m[wid]++;
            }
        }
        unordered_map <int,int>::iterator it;
        int wid_count=0;
        for(it=m.begin();it!=m.end();it++)
            if (it->second > wid_count) wid_count = it->second;
        return h-wid_count;
    }