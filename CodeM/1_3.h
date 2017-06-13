//codeM_1_3.h
//CodeM Qualifying

/*
Instruction: CodeM - 1_3 优惠券
Developer: lrushx
Process Time: June 12, 2017
*/

/*
美团点评上有很多餐馆优惠券，用户可以在美团点评App上购买。每种优惠券有一个唯一的正整数编号。每个人可以拥有多张优惠券，但每种优惠券只能同时拥有至多一张。每种优惠券可以在使用之后继续购买。
当用户在相应餐馆就餐时，可以在餐馆使用优惠券进行消费。某人优惠券的购买和使用按照时间顺序逐行记录在一个日志文件中，运营人员会定期抽查日志文件看业务是否正确。业务正确的定义为：一个优惠券必须先被购买，然后才能被使用。
某次抽查时，发现有硬盘故障，历史日志中有部分行损坏，这些行的存在是已知的，但是行的内容读不出来。假设损坏的行可以是任意的优惠券的购买或者使用。
现在给一个日志文件，问这个日志文件是否正确。若有错，输出最早出现错误的那一行，即求出最大s，使得记录1到s-1满足要求；若没有错误，输出-1。
*/

// 注意 ? ? O2 O2 的输入
// 注意 ? I1 I1 的输入
// 注意 I2 ? I1 ? I2 I1 的输入，两个问号应该为　O2 O1

#include <iostream>
#include <cstring>

using namespace std;

int main(){
    //freopen("1.in","r",stdin);
    int n;
    while (cin >> n){
        //std::unordered_map<int,int> m;
        //std::unordered_map<int,int>::iterator it;
        
        int f[500001] = {0};
        int I[100001],O[100001];
        memset(I,-1,sizeof(int)*100001);
        memset(O,-1,sizeof(int)*100001);
        int a,unknow = 0,res = -1;
        char c;
        for(int i = 0; i < n; i++){
            cin>>c;
            if (c == '?') {
                f[i] = 0;
                unknow++;      
                continue;
            }
            cin>>a;
            
            if (res > 0) continue;
            //it = m.find(a);
            if (c == 'I'){
                f[i] = a;
                //if (it != m.end()){// a在记录中
                if (I[a] > O[a]){// a在记录中
                    if (unknow){    // a曾在?中被output
                        bool hasunknow = false;
                        for (int j = I[a]+1;j<i;j++)
                            if (f[j] == 0) {
                                f[j] = -a;
                                O[a] = j;
                                hasunknow = true;
                                break;
                            }
                        if (!hasunknow) res = i+1;
                        else I[a] = i;
                        unknow--;	
                    }else{			// 没有?，a未被output，不应被再次记录
                        res = i+1;   continue;
                    }
                }else I[a] = i;		// a不在记录中，加入记录
            }else if (c == 'O'){
                f[i] = -a;
                //if (it != m.end())// a在记录中
                if (I[a] > O[a])
                    O[a] = i;
                    //m.erase(it);
                else {				// a不在记录中
                    if (unknow){	// a曾在?中被input
                        bool hasunknow = false;
                        for (int j = O[a]+1;j<i;j++)
                            if (f[j] == 0) {
                                f[j] = a;
                                I[a] = j;
                                hasunknow = true;
                                break;
                            }else if (f[j] == f[i]){
                                res = i+1;
                                break;
                            }
                        if (!hasunknow) res = i+1;
                        else O[a] = i;
                        unknow--;	
                    }else{			// 没有?，a未被output，不应被再次记录
                        res = i+1;   continue;
                    }
                }
            }
        }
        cout <<res <<endl;
    }
    return 0;
}
