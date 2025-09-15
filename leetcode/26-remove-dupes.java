// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        
        int lastIndex = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[lastIndex]){
                lastIndex++;
                nums[lastIndex] = nums[i];
            }
        }

        return lastIndex + 1;
    }
}