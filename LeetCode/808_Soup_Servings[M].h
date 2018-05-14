// 808_Soup_Servings[M].h
// 6ms  %

/*
Total Accepted: 2K 
Total Submissions: 6.1K
Developer: lrushx
Process Time: May 11, 2018
https://leetcode.com/problems/soup-servings/description/
*/


// 有N,N单位的汤，分发给A和B,每次等概率方案为100/0, 75/25, 50/50和25/75，求A先分完的概率
// 虽然N可以很大，但是N>5000后答案就为1
// 可以用递归+memo，dfs(A,B,a={})表示各自剩下的量，如果其中一个为0，就按情况返回1/0.5/0，否则就返回a[A,B]，如果a[A,B]还没有，则把4中分法的答案加起来赋值后返回

class Solution {
private:
    unordered_map<int, unordered_map<int, double> > store;
public:
    double soupServings(int N) {
        if (N >= 5000)
            return 1.0;
        else
            return helper(N, N);
    }
    double helper(int A, int B) {
	// Full probablity when A becomes empty first
        if (A == 0 && B != 0)
            return 1;
	// Half probablity when A and B become empty at the same time
        else if (A == 0 && B == 0)
            return 0.5;
	// Zero probablity when B becomes empty first
        else if (A != 0 && B == 0)
            return 0;
						
	// If the code reaches here, it implies that neither A nor B is empty yet. 
	// If there exist previous calculated result, return it.
        if (store[A][B] != 0)
            return store[A][B];
			
	// Otherwise, recursive for 4 possible selections
        double prob = 0;
        prob += 0.25 * helper(A - min(A, 100), B);
        prob += 0.25 * helper(A - min(A, 75), B - min(B, 25));
        prob += 0.25 * helper(A - min(A, 50), B - min(B, 50));
        prob += 0.25 * helper(A - min(A, 25), B - min(B, 75));
				
	// Store the calculated result
        store[A][B] = prob;
        return prob;
    }
};


int main(){
    Solution s;
    cout<<s.soupServings(3000)<<endl;

}
