//BD2017_Spring_1.h
//Baidu 2017 Spring written examination

/*
Instruction: 百度2017春招 - 1 买帽子
Developer: lrushx
Process Time: June 18, 2017
*/

/*
度度熊想去商场买一顶帽子，商场里有N顶帽子，有些帽子的价格可能相同。度度熊想买一顶价格第三便宜的帽子，问第三便宜的帽子价格是多少？ 
输入描述:
首先输入一个正整数N（N <= 50），接下来输入N个数表示每顶帽子的价格（价格均是正整数，且小于等于1000）

输出描述:
如果存在第三便宜的帽子，请输出这个价格是多少，否则输出-1
*/

#include <iostream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;

int main(){
    int n,i;
    vector<int> p;
    cin >> n;
    p.resize(n,0);
    for (i=0;i<n;i++)
        cin >> p[i];

    sort(p.begin(),p.end());
    int p0=0,c=0;
    for (i = 0;i<n;i++){
        if (p[i] > p0){
            c++;
            p0 = p[i];
            if (c == 3){
                cout<<p0<<endl;
                return 0;
            }
        }
    }
    cout<< -1<<endl;
    return 0;        
}
