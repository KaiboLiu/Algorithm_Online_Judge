//NetEase2017_Spring_7.h
//NetEase 2017 Spring written examination

/*
Instruction: 网易2017春招 - 7 集合
Developer: lrushx
Process Time: June 20, 2017
*/

/*
小易最近在数学课上学习到了集合的概念,集合有三个特征：1.确定性 2.互异性 3.无序性.
小易的老师给了小易这样一个集合：
S = { p/q | w ≤ p ≤ x, y ≤ q ≤ z }
需要根据给定的w，x，y，z,求出集合中一共有多少个元素。小易才学习了集合还解决不了这个复杂的问题,需要你来帮助他。 
输入描述:
输入包括一行：
一共4个整数分别是w(1 ≤ w ≤ x)，x(1 ≤ x ≤ 100)，y(1 ≤ y ≤ z)，z(1 ≤ z ≤ 100).以空格分隔

输出描述:
输出集合中元素的个数
*/

//题目中的p/q是除法，不是集合减法。因为数据较小，可以遍历p,q，每次把p,q除去公约数后折成hash值储存判断即可

#include <iostream>
#include <unordered_map>// for hash table
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b,a % b);
}


int main(){
    int w,x,y,z,i,j,g,v_hash,res=0;
    unordered_map<int,int> m;
    cin>> w >> x >> y >> z;
    for (i = w;i <= x; i++)
        for (j = y;j <= z; j++){
            g = gcd(i,j);
            v_hash = (i/g-1)*100 + j/g-1;
            if (m.find(v_hash) == m.end()){
                m[v_hash] = 1;
                res++;
            }
        }
    cout<<res<<endl;
            
    return 0;
}
