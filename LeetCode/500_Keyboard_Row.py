#LeetCode - 500_Keyboard_Row.py
#45ms    56.48%

'''
Instruction: LeetCode 500 - Keyboard Row - [E]
Developer: lrushx
Process Time: Apr 13, 2017
'''
 
'''
Given a List of words, return the words that can be typed using letters of 
alphabet on only one row's of American keyboard like the image below.

Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
'''

#给一组单词，返回左右字母都在键盘同一行的词
#可用Hash优化，还未尝试



class Solution(object):
    def findWords(self,words):
        row1 = ['q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P']
        row2 = ['a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L']
        row3 = ['z','x','c','v','b','n','m','Z','X','C','V','B','N','M']
        ans = []
        for word in words:
            if word[0] in row1:
                row = row1
            elif word[0] in row2:
                row = row2
            else:
                row = row3
            flag = True
            for i in range(1,len(word)):
                if not(word[i] in row):
                    flag = False
                    break
            if flag:
                ans.append(word)
        return ans

a = ["Hello", "Alaska", "Dad", "Peace"]
print(findWords(a))
