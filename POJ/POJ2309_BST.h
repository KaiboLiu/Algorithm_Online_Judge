//POJ2309_BST.h
//16MS

/**
 * Instruction：POJ 2309 - BST- [60%(5788/9500)]
 * Developer：lrushx
 * Process Time：May 10, 2016
 */
 
 //一个无限全满搜索二叉树，节点数字从1~无穷，左下1，给一个节点X，求其子节点中最小值和最大值
 //数学方法，每行都是等差数列，最下行为l=0，首项2^l，公差2^(l+1)，从左往右第k个节点(k起始为0)节点值为(1+2k)*2^l=b*a,
 //根据X求出其位置{l,k}(其实只要a就行),则可得到其父节点值X+公差/2，则X子节点中最大值为父节点-1，即max=X+2^l-1=X+a-1，则min=2X-max；
 
#include <iostream>      //改用<iostream>
using namespace std;
int main(){
    int x,n,a,x1;
//下一行提交时删除********************
    cout<<"POJ2309_BST:Input n and a{n}, output N lines with the minimum and maximum numbers in the subtree whose root node is a{n}."<<endl;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x;//x = 2^l * (1+2k) = a * b;
        a = 1; x1 = x;
        while ((x1 & 1) == 0){x1 >>= 1;a <<= 1;}
//        a = (~x+1) & x;//a为2^l，可用~x & x求出x最右1所在位置对应的数
        cout<<x-a+1<<" "<<x+a-1<<endl;
    }
    return 0;
    
}
