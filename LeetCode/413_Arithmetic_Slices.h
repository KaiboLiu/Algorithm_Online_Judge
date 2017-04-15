//LeetCode - 413_Arithmetic_Slices.h
//3ms  100%

/*
Instruction: LeetCode 413 - Arithmetic Slices - [M]
Developer: lrushx
Process Time: Apr 14, 2017
*/
 
/*
Total Accepted: 18149
Total Submissions: 33031

A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
For example, these are arithmetic sequence:
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.
1, 1, 2, 5, 7
A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.
A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.
The function should return the number of arithmetic slices in the array A.

Example:
A = [1, 2, 3, 4]
return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
*/

//统计一个数列中长度>=3的子数列中连续等差数列的个数（合格样例中可以有重复元素）
//先用一个数列储存相邻差（也可以不用数列），求出当下等值（差）数列长度l，则方案数+l(l-1)/2，若差不相等，则更新差。


    int numberOfArithmeticSlices(vector<int>& A) {
        //vector<int> d=A;
        int l=A.size();
        if (l < 3) return 0;
        A.push_back(A[l-1]-A[l-2]+A[l-1]-1);
        
        int ans=0,wid=1,diff=A[1]-A[0];
        for (int i=2;i<=l;i++){
            if (A[i]-A[i-1] == diff) wid++;
            else {
                if (wid >= 2) ans += wid*(wid-1)/2;
                wid = 1;
                diff = A[i]-A[i-1];
            }
        }
        return ans;
    }

int main(){
    
    cout<<"413_Arithmetic_Slices:"<<endl;

    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    
    cout<<endl<<numberOfArithmeticSlices(a)<<endl;
        
    }