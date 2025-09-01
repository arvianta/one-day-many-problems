// https://leetcode.com/problems/longest-palindromic-substring/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLen = 1;
        
        for (int center = 0; center < s.size(); center++) {
            // odd length (starts from center)
            expand(s, center, center, start, maxLen);
            // even length (starts from center and center + 1)
            expand(s, center, center + 1, start, maxLen);
        }
        
        return s.substr(start, maxLen);
    }
    
private:
    void expand(const string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }
};