// https://leetcode.com/problems/permutations/
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        solve(nums, new LinkedHashSet<>(), res);

        return res; 
    }

    private void solve (int[] nums, Set<Integer> set, List<List<Integer>> res) {
        if (set.size() == nums.length) {
            res.add(new ArrayList<>(set));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            if(!set.contains(nums[i])) {
                set.add(nums[i]);
                solve(nums, set, res);
                set.remove(nums[i]);
            }
        }
    }
}