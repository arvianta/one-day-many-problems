// https://leetcode.com/problems/first-missing-positive/
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        for (int i = 0; i < n; i++) {
            int x = Math.abs(nums[i]);
            if (x >= 1 && x <= n) {
                if (nums[x - 1] > 0) 
                    nums[x - 1] = -nums[x - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1; 
        }

        return n + 1;
    }
}