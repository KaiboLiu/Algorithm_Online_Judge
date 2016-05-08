//264_Ugly_Number_II.h
//8ms	98.90%

/**
 * 功能说明：LeetCode 264 - Ugly Number II
 * 开发人员：lrushx
 * 开发时间：2016年5月7日
 */

/*
264. Ugly Number II   My Submissions QuestionEditorial Solution
Total Accepted: 29618 Total Submissions: 105216 Difficulty: Medium
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

//找出第n个丑数，以1开始，其余的质因数只有2，3，5
//不要判断，要自己生成长度为n的数组ugly，用于从小到大顺序存储n个丑数，数组中的首项为1，即第一个丑数为1
//设3个idx初始为0，编号2,3,5分别对应在Ugly数组中的值应该*2,*3,*5，最小者为新丑数，然后对应idx++，指向Ugly数组中的下一个generator下标（如果多个数字同时为最小值，则它们的下标都要更新）


    int nthUglyNumber(int n) {
        int idx2=0,idx3=0,idx5=0;
		int UglyNumber[n];
		UglyNumber[0] = 1;
		
		for (int i=1;i<n;i++){
			int a = UglyNumber[idx2]*2;
			int b = UglyNumber[idx3]*3;
			int c = UglyNumber[idx5]*5;
//			int min = MIN(a,min(b,c)); 
			int min = a;
			if (min > b) min = b;
			if (min > c) min = c;

			if (min == a) idx2++;
			if (min == b) idx3++;
			if (min == c) idx5++;
			UglyNumber[i] = min;

		}
		return UglyNumber[n-1];
    }
	
    
int main(){
    cout<<"264_Ugly_Number_II.h:Input n, return the n-th ugly number."<<endl;
    int n;
    cin>>n;
    while(n >0){
        cout<<nthUglyNumber(n)<<"!"<<endl;        
        cin>>n;
    }    
    return 0;
}
