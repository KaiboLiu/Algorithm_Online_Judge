## 443_String_Compression.py
## 80ms  61.42% 

'''
Total Accepted: 14.6K
Total Submissions: 40.4K
Instruction: LeetCode 443 - String Compression [E]
Developer: lrushx
Process Time: Mar 21, 2018
'''

'''
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
'''


class Solution:
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        chars.sort()
        print(chars)
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
        return chars[:p]
