// https://leetcode.com/problems/string-to-integer-atoi/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        // skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // convert digits
        long result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // check overflow before multiplying
            if (result > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return (int)(result * sign);
    }
};