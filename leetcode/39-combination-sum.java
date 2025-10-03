// https://leetcode.com/problems/combination-sum/
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        solve(candidates, target, 0, path, res);

        return res;
    }

    private void solve(int[] candidates, int target, int start, List<Integer> path, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(path));
            return;
        }

        if (target < 0) return;

        for (int i = start; i < candidates.length; i++) {
            path.add(candidates[i]);
            solve(candidates, target - candidates[i], i, path, res);
            path.remove(path.size() - 1);
        }
    } 
}