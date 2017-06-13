//1_2.h
//CodeM Qualifying

/*
Instruction: CodeM - 1_2 锦标赛
Developer: lrushx
Process Time: June 11, 2017
*/

/*
比赛有 n 个人参加（其中 n 为2的幂），每个参赛者根据资格赛和预赛、复赛的成绩，会有不同的积分。比赛采取锦标赛赛制，分轮次进行，设某一轮有 m 个人参加，那么参赛者会被分为 m/2 组，每组恰好 2 人，m/2 组的人分别厮杀。我们假定积分高的人肯定获胜，若积分一样，则随机产生获胜者。获胜者获得参加下一轮的资格，输的人被淘汰。重复这个过程，直至决出冠军。
现在请问，参赛者小美最多可以活到第几轮（初始为第0轮）？
*/

// 统计积分<=x[0]的选手数作为0号选手的排名rank，求int(log(rank,2))，可以用位运算
// python MLE,改用C++就AC了...

#include <iostream>
using namespace std;
int main() {
    int rank=1,x0,x,n;
	cin >> n;
    scanf("%d",&x0);
	for(int i = 1; i < n; i++){
		scanf("%d",&x);
		if (x <= x0) rank++;
	}
    int ans = 0;
    while (rank > 1){
        ans++;
        rank >>= 1;
    }
	cout << ans << endl;
	return 0;
}
