//454_4Sum_II.h
//342ms	82.78%

/*
Total Accepted: 12252
Total Submissions: 26939
Instruction: LeetCode 454 - 4Sum II - [M]
Developer: lrushx
Process Time: May 08, 2017
*/


/*
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:
Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]
Output:
2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/


//给4个数组，每个里取一个数，使得4个数的和为0，求满足条件的取法(值可以重复，只要每个数组中索引不同即可)
//一开始想的和018一样的方案，先搜i,j，然后k，l往中间，加些剪枝做到O(n^3)，可是成绩不理想，属于后10%
//之后用hash table，把a,b 2个数组所有和的方案数存到map中<和，方案数>，然后遍历k,l,用-c[k]-d[l]的值去map中找，若表中有值，则加到答案方案中。复杂度O(n^2)。
//其中剪枝是遍历i,j时是二重for，若排序了a，则可在第一层for中处理a的重复数字，避免j再多for一轮，同理k,l也这样。
//这种的hash table确实挺好用。虽然还是自己想出来，但是花了不少时间。


//solution1 , O(n^3) with two pointers
//1276 ms even with prune

    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = A.size();
        if (len == 0) return 0;
        int i,j,k,l,s,res=0,c_i,c_j,c_k,c_l;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        sort(C.begin(),C.end());
        sort(D.begin(),D.end());
        for (i=0;i<len;i++){
            if (A[i]+B[0]+C[0]+D[0] > 0) break;
            if (A[i]+B[len-1]+C[len-1]+D[len-1] < 0) continue;
            c_i = 1;
            while (i<len-1 && A[i] == A[i+1]){i++;c_i++;}
            for (j=0;j<len;j++){
                s = -A[i]-B[j];
                if (C[0]+D[0] > s) break;
                if (C[len-1]+D[len-1] < s) continue;
                c_j = 1;
                while (j<len-1 && B[j] == B[j+1]){j++;c_j++;}
                k=0; l=len-1;
                while (k < len && l >=0){
                    while (k < len && l >=0 && C[k]+D[l] != s){
                        while (k<len && C[k]+D[l] < s) k++;
                        if (k == len) break;
                        while (l>=0  && C[k]+D[l] > s) l--;
                    }
                    if (k<len && l>=0) {
                        //cout<<A[i]<<"+"<<B[j]<<"+"<<C[k]<<"+"<<D[l]<<"=0"<<endl;
                        k++;    l--;
                        c_k = 1;
                        c_l = 1;
                        while (k < len && C[k] == C[k-1]){c_k++; k++;}
                        while (l >= 0  && D[l] == D[l+1]){c_l++; l--;}
                        res += (c_i * c_j * c_k * c_l);
                    }
                }
            }
        }
        return res;
    }

//solution2, O(n^2) with hash table, divide them into (A,B) and (C,D), put A+B into hash table then check -C-D in the table
//342ms	82.78%

    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int len = A.size();
        if (len == 0) return 0;
        int i,j,res=0,c_i,c_j;
        sort(A.begin(),A.end());
        sort(C.begin(),C.end());
        unordered_map <int,int> m1;
        
        for (i=0;i<len;i++){
            c_i = 1;
            while (i<len-1 && A[i] == A[i+1]){i++;c_i++;}
            for (j=0;j<len;j++){
                m1[A[i]+B[j]] += c_i;
            }
        }

        for (i=0;i<len;i++){
            c_i = 1;
            while (i<len-1 && C[i] == C[i+1]){i++;c_i++;}
            for (j=0;j<len;j++){
                if (m1[-C[i]-D[j]])
                    res += m1[-C[i]-D[j]] * c_i;
            }
        }
        return res;
    }
