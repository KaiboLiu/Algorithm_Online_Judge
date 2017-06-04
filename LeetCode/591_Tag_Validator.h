//591_Tag_Validator.h
//3ms	100.00%
//LeetCode Contest 35

/*
Total Accepted: 130
Total Submissions: 818
Instruction: LeetCode 519 - Tag Validator - [H]
Developer: lrushx
Process Time: June 03, 2017
*/

/*
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
*/

//<AA>*</AA>类型的字符串判断是否valid，其中*可以是有tag也可以是plain text，<![CDATA[**]]>中的**是plain text，可以无视<等。并且*可以有单独的>
//函数f部分：初始串一定是<A>*</A>，然后*中删除所有<![CDATA[**]]>，再用另一个函数g继续递归*部分；
//g部分：找一对<B></B>，但是要注意(1)<B></B><B></B>和(2)<B><B></B></B>的情况，类似括号对的情况，有<B>之后，查找</B>为pos1，同时查找另一个<B>为pos2。若pos2<pos1，说明是(2)，要往后成对找到对应的</B>，然后把这个字符串分成中间f(<B>*</B>)，g(左边)，和g(右边)。
//同时注意：左边和右边用substr复制时要注意长度为0的情况
//太多情况，一次次WA才发现。
//其中一个是CDATA中有<B>或者</B>千万不能参与查找tag，要提前先删除这部分，但是要在判断初始串有<A>*</A>之后再删除；

    bool isValidcontent(string code) {
        int len = code.size();
        if (len == 0) return true;
        size_t found,found1,found2,found3;
                
        found = code.find("<");
        if (found != std::string::npos){
            found1 = code.find(">",found);
            string tag1 = code.substr(found+1,found1-found-1),tag2;
            tag2 = "</"+tag1+">";
            tag1 = "<"+tag1+">";
            int c = 2,s2=tag2.size();
            found2 = code.find(tag2,found1+1);
            if (found2 == std::string::npos) return false;
            found3 = code.find(tag1,found1+1);
            if (found3 != std::string::npos && found3 < found2){
                for (int i=found3+1;i<=len-s2;i++)
                    if (code[i] == '<'){
                        if (tag2 == code.substr(i,s2)) { c--; i += s2;}
                        if (c == 0) { found2 = i;break;}
                        if (i > len-s2) break;
                        if (tag1 == code.substr(i,s2-1)) {c++;  i += s2-1;}
                    }
                if (c) return false;
            }
            if (found2+s2 < len) return isValidcontent(code.substr(0,found))&&isValidcontent(code.substr(found2+s2))&&isValid(code.substr(found,found2+s2-found));
            else return isValidcontent(code.substr(0,found))&&isValid(code.substr(found,found2+s2-found));
        }
        return true;
        
    }
    
    bool isValid(string code) {
        int len = code.size();
        size_t found,pos,found1;
        
        if (code[0] != '<' || code[len-1] != '>') return false;
        
        len = code.size();
        if (len < 7) return false;
        found = code.find('>');
        if (found > len/2 || found < 2 || found > 10) return false;
        for (pos=1;pos<found;pos++) {
            if (code[pos] > 'Z' || code[pos] < 'A') return false;
            if (code[pos] != code[len-found+pos-1]) return false;
        }
        if (code[len-found-1] != '/' || code[len-found-2] != '<') return false;
        code = code.substr(found+1,len-found-found-3);
        
        found = code.find("<![CDATA[");
        while (found != std::string::npos){
            found1 = code.find("]]>",found);
            if (found1 == std::string::npos) return false;
            code.erase(found,found1-found+3);
            found = code.find("<![CDATA[");
        }
        return isValidcontent(code);
    }

/*
"""<DIV>This is the first line <![CDATA[<div>]]></DIV>""""<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>""
""<A>  <B> </A>   </B>""
""<DIV>  div tag is not closed  <DIV>""
""<DIV>  unmatched <  </DIV>""
""<A><A></A></A>""
""<DIV> closed tags with invalid tag name  <b>123</b> </DIV>""
""<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>""
""<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>""
""<A><A>456</A>  <A> 123  !!  <![CDATA[]]>  123 </A>   <A>123</A></A>""
""<A><A>456</A>  <A> 123  !!  <![CDATA[]]>  123 </A>   <B>123</B></A>""
""<A><B>456</A>  <A> 123  !!  <![CDATA[]]>  123 </A>   <A>123</B></A>""
""<A><A>789</A>  <A> 987  !!  <![CDATA[<![cdata]>]]>  675 </A>   <A><![CDATA[</A>]]>  </A>  <A>123</A></A>""
""<H></H>""
""<DIV><YFSYYS><UVBNIQ><XPMXUNT><WNGMV><OJJGQREMT><Z><GEJDP><LIQS><NCVYU><RAS><UYFKCJCDN><NA><POJVYT><Z><TDC><VUIZQC><BNANGX><TOF><MR>MK</MR></TOF></BNANGX></VUIZQC></TDC></Z></POJVYT></NA></UYFKCJCDN></RAS></NCVYU></LIQS></GEJDP></Z></OJJGQREMT></WNGMV></XPMXUNT></UVBNIQ></YFSYYS></DIV>""
""<![CDATA[ABC]]><TAG>sometext</TAG>""


true
false
false
false
true
false
false
false
true
true
false
true
true
true
false"
*/
