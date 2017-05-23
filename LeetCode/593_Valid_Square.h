//593_Valid_Square.h
//
//LeetCode Contest 33


/*
Total Accepted: 666
Total Submissions: 850
Instruction: LeetCode 593 - Valid Square - [M]
Developer: lrushx
Process Time: May 20, 2017
*/

/*
Given the coordinates of four points in 2D space, return whether the four points could construct a square.
The coordinate (x,y) of a point is represented by an integer array with two integers.
Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:
All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/

//给4个坐标，判断这4个点能否构成正方形
//以p1为原点更新其余3个点，计算到p1的距离，然后把最大距离放到p4，判断2和3是否边长相等是否角度90，然后再比较p4p3和p3p0之间是否90度是否p4长度平方为2倍p1长度平方
//前2名的牛人一个用了next_permutation(p,p+4)做数组的全排列来重组4个点顺序
//另一个用python计算出所有两两点距离平方(6对)然后排序，满足前4个相等不为0，后2个相等且为前4个的2倍则满足条件。

    int dot(vector<int>& p1, vector<int>& p2){
        return p1[0]*p2[0]+p1[1]*p2[1];
    }
    int dist(vector<int>& p1){
        return p1[0]*p1[0] + p1[1]*p1[1];
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        p2[0] -= p1[0];  p2[1] -= p1[1];
        p3[0] -= p1[0];  p3[1] -= p1[1];
        p4[0] -= p1[0];  p4[1] -= p1[1];
        int d2 = dist(p2),d3 = dist(p3),d4 = dist(p4);
        if (d2 == 0 || d3 == 0 || d4 == 0) return false;
        if (d2 > d4) {swap(p2,p4); swap(d2,d4);}
        if (d3 > d4) {swap(p3,p4); swap(d3,d4);}
        if (d2 != d3) return false;
        if (dot(p2,p3) != 0) return false;
        if (d4 != 2*d2) return false;
        p4[0] -= p3[0]; p4[1] -= p3[1];
        if (dot(p4,p3) != 0) return false;
        return true;
    }
