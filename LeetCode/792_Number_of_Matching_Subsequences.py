## 792_Number_of_Matching_Subsequences.py
## 776ms   41.2%

'''
Total Accepted: 3.5K
Total Submissions: 10.4K
Instruction: LeetCode 792 - Number of Matching Subsequences [M]
Developer: lrushx
Process Time: Mar 22, 2018
'''

'''
Given string S and a dictionary of words words, find the number of words[i] that is a subsequence of S.

Example :
Input: 
S = "abcde"
words = ["a", "bb", "acd", "ace"]
Output: 3
Explanation: There are three words in words that are a subsequence of S: "a", "acd", "ace".
Note:

All words in words and S will only consists of lowercase letters.
The length of S will be in the range of [1, 50000].
The length of words will be in the range of [1, 5000].
The length of words[i] will be in the range of [1, 50].
'''

class Solution:
    def numMatchingSubseq(self, S, words):
        """
        :type S: str
        :type words: List[str]
        :rtype: int
        """
        """
        idx = [0] * len(words)
        res = 0
        for ch in S:
            for i,word in enumerate(words):
                if idx[i] >= 0 and ch == word[idx[i]]:
                    idx[i] += 1
                    if idx[i] == len(words[i]):
                        idx[i] = -1
                        res += 1
        return res             
        """
        idx = collections.defaultdict(list)
        for i,ch in enumerate(S): idx[ch].append(i)
        res = 0
        for word in words:
            i,pos = 0,0
            for ch in word:
                pos = bisect.bisect_left(idx[ch], pos)
                if (pos == len(idx[ch])): break
                pos = idx[ch][pos] + 1
                i += 1
            if i == len(word): res += 1
        return res
