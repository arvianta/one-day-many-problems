// https://leetcode.com/problems/zigzag-conversion/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        vector<string> rows(numRows);
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < s.size(); i++) {
            int pos = i % cycleLen;
            int row = pos < numRows ? pos : cycleLen - pos;
            rows[row] += s[i];
        }

        string result;
        for (string& row : rows) result += row;
        return result;
    }
};