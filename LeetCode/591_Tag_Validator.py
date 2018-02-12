## 591_Tag_Validator.h
## 3ms   100.00%

'''
Total Accepted: 130
Total Submissions: 818
Instruction: LeetCode 519 - Tag Validator - [H]
Developer: lrushx
Process Time: Feb 11, 2018
'''

'''
Given a string representing a code snippet, you need to implement a tag validator to parse the code and return whether it is valid. A code snippet is valid if all the following rules hold:
1.The code must be wrapped in a valid closed tag. Otherwise, the code is invalid.
2.A closed tag (not necessarily valid) has exactly the following format : <TAG_NAME>TAG_CONTENT</TAG_NAME>. Among them, <TAG_NAME> is the start tag, and </TAG_NAME> is the end tag. The TAG_NAME in start and end tags should be the same. A closed tag is valid if and only if the TAG_NAME and TAG_CONTENT are valid.
3.A valid TAG_NAME only contain upper-case letters, and has length in range [1,9]. Otherwise, the TAG_NAME is invalid.
4.A valid TAG_CONTENT may contain other valid closed tags, cdata and any characters (see note1) EXCEPT unmatched <, unmatched start and end tag, and unmatched or closed tags with invalid TAG_NAME. Otherwise, the TAG_CONTENT is invalid.
5.A start tag is unmatched if no end tag exists with the same TAG_NAME, and vice versa. However, you also need to consider the issue of unbalanced when tags are nested.
6.A < is unmatched if you cannot find a subsequent >. And when you find a < or </, all the subsequent characters until the next > should be parsed as TAG_NAME (not necessarily valid).
7.The cdata has the following format : <![CDATA[CDATA_CONTENT]]>. The range of CDATA_CONTENT is defined as the characters between <![CDATA[ and the first subsequent ]]>.
8.CDATA_CONTENT may contain any characters. The function of cdata is to forbid the validator to parse CDATA_CONTENT, so even it has some characters that can be parsed as tag (no matter valid or invalid), you should treat it as regular characters.

Note:
For simplicity, you could assume the input code (including the any characters mentioned above) only contain letters, digits, '<','>','/','!','[',']' and ' '.

Sample data is at the bottom
'''

# <AA>*</AA>类型的字符串判断是否valid，其中*可以是有tag也可以是plain text，<![CDATA[**]]>中的**是plain text，可以无视<等。并且*可以有单独的>
# 函数f部分：初始串一定是<A>*</A>，然后*中删除所有<![CDATA[**]]>，再用另一个函数g继续递归*部分；
# g部分：找一对<B></B>，但是要注意(1)<B></B><B></B>和(2)<B><B></B></B>的情况，类似括号对的情况，有<B>之后，查找</B>为pos1，同时查找另一个<B>为pos2。若pos2<pos1，说明是(2)，要往后成对找到对应的</B>，然后把这个字符串分成中间f(<B>*</B>)，g(左边)，和g(右边)。
# 同时注意：左边和右边用substr复制时要注意长度为0的情况
# 太多情况，一次次WA才发现。
# 其中一个是CDATA中有<B>或者</B>千万不能参与查找tag，要提前先删除这部分，但是要在判断初始串有<A>*</A>之后再删除；
class Solution:
    def isValid(self, code):
        """
        :type code: str
        :rtype: bool
        """
        import re

        pat_tag1 = '^<([A-Z]{1,9})>'
        tags = re.findall(pat_tag1, code)
        #print(tags[0])
        if tags == []: return False
        pat_tag2 = '^<'+tags[0]+'>(.*)</'+tags[0]+'>$'
        content_list = re.findall(pat_tag2, code)
        if content_list == []: return False
        content = content_list[0]

        ## remove all the valid cdata
        pat_cdata = '(<!\[CDATA\[((?!\]\]>).)*\]\]>)'   # (?!\]\]>).  means any character except ']]>'
        cdatas = re.findall(pat_cdata,content)
        #print('cdata: ', cdatas)
        for cdata in cdatas:
            if type(cdata) == tuple:
                content = content.replace(cdata[0],'')
            else: content = content.replace(cdata,'')
        
        #print('content: '+ content)
        def validContent(content):
            if '<' in content:
                tags = re.findall(pat_tag1, content)
                if tags == []: return False
                count, pos_open, tag = 1, content.find(tag), tags[0]
                pos = pos_open + 1
                while pos > 0 and count > 0:
                    i, j = content.find('<'+tag+'>',pos), content.find('</'+tag+'>',pos)
                    if i > -1 and (i < j or j == -1): 
                        count += 1      # find a next open tag
                        pos = i + 1
                    elif j > -1 and (j < i or i == -1): 
                        count -= 1      # find a next closed tag
                        pos = j + 1
                    else: pos = -1
                if count != 0: return False
                pos_close += (1+len(tag))
                print('nested: '+content[pos_open:pos_close+1])
                return validContent(content[:pos_open]) and validContent(isValid(content[pos_open:pos_close+1])) and validContent(content[pos_close+1:])

            else: return True

        return validContent(content)


if __name__ == "__main__":
    c = Solution()
    s = "<DIV>This is the <![CDATA[dfdsad<CDATA>]]>first line <![CDATA[<div>99]]></DIV>"
    print(c.isValid(s))
    s = "<DIV>This is the first line <![CDATA[<div>]]></DIV>"
    print(c.isValid(s))
    s = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>"
    print(c.isValid(s))
    s = "<A>  <B> </A>   </B>"
    print(c.isValid(s))
    s = "<DIV>  div tag is not closed  <DIV>"
    print(c.isValid(s))
    s = "<DIV>  unmatched <  </DIV>"
    print(c.isValid(s))
    s = "<DIV> closed tags with invalid tag name  <b>123</b> </DIV>"
    print(c.isValid(s))
    s = "<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>"
    print(c.isValid(s))
    s = "<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>"
    print(c.isValid(s))
    s = "<A><A>/A></A></A>"
    print(c.isValid(s))

    
