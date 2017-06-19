//BD2017_Spring_3.h
//Baidu 2017 Spring written examination

/*
Instruction: 百度2017春招 - 3 寻找三角形
Developer: lrushx
Process Time: June 19, 2017
*/

/*
三维空间中有N个点，每个点可能是三种颜色的其中之一，三种颜色分别是红绿蓝，分别用'R', 'G', 'B'表示。 
现在要找出三个点，并组成一个三角形，使得这个三角形的面积最大。
但是三角形必须满足：三个点的颜色要么全部相同，要么全部不同。 
输入描述:
首先输入一个正整数N三维坐标系内的点的个数.(N <= 50) 

接下来N行，每一行输入 c x y z，c为'R', 'G', 'B' 的其中一个。x，y，z是该点的坐标。(坐标均是0到999之间的整数)


输出描述:
输出一个数表示最大的三角形面积，保留5位小数。
*/

// Hallen equation

#include <iostream>
#include <algorithm>    /// std::max
#include <cmath>
#include <iomanip>

using namespace std;

double area(int x1,int y1, int z1, int x2,int y2,int z2, int x3,int y3,int z3){
    double a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
    double b = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)+(z1-z3)*(z1-z3));
    double c = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2)+(z3-z2)*(z3-z2));
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
    //return (x2*y3+x1*y2+x3*y1-x3*y2-x2*y1-x1*y3)/2.0;
}

int main(){
    int n,i,j,k,len,x,y,z;
    double res = 0.0;
    int R[50][3],G[50][3],B[50][3],nr=0,ng=0,nb=0;
    //vector<pair<int,int> > R,G,B;
    char c;
    cin >> n;
    for (i=0;i<n;i++){
        cin >> c >> x >> y >> z;
        if (c == 'R') {
            R[nr][0] = x;
            R[nr][1] = y;
            R[nr][2] = z;
            nr++;
        }
        else if (c == 'G') {
            G[ng][0] = x;
            G[ng][1] = y;
            G[ng][2] = z;
            ng++;
        }else {
            B[nb][0] = x;
            B[nb][1] = y;
            B[nb][2] = z;
            nb++;
        }
    }

    // all red
    for (i = 0;i<nr-2;i++)
        for (j = i+1;j<nr-1;j++)
            for (k = j+1;k<nr;k++)
                res = max(res,area(R[i][0],R[i][1],R[i][2],R[j][0],R[j][1],R[j][2],R[k][0],R[k][1],R[k][2]));
    // all green            
    for (i = 0;i<ng-2;i++)
        for (j = i+1;j<ng-1;j++)
            for (k = j+1;k<ng;k++)
                res = max(res,area(G[i][0],G[i][1],G[i][2],G[j][0],G[j][1],G[j][2],G[k][0],G[k][1],G[k][2]));
    // all blue            
    for (i = 0;i<nb-2;i++)
        for (j = i+1;j<nb-1;j++)
            for (k = j+1;k<nb;k++)
                res = max(res,area(B[i][0],B[i][1],B[i][2],B[j][0],B[j][1],B[j][2],B[k][0],B[k][1],B[k][2]));
    // R,G, and B            
    for (i = 0;i<nr;i++)
        for (j = 0;j<ng;j++)
            for (k = 0;k<nb;k++)
                res = max(res,area(R[i][0],R[i][1],R[i][2],G[j][0],G[j][1],G[j][2],B[k][0],B[k][1],B[k][2]));
    cout<<setiosflags(ios::fixed)<<setprecision(5)<<res<<endl;
    return 0;        
}
