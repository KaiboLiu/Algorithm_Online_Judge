//NetEase2017_Spring_2.h
//NetEase 2017 Spring written examination

/*
Instruction: 网易2017春招 - 2 赶去公司
Developer: lrushx
Process Time: June 20, 2017
*/

/*
终于到周末啦！小易走在市区的街道上准备找朋友聚会，突然服务器发来警报,小易需要立即回公司修复这个紧急bug。假设市区是一个无限大的区域，每条街道假设坐标是(X，Y)，小易当前在(0，0)街道，办公室在(gx,gy)街道上。小易周围有多个出租车打车点，小易赶去办公室有两种选择，一种就是走路去公司，另外一种就是走到一个出租车打车点，然后从打车点的位置坐出租车去公司。每次移动到相邻的街道(横向或者纵向)走路将会花费walkTime时间，打车将花费taxiTime时间。小易需要尽快赶到公司去，现在小易想知道他最快需要花费多少时间去公司。 
输入描述:
输入数据包括五行:

第一行为周围出租车打车点的个数n(1 ≤ n ≤ 50)

第二行为每个出租车打车点的横坐标tX[i] (-10000 ≤ tX[i] ≤ 10000)

第三行为每个出租车打车点的纵坐标tY[i] (-10000 ≤ tY[i] ≤ 10000)

第四行为办公室坐标gx,gy(-10000 ≤ gx,gy ≤ 10000),以空格分隔

第五行为走路时间walkTime(1 ≤ walkTime ≤ 1000)和taxiTime(1 ≤ taxiTime ≤ 1000),以空格分隔


输出描述:
输出一个整数表示，小易最快能赶到办公室的时间

*/

// easy dp. If taxiTime<walkTime, then time[start,end] = min{dist[start,taxi_i]*walkTime+dist[taxi_i,end]*taxiTime]

#include <iostream>
#include <algorithm>    // std::sort, std::min

using namespace std;

int main(){
    int n,X[50],Y[50],gx,gy,i,res,wTime,tTime,t1;
    cin>>n;
    for (i=0;i<n;i++) cin>>X[i];
    for (i=0;i<n;i++) cin>>Y[i];
    cin>>gx>>gy;
    cin>>wTime>>tTime;
    
    res = wTime * (abs(gx)+abs(gy));
    
    if (wTime > tTime){
        for (i=0;i<n;i++){
            t1 = wTime * (abs(X[i])+abs(Y[i])) + tTime * (abs(gx-X[i])+abs(gy-Y[i]));
            res = min(res,t1);
        }
    }
    cout<<res<<endl;
    return 0;
}
