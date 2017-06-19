//BD2017_Spring_2.h
//Baidu 2017 Spring written examination

/*
Instruction: 百度2017春招 - 2 度度熊回家
Developer: lrushx
Process Time: June 19, 2017
*/

/*
一个数轴上共有N个点，第一个点的坐标是度度熊现在位置，第N-1个点是度度熊的家。现在他需要依次的从0号坐标走到N-1号坐标。
但是除了0号坐标和N-1号坐标，他可以在其余的N-2个坐标中选出一个点，并直接将这个点忽略掉，问度度熊回家至少走多少距离？ 
输入描述:
输入一个正整数N, N <= 50。

接下来N个整数表示坐标，正数表示X轴的正方向，负数表示X轴的负方向。绝对值小于等于100


输出描述:
输出一个整数表示度度熊最少需要走的距离。
*/

#include <iostream>
#include <stdlib.h>     /* abs */
#include <algorithm>    // std::max


using namespace std;

int main(){
    int n,i,p[50],dist=0,del = 0;
    cin >> n;
    for (i=0;i<n;i++)
        cin >> p[i];

    if (n < 2){
        cout<< 0 << endl;
        return 0;
    }
    if (n == 2){
        cout<< abs(p[1]-p[0])<<endl;
        return 0;
    }
    for (i = 1;i < n-1; i++){
        del = max(del,abs(p[i+1]-p[i])+abs(p[i]-p[i-1])-abs(p[i+1]-p[i-1]));
        dist += abs(p[i]-p[i-1]);
    }
    dist += abs(p[n-1]-p[n-2]);
    cout<<dist-del<<endl;
    return 0;        
}
