// https://leetcode.com/problems/combination-sum-ii/
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();

        Arrays.sort(candidates);

        solve(candidates, target, 0, path, res);

        return res;
    }

    private void solve(int[] candidates, int target, int start, List<Integer> path, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(path));
            return;
        }

        for (int i = start; i < candidates.length; i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break;
            
            path.add(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, path, res);
            path.remove(path.size() - 1);
        }
    }
}