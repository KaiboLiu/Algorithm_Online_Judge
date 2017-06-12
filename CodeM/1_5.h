#1_5.h
#CodeM Qualifying

'''
Instruction: CodeM - 1_5 数码
Developer: lrushx
Process Time: June 11, 2017
'''

/*
给定两个整数 l 和 r ，对于所有满足1 ≤ l ≤ x ≤ r ≤ 10^9 的 x ，把 x 的所有约数全部写下来。对于每个写下来的数，只保留最高位的那个数码。求1～9每个数码出现的次数。
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

vector<long long> count_1(int n){
    int x = n;
    vector<long long> res(10,0);
    long long start,end,a,b,index,i=1;
    int count=0;
    while (1){
        count++;
        start=x/(i+1)+1;
        end=x/i;
        //print start, end
        //if (start > end) break;
        a = start;
        while (a <= end){
            long long index = a,len = 1;
            while (index >= 10) {index = index / 10; len *= 10;}
            b = (index+1)*len;
            
            /*
            string s = to_string(a);
            index = s[0]-'0';
            b = (index+1)*pow(10,s.size()-1);
            */
            res[index] += b<=end? (b-a)*i : (end-a+1)*i;
            a = b;
        }
        if (start==1) break;
        i=x/(start-1);
        //i++;
    }
    //cout<<"......."<<count<<endl;
    return res;
}

int main(){
    int l,r;
    cin>>l>>r;
    
    vector<long long> res = count_1(r);
    if (l > 1){
        vector<long long> res1 = count_1(l-1);
        for (int i=1;i<=9;i++)
            cout<< res[i]-res1[i]<<endl; 
    } else{
        for (int i=1;i<=9;i++)
            cout<< res[i]<<endl;
    }
        return 0;
}
