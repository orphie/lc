/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool overflow   = false;
        ListNode* head  = calculate(l1, l2, overflow);
        ListNode* last  = head;
        while (l1 || l2) {
            // create current node
            ListNode* current = calculate(l1, l2, overflow);
            last->next = current;
            last = current;
        }
        
        if (overflow) {
            ListNode* tail = new ListNode(1);
            last->next = tail;
        }
        return head;
    }
    
    inline ListNode* calculate(ListNode*& l1, ListNode*& l2, bool& overflow) {
        int newValue = addTwo(l1?l1->val:0, l2?l2->val:0, overflow);
        ListNode* ret = new ListNode(newValue);
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
        
        return ret;
    }
    
    inline int addTwo(int a, int b, bool& overflow) {
        int ret = a + b + (overflow ? 1 : 0);
        if (ret >= 10) {
            overflow = true;
            return ret - 10;
        } else {
            overflow = false;
            return ret;
        }
    }
};
