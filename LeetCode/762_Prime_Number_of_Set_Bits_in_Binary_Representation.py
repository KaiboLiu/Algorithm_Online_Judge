## 762_Prime_Number_of_Set_Bits_in_Binary_Representation.py
## ms   ?%

'''
Total Accepted:5.6K
Total Submissions:9.9K
Instruction: LeetCode 762 - Prime Number of Set Bits in Binary Representation - [E]
Developer: lrushx
Process Time: Feb 11, 2018
'''

'''
Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) having a prime number of set bits in their binary representation.

(Recall that the number of set bits an integer has is the number of 1s present when written in binary. For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)

Example 1:

Input: L = 6, R = 10
Output: 4
Explanation:
6 -> 110 (2 set bits, 2 is prime)
7 -> 111 (3 set bits, 3 is prime)
9 -> 1001 (2 set bits , 2 is prime)
10->1010 (2 set bits , 2 is prime)
'''

class Solution:
    def countPrimeSetBits(self, L, R):
        """
        :type L: int
        :type R: int
        :rtype: int
        """
        f = [2,3,5,7,11,13,17,19,23]
        res = 0
        for x in range(L,R+1):
            bits = 0
            y,s=x,''

            while x > 0:
                s = str(x&1)+s
                bits += (x & 1)
                x >>= 1
            if bits in f: res += 1
            print(y,s,bits)
        return res

if __name__ == "__main__":
    c = Solution()
    
    print(c.countPrimeSetBits(10,15))
    print(c.countPrimeSetBits(6,10))
    #print(c.countPrimeSetBits(492638,497046))
    print(c.countPrimeSetBits(842,888))
