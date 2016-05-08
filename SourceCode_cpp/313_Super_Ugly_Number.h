//313_Super_Ugly_Number.h
//76ms	94.97%

/**
 * Instruction：LeetCode 313 - Super Ugly Number
 * Developer：lrushx
 * Process Time：May 7, 2016
 */
 
/*
Write a program to find the nth super ugly number.
Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
*/

 
//扩展264.Ugly Number II，求第n个丑数，其中质因数组扩展到给定数组
//将263中的质因数2，3，5变成一个数组，原来用3个数字当下标记录中间变量generator，如今变成数组的k个，就用k长数组来记这些idx

    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size(),min,tmp;
		int SuperUglyNumber[n];
		SuperUglyNumber[0] = 1;
		int idx[k];//代表生成当前丑数的generator下标，idx[j]表示可以用SuperUglyNumber[idx[j]]*primes[j]来生成新丑数，要求本轮所有j的操作中最小的作为丑数，一旦生成，idx[i]++
		for (int i=0;i<k;i++) idx[i] = 0;
		
		for (int i=1;i<n;i++){
			min = SuperUglyNumber[idx[0]] * primes[0];
			for (int j=1;j<k;j++){
				tmp = SuperUglyNumber[idx[j]] * primes[j];
				min = min < tmp ? min : tmp;
//				if (min > tmp) min = tmp;					
			}			
			for (int j=0;j<k;j++)
				if (SuperUglyNumber[idx[j]] * primes[j] == min) idx[j]++;
					
			SuperUglyNumber[i] = min;			
		}
		return SuperUglyNumber[n-1];
    }
	
	
int main(){
    cout<<"313_Super_Ugly_Number:Input n, k and {ak}, return find the duplicate one."<<endl;
    int n,k;
    vector<int> nums;
    cin>>n>>k;
    while(n > 0 && k > 0){        
        nums.resize(k);
        for(int i=0;i<k;i++) cin>>nums[i];
        
        cout<<nthSuperUglyNumber(n,nums)<<endl;
        cin>>n>>k;
    }
    
    return 0;
}
