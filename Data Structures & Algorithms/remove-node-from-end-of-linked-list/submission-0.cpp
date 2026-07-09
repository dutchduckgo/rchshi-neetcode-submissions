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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // find size of ll

        int sz = 0;
        ListNode* cur = head;
        while (cur != NULL) {
            cur = cur->next;
            sz++;
        }
        

        // traverse sz - n nodes;
        int target = sz - n;

        if (target == 0) {
            return head->next;
        }
        
        cur = head;
        ListNode* prev = cur;
        for (int i = 0; i < target; i++) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        return head;

    }
};
