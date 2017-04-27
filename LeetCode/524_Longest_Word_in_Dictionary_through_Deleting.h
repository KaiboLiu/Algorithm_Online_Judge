//524_Longest_Word_in_Dictionary_through_Deleting.h
//99ms	92.18%

/*
Total Accepted: 5905
Total Submissions: 14436
Instruction: LeetCode 524 - Longest Word in Dictionary through Deleting - [M]
Developer: lrushx
Process Time: Apr 27, 2017
*/


/*
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]
Output: 
"apple"
*/

//给一个字符串s和一个字符串数组d，求字符组d中最长的为s子串(可以不连续)的元素串，若多个长度相等，输出字典顺序最小的。
//先根据长度逆序排序(自己写compare函数，长度相等则逐位比较升序排)，
//然后比较最大长度和s长度大小(可能d中好多个长度大于s，此时用二分找到第一个长度<=s的串位置k)；
//然后从k开始遍历d，每个字符串判断是否为s的非连续子串(subsequence)，d[k]逐位遍历，s中用一个pointer从前往后判断，有满足匹配的就return，否则返回空
//二分初始位置挺好，若没有则变成165ms/3.33%


    struct compare {
        bool operator()(const std::string& first, const std::string& second) {
            if (first.size() == second.size()){
                for (int i=0;i<first.size();i++){
                    if (first[i] == second[i]) continue;
                    return first[i]<second[i];
                }
                return true;
            }
            return first.size() > second.size();
        }
    };


    int bisearch(vector<string>& d,int lens){
        int l=0,r=d.size()-1,mid;
        while (l <= r){
            mid = (r-l)/2+l;
            if (d[mid].size() > lens) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }

    string findLongestWord(string s, vector<string>& d) {
        int num_d = d.size();
        if (num_d < 1) return "";
        compare c;
        sort(d.begin(), d.end(), c);
        
        int lens=s.size(),k=0,i,j;
        bool find;
        if (d[0].size() > lens)
            k = bisearch(d,s.size());
        for (;k<num_d;k++){
            find = true;
            j = 0;
            for (i=0;i<d[k].size();i++){//search d[k][i] in s
                while (j < lens && (s[j] != d[k][i])){
                    j++;
                }
                if (j == lens) {
                    find = false;
                    break;
                }
                else j++;
            }
            if (find) return d[k];
                
        }
        return "";
        
    }


