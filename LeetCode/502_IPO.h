//502_IPO.h
//45ms	96.45%


/*
Total Accepted: 3051
Total Submissions: 8745
Instruction: LeetCode 502 - IPO - [H]
Developer: lrushx
Process Time: May 18, 2017
*/


/*
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given several projects. For each project i, it has a pure profit Pi and a minimum capital of Ci is needed to start the corresponding project. Initially, you have W capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

To sum up, pick a list of at most k distinct projects from given projects to maximize your final capital, and output your final maximized capital.

Example 1:
Input: k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].

Output: 4

Explanation: Since your initial capital is 0, you can only start the project indexed 0.
             After finishing it you will obtain profit 1 and your capital becomes 1.
             With capital 1, you can either start the project indexed 1 or the project indexed 2.
             Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
             Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
Note:
You may assume all numbers in the input are non-negative integers.
The length of Profits array and Capital array will not exceed 50,000.
The answer is guaranteed to fit in a 32-bit signed integer.
*/


//类似背包问题，只不过换成了成本和利润，成为了value＝增加容量的背包问题。每加一个project，资金会相应增加(如同背包容量增加)，给个初始资本W，求最多k个project，最后可以有多少资本
//方法一：按k遍历，每次在W上加上profit最大的且cost<=现有W的一个project，将其掩盖后继续。因为被掩盖的project还会被遍历到，所以O(kn)，差点没过。1303ms/2.13%。
//方法二：用了比较高级的数据结构，完成了我之前一直想要达到的功能，每次用完一个project就删掉。用了priority_queue low的low.top()来获取最大值，再用multiset<int,int> high里的high.emplace(c,p)来插入，并且用high.begin()来获取key1最小的成员。
//把所有成本<=W的放到low中，只存profit；其余做成pair放到high中
//每次从low里取最大的加到W，再根据新的W更新high，有成本<=新W的转存到low中。很巧妙，45ms/96.45%。

//第二种方法借鉴，使用了新的数据结构
//priority_queue可以取最大，multiset.emplace()可以按升序存元素



//solution1, O(kn), traditional vector
//1303ms	2.13%
    static bool mysort(pair<int, int>& a, pair<int, int>& b){ 
        if (a.first == b.first) return a.second < b.second;
        else return a.first > b.first;   }
    
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int len = Profits.size(),i,j;
        vector<pair<int,int> > p(len);
        bool flag[len] = {},add;
        for (i=0; i<len; i++) p[i] = make_pair(Profits[i],Capital[i]);
        while (len >0 && Profits[len-1] == 0) len--;
        sort(p.begin(),p.end(),mysort);        
        //cout<<endl<<endl; for (i=0;i<len;i++) cout<<"["<<p[i].first<<","<<p[i].second<<"]"; cout<<endl;
        for (j=0; j<k; j++){
            add = false;
            for (i=0; i<len; i++){
                if (flag[i]) continue;
                if (p[i].second <= W){
                    //cout<<i<<" "<<"["<<p[i].first<<","<<p[i].second<<"]    ";
                    W += p[i].first;
                    flag[i] = true;
                    add = true;
                    break;
                }
            }
            if (!add) break;
        }
        return W;
    }


//solution2, O(klogn), priority_queue( using p.top() to get max) and multiset( using m.emplace(a,b),then m.begin() to get min)
//45ms	96.45%
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int len = Profits.size(),i,j;
        priority_queue<int> low;      // Profits[i]s within current W
        multiset<pair<int,int>> high; // (Caoutal[i],Profit[i])s outside current W
        
        for (i=0; i<len; i++)
            if (Profits[i])
                if (Capital[i] <= W) low.push(Profits[i]);
                else high.emplace(Capital[i],Profits[i]);
                
        while (k-- && low.size()){
            W += low.top();     // greedy to work on most profitable first
            low.pop();
            for (auto it = high.begin();high.size()&& it->first <= W; it=high.erase(it))
                low.push(it->second);
        }
        return W;
    }