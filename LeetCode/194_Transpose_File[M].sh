## 194_Transpose_File[M].sh
## 120ms  88.14%

## Total Accepted: 6.8K
## Total Submissions: 31.3K
## Developer: lrushx
## Process Time: Apr 27, 2018
## https://leetcode.com/problems/transpose-file/description/

# Read from the file file.txt and print its transposed content to stdout.

## solution 1, awk, 16ms/99.62%
awk '{
    for (i = 1; i <= NF; ++i) {
        if (NR == 1) s[i] = $i;
        else s[i] = s[i] " " $i;
    }
} END {
    for (i = 1; s[i] != ""; ++i) {
        print s[i];
    }
}' file.txt


## solution 2, 240ms
# python3 <<EOF
# m = [line.strip().split(' ') for line in open("file.txt")]
# for c in range(len(m[0])):
#   print(*(m[r][c] for r in range(len(m))))
# EOF
