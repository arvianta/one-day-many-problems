// https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            int dest = target - nums[i];
            if (map.count(dest)) {
                return {map[dest], i};
            }
            map[nums[i]] = i;
        }
        return{};
    }
};