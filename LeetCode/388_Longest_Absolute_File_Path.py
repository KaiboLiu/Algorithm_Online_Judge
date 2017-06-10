//388_Longest_Absolute_File_Path.py
//35ms	98.40%

/*
Total Accepted: 28550
Total Submissions: 79276
Instruction: LeetCode 388 - Longest Absolute File Path - [M]
Developer: lrushx
Process Time: June 08, 2017
*/

/*
Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Note:
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.
*/

//给一个字符串代表文件系统，\n分割文件(文件夹)，\t个数代表路径层级，有后缀的为文件，求字符路径最长的文件长度
//在字符串最后加上一个\n，然后循环查找\n，记为end，起始为start，在start处用while往下查找\t个数确定层级i，记下该层长度l[i]=end-start+l[i-1]，i==0单独处理，判断'.'是否在[start,end)区间中，若是则按最大值更新答案，然后start=end+1

    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        if ('.' not in input):
            return 0
        l = [0]*100
        res = 0
        words = input.split("\n")
        for word in words:
            i = word.count("\t")
            if (i == 0):
                l[0] = len(word)
            else:
                l[i] = l[i-1]+len(word)-i
            if ('.' in word):
                res = max(res,l[i]+i)
        return res
