// https://leetcode.com/problems/add-two-numbers/
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
        * 1. Initialize a dummy node to build the result list and a pointer to traverse it.
        * 2. Initialize a carry variable to handle sums greater than 9.
        * 3. Loop through both lists until both are fully traversed and there's no carry left.
        * 4. For each pair of nodes (or 0 if one list is shorter), calculate the sum and update the carry.
        * 5. Create a new node with the digit value (sum % 10) and append it to the result list.
        * 6. Move to the next nodes in both lists.
        * 7. Return the next node of the dummy node, which is the head of the resultant list.
        * 8. Clean up the dummy node to avoid memory leaks.
        * 9. Time complexity: O(max(m, n)), where m and n are the lengths of the two lists.
        * 10. Space complexity: O(max(m, n)) for the new list.
        */
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            int sum = val1 + val2 + carry;
            
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        ListNode* result = dummy->next;
        delete dummy;
        
        return result;
    }
};