// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Worst case O(n), best O(log n)
class Solution1 {
    public int[] searchRange(int[] nums, int target) {
        int lo = 0, hi = nums.length - 1;
        int[] res = new int[2];

        while (hi >= lo) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                int left = mid;
                int right = mid;

                // find left
                while (true) {
                    if (nums[left] < target) break;
                    left--;
                }

                // find right
                while(true) {
                    if (nums[right] > target) break;
                    right++;
                }
                res[0] = left + 1;
                res[1] = right - 1;
                return res;
            }

            if (target < mid) hi = mid - 1;
            else lo = mid + 1;
        }
        res[0] = -1;
        res[1] = -1;

        return res;
    }
}

// O(log n)
class Solution2 {
    public int[] searchRange(int[] nums, int target) {
        int[] res = new int[2];
        res[0] = findLeft(nums, target);
        res[1] = findRight(nums, target);
        return res;
    }

    private int findLeft(int[] nums, int target) {
        int lo = 0, hi = nums.length - 1, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
            if (nums[mid] == target) ans = mid;
        }
        return ans;
    }

    private int findRight(int[] nums, int target) {
        int lo = 0, hi = nums.length - 1, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
            if (nums[mid] == target) ans = mid;
        }
        return ans;
    }
}