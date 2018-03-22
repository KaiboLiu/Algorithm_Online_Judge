## 443_String_Compression.py
## 56ms  93.78% 

'''
Total Accepted: 14.6K
Total Submissions: 40.4K
Instruction: LeetCode 443 - String Compression [E]
Developer: lrushx
Process Time: Mar 21, 2018
'''

'''
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.


Follow up:
Could you solve it using only O(1) extra space?


Example 1:
Input:
["a","a","b","b","c","c","c"]

Output:
Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]

Explanation:
"aa" is replaced by "a2". "bb" is replaced by "b2". "ccc" is replaced by "c3".
'''

class Solution:
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        #chars.sort()
        l = len(chars)
        p = i = 0
        while i < l:
            chars[p] = chars[i]
            j = i + 1
            while j < l and chars[i]==chars[j]: j += 1
            n = j-i
            p += 1
            if n > 1:
                for dig in str(n):
                    chars[p] = dig
                    p += 1
            i = j
        while len(chars) > p: chars.pop()
        #chars = chars[:p]
        #print(chars)
        return None
