//POJ_2663_Tri_Tiling.h
//方法1：用组合数来求 252K 16MS
//方法2：直接得出0~30的答案 164K  0MS(cout)/248K 0MS(printf)
//方法3：递推式a[n]=4*a[n-1]-a[n-2]  164K 0MS


/**
 * Instruction：POJ 2663 - Tri Tiling- [51%(4780/9216)]
 * Developer：lrushx
 * Process Time：May 12, 2016
 */
 
 //在一个3*n空间里，用1*2方块填满，求方案数，0 <= n <= 30
 /*
  * ***********注意在中间计算过程中，可能会溢出，导致结果不对，只要中间答案用double最后换成int就能解决*******
  * 数学方法：
  * 1、n==0或者奇数则答案为0，n==2时返回3；
  * 2、n==4有2种情况，以下2个答案相加，返回11；
    2.1、分成宽为2的子区域*2，1种分法，答案3*3；
    2.2、分成宽为4的区域，1种分法，答案2
  *3、n==6有3中情况，以下3个答案相加，返回41；
    3.1、分成宽为2的子区域*3，1种分法，答案3^3；
    3.2、分成宽为2的子区域*1+宽为4的子区域*1，C(2,1)种分法，答案C(2,1)*3^1*2^1；
    3.3、分成宽为6的子区域*1，1种分法，答案2；
  *4、以此类推，扩展到一般方法：
    4.1、a、b、c、d...o表示宽为2、4、6...30的子区域的个数
    4.2、(2,4,6,...,30)(a,b,c,...,d)^T=n，30元线性方程，求出所有解{a,b,c,...,o}
    4.3、对于每个解，区域的分法由组合数得出C(a+b+..,a)*C(b+c+...,b)*...=(a+b+c...)!/(a!*b!*c!...)，每个区域的方案数为3^a*2^b*2^c*...，相乘得到这组解的方案数；
    4.4、把所有解的方案数相加即是答案
  */
/*
* 有了上面分析的程序，可以直接得出0~30的答案，左边为中间计算过程中溢出答案，右边为正解
2-->3               2-->3
4-->11              4-->11
6-->41              6-->41
8-->153             8-->153
10-->571            10-->571
12-->2131           12-->2131
14-->7953           14-->7953
16-->29681          16-->29681
18-->109799         18-->110771
20-->412431         20-->413403
22-->1540897        22-->1542841
24-->5756017        24-->5757961
26-->21485223       26-->21489003
28-->80141783       28-->80198051
30-->299245097      30-->299303201


*/
 
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


//方法1：用组合数来求 252K 16MS***************************
double comb(vector<unsigned> root,int sum_root,int n){
    double res=1.0;
    for (int i=1;i<n/2;i++){
        for (int j=root[i];j>=1;j--)
            res = res * double(sum_root--) / double(j);
    }
//    return int(res);
    return res;
    
}

double solve(vector<unsigned> root,int level,int sum_eq,int sum_root,int n){
    //level为当前解的系数2,4,6,8等，sum_eq为当前求解方程的和（减去已求出根对应的值），sum_root为当前根的和

    if (level == 2){
        root[1] = sum_eq / 2;   //最后一个根a
        if (sum_root+root[1] > 0){
            return comb(root,sum_root+root[1],n)*pow(3.0,int(root[1]))*pow(2.0,sum_root);
        }
        else return 0;
    }
    int tmp = sum_eq / level;
    double ans = 0;
    for (int i=tmp;i>=0;i--){
        root[level/2]=i;
        ans += solve(root,level-2,sum_eq-i*level,sum_root+i,n);
    }
    return ans;
}


int main(){
    int n;
    cin>>n;
    while (n > -1){
        if ((n & 1)==1) {
            cout<<0<<endl;
            cin>>n;           
            continue;
        }
        if (n == 0){//WA这么多次特么n=0答案是1？？？？你逗我玩呢？？？
            cout<<1<<endl;
            cin>>n;           
            continue;
        }
        vector<unsigned> root(n+1);
        cout<<(long)solve(root,n,n,0,n)<<endl;
        cin>>n;
        
    }
    return 0;
}

//方法2：直接得出0~30的答案 164K  0MS(cout)/248K 0MS(printf)**********************
/*
int main(){
    int n;
    int a[16]={1,3,11,41,153,571,2131,7953,29681,110771,413403,1542841,5757961,21489003,80198051,299303201};
    while (scanf("%d",&n) && n != -1){
        if ((n&1)==1) printf("%d\n",0);
        else printf("%d\n",a[n/2]);
    }
    return 0;
}

//方法3：递推式a[n]=4*a[n-1]-a[n-2]  164K 0MS************************************

int main()  
{  
    int n;  
    int a[31];  
    a[0]=1;  
    a[2]=3;  
  
    int i;  
    for(i=1;i<=30;i=i+2)  
        a[i]=0;  
    for (i=4;i<=30;i=i+2)  
        a[i]=a[i-2]*4-a[i-4];  
//    for (i=2;i<=30;i=i+2) cout<<i<<"-->"<<a[i]<<endl;
    while (scanf("%d",&n)&&n!=-1)  
        printf("%d\n",a[n]);  
    return 0;  
}


*/
