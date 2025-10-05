// https://leetcode.com/problems/merge-intervals/
class Solution {
    public int[][] merge(int[][] intervals) {
        
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> res = new ArrayList<>();

        int currStart = intervals[0][0];
        int currEnd = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            int nextStart = intervals[i][0];
            int nextEnd = intervals[i][1];

            if (nextStart <= currEnd) {
                currEnd = Math.max(currEnd, nextEnd);
            } else {
                res.add(new int[]{currStart, currEnd});
                currStart = nextStart;
                currEnd = nextEnd;
            }
        }

        res.add(new int[]{currStart, currEnd});

        return res.toArray(new int[res.size()][]);
    }
}