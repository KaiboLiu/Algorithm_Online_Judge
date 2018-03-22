//BD2017_Spring_4.h
//Baidu 2017 Spring written examination

/*
Instruction: 百度2017春招 - 4 有趣的排序
Developer: lrushx
Process Time: June 18, 2017
*/

/*
度度熊有一个N个数的数组，他想将数组从小到大 排好序，但是萌萌的度度熊只会下面这个操作：
任取数组中的一个数然后将它放置在数组的最后一个位置。
问最少操作多少次可以使得数组从小到大有序？ 
输入描述:
首先输入一个正整数N，接下来的一行输入N个整数。(N <= 50, 每个数的绝对值小于等于1000)


输出描述:
输出一个整数表示最少的操作次数。

输入例子:
4
19 7 8 25

输出例子:
2
*/

//a is the original array, b is the sorted array of a
//if b[0],b[1],...,b[k] is in order in a, but the position of b[k+1] in a in before the postion of b[k] in a, then the answer is n-k-1
//if element a[i] will be placed to the last postion, then any element a[i']>a[i] will definitely be placed to the last postion. I want to make the a[i] as big as I can. So I need to find the longest subsequence in a, which are the first elements in b


#include <iostream>
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;

int main(){
    int n,i=0,j=0,res = 0;
    vector<int> a,b;
    
    cin >> n;
    a.resize(n,0);
    for (i = 0;i<n;i++)
        cin >> a[i];
    b = a;
    sort(b.begin(),b.end());    // i in a, j in b
    i = 0;
    j = 0;
    while (i < n){
        while (i < n && a[i] != b[j]) i++;
        if (i < n){
            res++;
            i++;
            j++;
        }
    }
    cout<<n-res<<endl;
    return 0;
}
