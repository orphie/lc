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
    typedef std::vector<ListNode*> NodeVec;
    typedef NodeVec::iterator Iter;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())      return NULL;
        while (1 != lists.size()) { 
            ListNode* last = lists.back();
            lists.pop_back();
            merge2Lists(lists.back(), last);
        }
        return lists.front();
    }
    
    void merge2Lists(ListNode*& l1, ListNode* l2) {
        if (!l2) return;
        if (!l1) {
            l1 = l2;
            return;
        }
        
        if (l1->val > l2->val) {
            ListNode* temp = l2->next;
            l2->next = l1;
            l1 = l2;
            l2 = temp;
        }
        
        ListNode* localL1 = l1;
        // localL1->val is always small than l2->val
        while (l2) {
            ListNode* temp = l2->next;
            insertToList(localL1, l2);
            if (temp == l2->next) {
                return;
            }
            localL1 = l2;
            l2 = temp;
        }
    }
    
    inline void insertToList(ListNode* list, ListNode* node) {
        if (!list) {
            list = node;
            return;
        }
        
        while (1) {
            if (!list->next) {
                list->next = node;
                return;
            }
            
            if (list->next->val > node->val) {
                ListNode* temp = list->next;
                list->next = node;
                node->next = temp;
                return;
            }
            list = list->next;
        }
    }
};
