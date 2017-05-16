//386_Lexicographical_Numbers.h
//132ms	93.52%

/*
Total Accepted: 17508
Total Submissions: 43161
Instruction: LeetCode 386 - Lexicographical Numbers - [M]
Developer: lrushx
Process Time: May 10, 2017
*/


/*
Given an integer n, return 1 - n in lexicographical order.
For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
*/


//给一个n,输出1..n，按照字典顺序，也就是1,10,100,1000,1001,...1009,101,1010,1011,...从左往右相对应位置值从小到大，每位都相同的话从短到长
//直接按位生成，有了x就遍历i=0~9，下一步是10x+i。
//另一种方法是借鉴来的，直接生成：有了x后下一个是10x，若没超过n则是下一个答案；若超过n则/=10，再+1，这之后若是10倍数，则一直/=10。

//第一种方法每个数需要计算digits次，162ms/63.12%
//第二种方法每个数需要计算1/3次，132ms/93.52%


//solution1, 162ms/63.12%

    vector<int> res;
    int it=0;
    void generate(int x,int n){
        res[it++] = x;
        int i,tmp;
        for (i=0;i<=9;i++){
            tmp = 10 * x + i;
            if (tmp > n) return;
            generate(tmp,n);
        }
        return;
    }
    
    vector<int> lexicalOrder(int n) {
        res.resize(n,0);
        int front;
        for (front=1;front<=9;front++){
            if (front <= n){
                //res[it++] = front;
                generate(front,n);
            }
        }
        return res;
    }
    
//solution2, 132ms/93.52%

    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int cur = 1;
        for (int i = 0; i < n; i++) {
            res[i] = cur;
            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                if (cur >= n) 
                    cur /= 10;
                cur += 1;
                while (cur % 10 == 0)
                    cur /= 10;
            }
        }
        return res;
    }