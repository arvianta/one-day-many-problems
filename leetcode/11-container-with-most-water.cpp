// https://leetcode.com/problems/container-with-most-water/description/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            int len = right - left;
            int curr_area = len * min(height[left], height[right]);
            max_area = max(max_area, curr_area);

            if (height[left] < height[right]) left++;
            else right--;
        }

        return max_area;
    }
};