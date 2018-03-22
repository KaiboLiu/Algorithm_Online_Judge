//NetEase2017_Spring_4.h
//NetEase 2017 Spring written examination

/*
Instruction: 网易2017春招 - 4 消除重复元素
Developer: lrushx
Process Time: June 20, 2017
*/

/*
小易有一个长度为n序列，小易想移除掉里面的重复元素，但是小易想是对于每种元素保留最后出现的那个。小易遇到了困难,希望你来帮助他。 
输入描述:
输入包括两行：
第一行为序列长度n(1 ≤ n ≤ 50)
第二行为n个数sequence[i](1 ≤ sequence[i] ≤ 1000)，以空格分隔

输出描述:
输出消除重复元素之后的序列，以空格分隔，行末无空格
*/

// 从后往前，将首次出现的数字存入hash table并且染色为true，已经出现过的为false。然后从前往后输出染色值为true的元素

#include <iostream>
#include <unordered_map>// for hash table
#include <cstring>      // memset

using namespace std;
int main(){
    int n,a[50],i;
    bool flag[50];
    memset(flag,0,50*sizeof(bool));
    unordered_map<int,int> m;
    cin >> n;
    for (i = 0;i < n; i++) cin >> a[i];
    for (i = n-1; i>=0; i--)
        if (m.find(a[i]) == m.end()) {
            flag[i] = true;
            m[a[i]] = 1;
        }else flag[i] = false;
    for (i = 0;i < n; i++)
        if (flag[i]) {
            cout<<a[i];
            break;
        }
    for (++i;i < n; i++)
        if (flag[i]) cout<<" "<<a[i];
    cout<<endl;
    return 0;
}
