//NetEase2017_Spring_1.h
//NetEase 2017 Spring written examination

/*
Instruction: 网易2017春招 - 1 双核处理
Developer: lrushx
Process Time: June 20, 2017
*/

/*
一种双核CPU的两个核能够同时的处理任务，现在有n个已知数据量的任务需要交给CPU处理，假设已知CPU的每个核1秒可以处理1kb，每个核同时只能处理一项任务。n个任务可以按照任意顺序放入CPU进行处理，现在需要设计一个方案让CPU处理完这批任务所需的时间最少，求这个最小的时间。 
输入描述:
输入包括两行：
第一行为整数n(1 ≤ n ≤ 50)
第二行为n个整数length[i](1024 ≤ length[i] ≤ 4194304)，表示每个任务的长度为length[i]kb，每个数均为1024的倍数。


输出描述:
输出一个整数，表示最少需要处理的时间

输入例子:
5
3072 3072 7168 3072 1024

输出例子:
9216
*/

//等价于把一个数组分成2份，使每组的和尽量接近sum/2，像LeetCode 416
//可以把数据/1024，则元素范围为1～4096，sum/2范围为25~102400
//DP即可Dp[m]表示和m是否可以得到，DP[0]=true。遍历数组a[i]，内循环为从大到小遍历和m，DP[m]|=DP[m-a[i]]

#include <iostream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <cstring>      // memset

using namespace std;

int main(){
    int n,a[50],i,m,sum0=0,sum;
    int mul = 1024;
    cin>>n;
    for (i = 0;i<n;i++) {
        cin>>a[i];
        a[i] /= mul;
        sum0 += a[i];
    }
    sum = sum0 / 2;
    //bool DP[sum+1] = {1};
    bool DP[102401] = {1};
    memset(DP,0,102401*sizeof(bool));
    DP[0] = 1;
    for (i=0;i<n;i++)
        for (m=sum;m>=a[i];m--)
            //DP[m] = DP[m] || DP[m-a[i]];
            DP[m] |= DP[m-a[i]];
    i = sum;
    while (!DP[i]) i--;
    cout<<(sum0-i)*mul<<endl;
    return 0;
}
