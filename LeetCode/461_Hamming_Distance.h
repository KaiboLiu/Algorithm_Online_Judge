
//LeetCode - 461_Hamming_Distance.h
//3ms	99.51%

/**
 * Instruction：LeetCode 461 - Hamming Distance - [E]
 * Developer：lrushx
 * Process Time：Apr 13, 2017
 */
 
/*
Total Accepted: 51296
Total Submissions: 72579
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
*/

//求2个32位整数的汉明距

    int hammingDistance(int x, int y) {
        int dist = 0;
        do{
            dist += (x & 1)^(y & 1);
            x = x>>1;
            y = y>>1;
        }
        while (x+y>0);
        return dist;
    }


int main(){
    int a = hammingDistance(1577962638,1727613287);
    cout<<a<<endl;
    
    }