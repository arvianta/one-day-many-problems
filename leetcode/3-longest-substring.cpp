// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
        * 1. Use a hash map to store the last index of each character.
        * 2. Use two pointers (left and right) to represent the current window of non-repeating characters.
        * 3. Iterate through the string with the right pointer.
        * 4. If the character at the right pointer is already in the hash map and its index is within the current window, move the left pointer to one position right of that index.
        * 5. Update the character's index in the hash map to the current right pointer
        * 6. Calculate the length of the current window and update the maximum length if necessary.
        * 7. Return the maximum length found.
        * 8. Time complexity: O(n), where n is the length of the string.
        * 9. Space complexity: O(min(m, n)), where m is the size of the character set and n is the length of the string.
        * 
        */
        unordered_map<char, int> charIndexMap;
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];
            if (charIndexMap.find(currentChar) != charIndexMap.end()) {
                left = max(left, charIndexMap[currentChar] + 1);
            }
            charIndexMap[currentChar] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};