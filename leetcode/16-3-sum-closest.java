// https://leetcode.com/problems/3sum-closest
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int res = nums[0] + nums[1] + nums[2]; // initialize with first triplet
        int min_diff = Math.abs(target - res);

        for (int i = 0; i < nums.length - 2; i++) {
            int left = i + 1, right = nums.length - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int curr_diff = Math.abs(target - sum);

                if (curr_diff < min_diff) {
                    min_diff = curr_diff;
                    res = sum;
                }

                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    return sum; // exact match = best possible
                }
            }
        }
        return res;
    }
}