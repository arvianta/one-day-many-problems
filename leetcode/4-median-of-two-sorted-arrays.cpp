// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        * 1. Ensure nums1 is the smaller array to optimize the binary search.
        * 2. Use binary search on the smaller array to find the correct partition.
        * 3. Calculate the partition indices for both arrays.
        * 4. Determine the maximum of the left partitions and the minimum of the right partitions.
        * 5. Check if the partitions are correct (i.e., max_left1 <= min_right2 and max_left2 <= min_right1).
        * 6. If the partitions are correct, calculate the median based on the total length (even or odd).
        * 7. If the partitions are not correct, adjust the binary search range.
        * 8. Time complexity: O(log(min(m, n))), where m and n are the lengths of the two arrays.
        * 9. Space complexity: O(1).
        */
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();
        int left_size = (x + y + 1) / 2;
        
        int low = 0, high = x;
        while (low <= high) {
            int i = (low + high) / 2;   // partition nums1
            int j = left_size - i;      // partition nums2
            
            int max_left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int min_right1 = (i == x) ? INT_MAX : nums1[i];
            int max_left2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int min_right2 = (j == y) ? INT_MAX : nums2[j];

            if (max_left1 <= min_right2 && max_left2 <= min_right1) {
                if ((x + y) % 2 == 0) {
                    return (max(max_left1, max_left2) + min(min_right1, min_right2)) / 2.0;
                } else {
                    return max(max_left1, max_left2);
                }
            } else if (max_left1 > min_right2) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
        return 0.0; // default return, should not reach here
    }
};